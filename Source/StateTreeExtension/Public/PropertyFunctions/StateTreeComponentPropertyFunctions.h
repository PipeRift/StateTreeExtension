// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <StateTreePropertyFunctionBase.h>

#include "StateTreeComponentPropertyFunctions.generated.h"


USTRUCT()
struct FStateTreeGetComponentLocationPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	TObjectPtr<class USceneComponent> Input = nullptr;

	UPROPERTY(EditAnywhere, Category = Output)
	FVector Output = FVector::ZeroVector;
};

/**
 * Get the world location of a scene component.
 */
USTRUCT(meta = (DisplayName = "Get Component Location", Category = "Component"))
struct FStateTreeGetComponentLocationPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetComponentLocationPropertyFunctionInstanceData;

	virtual const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API virtual void Execute(FStateTreeExecutionContext& Context) const override;

#if WITH_EDITOR
	STE_API virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const;
#endif
};