// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <AITypes.h>
#include <StateTreeAnyEnum.h>
#include <StateTreeConditionBase.h>

#include "StateTreeFlagCompareConditions.generated.h"

struct FStateTreeDataView;


UENUM()
enum class EStateTreeFlagOperator : uint8
{
	Equal = 0,
	Any,
	All,
};


USTRUCT()
struct FStateTreeFlagCompareConditionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Input", meta = (AllowAnyBinding))
	FStateTreeAnyEnum Left;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	FStateTreeAnyEnum Right;
};
STATETREE_POD_INSTANCEDATA(FStateTreeFlagCompareConditionInstanceData);

/**
 * Condition comparing two enum flags.
 */
USTRUCT(DisplayName = "Flag Compare")
struct FStateTreeFlagCompareCondition : public FStateTreeConditionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeFlagCompareConditionInstanceData;

	FStateTreeFlagCompareCondition() = default;
	explicit FStateTreeFlagCompareCondition(const EStateTreeCompare InInverts)
		: bInvert(InInverts == EStateTreeCompare::Invert)
	{}

	FStateTreeFlagCompareCondition(const bool bInInverts) : bInvert(bInInverts) {}

	virtual const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API virtual bool TestCondition(FStateTreeExecutionContext& Context) const override;

#if WITH_EDITOR
	STE_API virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup,
		EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;

	STE_API virtual void OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
		const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
		const IStateTreeBindingLookup& BindingLookup) override;
#endif

	UPROPERTY(EditAnywhere, Category = "Parameter")
	bool bInvert = false;

	UPROPERTY(EditAnywhere, Category = "Parameter")
	EStateTreeFlagOperator Operator = EStateTreeFlagOperator::Any;
};