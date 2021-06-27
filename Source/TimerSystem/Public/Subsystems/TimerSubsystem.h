// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TimerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class TIMERSYSTEM_API UTimerSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	public:

	protected:

	private:

	public:
	UTimerSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

	protected:

	private:
};
