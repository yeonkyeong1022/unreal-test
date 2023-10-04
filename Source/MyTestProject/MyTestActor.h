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

	// �浹ü �����
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class USphereComponent* CollisionSphere;     //�浹ü �ø��� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* mStaticMesh;           // ����� ���̰� �޽��� static���� ����

	UPROPERTY(EditDefaultsOnly, Category = "MyItem") // ��ƼŬ�� �����Ѵ�
		UParticleSystem* ParticleFX;

	UFUNCTION()  //�ø����� �޽��� ��ĥ? ��? ���� �Լ�
		void OnOverlapBegin(UPrimitiveComponent* OverlappedCopm, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
