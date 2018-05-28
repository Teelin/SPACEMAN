// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SPACEMANGameMode.h"
#include "SPACEMANHUD.h"
#include "SPACEMANCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASPACEMANGameMode::ASPACEMANGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASPACEMANHUD::StaticClass();
}
