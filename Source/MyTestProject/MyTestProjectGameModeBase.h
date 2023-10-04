// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyTestProjectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYTESTPROJECT_API AMyTestProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay()override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	UUserWidget* CurrentWidget; //현재 가지고 있는 위젯


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	TSubclassOf<UUserWidget> HUDWidget; // UserWidget만 나올수 있게끔 타입을 제한한다.
	
};
