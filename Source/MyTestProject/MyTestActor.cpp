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
	RootComponent = mStaticMesh; // 메쉬와 컬리젼이 서로 붙도록

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->InitSphereRadius(100.0f);
	CollisionSphere->SetupAttachment(RootComponent); //root 컴포넌트에 부착
	
	//MyTestActor.h 에 OnOverlapBegin 함수를 미리 만들어 둔다.
	//그 상황이 되었을 때 OnOverlapBegint 함수가 자동 발생하게끔
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AMyTestActor::OnOverlapBegin);

	//위와 같은 식의 비슷한 패턴이 자주 사용되므로 유심히 봐두는 것이 좋다.

	//"Kismet/GameplayStatics.h"
	// particle 파일 우클릭-> copy reference 클릭하여 붙여넣기
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

// 다른 액터가 구체 컴포넌트에 들어설 때 호출되는 함수. OnTriggerEnter와 비슷한 함수인가?
void AMyTestActor::OnOverlapBegin(UPrimitiveComponent* OverlappedCopm, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	//OtherActor가 AMyTestCharacter 인지 확인한다
	// AActor* OtherActor : 컴포넌트에 닿은 다른 액터

	if (OtherActor->IsA(AMyTestCharacter::StaticClass())) {
		// AMyTestCharacter::StaticClass : 컴파일 시점에서 UClass 타입의 정보를 얻어온다.
		// 부딪힌 다른 액터의 UClass 타입이 우리가 만든 MyTestCharacter 클래스라면 true 반환

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Collision Touch!!"));

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleFX, GetActorLocation());
		// 1: 생성할 world, 2: 생성할 파티클 시스템, 3: 생성할 위치(transform)

		Destroy();
	}
	// 다른 MyTestActor와 부딪혔을 때, 폭발 파티클 효과가 생성되며 부딪힌 대상이 사라진다.
}

