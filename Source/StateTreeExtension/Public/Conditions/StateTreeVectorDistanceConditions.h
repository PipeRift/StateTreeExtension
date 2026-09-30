// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <AITypes.h>
#include <StateTreeConditionBase.h>

#include "StateTreeVectorDistanceConditions.generated.h"


struct FStateTreeExecutionContext;


USTRUCT()
struct FStateTreeCompareVector2DDistanceConditionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	FVector2D Source = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	FVector2D Target = FVector2D::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	double Distance = 0.0;
};
UE_STATETREE_ZEROED_TRIVIALLY_COPIED_NO_DESTRUCTOR_INSTANCEDATA(
	FStateTreeCompareVector2DDistanceConditionInstanceData);

/**
 * Condition comparing distance between two Vector2D by a tolerance distance.
 */
USTRUCT(DisplayName = "Distance Compare (Vector2D)")
struct FStateTreeCompareVector2DDistanceCondition : public FStateTreeConditionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeCompareVector2DDistanceConditionInstanceData;

	FStateTreeCompareVector2DDistanceCondition() = default;
	explicit FStateTreeCompareVector2DDistanceCondition(const UE::StateTree::EComparisonOperator InOperator,
		const EStateTreeCompare InInverts = EStateTreeCompare::Default)
		: bInvert(InInverts == EStateTreeCompare::Invert)
		, Operator(InOperator)
	{}

	virtual const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

#if WITH_EDITOR
	STE_API virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup,
		EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
#endif

	UPROPERTY(EditAnywhere, Category = "Condition")
	bool bInvert = false;

	UPROPERTY(EditAnywhere, Category = "Condition", meta = (InvalidEnumValues = "IsTrue"))
	UE::StateTree::EComparisonOperator Operator = UE::StateTree::EComparisonOperator::LessOrEqual;
};


USTRUCT()
struct FStateTreeCompareIntVectorDistanceConditionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	FIntVector Source = FIntVector::ZeroValue;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	FIntVector Target = FIntVector::ZeroValue;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	double Distance = 0.0;
};
UE_STATETREE_ZEROED_TRIVIALLY_COPIED_NO_DESTRUCTOR_INSTANCEDATA(
	FStateTreeCompareIntVectorDistanceConditionInstanceData);

/**
 * Condition comparing distance between two IntVector by a tolerance distance.
 */
USTRUCT(DisplayName = "Distance Compare (IntVector)")
struct FStateTreeCompareIntVectorDistanceCondition : public FStateTreeConditionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeCompareIntVectorDistanceConditionInstanceData;

	FStateTreeCompareIntVectorDistanceCondition() = default;
	explicit FStateTreeCompareIntVectorDistanceCondition(const UE::StateTree::EComparisonOperator InOperator,
		const EStateTreeCompare InInverts = EStateTreeCompare::Default)
		: bInvert(InInverts == EStateTreeCompare::Invert)
		, Operator(InOperator)
	{}

	virtual const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

#if WITH_EDITOR
	STE_API virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup,
		EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
#endif

	UPROPERTY(EditAnywhere, Category = "Condition")
	bool bInvert = false;

	UPROPERTY(EditAnywhere, Category = "Condition", meta = (InvalidEnumValues = "IsTrue"))
	UE::StateTree::EComparisonOperator Operator = UE::StateTree::EComparisonOperator::LessOrEqual;
};


USTRUCT()
struct FStateTreeCompareIntPointDistanceConditionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input")
	FIntPoint Source = FIntPoint::ZeroValue;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	FIntPoint Target = FIntPoint::ZeroValue;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	double Distance = 0.0;
};
UE_STATETREE_ZEROED_TRIVIALLY_COPIED_NO_DESTRUCTOR_INSTANCEDATA(
	FStateTreeCompareIntPointDistanceConditionInstanceData);

/**
 * Condition comparing distance between two IntPoint by a tolerance distance.
 */
USTRUCT(DisplayName = "Distance Compare (IntPoint)")
struct FStateTreeCompareIntPointDistanceCondition : public FStateTreeConditionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeCompareIntPointDistanceConditionInstanceData;

	FStateTreeCompareIntPointDistanceCondition() = default;
	explicit FStateTreeCompareIntPointDistanceCondition(const UE::StateTree::EComparisonOperator InOperator,
		const EStateTreeCompare InInverts = EStateTreeCompare::Default)
		: bInvert(InInverts == EStateTreeCompare::Invert)
		, Operator(InOperator)
	{}

	virtual const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

#if WITH_EDITOR
	STE_API virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup,
		EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
#endif

	UPROPERTY(EditAnywhere, Category = "Condition")
	bool bInvert = false;

	UPROPERTY(EditAnywhere, Category = "Condition", meta = (InvalidEnumValues = "IsTrue"))
	UE::StateTree::EComparisonOperator Operator = UE::StateTree::EComparisonOperator::LessOrEqual;
};