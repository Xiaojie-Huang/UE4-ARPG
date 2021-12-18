// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Enemy.generated.h"

UCLASS()
class MYPROJECT2_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	class UBlackboardComponent* get_blackvord() const;

private:
	UPROPERTY(EditInstanceOnly,BlueprintReadWrite,Category="AI",meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* behavior_tree_component;

	UPROPERTY(EditInstanceOnly,BlueprintReadWrite,Category="AI",meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* behavior_treet;

	class UBlackboardComponent* blackboard;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
