// Fill out your copyright notice in the Description page of Project Settings.

#include "Subsystems/TimerSubsystem.h"
#include "LogTimerSystem.h"

UTimerSubsystem::UTimerSubsystem()
{
	
}

void UTimerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
}

void UTimerSubsystem::Deinitialize()
{
	StopTimer();
}

void UTimerSubsystem::StartTimer(const float Rate, const bool bLoop, const float FirstDelay)
{
	TimerRate = Rate;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&UTimerSubsystem::TimerFinished,Rate,bLoop,FirstDelay);

	OnTimerStarted.IsBound() ? OnTimerStarted.Broadcast() : FLogTimerSystem::Info("UTimerSubsystem::StartTimer OnTimerStarted.IsBound is false");
}

void UTimerSubsystem::StopTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	
	OnTimerStopped.IsBound() ? OnTimerStopped.Broadcast() : FLogTimerSystem::Info("UTimerSubsystem::StopTimer OnTimerStopped.IsBound is false");
}

void UTimerSubsystem::PauseTimer()
{
	GetWorld()->GetTimerManager().PauseTimer(TimerHandle);

	OnTimerPaused.IsBound() ? OnTimerPaused.Broadcast() : FLogTimerSystem::Info("UTimerSubsystem::PauseTimer OnTimerPaused.IsBound is false");
}

void UTimerSubsystem::UnPauseTimer()
{
	GetWorld()->GetTimerManager().UnPauseTimer(TimerHandle);

	OnTimerUnPaused.IsBound() ? OnTimerUnPaused.Broadcast() : FLogTimerSystem::Info("UTimerSubsystem::UnPauseTimer OnTimerUnPaused.IsBound is false");
}

bool UTimerSubsystem::IsTimerPaused() const
{
	return GetWorld()->GetTimerManager().IsTimerPaused(TimerHandle);
}

bool UTimerSubsystem::IsTimerActive() const
{
	return GetWorld()->GetTimerManager().IsTimerActive(TimerHandle);
}

float UTimerSubsystem::GetTimerElapsed() const
{
	return GetWorld()->GetTimerManager().GetTimerElapsed(TimerHandle);
}

float UTimerSubsystem::GetTimerRemaining() const
{
	return GetWorld()->GetTimerManager().GetTimerRemaining(TimerHandle);
}

float UTimerSubsystem::GetTimerRate() const
{
	return TimerRate;
}

void UTimerSubsystem::TimerFinished() const
{
	OnTimerFinished.IsBound() ? OnTimerFinished.Broadcast() : FLogTimerSystem::Info("UTimerSubsystem::TimerFinished OnTimerFinished.IsBound is false");
}
