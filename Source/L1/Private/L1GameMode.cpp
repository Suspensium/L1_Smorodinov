// Copyright Epic Games, Inc. All Rights Reserved.

#include "L1GameMode.h"
#include "L1Character.h"
#include "UObject/ConstructorHelpers.h"

AL1GameMode::AL1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
