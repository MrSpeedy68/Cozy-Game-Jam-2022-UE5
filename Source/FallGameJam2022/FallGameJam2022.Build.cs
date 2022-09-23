// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FallGameJam2022 : ModuleRules
{
	public FallGameJam2022(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
