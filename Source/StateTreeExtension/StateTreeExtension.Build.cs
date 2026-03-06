// Copyright 2015-2026 Piperift. All Rights Reserved.

using UnrealBuildTool;

public class StateTreeExtension : ModuleRules
{
	public StateTreeExtension(ReadOnlyTargetRules TargetRules) : base(TargetRules)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayTags",
			"StateTreeModule"
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"PropertyBindingUtils"
		});

		PublicDefinitions.Add("STE_API=STATETREEEXTENSION_API");
	}
}
