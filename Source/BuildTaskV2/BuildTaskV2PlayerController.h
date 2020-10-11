// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework\MovementComponent.h"
#include "BuildTaskV2PlayerController.generated.h"

UCLASS()
class ABuildTaskV2PlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABuildTaskV2PlayerController();
	/* FreakyFriends */
	UFUNCTION()
	void BuildingIsFinishedOrCanceled();
	/**/
protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;
	bool bBuildProcessRequested = false;
	bool bIsAlreadySpawning = false;
	bool bSpawnBuilding = false;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	/* FreakyFriends */
	void OnStartBuildProcessPressed();
	void OnStartBuildProcessReleased();
	UFUNCTION()
	void StartBuildProcess();
	UFUNCTION()
	void DisableControls();
	UFUNCTION()
	void HideBuilder(ABuildTaskV2Character* MyChar);
	UFUNCTION()
	void DisableCollisions(ABuildTaskV2Character* MyChar);

	UFUNCTION()
	void EnableCollisions(ABuildTaskV2Character* MyChar);
	UFUNCTION()
	void ShowBuilder(ABuildTaskV2Character* MyChar);
	UFUNCTION()
	void EnableControls();
	/**/
};


