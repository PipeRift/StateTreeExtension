// Copyright 2015-2026 Piperift. All Rights Reserved.

#include "Conditions/StateTreeVectorDistanceConditions.h"

#include <StateTreeExecutionContext.h>
#include <StateTreeNodeDescriptionHelpers.h>

#include UE_INLINE_GENERATED_CPP_BY_NAME(StateTreeVectorDistanceConditions)

#define LOCTEXT_NAMESPACE "StateTreeVectorDistanceConditions"

namespace
{
	template <typename T>
	bool CompareNumbers(const T Left, const T Right, const EGenericAICheck Operator)
	{
		switch (Operator)
		{
			case EGenericAICheck::Equal:
				return Left == Right;
			case EGenericAICheck::NotEqual:
				return Left != Right;
			case EGenericAICheck::Less:
				return Left < Right;
			case EGenericAICheck::LessOrEqual:
				return Left <= Right;
			case EGenericAICheck::Greater:
				return Left > Right;
			case EGenericAICheck::GreaterOrEqual:
				return Left >= Right;
			default:
				ensureMsgf(false, TEXT("Unhandled operator %d"), int32(Operator));
				return false;
		}
	}
}	 // namespace


bool FStateTreeCompareVector2DDistanceCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	const double Left = FVector2D::DistSquared(InstanceData.Source, InstanceData.Target);
	const double Right = FMath::Square(InstanceData.Distance);
	const bool bResult = CompareNumbers(Left, Right, Operator);

	SET_NODE_CUSTOM_TRACE_TEXT(Context, Override, TEXT("%sDistance %s %s %s (from [%s] to [%s])"),
		*UE::StateTree::DescHelpers::GetInvertText(bInvert, EStateTreeNodeFormatting::Text).ToString(),
		*LexToString(FMath::Sqrt(Left)),
		*UE::StateTree::DescHelpers::GetOperatorText(Operator, EStateTreeNodeFormatting::Text).ToString(),
		*LexToString(InstanceData.Distance), *InstanceData.Source.ToString(),
		*InstanceData.Target.ToString());

	return bResult ^ bInvert;
}

bool FStateTreeCompareIntVectorDistanceCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	const double Left = FMath::Square(InstanceData.Source.X - InstanceData.Target.X) +
						FMath::Square(InstanceData.Source.Y - InstanceData.Target.Y) +
						FMath::Square(InstanceData.Source.Z - InstanceData.Target.Z);
	const double Right = FMath::Square(InstanceData.Distance);
	const bool bResult = CompareNumbers(Left, Right, Operator);

	SET_NODE_CUSTOM_TRACE_TEXT(Context, Override, TEXT("%sDistance %s %s %s (from [%s] to [%s])"),
		*UE::StateTree::DescHelpers::GetInvertText(bInvert, EStateTreeNodeFormatting::Text).ToString(),
		*LexToString(FMath::Sqrt(Left)),
		*UE::StateTree::DescHelpers::GetOperatorText(Operator, EStateTreeNodeFormatting::Text).ToString(),
		*LexToString(InstanceData.Distance), *InstanceData.Source.ToString(),
		*InstanceData.Target.ToString());

	return bResult ^ bInvert;
}

bool FStateTreeCompareIntPointDistanceCondition::TestCondition(FStateTreeExecutionContext& Context) const
{
	const FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	const double Left = FMath::Square(InstanceData.Source.X - InstanceData.Target.X) +
						FMath::Square(InstanceData.Source.Y - InstanceData.Target.Y);
	const double Right = FMath::Square(InstanceData.Distance);
	const bool bResult = CompareNumbers(Left, Right, Operator);

	SET_NODE_CUSTOM_TRACE_TEXT(Context, Override, TEXT("%sDistance %s %s %s (from [%s] to [%s])"),
		*UE::StateTree::DescHelpers::GetInvertText(bInvert, EStateTreeNodeFormatting::Text).ToString(),
		*LexToString(FMath::Sqrt(Left)),
		*UE::StateTree::DescHelpers::GetOperatorText(Operator, EStateTreeNodeFormatting::Text).ToString(),
		*LexToString(InstanceData.Distance), *InstanceData.Source.ToString(),
		*InstanceData.Target.ToString());

	return bResult ^ bInvert;
}


#if WITH_EDITOR
FText FStateTreeCompareVector2DDistanceCondition::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FInstanceDataType>();
	check(InstanceData);

	FNumberFormattingOptions Options;
	Options.MinimumFractionalDigits = 1;
	Options.MaximumFractionalDigits = 3;

	const FText SourceValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Source)), Formatting);

	const FText TargetValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Target)), Formatting);

	FText DistanceValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Distance)), Formatting);
	if (DistanceValue.IsEmpty())
	{
		DistanceValue = FText::AsNumber(InstanceData->Distance, &Options);
	}

	const FText OperatorText = UE::StateTree::DescHelpers::GetOperatorText(Operator, Formatting);
	const FText InvertText = UE::StateTree::DescHelpers::GetInvertText(bInvert, Formatting);

	const FText Format = (Formatting == EStateTreeNodeFormatting::RichText)
						   ? LOCTEXT("CompareVector2DDistanceRich",
								 "{EmptyOrNot}<s>Distance from</> {Source} <s>to</> {Target} {Op} {Distance}")
						   : LOCTEXT("CompareVector2DDistance",
								 "{EmptyOrNot}Distance from {Source} to {Target} {Op} {Distance}");

	return FText::FormatNamed(Format, TEXT("EmptyOrNot"), InvertText, TEXT("Source"), SourceValue,
		TEXT("Target"), TargetValue, TEXT("Op"), OperatorText, TEXT("Distance"), DistanceValue);
}

FText FStateTreeCompareIntVectorDistanceCondition::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FInstanceDataType>();
	check(InstanceData);

	FNumberFormattingOptions Options;
	Options.MinimumFractionalDigits = 1;
	Options.MaximumFractionalDigits = 3;

	const FText SourceValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Source)), Formatting);

	const FText TargetValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Target)), Formatting);

	FText DistanceValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Distance)), Formatting);
	if (DistanceValue.IsEmpty())
	{
		DistanceValue = FText::AsNumber(InstanceData->Distance, &Options);
	}

	const FText OperatorText = UE::StateTree::DescHelpers::GetOperatorText(Operator, Formatting);
	const FText InvertText = UE::StateTree::DescHelpers::GetInvertText(bInvert, Formatting);

	const FText Format = (Formatting == EStateTreeNodeFormatting::RichText)
						   ? LOCTEXT("CompareIntVectorDistanceRich",
								 "{EmptyOrNot}<s>Distance from</> {Source} <s>to</> {Target} {Op} {Distance}")
						   : LOCTEXT("CompareIntVectorDistance",
								 "{EmptyOrNot}Distance from {Source} to {Target} {Op} {Distance}");

	return FText::FormatNamed(Format, TEXT("EmptyOrNot"), InvertText, TEXT("Source"), SourceValue,
		TEXT("Target"), TargetValue, TEXT("Op"), OperatorText, TEXT("Distance"), DistanceValue);
}

FText FStateTreeCompareIntPointDistanceCondition::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FInstanceDataType>();
	check(InstanceData);

	FNumberFormattingOptions Options;
	Options.MinimumFractionalDigits = 1;
	Options.MaximumFractionalDigits = 3;

	const FText SourceValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Source)), Formatting);

	const FText TargetValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Target)), Formatting);

	FText DistanceValue = BindingLookup.GetBindingSourceDisplayName(
		FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(FInstanceDataType, Distance)), Formatting);
	if (DistanceValue.IsEmpty())
	{
		DistanceValue = FText::AsNumber(InstanceData->Distance, &Options);
	}

	const FText OperatorText = UE::StateTree::DescHelpers::GetOperatorText(Operator, Formatting);
	const FText InvertText = UE::StateTree::DescHelpers::GetInvertText(bInvert, Formatting);

	const FText Format = (Formatting == EStateTreeNodeFormatting::RichText)
						   ? LOCTEXT("CompareIntPointDistanceRich",
								 "{EmptyOrNot}<s>Distance from</> {Source} <s>to</> {Target} {Op} {Distance}")
						   : LOCTEXT("CompareIntPointDistance",
								 "{EmptyOrNot}Distance from {Source} to {Target} {Op} {Distance}");

	return FText::FormatNamed(Format, TEXT("EmptyOrNot"), InvertText, TEXT("Source"), SourceValue,
		TEXT("Target"), TargetValue, TEXT("Op"), OperatorText, TEXT("Distance"), DistanceValue);
}
#endif	  // WITH_EDITOR

#undef LOCTEXT_NAMESPACE