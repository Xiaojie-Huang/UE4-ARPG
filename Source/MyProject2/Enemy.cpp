// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include <NvParamUtils.h>

#include "Runtime/Engine/Classes/Engine/World.h"
#include "Materials/MaterialInstance.h"
#include "GameFramework/PlayerController.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	//修改敌人材质，使敌人呈现红色用来区分
	UMaterialInstanceDynamic* const material_instance = UMaterialInstanceDynamic::Create(GetMesh()->GetMaterial(0),this);
	if(material_instance)
	{
		material_instance->SetVectorParameterValue("BodyColor",FLinearColor(1.0,0,0,1.0));
		GetMesh()->SetMaterial(0,material_instance);
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UBlackboardComponent* AEnemy::get_blackvord() const
{
	return blackboard;
}

