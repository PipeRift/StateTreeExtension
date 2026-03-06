// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <GameplayTagContainer.h>
#include <StateTreePropertyRef.h>
#include <StateTreeTaskBase.h>

#include "GameplayTagTasks.generated.h"


USTRUCT()
struct FStateTreeAddGameplayTagInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Out, meta = (RefType = "/Script/GameplayTags.GameplayTagContainer"))
	FStateTreePropertyRef Container;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, Category = Parameter)
	bool bWaitAndAddOnExit = false;
};

USTRUCT(meta = (DisplayName = "Add Gameplay Tag", Category = "Common|GameplayTags"))
struct FStateTreeAddGameplayTagTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeAddGameplayTagInstanceData;

	STE_API FStateTreeAddGameplayTagTask();

	const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API EStateTreeRunStatus EnterState(
		FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	STE_API void ExitState(
		FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

#if WITH_EDITOR
	STE_API FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup,
		EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
	FName GetIconName() const override
	{
		return FName("StateTreeEditorStyle|Node.Tag");
	}
	FColor GetIconColor() const override
	{
		return UE::StateTree::Colors::Grey;
	}
#endif	  // WITH_EDITOR
};


USTRUCT()
struct FStateTreeRemoveGameplayTagInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Out, meta = (RefType = "/Script/GameplayTags.GameplayTagContainer"))
	FStateTreePropertyRef Container;

	UPROPERTY(EditAnywhere, Category = Parameter)
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere, Category = Parameter)
	bool bWaitAndRemoveOnExit = false;
};

USTRUCT(meta = (DisplayName = "Remove Gameplay Tag", Category = "Common|GameplayTags"))
struct FStateTreeRemoveGameplayTagTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeRemoveGameplayTagInstanceData;

	STE_API FStateTreeRemoveGameplayTagTask();

	const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API EStateTreeRunStatus EnterState(
		FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;
	STE_API void ExitState(
		FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const override;

#if WITH_EDITOR
	STE_API FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup,
		EStateTreeNodeFormatting Formatting = EStateTreeNodeFormatting::Text) const override;
	FName GetIconName() const override
	{
		return FName("StateTreeEditorStyle|Node.Tag");
	}
	FColor GetIconColor() const override
	{
		return UE::StateTree::Colors::Grey;
	}
#endif	  // WITH_EDITOR
};