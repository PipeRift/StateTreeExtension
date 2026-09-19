// Copyright 2015-2026 Piperift. All Rights Reserved.

#include "PropertyFunctions/StateTreeEnumPropertyFunctions.h"

#include "PropertyFunctions/StateTreePropertyFunctionHelpers.h"

#include <UObject/EnumProperty.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(StateTreeEnumPropertyFunctions)

#define LOCTEXT_NAMESPACE "StateTreeEnumPropertyFunctions"

#if WITH_EDITOR
namespace Details
{
	// Syncs the enum type of the changed target from its binding source, and lets the other
	// (unbound) side inherit that type.
	void OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
		const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
		const IStateTreeBindingLookup& BindingLookup)
	{
		if (!TargetPath.GetStructID().IsValid())
		{
			return;
		}

		const FName TargetName =
			TargetPath.IsPathEmpty() ? NAME_None : TargetPath.GetSegments().Last().GetName();
		const bool bLeftChanged =
			TargetName == GET_MEMBER_NAME_CHECKED(FStateTreeEnumFlagPropertyFunctionInstanceData, Left);
		const bool bRightChanged =
			TargetName == GET_MEMBER_NAME_CHECKED(FStateTreeEnumFlagPropertyFunctionInstanceData, Right);
		if (!bLeftChanged && !bRightChanged)
		{
			return;
		}

		auto& Instance = InstanceData.GetMutable<FStateTreeEnumFlagPropertyFunctionInstanceData>();
		FStateTreeAnyEnum& Changed = bLeftChanged ? Instance.Left : Instance.Right;
		FStateTreeAnyEnum& Other = bLeftChanged ? Instance.Right : Instance.Left;

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

			if (Changed.Enum != NewEnum)
			{
				Changed.Initialize(NewEnum);
			}
		}
		else
		{
			Changed.Initialize(nullptr);
		}

		if (Other.Enum != Changed.Enum)
		{
			Other.Initialize(Changed.Enum);
		}
	}

	FText GetDescriptionInternal(const FText& OpText, const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting)
	{
		const FStateTreeEnumFlagPropertyFunctionInstanceData* InstanceData =
			InstanceDataView.GetPtr<FStateTreeEnumFlagPropertyFunctionInstanceData>();
		check(InstanceData);

		FText LeftValue = BindingLookup.GetBindingSourceDisplayName(
			FPropertyBindingPath(
				ID, GET_MEMBER_NAME_CHECKED(FStateTreeEnumFlagPropertyFunctionInstanceData, Left)),
			Formatting);
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
			FPropertyBindingPath(
				ID, GET_MEMBER_NAME_CHECKED(FStateTreeEnumFlagPropertyFunctionInstanceData, Right)),
			Formatting);
		if (RightValue.IsEmpty())
		{
			if (InstanceData->Right.Enum)
			{
				RightValue = InstanceData->Right.Enum->GetDisplayNameTextByValue(InstanceData->Right.Value);
			}
			else
			{
				RightValue = LOCTEXT("None", "None");
			}
		}

		const FText Format = (Formatting == EStateTreeNodeFormatting::RichText)
							   ? LOCTEXT("FlagCheckRich", "<b>{Op}</> ({Left}, {Right})")
							   : LOCTEXT("FlagCheck", "{Op} ({Left}, {Right})");

		return FText::FormatNamed(
			Format, TEXT("Op"), OpText, TEXT("Left"), LeftValue, TEXT("Right"), RightValue);
	}
}	 // namespace Details
#endif	  // WITH_EDITOR

void FStateTreeFlagHasAnyPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.bOutput = (InstanceData.Left.Value & InstanceData.Right.Value) != 0;
}

void FStateTreeFlagHasAllPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.bOutput = (InstanceData.Left.Value & InstanceData.Right.Value) == InstanceData.Right.Value;
}

void FStateTreeEnumEqualsPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.bOutput = InstanceData.Left.Value == InstanceData.Right.Value;
}

#if WITH_EDITOR
EDataValidationResult FStateTreeFlagHasAnyPropertyFunction::Compile(
	UE::StateTree::ICompileNodeContext& CompileContext)
{
	const FStateTreeEnumFlagPropertyFunctionInstanceData& InstanceData =
		CompileContext.GetInstanceDataView().Get<FStateTreeEnumFlagPropertyFunctionInstanceData>();

	const bool bLeftBound = CompileContext.HasBindingForProperty("Left");
	const bool bRightBound = CompileContext.HasBindingForProperty("Right");
	if (bLeftBound && bRightBound && InstanceData.Left.Enum != InstanceData.Right.Enum)
	{
		CompileContext.AddValidationError(
			LOCTEXT("EnumMismatch", "Left and Right bound to different enum types."));
		return EDataValidationResult::Invalid;
	}
	return EDataValidationResult::Valid;
}

EDataValidationResult FStateTreeFlagHasAllPropertyFunction::Compile(
	UE::StateTree::ICompileNodeContext& CompileContext)
{
	const FStateTreeEnumFlagPropertyFunctionInstanceData& InstanceData =
		CompileContext.GetInstanceDataView().Get<FStateTreeEnumFlagPropertyFunctionInstanceData>();

	const bool bLeftBound = CompileContext.HasBindingForProperty("Left");
	const bool bRightBound = CompileContext.HasBindingForProperty("Right");
	if (bLeftBound && bRightBound && InstanceData.Left.Enum != InstanceData.Right.Enum)
	{
		CompileContext.AddValidationError(
			LOCTEXT("EnumMismatch", "Left and Right bound to different enum types."));
		return EDataValidationResult::Invalid;
	}
	return EDataValidationResult::Valid;
}

EDataValidationResult FStateTreeEnumEqualsPropertyFunction::Compile(
	UE::StateTree::ICompileNodeContext& CompileContext)
{
	const FStateTreeEnumFlagPropertyFunctionInstanceData& InstanceData =
		CompileContext.GetInstanceDataView().Get<FStateTreeEnumFlagPropertyFunctionInstanceData>();

	const bool bLeftBound = CompileContext.HasBindingForProperty("Left");
	const bool bRightBound = CompileContext.HasBindingForProperty("Right");
	if (bLeftBound && bRightBound && InstanceData.Left.Enum != InstanceData.Right.Enum)
	{
		CompileContext.AddValidationError(
			LOCTEXT("EnumMismatch", "Left and Right bound to different enum types."));
		return EDataValidationResult::Invalid;
	}
	return EDataValidationResult::Valid;
}

FText FStateTreeFlagHasAnyPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return Details::GetDescriptionInternal(
		LOCTEXT("HasAnyOp", "HasAny"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeFlagHasAllPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return Details::GetDescriptionInternal(
		LOCTEXT("HasAllOp", "HasAll"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeEnumEqualsPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return Details::GetDescriptionInternal(
		LOCTEXT("EqualsOp", "Equals"), ID, InstanceDataView, BindingLookup, Formatting);
}

void FStateTreeEnumEqualsPropertyFunction::OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
	const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
	const IStateTreeBindingLookup& BindingLookup)
{
	Details::OnBindingChanged(ID, InstanceData, SourcePath, TargetPath, BindingLookup);
}

void FStateTreeFlagHasAnyPropertyFunction::OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
	const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
	const IStateTreeBindingLookup& BindingLookup)
{
	Details::OnBindingChanged(ID, InstanceData, SourcePath, TargetPath, BindingLookup);
}

void FStateTreeFlagHasAllPropertyFunction::OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
	const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
	const IStateTreeBindingLookup& BindingLookup)
{
	Details::OnBindingChanged(ID, InstanceData, SourcePath, TargetPath, BindingLookup);
}
#endif

#undef LOCTEXT_NAMESPACE