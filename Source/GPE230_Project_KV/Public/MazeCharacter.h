// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MazeCharacter.generated.h"


class UMappingContext;
class UInputAction;
//class UInputMappingContext* MappingContext;
//class UInputAction* JumpAction;
//class UInputAction* MoveAction;
//class UInputAction* LookAction;


UCLASS()
class GPE230_PROJECT_KV_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMazeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



protected:

	//Enchanced Input//

	//Mapping Contect //meta = (AllowPrivateAccess = "true")
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputMappingContext* MappingContext;

	// Jump
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* JumpAction;

	//Move
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* MoveAction;

	//Look
	UPROPERTY(EditAnywhere, Category = "EnhancedInput")
	class UInputAction* LookAction;

	//

	//move method
	void MoveActionInput(const FInputActionValue& value);

	//jump method
	void JumpActionInput();

	//look method
	void LookActionInput(const FInputActionValue& value);

};
