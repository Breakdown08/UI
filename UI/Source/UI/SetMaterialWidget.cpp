// Fill out your copyright notice in the Description page of Project Settings.


#include "SetMaterialWidget.h"

#include "GamePlayerController.h"
#include "Kismet/GameplayStatics.h"

void USetMaterialWidget::NativeConstruct()
{
	Super::NativeConstruct();
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AGamePlayerController * PC = Cast<AGamePlayerController>(PlayerController);
	PC->OnMouseButtonUp.AddUObject(this, &USetMaterialWidget::OnMouseButtonUp);
}

FReply USetMaterialWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry,
const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		//DraggedActor = GetWorld()->SpawnActor<AActor>(DraggedActorClass);
	}
	return FReply::Handled();
}
void USetMaterialWidget::OnMouseButtonUp()
{
	if (DraggedActor)
	{
		DraggedActor = nullptr;
	}
}

void USetMaterialWidget::SetMaterial()
{
	UE_LOG(LogTemp, Warning, TEXT("Устанавливаем материал"));
}

void USetMaterialWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (DraggedActor && PlayerController)
	{
		FVector WorldMouseLocation;
		FVector WorldMouseDirection;
		PlayerController->DeprojectMousePositionToWorld(
		WorldMouseLocation, WorldMouseDirection);
		FHitResult HitResult;
		float TraseDistance = 1000000.f;
		GetWorld()->LineTraceSingleByChannel(
		HitResult,
		WorldMouseLocation,
		WorldMouseLocation + WorldMouseDirection * TraseDistance,
		ECollisionChannel::ECC_WorldStatic);
		if (HitResult.GetActor())
		{
			//DraggedActor->SetActorLocation(HitResult.Location);
			SetMaterial();
		}
	}
}
