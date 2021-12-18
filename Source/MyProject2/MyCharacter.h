// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT2_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	
	UCharacterMovementComponent* move;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UFUNCTION(BlueprintCallable,Category="Myfunc")
	void MoveRight(float value);

	UFUNCTION(BlueprintCallable,Category="Myfunc")
	void MoveForward(float value);

	UFUNCTION(BlueprintCallable,Category="Myfunc")
    void ShiftRun(bool run);

	UFUNCTION(BlueprintCallable,Category="Myfunc")
	void Turn(float value);

	UFUNCTION(BlueprintCallable,Category="Myfunc")
	void Lookup(float value);

	UFUNCTION(BlueprintCallable,Category="Myfunc")
	void Startjump(bool Dojump);
	

};
