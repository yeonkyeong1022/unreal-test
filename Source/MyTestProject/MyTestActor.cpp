// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "BasicCharacter.h"
#include "Engine.h"
#include "Components/PrimitiveComponent.h"
#include "MyTestCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "particles/ParticleSystemComponent.h"

// Sets default values
AMyTestActor::AMyTestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("obj"));
	RootComponent = mStaticMesh; // �޽��� �ø����� ���� �ٵ���

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->InitSphereRadius(100.0f);
	CollisionSphere->SetupAttachment(RootComponent); //root ������Ʈ�� ����
	
	//MyTestActor.h �� OnOverlapBegin �Լ��� �̸� ����� �д�.
	//�� ��Ȳ�� �Ǿ��� �� OnOverlapBegint �Լ��� �ڵ� �߻��ϰԲ�
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AMyTestActor::OnOverlapBegin);

	//���� ���� ���� ����� ������ ���� ���ǹǷ� ������ ���δ� ���� ����.

	//"Kismet/GameplayStatics.h"
	// particle ���� ��Ŭ��-> copy reference Ŭ���Ͽ� �ٿ��ֱ�
	static ConstructorHelpers::FObjectFinder<UParticleSystem>ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
	ParticleFX = ParticleAsset.Object;
}
 
// Called when the game starts or when spawned
void AMyTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// �ٸ� ���Ͱ� ��ü ������Ʈ�� �� �� ȣ��Ǵ� �Լ�. OnTriggerEnter�� ����� �Լ��ΰ�?
void AMyTestActor::OnOverlapBegin(UPrimitiveComponent* OverlappedCopm, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	//OtherActor�� AMyTestCharacter ���� Ȯ���Ѵ�
	// AActor* OtherActor : ������Ʈ�� ���� �ٸ� ����

	if (OtherActor->IsA(AMyTestCharacter::StaticClass())) {
		// AMyTestCharacter::StaticClass : ������ �������� UClass Ÿ���� ������ ���´�.
		// �ε��� �ٸ� ������ UClass Ÿ���� �츮�� ���� MyTestCharacter Ŭ������� true ��ȯ

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Touch!!"));

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleFX, GetActorLocation());
		// 1: ������ world, 2: ������ ��ƼŬ �ý���, 3: ������ ��ġ(transform)

		Destroy();
	}
	// �ٸ� MyTestActor�� �ε����� ��, ���� ��ƼŬ ȿ���� �����Ǹ� �ε��� ����� �������.
}

