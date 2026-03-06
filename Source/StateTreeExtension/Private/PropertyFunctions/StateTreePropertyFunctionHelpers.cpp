// Copyright 2015-2026 Piperift. All Rights Reserved.

#include "PropertyFunctions/StateTreePropertyFunctionHelpers.h"


#define LOCTEXT_NAMESPACE "StateTreePropertyFunctionHelpers"

namespace UE::StateTree::DescHelpers
{
	FText GetTwoParamsFunctionText(const FText& FunctionText, const FText& LeftParamText,
		const FText& RightParamText, EStateTreeNodeFormatting Formatting)
	{
		const FText Format = (Formatting == EStateTreeNodeFormatting::RichText)
								 ? LOCTEXT("TwoParamsFuncRich", "<s>{Function}</>({Left}, {Right})")
								 : LOCTEXT("TwoParamsFunc", "{Function}({Left}, {Right})");

		return FText::FormatNamed(Format, TEXT("Function"), FunctionText, TEXT("Left"), LeftParamText,
			TEXT("Right"), RightParamText);
	}
}	 // namespace UE::StateTree::DescHelpers

#undef LOCTEXT_NAMESPACE