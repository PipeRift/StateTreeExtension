// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <StateTreePropertyFunctionBase.h>

#include "StateTreeVectorPropertyFunctions.generated.h"


USTRUCT()
struct FStateTreeVectorCombinationPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector Left = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector Right = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Output)
	FVector Result = FVector::ZeroVector;
};

/**
 * Add right vector from left vector.
 */
USTRUCT(meta = (DisplayName = "Add", Category = "Math|Vector"))
struct FStateTreeAddVectorPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeVectorCombinationPropertyFunctionInstanceData;

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


/**
 * Subtract right vector from left vector.
 */
USTRUCT(meta = (DisplayName = "Subtract", Category = "Math|Vector"))
struct FStateTreeSubtractVectorPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeVectorCombinationPropertyFunctionInstanceData;

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


USTRUCT()
struct FStateTreeGetDistancePropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector Left = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector Right = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Output)
	double Output = 0;
};


USTRUCT(meta = (DisplayName = "Get Distance", Category = "Math|Vector"))
struct FStateTreeGetDistancePropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistancePropertyFunctionInstanceData;

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


USTRUCT(meta = (DisplayName = "Get Distance (Squared)", Category = "Math|Vector"))
struct FStateTreeGetDistanceSqrtPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistancePropertyFunctionInstanceData;

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
