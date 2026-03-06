// Copyright 2015-2026 Piperift. All Rights Reserved.

using UnrealBuildTool;

public class StateTreeExtensionEditor : ModuleRules
{
	public StateTreeExtensionEditor(ReadOnlyTargetRules TargetRules) : base(TargetRules)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
		});

		PrivateDependencyModuleNames.AddRange(new string[] {
			"Core",
			"UnrealEd",
			"StateTreeExtension"
		});
	}
}
