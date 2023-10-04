// Copyright Epic Games, Inc. All Rights Reserved.
// 자동으로 만들어지는 파일이다. 게임 전체를 관할하는 파일

#include "MyTestProjectGameModeBase.h"
#include "Blueprint/UserWidget.h"

void AMyTestProjectGameModeBase::BeginPlay() {
	Super::BeginPlay();

	CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidget); //전체 화면에 있는 것을 가져와 CurrentWidget에 넣어준다.
	CurrentWidget->AddToViewport(); // 컴파일하면 오류가 발생하므로 MyTestProject.Build.cs로 가서 수정해주어야한다.
}

