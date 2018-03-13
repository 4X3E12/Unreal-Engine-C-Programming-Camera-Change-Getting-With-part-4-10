// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CamerChange.generated.h"

UCLASS()
class CPLUSTHIREDBOOKNEW_API ACamerChange : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACamerChange();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

 UPROPERTY (EditAnywhere)	
  AActor* OneCamer;
	
 UPROPERTY (EditAnywhere)	
  AActor* CamerTwo;

  float NextTimeCamerChange;	
};
