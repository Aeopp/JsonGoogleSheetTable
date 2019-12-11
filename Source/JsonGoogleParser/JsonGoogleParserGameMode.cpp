// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "JsonGoogleParserGameMode.h"
#include "JsonGoogleParserHUD.h"
#include "JsonGoogleParserCharacter.h"l
#include "UObject/ConstructorHelpers.h"

AJsonGoogleParserGameMode::AJsonGoogleParserGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnCassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AJsonGoogleParserHUD::StaticClass();
}

void AJsonGoogleParserGameMode::GameSave()
{
	auto* SaveGameInstance =
	Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject
	(UMySaveGame::StaticClass()));

	if (SaveGameInstance)
	{
		SaveGameInstance->SaveSlotName = "MySaveGame";
		SaveGameInstance->SaveIndex = 0;

		SaveGameInstance->SaveName = "Player0";

		SaveGameInstance->SaveFloat = 11.11f;

		SaveGameInstance->SaveTArray.Add(1);
		SaveGameInstance->SaveTArray.Add(3);
		SaveGameInstance->SaveTArray.Add(6);

		SaveGameInstance->SaveTransform = FTransform(FVector(10, 11, 12));

		SaveGameInstance->SaveStruct.StructInteger = 15;


	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("SaveGameInstance is nullptr"));
	}

	UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->SaveIndex);

}

void AJsonGoogleParserGameMode::GameLoad()
{
	auto* LoadGameInstance =
		Cast<UMySaveGame>
		(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	if (LoadGameInstance)
	{
		LoadGameInstance->SaveSlotName = "MySaveGame";
		LoadGameInstance->SaveIndex = 0;

		LoadGameInstance =
			Cast<UMySaveGame>(UGameplayStatics::
				LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->SaveIndex));


			UE_LOG(LogTemp, Warning, TEXT("SaveName : %s"), *LoadGameInstance->SaveName.ToString());
			UE_LOG(LogTemp, Warning, TEXT("SaveFloat : %f"), LoadGameInstance->SaveFloat);
			UE_LOG(LogTemp, Warning, TEXT("SaveTArray : [%d, %d, %d]"), LoadGameInstance->SaveTArray[0], LoadGameInstance->SaveTArray[1], LoadGameInstance->SaveTArray[2]);
			UE_LOG(LogTemp, Warning, TEXT("SaveTransform : %s"), *LoadGameInstance->SaveTransform.ToString());
			UE_LOG(LogTemp, Warning, TEXT("SaveStruct : %d"), LoadGameInstance->SaveStruct.StructInteger);
	}
}
