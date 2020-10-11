// Fill out your copyright notice in the Description page of Project Settings.
/* FreakyFriends */

#include "BoxV2.h"

// Sets default values
ABoxV2::ABoxV2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    PickUpRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickUpRoot"));
    RootComponent = PickUpRoot;

    PickUpMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("PickUpMesh") );
    PickUpMesh->AttachToComponent(PickUpRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

    PickUpBox = CreateDefaultSubobject<UBoxComponent>( TEXT("PickUpBox") );
	PickUpBox->SetWorldScale3D(FVector(8.5f, 8.5f, 8.5f));
    PickUpBox->SetGenerateOverlapEvents(true);
    PickUpBox->OnComponentBeginOverlap.AddDynamic(this, &ABoxV2::OnBoxOverlap);
    PickUpBox->AttachToComponent(PickUpRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

    // SetActorEnableCollision(false);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/Geometry/Meshes/1M_Cube"));
	Asset = MeshAsset.Object;
    if(Asset)
        PickUpMesh->SetStaticMesh(Asset);
	PickUpMesh->SetWorldScale3D(FVector(5.0f, 5.0f, 5.0f));
 	PickUpMesh->SetRelativeScale3D(FVector(5.0f, 5.0f, 5.0f));
}

// Called when the game starts or when spawned
void ABoxV2::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABoxV2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABoxV2::OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	ABuildTaskV2Character* Char = Cast<ABuildTaskV2Character>(OtherActor);
	if( (Char != nullptr) && (!bImAlreadyBuilt) )
	{
		UE_LOG(LogTemp, Warning, TEXT("IM IN OVERLAP") );	
		OverlapDelegate.Broadcast();
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ABoxV2::BuildingFinished, 5.0f, false);
		bImAlreadyBuilt = true;
	}
}

void ABoxV2::BuildingFinished() 
{
	UE_LOG(LogTemp, Warning, TEXT("I FINISHED BUILDING") );	
	MyDelegate.Broadcast();
}
/**/