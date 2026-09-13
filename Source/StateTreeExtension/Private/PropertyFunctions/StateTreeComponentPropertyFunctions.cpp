// Copyright 2015-2026 Piperift. All Rights Reserved.

#include "PropertyFunctions/StateTreeComponentPropertyFunctions.h"

#include "PropertyFunctions/StateTreePropertyFunctionHelpers.h"

#include <Components/SceneComponent.h>


#include UE_INLINE_GENERATED_CPP_BY_NAME(StateTreeComponentPropertyFunctions)

#define LOCTEXT_NAMESPACE "StateTreeComponentPropertyFunctions"


void FStateTreeGetComponentLocationPropertyFunction::Execute(FStateTreeExecutionContext& Context) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	InstanceData.Output = InstanceData.Input ? InstanceData.Input->GetComponentLocation() : FVector::ZeroVector;
}

#if WITH_EDITOR
FText FStateTreeGetComponentLocationPropertyFunction::GetDescription(const FGuid& ID,
	FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
	EStateTreeNodeFormatting Formatting) const
{
	return UE::StateTree::DescHelpers::GetDescriptionForSingleParameterFunc<FInstanceDataType>(
		LOCTEXT("StateTreeComponentLocation", "GetComponentLocation"), ID, InstanceDataView, BindingLookup,
		Formatting);
}
#endif

#undef LOCTEXT_NAMESPACE