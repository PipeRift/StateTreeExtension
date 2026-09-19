// Copyright 2015-2026 Piperift. All Rights Reserved.
#pragma once

#include <StateTreeAnyEnum.h>
#include <StateTreePropertyFunctionBase.h>

#include "StateTreeEnumPropertyFunctions.generated.h"


USTRUCT()
struct FStateTreeEnumFlagPropertyFunctionInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Parameter, meta = (AllowAnyBinding))
	FStateTreeAnyEnum Left;

	UPROPERTY(EditAnywhere, Category = Parameter, meta = (AllowAnyBinding))
	FStateTreeAnyEnum Right;

	UPROPERTY(EditAnywhere, Category = Output)
	bool bOutput = false;
};

/**
 * Returns true if the left mask has any of the right flags set.
 */
USTRUCT(meta = (DisplayName = "Has Any", Category = "Enum"))
struct FStateTreeFlagHasAnyPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeEnumFlagPropertyFunctionInstanceData;

	virtual const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API virtual void Execute(FStateTreeExecutionContext& Context) const override;

#if WITH_EDITOR
	STE_API virtual EDataValidationResult Compile(UE::StateTree::ICompileNodeContext& CompileContext) override;

	STE_API virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const override;

	STE_API virtual void OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
		const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
		const IStateTreeBindingLookup& BindingLookup) override;
#endif
};

/**
 * Returns true if the left mask has all of the right flags set.
 */
USTRUCT(meta = (DisplayName = "Has All", Category = "Enum"))
struct FStateTreeFlagHasAllPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeEnumFlagPropertyFunctionInstanceData;

	virtual const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API virtual void Execute(FStateTreeExecutionContext& Context) const override;

#if WITH_EDITOR
	STE_API virtual EDataValidationResult Compile(UE::StateTree::ICompileNodeContext& CompileContext) override;

	STE_API virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const override;

	STE_API virtual void OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
		const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
		const IStateTreeBindingLookup& BindingLookup) override;
#endif
};

/**
 * Returns true if the left enum equals the right.
 */
USTRUCT(meta = (DisplayName = "Equals", Category = "Enum"))
struct FStateTreeEnumEqualsPropertyFunction : public FStateTreePropertyFunctionCommonBase
{
	GENERATED_BODY()

	using FInstanceDataType = FStateTreeEnumFlagPropertyFunctionInstanceData;

	virtual const UStruct* GetInstanceDataType() const override
	{
		return FInstanceDataType::StaticStruct();
	}

	STE_API virtual void Execute(FStateTreeExecutionContext& Context) const override;

#if WITH_EDITOR
	STE_API virtual EDataValidationResult Compile(UE::StateTree::ICompileNodeContext& CompileContext) override;

	STE_API virtual FText GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView,
		const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting) const override;

	STE_API virtual void OnBindingChanged(const FGuid& ID, FStateTreeDataView InstanceData,
		const FPropertyBindingPath& SourcePath, const FPropertyBindingPath& TargetPath,
		const IStateTreeBindingLookup& BindingLookup) override;
#endif
};