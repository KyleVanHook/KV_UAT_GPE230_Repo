// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();

	//add input mapping context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		//get local player subsystems
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}

	}

	
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//bind input action
		Input->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMazeCharacter::MoveActionInput);
		Input->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AMazeCharacter::JumpActionInput);
		Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMazeCharacter::LookActionInput);

	}

}

//Move Input Action Method
void AMazeCharacter::MoveActionInput(const FInputActionValue& value)
{



	//input is a Vector 2D
	const FVector2D movementVector = value.Get<FVector2D>();

	// find which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	//get forward Vector
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	//get right Vector
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	//add movement
	AddMovementInput(ForwardDirection, movementVector.X);
	AddMovementInput(RightDirection, movementVector.Y);

}

//Jump Input Action Method
void AMazeCharacter::JumpActionInput()
{

	Jump();
	

}

//Look Input Action Method
void AMazeCharacter::LookActionInput(const FInputActionValue& value)
{

	//input is a Vector 2D
	const FVector2D lookAxisVector = value.Get<FVector2D>();

	//if (Controller != nullptr)
	//{
		//add Yaw and Pitch to Controller
		AddControllerYawInput(lookAxisVector.X);
		AddControllerPitchInput(lookAxisVector.Y);

	//}

}

