// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/DefaultPawn.h"    
#include "GameFramework/PlayerController.h"    
#include "GameFramework/Character.h" 
#include "GameFramework/CharacterMovementComponent.h"

AMyTestCharacter::AMyTestCharacter() {
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent); //루트 컴포넌트(정중앙)에 붙여줌
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	//회전 처리
	GetCharacterMovement()->bOrientRotationToMovement = true; //"GameFramework/CharacterMovementComponent.h"필요

}

void AMyTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent); //플레이어 인풋 컴포넌트가 있는지 확인
	// "GameFramework/DefaultPawn.h"  헤더파일이 필요한 명령어이므로 include
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyTestCharacter::MoveForward); 
	//MoveForward 함수를 불러올 수 있도록 묶어준다.(뭐라는지모르겟음)
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyTestCharacter::MoveRight);

	//action에 attack을 바인딩 해준다. Attack_Mele라는 함수를 따로 만들어주어야 함.
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AMyTestCharacter::Attack_Melee); 
	//MyTestCharacter는 BasicCharacter를 상속받는다. 


}

void AMyTestCharacter::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && isDuringAttack == false) { //공격하는 동안은 움직이지 않는다. 
		const FRotator Rot = Controller->GetControlRotation(); //"GameFramework/PlayerController.h" 필요
		const FRotator YawRot(0, Rot.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AMyTestCharacter::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && isDuringAttack == false) {
		const FRotator Rot = Controller->GetControlRotation();
		const FRotator YawRot(0, Rot.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, value);
	}
}
