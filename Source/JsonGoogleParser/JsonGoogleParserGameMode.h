// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "JsonGoogleParserGameMode.generated.h"

UCLASS(minimalapi)
class AJsonGoogleParserGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AJsonGoogleParserGameMode();

	UFUNCTION(BlueprintCallable,Category=Save)
	void GameSave();


	UFUNCTION(BlueprintCallable, Category = Save)
		void GameLoad();
};



