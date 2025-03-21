// Boss AI - 신설빈


#include "AI/ShockWaveManager.h"
#include "ShockWavePoint.h"

// Sets default values
AShockWaveManager::AShockWaveManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AShockWaveManager::BeginPlay()
{
	Super::BeginPlay();

	FVector SpawnLoc = GetActorLocation();
	FRotator SpawnRot = GetActorRotation();
	SpawnLoc.Z -= 9999;
	
	FActorSpawnParameters Param;
	Param.Owner = this;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	for (int i = 0; i < SpawnCount; i++)
	{
		SpawnRot.Yaw = i;
		AShockWavePoint* WavePoint = GetWorld()->SpawnActor<AShockWavePoint>(ShockWavePointFactory, SpawnLoc, SpawnRot, Param);
		WavePoints.Add(WavePoint);
	}
	ConnectCablePointToPoint();
}

void AShockWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShockWaveManager::SetNewLocation(const FVector InNewLoc)
{
	FRotator SpawnRot = GetActorRotation();
	FTransform NewTransform;
	FQuat MyQuat;
	NewTransform.SetLocation(InNewLoc);
	for (int i = 0; i < WavePoints.Num(); i++)
	{
		SpawnRot.Yaw = i;
		MyQuat = SpawnRot.Quaternion();
		NewTransform.SetRotation(MyQuat);
		WavePoints[i]->SetActorTransform(NewTransform);
	}
}

