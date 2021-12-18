// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include <set>

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	move = GetCharacterMovement();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
}

void AMyCharacter::MoveForward(float value)
{
	if ((Controller != nullptr) && (value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		//注意这里取z轴分量，防止向量分解导致的视角速度变换
		const FRotator YawRotation(0, Rotation.Yaw, 0);            

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AMyCharacter::MoveRight(float value)
{
	if ( (Controller != nullptr) && (value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, value);
	}
}

void AMyCharacter::ShiftRun(bool run)
{
	if((Controller != nullptr))
	{
		
		if(run)
		{
			move->MaxWalkSpeed = 600.0f;
		}
			
		else
			move->MaxWalkSpeed = 200.0f;
	}
}

void AMyCharacter::Turn(float value)
{
	if((Controller != nullptr))
	{
		AddControllerYawInput(value);
	}
}

void AMyCharacter::Lookup(float value)
{
	if((Controller != nullptr))
	{
		AddControllerPitchInput(value);
	}
}

void AMyCharacter::Startjump(bool Dojump)
{
	if((Controller != nullptr))
	{
		if(Dojump)
			Jump();
		else
			StopJumping();
	}
}

