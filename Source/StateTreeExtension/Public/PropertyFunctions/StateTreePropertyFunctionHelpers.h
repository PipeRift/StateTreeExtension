// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <GameplayTagContainer.h>
#include <StateTreeNodeDescriptionHelpers.h>
#include <StateTreePropertyFunctionBase.h>
#include <StateTreePropertyRef.h>


namespace UE::StateTree::DescHelpers
{
	FText GetTwoParamsFunctionText(const FText& FunctionText, const FText& LeftParamText,
		const FText& RightParamText, EStateTreeNodeFormatting Formatting);

#if WITH_EDITOR
	/** @return description in the form of OperationText(Left, Right).
	 *	Expect TInstanceDataType to have a member Left and Right whose types have an overloaded
	 *UE::StateTree::DescHelpers::GetText function.
	 */
	template <typename TInstanceDataType>
	FText GetDescriptionForTwoParametersFunc(FText OperationText, const FGuid& ID,
		FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup,
		EStateTreeNodeFormatting Formatting)
	{
		const TInstanceDataType& InstanceData = InstanceDataView.Get<TInstanceDataType>();

		FText LeftValue = BindingLookup.GetBindingSourceDisplayName(
			FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(TInstanceDataType, Left)), Formatting);
		if (LeftValue.IsEmpty())
		{
			LeftValue = UE::StateTree::DescHelpers::GetText(InstanceData.Left, Formatting);
		}

		FText RightValue = BindingLookup.GetBindingSourceDisplayName(
			FPropertyBindingPath(ID, GET_MEMBER_NAME_CHECKED(TInstanceDataType, Right)), Formatting);
		if (RightValue.IsEmpty())
		{
			RightValue = UE::StateTree::DescHelpers::GetText(InstanceData.Right, Formatting);
		}

		return GetTwoParamsFunctionText(OperationText, LeftValue, RightValue, Formatting);
	}
#endif	  // WITH_EDITOR
}	 // namespace UE::StateTree::DescHelpers
