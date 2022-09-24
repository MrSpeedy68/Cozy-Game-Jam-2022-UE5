// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FallGameJam2022Character.generated.h"


USTRUCT(BlueprintType)
struct FInventory
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int Pumpkins {50};
};

USTRUCT(BlueprintType)
struct FPlayerStats
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	int JumpLevel {1};
	UPROPERTY(BlueprintReadWrite)
	float JumpCost {10};
	
	UPROPERTY(BlueprintReadWrite)
	int WalkSpeedLevel {1};
	UPROPERTY(BlueprintReadWrite)
	float WalkSpeedCost {20};
	
	UPROPERTY(BlueprintReadWrite)
	int BlastRadiusLevel {1};
	UPROPERTY(BlueprintReadWrite)
	float BlastRadiusCost {30};
	
	UPROPERTY(BlueprintReadWrite)
	int ShootingSpeedLevel {1};
	UPROPERTY(BlueprintReadWrite)
	float ShootingSpeedCost {15};
	
	UPROPERTY(BlueprintReadWrite)
	int DamageLevel {1};
	UPROPERTY(BlueprintReadWrite)
	float DamageCost {35};
};


UCLASS(config=Game)
class AFallGameJam2022Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AFallGameJam2022Character();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> Projecticle;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetGun, BlueprintSetter=SetGun)
	AActor *Gun;
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	AActor *GetGun() {return Gun;}
	
	UFUNCTION(BlueprintCallable)
	void SetGun(AActor *Value);

	UFUNCTION(BlueprintCallable)
	void OnShoot();

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FInventory GetInventory() { return Inventory; }

	UFUNCTION(BlueprintCallable)
	void SetInventory(FInventory Items);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FPlayerStats GetPlayerStats() { return PlayerStats; }

	UFUNCTION(BlueprintCallable)
	void SetPlayerStats(FPlayerStats Items);
	
	UPROPERTY(BlueprintReadWrite, BlueprintGetter=GetInventory, BlueprintSetter=SetInventory, Category="PlayerController")
	FInventory Inventory;

	UPROPERTY(BlueprintReadWrite, BlueprintGetter=GetPlayerStats, BlueprintSetter=SetPlayerStats, Category="PlayerController")
	FPlayerStats PlayerStats;

	//Getters
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetJumpLevel() {return PlayerStats.JumpLevel; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetJumpCost() {return PlayerStats.JumpCost; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetWalkSpeedLevel() {return PlayerStats.WalkSpeedLevel; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetWalkSpeedCost() {return PlayerStats.WalkSpeedCost; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetBlastRadiusLevel() {return PlayerStats.BlastRadiusLevel; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetBlastRadiusCost() {return PlayerStats.BlastRadiusCost; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetShootingSpeedLevel() {return PlayerStats.ShootingSpeedLevel; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetShootingSpeedCost() {return PlayerStats.ShootingSpeedCost; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetDamageLevel() {return PlayerStats.DamageLevel; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="PlayerStats")
	int GetDamageCost() {return PlayerStats.DamageCost; }

	//Setters
	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetJumpLevel(int Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetJumpCost(float Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetWalkSpeedLevel(int Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetWalkSpeedCost(float Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetBlastRadiusLevel(int Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetBlastRadiusCost(float Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetShootingSpeedLevel(int Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetShootingSpeedCost(float Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetDamageLevel(int Value);

	UFUNCTION(BlueprintCallable, Category="PlayerStats")
	void SetDamageCost(float Value);
};

