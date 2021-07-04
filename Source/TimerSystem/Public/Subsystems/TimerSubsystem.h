// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TimerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimer);

/**
 * 
 */
UCLASS()
class TIMERSYSTEM_API UTimerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	UPROPERTY(BlueprintAssignable, Category = "Timer System")
	FOnTimer OnTimerStarted;

	UPROPERTY(BlueprintAssignable, Category = "Timer System")
	FOnTimer OnTimerStopped;

	UPROPERTY(BlueprintAssignable, Category = "Timer System")
	FOnTimer OnTimerPaused;

	UPROPERTY(BlueprintAssignable, Category = "Timer System")
	FOnTimer OnTimerUnPaused;

	UPROPERTY(BlueprintAssignable, Category = "Timer System")
	FOnTimer OnTimerFinished;

	protected:

	FTimerHandle TimerHandle;

	private:

	public:
	UTimerSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable,Category= "Timer System")
	void StartTimer(const float Rate, const bool bLoop, const float FirstDelay);

	UFUNCTION(BlueprintCallable,Category= "Timer System")
	void StopTimer();

	UFUNCTION(BlueprintCallable,Category= "Timer System")
	void PauseTimer();

	UFUNCTION(BlueprintCallable,Category= "Timer System")
	void UnPauseTimer();

	UFUNCTION(BlueprintPure,Category= "Timer System")
	bool IsTimerPaused() const;

	UFUNCTION(BlueprintPure,Category= "Timer System")
	bool IsTimerActive() const;

	UFUNCTION(BlueprintPure,Category= "Timer System")
	float GetTimerElapsed() const;

	UFUNCTION(BlueprintPure,Category= "Timer System")
	float GetTimerRemaining() const;

	void TimerFinished() const;

	protected:

	private:
};
