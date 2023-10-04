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
	AMyTestCharacter(); //������ ����

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera) //��ũ�� ����
	class USpringArmComponent* CameraBoom; //ī�޶� ������

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* FollowCamera; //ī�޶� 

protected:
	//MyTestCharacter.cpp�� �Լ��� �����صξ���� ���� �����صа� ������ �ȳ���.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override; 
	void MoveForward(float value);
	void MoveRight(float value);
};