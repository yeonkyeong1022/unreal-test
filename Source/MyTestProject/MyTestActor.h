// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTestActor.generated.h"


UCLASS()
class MYTESTPROJECT_API AMyTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 충돌체 만들기
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* CollisionSphere;     //충돌체 컬리젼 생성

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* mStaticMesh;           // 모양이 보이게 메쉬를 static으로 생성

	UPROPERTY(EditDefaultsOnly, Category = "MyItem") // 파티클을 생성한다
		UParticleSystem* ParticleFX;

	UFUNCTION()  //컬리젼과 메쉬를 겹칠? 때? 쓰는 함수
		void OnOverlapBegin(UPrimitiveComponent* OverlappedCopm, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
