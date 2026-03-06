// Copyright 2015-2026 Piperift. All Rights Reserved.

#include "PropertyFunctions/StateTreeVectorPropertyFunctions.h"

#include "PropertyFunctions/StateTreePropertyFunctionHelpers.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(StateTreeVectorPropertyFunctions)

#define LOCTEXT_NAMESPACE "StateTreeVectorPropertyFunctions"

void FStateTreeAddVectorPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Result = InstanceData.Left + InstanceData.Right;
}

void FStateTreeSubtractVectorPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Result = InstanceData.Left - InstanceData.Right;
}

void FStateTreeGetDistancePropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FVector::Dist(InstanceData.Left, InstanceData.Right);
}

void FStateTreeGetDistanceSqrtPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FVector::DistSquared(InstanceData.Left, InstanceData.Right);
}


#if WITH_EDITOR
FText FStateTreeAddVectorPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForMathOperation<FInstanceDataType>(
		LOCTEXT("VectorAdd", "+"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeSubtractVectorPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForMathOperation<FInstanceDataType>(
		LOCTEXT("VectorSubtract", "-"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeGetDistancePropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistance", "GetDistance"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeGetDistanceSqrtPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistanceSquared", "GetDistanceSqrt"), ID, InstanceDataView, BindingLookup,
		Formatting);
}
#endif

#undef LOCTEXT_NAMESPACE