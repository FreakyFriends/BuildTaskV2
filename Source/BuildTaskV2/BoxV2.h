// Fill out your copyright notice in the Description page of Project Settings.
/* FreakyFriends */
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components\BoxComponent.h"
#include "BuildTaskV2Character.h"
// #include "BuildTaskV2PlayerController.h"
#include "BoxV2.generated.h"

UCLASS()
class BUILDTASKV2_API ABoxV2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxV2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    UStaticMeshComponent *PickUpMesh;    

    UPROPERTY(EditAnywhere)
    USceneComponent* PickUpRoot;

    UPROPERTY(EditAnywhere)
    UShapeComponent* PickUpBox;

	UStaticMesh* Asset;

    UFUNCTION()
    void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	FTimerHandle TimerHandle;

	bool bImAlreadyBuilt = false;

	class ABuildTaskV2Character* Builder = nullptr;
	void AssignBuilder(ABuildTaskV2Character* Builder);

	void StartBuildProcess();
	void DisableControls();
	void HideBuilder();
	void DisableCollisions();

	void BuildingIsFinishedOrCanceled();
	void EnableCollisions();
	void ShowBuilder();
	void EnableControls();
};
/**/