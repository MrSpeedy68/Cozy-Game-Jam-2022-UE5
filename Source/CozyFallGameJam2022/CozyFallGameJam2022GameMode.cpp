// Copyright Epic Games, Inc. All Rights Reserved.

#include "CozyFallGameJam2022GameMode.h"
#include "CozyFallGameJam2022Character.h"
#include "UObject/ConstructorHelpers.h"

ACozyFallGameJam2022GameMode::ACozyFallGameJam2022GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
