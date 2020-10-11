// Copyright Epic Games, Inc. All Rights Reserved.

#include "BuildTaskV2GameMode.h"
#include "BuildTaskV2PlayerController.h"
#include "BuildTaskV2Character.h"
#include "UObject/ConstructorHelpers.h"

ABuildTaskV2GameMode::ABuildTaskV2GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABuildTaskV2PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}