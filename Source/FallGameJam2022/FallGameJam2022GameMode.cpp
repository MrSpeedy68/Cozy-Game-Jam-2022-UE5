// Copyright Epic Games, Inc. All Rights Reserved.

#include "FallGameJam2022GameMode.h"
#include "FallGameJam2022Character.h"
#include "UObject/ConstructorHelpers.h"

AFallGameJam2022GameMode::AFallGameJam2022GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
