// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	//The distance that player can reach
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	//Ray-cast and Grab Action
	void Grab();

	//Call When Grab is released
	void Release();

	//Find Attached Physics Handle
	void FindPhysicsHandleComponent();

	//Find Attached Input Component
	void SetupInputComponent();

	//return hit for first actor in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	//return current start of reach line
	FVector GetReachLineStart();

	//return current end of reach line
	FVector GetReachLineEnd();
};
