// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"
#include "GPE230_Project_KV/GPE230_Project_KV.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//components set
	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	//warning log message in C++
	UE_LOG(LogTemp, Warning, TEXT("Hello, from C++!"));
	
	//on screen debug message in C++. (Key is replaced from message further down.)
	if (GEngine)
	{

		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Onscreen message from C++."));
	}

	/*
	// regular DrawDebugSphere process 
	
	//pointer variable for UWorld 
	UWorld* World = GetWorld();

	if (World)
	{
		FVector Location = GetActorLocation();

		DrawDebugSphere(World, Location, 25.f, 25, FColor::Green, false, 60.f);
	}
	*/
	

	// set the actor location
	//SetActorLocation(FVector(0.f, 0.f, 50.f));

	
	// Location of this actor in game world
	FVector Location = GetActorLocation();

	// Actor forward vector  in game world
	FVector Forward = GetActorForwardVector();

	
	//pointer variable for UWorld 
	UWorld* World = GetWorld();


	//Macros
	// 
	//draw Sphere Macro
	DRAW_SPHERE(Location);
	//draw line macro
	DRAW_LINE(Location, Location + Forward * 100.f);
	//draw point macro
	DRAW_POINT(Location + Forward * 100.f);
	// draw vector macro
	DRAW_VECTOR(Location, Location + Forward * (-100.f));

	/*
	// draw a debug line
	if (World)
	{
		//FVector Forward = GetActorForwardVector();

		DrawDebugLine(World, Location, Location + Forward * 100.f, FColor::Blue, true);
	}
	*/

	//debug draw point
	/*
	if (World)
	{

		DrawDebugPoint(World, Location + Forward * 100.f, 15.f, FColor::Black, true);

	}
	*/
	
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Logs DeltaTIme in the output. ("DeltaTime: %f"), DeltaTime) is C format. 
	//For some reason, I have a very stable framerate...
	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	// on screen debug message in C++.
	if (GEngine)
	{
		FString name = GetName();

		FString message = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);

		FString itemNameMEssage = FString::Printf(TEXT("Item Name: %s"), *name);

		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, itemNameMEssage);
	}

}

