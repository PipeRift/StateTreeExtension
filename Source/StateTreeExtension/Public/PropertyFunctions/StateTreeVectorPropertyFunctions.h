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
struct FStateTreeVector2DCombinationPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector2D Left = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector2D Right = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Output)
	FVector2D Result = FVector2D::ZeroVector;
};


/**
 * Add right vector2d to left vector2d.
 */
USTRUCT(meta = (DisplayName = "Add (Vector2D)", Category = "Math|Vector2D"))
struct FStateTreeAddVector2DPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeVector2DCombinationPropertyFunctionInstanceData;

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
 * Subtract right vector2d from left vector2d.
 */
USTRUCT(meta = (DisplayName = "Subtract (Vector2D)", Category = "Math|Vector2D"))
struct FStateTreeSubtractVector2DPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeVector2DCombinationPropertyFunctionInstanceData;

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
struct FStateTreeIntVectorCombinationPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FIntVector Left = FIntVector::ZeroValue;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FIntVector Right = FIntVector::ZeroValue;

	UPROPERTY(EditAnywhere, Category = Output)
	FIntVector Result = FIntVector::ZeroValue;
};


/**
 * Add right int vector to left int vector.
 */
USTRUCT(meta = (DisplayName = "Add (IntVector)", Category = "Math|IntVector"))
struct FStateTreeAddIntVectorPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeIntVectorCombinationPropertyFunctionInstanceData;

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
 * Subtract right int vector from left int vector.
 */
USTRUCT(meta = (DisplayName = "Subtract (IntVector)", Category = "Math|IntVector"))
struct FStateTreeSubtractIntVectorPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeIntVectorCombinationPropertyFunctionInstanceData;

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
struct FStateTreeIntPointCombinationPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FIntPoint Left = FIntPoint::ZeroValue;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FIntPoint Right = FIntPoint::ZeroValue;

	UPROPERTY(EditAnywhere, Category = Output)
	FIntPoint Result = FIntPoint::ZeroValue;
};


/**
 * Add right int point to left int point.
 */
USTRUCT(meta = (DisplayName = "Add (IntPoint)", Category = "Math|IntPoint"))
struct FStateTreeAddIntPointPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeIntPointCombinationPropertyFunctionInstanceData;

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
 * Subtract right int point from left int point.
 */
USTRUCT(meta = (DisplayName = "Subtract (IntPoint)", Category = "Math|IntPoint"))
struct FStateTreeSubtractIntPointPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeIntPointCombinationPropertyFunctionInstanceData;

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
struct FStateTreeGetDistanceVectorPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector Left = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector Right = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Output)
	double Output = 0;
};


USTRUCT(meta = (DisplayName = "Get Distance (Vector)", Category = "Math|Vector"))
struct FStateTreeGetDistanceVectorPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistanceVectorPropertyFunctionInstanceData;

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
struct FStateTreeGetDistanceSqrtVectorPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistanceVectorPropertyFunctionInstanceData;

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
struct FStateTreeGetDistanceVector2DPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector2D Left = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FVector2D Right = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, Category = Output)
	double Output = 0;
};


USTRUCT(meta = (DisplayName = "Get Distance (Vector2D)", Category = "Math|Vector"))
struct FStateTreeGetDistanceVector2DPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistanceVector2DPropertyFunctionInstanceData;

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


USTRUCT(meta = (DisplayName = "Get Distance (Vector2D, Squared)", Category = "Math|Vector"))
struct FStateTreeGetDistanceSqrtVector2DPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistanceVector2DPropertyFunctionInstanceData;

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
struct FStateTreeGetDistanceIntVectorPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FIntVector Left = FIntVector::ZeroValue;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FIntVector Right = FIntVector::ZeroValue;

	UPROPERTY(EditAnywhere, Category = Output)
	double Output = 0;
};


USTRUCT(meta = (DisplayName = "Get Distance (IntVector)", Category = "Math|Vector"))
struct FStateTreeGetDistanceIntVectorPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistanceIntVectorPropertyFunctionInstanceData;

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


USTRUCT(meta = (DisplayName = "Get Distance (IntVector, Squared)", Category = "Math|Vector"))
struct FStateTreeGetDistanceSqrtIntVectorPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistanceIntVectorPropertyFunctionInstanceData;

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
struct FStateTreeGetDistanceIntPointPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter)
	FIntPoint Left = FIntPoint::ZeroValue;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FIntPoint Right = FIntPoint::ZeroValue;

	UPROPERTY(EditAnywhere, Category = Output)
	double Output = 0;
};


USTRUCT(meta = (DisplayName = "Get Distance (IntPoint)", Category = "Math|Vector"))
struct FStateTreeGetDistanceIntPointPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistanceIntPointPropertyFunctionInstanceData;

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


USTRUCT(meta = (DisplayName = "Get Distance (IntPoint, Squared)", Category = "Math|Vector"))
struct FStateTreeGetDistanceSqrtIntPointPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeGetDistanceIntPointPropertyFunctionInstanceData;

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
