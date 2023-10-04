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
	CameraBoom->SetupAttachment(RootComponent); //��Ʈ ������Ʈ(���߾�)�� �ٿ���
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	//ȸ�� ó��
	GetCharacterMovement()->bOrientRotationToMovement = true; //"GameFramework/CharacterMovementComponent.h"�ʿ�

}

void AMyTestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent); //�÷��̾� ��ǲ ������Ʈ�� �ִ��� Ȯ��
	// "GameFramework/DefaultPawn.h"  ��������� �ʿ��� ��ɾ��̹Ƿ� include
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyTestCharacter::MoveForward); 
	//MoveForward �Լ��� �ҷ��� �� �ֵ��� �����ش�.(��������𸣰���)
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyTestCharacter::MoveRight);

	//action�� attack�� ���ε� ���ش�. Attack_Mele��� �Լ��� ���� ������־�� ��.
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AMyTestCharacter::Attack_Melee); 
	//MyTestCharacter�� BasicCharacter�� ��ӹ޴´�. 


}

void AMyTestCharacter::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && isDuringAttack == false) { //�����ϴ� ������ �������� �ʴ´�. 
		const FRotator Rot = Controller->GetControlRotation(); //"GameFramework/PlayerController.h" �ʿ�
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
