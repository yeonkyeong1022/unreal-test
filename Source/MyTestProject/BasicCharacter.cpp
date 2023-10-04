// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicCharacter.h"

// Sets default values
ABasicCharacter::ABasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasicCharacter::Attack_Melee() {

	int tmp_Num= rand() % 3 + 1;

	FString PlaySection = "Attack_" + FString::FromInt(tmp_Num);

	PlayAnimMontage(AttackCombo_AnimMt, 1.f, FName(*PlaySection));
	
	ComboAttack_Num++;

	isDuringAttack = true;

	//switch (ComboAttack_Num) {  //공격키를 누르면 순차적으로 공격모션이 출력된다.
	//case 0:
	//	PlayAnimMontage(Attack_Melee_Anim01, 1.0f);  // 애니 동작 출력
	//	isDuringAttack = true; // 이 변수가 true 상태 일 땐 공격할 수 있다.
	//	ComboAttack_Num++;
	//	break;

	//case 1:
	//	PlayAnimMontage(Attack_Melee_Anim02, 1.0f);  // 애니 동작 출력
	//	isDuringAttack = true; // 이 변수가 true 상태 일 땐 공격할 수 있다.
	//	ComboAttack_Num++;
	//	break;
	//
	//case 2:
	//	PlayAnimMontage(Attack_Melee_Anim03, 1.0f);  // 애니 동작 출력
	//	isDuringAttack = true; // 이 변수가 true 상태 일 땐 공격할 수 있다.
	//	ComboAttack_Num++;
	//	break;
	//default:
	//	ComboAttack_Num = 0;
	//}

	FTimerHandle TH_Attack_End;
	GetWorldTimerManager().SetTimer(TH_Attack_End, this, &ABasicCharacter::Attack_Melee_End, 1.7f, false);

	//이 함수가 끝나면 1.7f 초 후에 Attack_Melee_End 함수를 호출한다.
}


void ABasicCharacter::Attack_Melee_End() {
	isDuringAttack = false;

}

