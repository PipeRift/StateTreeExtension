// Copyright 2015-2026 Piperift. All Rights Reserved.

#include "Tasks/GameplayTagTasks.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(GameplayTagTasks)

#define LOCTEXT_NAMESPACE "GameplayTagTasks"

FStateTreeAddGameplayTagTask::FStateTreeAddGameplayTagTask()
{
	bShouldCallTick = false;
	bShouldCopyBoundPropertiesOnTick = false;
	bShouldCopyBoundPropertiesOnExitState = false;
#if WITH_EDITORONLY_DATA
	bConsideredForCompletion = false;
#endif
}

EStateTreeRunStatus FStateTreeAddGameplayTagTask::EnterState(
	FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	if (InstanceData.bWaitAndAddOnExit)
	{
		return EStateTreeRunStatus::Running;
	}

	auto* Container = InstanceData.Container.GetMutablePtr<FGameplayTagContainer>(Context);
	if (Container && !Container->HasTag(InstanceData.Tag))
	{
		Container->AddTag(InstanceData.Tag);
		return EStateTreeRunStatus::Succeeded;
	}
	return EStateTreeRunStatus::Failed;
}

void FStateTreeAddGameplayTagTask::ExitState(
	FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (InstanceData.bWaitAndAddOnExit)
	{
		auto* Container = InstanceData.Container.GetMutablePtr<FGameplayTagContainer>(Context);
		if (Container)
		{
			Container->AddTag(InstanceData.Tag);
		}
	}
}

#if WITH_EDITOR
FText FStateTreeAddGameplayTagTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FInstanceDataType>();
	check(InstanceData);

	FText TagName = FText::FromString(InstanceData->Tag.ToString());

	if (Formatting == EStateTreeNodeFormatting::RichText)
	{
		return FText::Format(LOCTEXT("AddGameplayTagRT", "<b>Add Tag</> '{0}'"), TagName);
	}
	return FText::Format(LOCTEXT("AddGameplayTag", "Add Tag '{0}'"), TagName);
}
#endif	  // WITH_EDITOR


FStateTreeRemoveGameplayTagTask::FStateTreeRemoveGameplayTagTask()
{
	bShouldCallTick = false;
	bShouldCopyBoundPropertiesOnTick = false;
	bShouldCopyBoundPropertiesOnExitState = false;
#if WITH_EDITORONLY_DATA
	bConsideredForCompletion = false;
#endif
}

EStateTreeRunStatus FStateTreeRemoveGameplayTagTask::EnterState(
	FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);

	if (InstanceData.bWaitAndRemoveOnExit)
	{
		return EStateTreeRunStatus::Running;
	}

	auto* Container = InstanceData.Container.GetMutablePtr<FGameplayTagContainer>(Context);
	if (Container && Container->RemoveTag(InstanceData.Tag))
	{
		return EStateTreeRunStatus::Succeeded;
	}
	return EStateTreeRunStatus::Failed;
}

void FStateTreeRemoveGameplayTagTask::ExitState(
	FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition) const
{
	FInstanceDataType& InstanceData = Context.GetInstanceData(*this);
	if (InstanceData.bWaitAndRemoveOnExit)
	{
		auto* Container = InstanceData.Container.GetMutablePtr<FGameplayTagContainer>(Context);
		if (Container)
		{
			Container->RemoveTag(InstanceData.Tag);
		}
	}
}

#if WITH_EDITOR
FText FStateTreeRemoveGameplayTagTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
	const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const
{
	const FInstanceDataType* InstanceData = InstanceDataView.GetPtr<FInstanceDataType>();
	check(InstanceData);

	FText TagName = FText::FromString(InstanceData->Tag.ToString());

	if (Formatting == EStateTreeNodeFormatting::RichText)
	{
		return FText::Format(LOCTEXT("RemoveGameplayTagRT", "<b>Remove Tag</> '{0}'"), TagName);
	}
	return FText::Format(LOCTEXT("RemoveGameplayTag", "Remove Tag '{0}'"), TagName);
}
#endif	  // WITH_EDITOR

#undef LOCTEXT_NAMESPACE