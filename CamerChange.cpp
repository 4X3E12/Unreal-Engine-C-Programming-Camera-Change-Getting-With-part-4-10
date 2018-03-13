// Fill out your copyright notice in the Description page of Project Settings.

#include "CamerChange.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ACamerChange::ACamerChange()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACamerChange::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACamerChange::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	const float TimeBetweenCarmerchange = 2.0f;
	const float SmoothBlenTime			= 0.76f;
				NextTimeCamerChange -= DeltaTime;
	
	if (NextTimeCamerChange <= 0.0f)
	{
		NextTimeCamerChange += TimeBetweenCarmerchange;
		APlayerController * OurPlayerController = UGameplayStatics::GetPlayerController(this,0);
		if( OurPlayerController ){
			if( (OurPlayerController->GetViewTarget() != OneCamer ) && (OneCamer != nullptr) ){

			OurPlayerController->SetViewTarget(OneCamer);
			}
			else if ((OurPlayerController->GetViewTarget() != CamerTwo ) && (CamerTwo != nullptr))
				{
				OurPlayerController->SetViewTargetWithBlend(CamerTwo , SmoothBlenTime);
			}

		}
		
	}


}

