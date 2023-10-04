// Copyright Epic Games, Inc. All Rights Reserved.
// �ڵ����� ��������� �����̴�. ���� ��ü�� �����ϴ� ����

#include "MyTestProjectGameModeBase.h"
#include "Blueprint/UserWidget.h"

void AMyTestProjectGameModeBase::BeginPlay() {
	Super::BeginPlay();

	CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidget); //��ü ȭ�鿡 �ִ� ���� ������ CurrentWidget�� �־��ش�.
	CurrentWidget->AddToViewport(); // �������ϸ� ������ �߻��ϹǷ� MyTestProject.Build.cs�� ���� �������־���Ѵ�.
}

