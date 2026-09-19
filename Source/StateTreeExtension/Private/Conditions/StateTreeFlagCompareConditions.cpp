// Copyright 2015-2026 Piperift. All Rights Reserved.

#include "Conditions/StateTreeFlagCompareConditions.h"

#include <StateTreeExecutionContext.h>
#include <StateTreeNodeDescriptionHelpers.h>
#include <UObject/EnumProperty.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(StateTreeFlagCompareConditions)

#define LOCTEXT_NAMESPACE "StateTreeFlagCompareConditions"

namespace
{
	FText GetOperatorText(const EStateTreeFlagOperator Operator, const EStateTreeNodeFormatting Formatting)
	{
		if (Formatting == EStateTreeNodeFormatting::RichText)
		{
			switch (Operator)
			{
				case EStateTreeFlagOperator::Equal:
					return LOCTEXT("EqualOperator", "<s>is</>");
				case EStateTreeFlagOperator::Any:
					return LOCTEXT("AnyOperator", "<s>has</> any <s>of</>");
				case EStateTreeFlagOperator::All:
					return LOCTEXT("AllOperator", "<s>has</> all <s>of</>");
				default:
					return FText::GetEmpty();
			}
		}
		switch (Operator)
		{
			case EStateTreeFlagOperator::Equal:
				return LOCTEXT("EqualOperator", "is");
			case EStateTreeFlagOperator::Any:
				return LOCTEXT("AnyOperator", "has any of");
			case EStateTreeFlagOperator::All:
				return LOCTEXT("AllOperator", "has all of");
			default:
				return FText::GetEmpty();
		}
	}
}	 // namespace

bool FStateTreeFlagCompareCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	const uint32 Left = InstanceData.Left.Value;
	const uint32 Right = InstanceData.Right.Value;

	bool bResult = false;
	switch (Operator)
	{
		case EStateTreeFlagOperator::Equal:
			bResult = Left == Right;
			break;
		case EStateTreeFlagOperator::Any:
			bResult = (Left & Right) != 0;
			break;
		case EStateTreeFlagOperator::All:
			bResult = (Left & Right) == Right;
			break;
		default:
			break;
	}

	SET_NODE_CUSTOM_TRACE_TEXT(Context, Override, TEXT("%s%s %s %s"),
		*UE::StateTree::DescHelpers::GetInvertText(bInvert, EStateTreeNodeFormatting::Text).ToString(),
		*InstanceData.Left.Enum->GetNameStringByValue(InstanceData.Left.Value),
		*GetOperatorText(Operator, EStateTreeNodeFormatting::Text).ToString(),
		*InstanceData.Left.Enum->GetNameStringByValue(InstanceData.Right.Value));

	return bResult ^ bInvert;
}

#if WITH_EDITOR
FText FStateTreeFlagCompareCondition::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FInstanceDataType>();
	check(InstanceData);

	FText LeftValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Left)), Formatting);
	if (LeftValue.IsEmpty())
	{
		if (InstanceData->Left.Enum)
		{
			LeftValue = InstanceData->Left.Enum->GetDisplayNameTextByValue(InstanceData->Left.Value);
		}
		else
		{
			LeftValue = LOCTEXT("None", "None");
		}
	}

	FText RightValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Right)), Formatting);
	if (RightValue.IsEmpty())
	{
		if (InstanceData->Left.Enum)
		{
			RightValue = InstanceData->Right.Enum->GetDisplayNameTextByValue(InstanceData->Right.Value);
		}
		else
		{
			RightValue = LOCTEXT("None", "None");
		}
	}

	const FText InvertText = UE::StateTree::DescHelpers::GetInvertText(bInvert, Formatting);
	const FText OperatorText = GetOperatorText(Operator, Formatting);

	const FText Format = (Formatting == EStateTreeNodeFormatting::RichText)
						   ? LOCTEXT("CompareFlagRich", "{EmptyOrNot}{Left} <s>{Op}</> {Right}")
						   : LOCTEXT("CompareFlag", "{EmptyOrNot}{Left} {Op} {Right}");

	return FText::FormatNamed(Format, TEXT("EmptyOrNot"), InvertText, TEXT("Left"), LeftValue, TEXT("Op"),
		OperatorText, TEXT("Right"), RightValue);
}

void FStateTreeFlagCompareCondition::OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
	const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
	const IStateTreeBindingLookup& BindingLookup)
{
	if (!TargetPath.GetStructID().IsValid())
	{
		return;
	}

	FInstanceDataType& Instance = InstanceData.GetMutable<FInstanceDataType>();

	// Left has changed, update enums from the leaf property.
	if (!TargetPath.IsPathEmpty() &&
		TargetPath.GetSegments().Last().GetName() == GET_MEMBER_NAME_CHECKED(FInstanceDataType, Left))
	{
		if (const FProperty* LeafProperty = BindingLookup.GetPropertyPathLeafProperty(SourcePath))
		{
			// Handle both old stype namespace enums and new class enum properties.
			UEnum* NewEnum = nullptr;
			if (const FByteProperty* ByteProperty = CastField<FByteProperty>(LeafProperty))
			{
				NewEnum = ByteProperty->GetIntPropertyEnum();
			}
			else if (const FEnumProperty* EnumProperty = CastField<FEnumProperty>(LeafProperty))
			{
				NewEnum = EnumProperty->GetEnum();
			}

			if (Instance.Left.Enum != NewEnum)
			{
				Instance.Left.Initialize(NewEnum);
			}
		}
		else
		{
			Instance.Left.Initialize(nullptr);
		}

		if (Instance.Right.Enum != Instance.Left.Enum)
		{
			Instance.Right.Initialize(Instance.Left.Enum);
		}
	}
}
#endif	  // WITH_EDITOR

#undef LOCTEXT_NAMESPACE