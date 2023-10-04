  // Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasicCharacter.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "MyTestCharacter.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)

struct FCharacterInfo : public FTableRowBase {
	GENERATED_BODY()

public:
	FCharacterInfo() {
		CharacterName = FText::FromString("Name");
		CharacterLevel = 1;
		Description = FText::FromString("Your Character is ...");
	}
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CharacterID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* CharacterThumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CharacterLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;
};

UCLASS()
class MYTESTPROJECT_API AMyTestCharacter : public ABasicCharacter
{
	GENERATED_BODY()
	
public:
	AMyTestCharacter(); //생성자 선언

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera) //매크로 설정
	class USpringArmComponent* CameraBoom; //카메라 지지대

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera; //카메라 

protected:
	//MyTestCharacter.cpp에 함수를 정의해두어야지 여기 선언해둔게 오류가 안난다.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override; 
	void MoveForward(float value);
	void MoveRight(float value);
};