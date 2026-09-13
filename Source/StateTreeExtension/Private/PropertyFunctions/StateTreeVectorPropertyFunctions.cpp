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

void FStateTreeAddVector2DPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Result = InstanceData.Left + InstanceData.Right;
}

void FStateTreeSubtractVector2DPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Result = InstanceData.Left - InstanceData.Right;
}

void FStateTreeAddIntVectorPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Result = InstanceData.Left + InstanceData.Right;
}

void FStateTreeSubtractIntVectorPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Result = InstanceData.Left - InstanceData.Right;
}

void FStateTreeAddIntPointPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Result = InstanceData.Left + InstanceData.Right;
}

void FStateTreeSubtractIntPointPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Result = InstanceData.Left - InstanceData.Right;
}

void FStateTreeGetDistanceVectorPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FVector::Dist(InstanceData.Left, InstanceData.Right);
}

void FStateTreeGetDistanceSqrtVectorPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FVector::DistSquared(InstanceData.Left, InstanceData.Right);
}

void FStateTreeGetDistanceVector2DPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FVector2D::Distance(InstanceData.Left, InstanceData.Right);
}

void FStateTreeGetDistanceSqrtVector2DPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FVector2D::DistSquared(InstanceData.Left, InstanceData.Right);
}

void FStateTreeGetDistanceIntVectorPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FMath::Sqrt(double(FMath::Square(InstanceData.Left.X - InstanceData.Right.X) +
											 FMath::Square(InstanceData.Left.Y - InstanceData.Right.Y) +
											 FMath::Square(InstanceData.Left.Z - InstanceData.Right.Z)));
}

void FStateTreeGetDistanceSqrtIntVectorPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FMath::Square(InstanceData.Left.X - InstanceData.Right.X) +
						  FMath::Square(InstanceData.Left.Y - InstanceData.Right.Y) +
						  FMath::Square(InstanceData.Left.Z - InstanceData.Right.Z);
}

void FStateTreeGetDistanceIntPointPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FMath::Sqrt(double(FMath::Square(InstanceData.Left.X - InstanceData.Right.X) +
											 FMath::Square(InstanceData.Left.Y - InstanceData.Right.Y)));
}

void FStateTreeGetDistanceSqrtIntPointPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = FMath::Square(InstanceData.Left.X - InstanceData.Right.X) +
						  FMath::Square(InstanceData.Left.Y - InstanceData.Right.Y);
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

FText FStateTreeAddVector2DPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("Vector2DAdd", "+"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeSubtractVector2DPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("Vector2DSubtract", "-"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeAddIntVectorPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("IntVectorAdd", "+"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeSubtractIntVectorPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("IntVectorSubtract", "-"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeAddIntPointPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("IntPointAdd", "+"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeSubtractIntPointPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("IntPointSubtract", "-"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeGetDistanceVectorPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistance", "GetDistance"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeGetDistanceSqrtVectorPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistanceSquared", "GetDistanceSqrt"), ID, InstanceDataView, BindingLookup,
		Formatting);
}

FText FStateTreeGetDistanceVector2DPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistanceVector2D", "GetDistance"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeGetDistanceSqrtVector2DPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistanceSquaredVector2D", "GetDistanceSqrt"), ID, InstanceDataView, BindingLookup,
		Formatting);
}

FText FStateTreeGetDistanceIntVectorPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistanceIntVector", "GetDistance"), ID, InstanceDataView, BindingLookup,
		Formatting);
}

FText FStateTreeGetDistanceSqrtIntVectorPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistanceSquaredIntVector", "GetDistanceSqrt"), ID, InstanceDataView, BindingLookup,
		Formatting);
}

FText FStateTreeGetDistanceIntPointPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistanceIntPoint", "GetDistance"), ID, InstanceDataView, BindingLookup, Formatting);
}

FText FStateTreeGetDistanceSqrtIntPointPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForTwoParametersFunc<FInstanceDataType>(
		LOCTEXT("StateTreeDistanceSquaredIntPoint", "GetDistanceSqrt"), ID, InstanceDataView, BindingLookup,
		Formatting);
}
#endif

#undef LOCTEXT_NAMESPACE