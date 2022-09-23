// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CozyFallGameJam2022 : ModuleRules
{
	public CozyFallGameJam2022(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
