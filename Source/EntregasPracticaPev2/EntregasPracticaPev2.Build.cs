// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EntregasPracticaPev2 : ModuleRules
{
	public EntregasPracticaPev2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"EntregasPracticaPev2",
			"EntregasPracticaPev2/Variant_Platforming",
			"EntregasPracticaPev2/Variant_Platforming/Animation",
			"EntregasPracticaPev2/Variant_Combat",
			"EntregasPracticaPev2/Variant_Combat/AI",
			"EntregasPracticaPev2/Variant_Combat/Animation",
			"EntregasPracticaPev2/Variant_Combat/Gameplay",
			"EntregasPracticaPev2/Variant_Combat/Interfaces",
			"EntregasPracticaPev2/Variant_Combat/UI",
			"EntregasPracticaPev2/Variant_SideScrolling",
			"EntregasPracticaPev2/Variant_SideScrolling/AI",
			"EntregasPracticaPev2/Variant_SideScrolling/Gameplay",
			"EntregasPracticaPev2/Variant_SideScrolling/Interfaces",
			"EntregasPracticaPev2/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
