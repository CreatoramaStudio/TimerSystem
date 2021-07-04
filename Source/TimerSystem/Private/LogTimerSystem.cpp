// Fill out your copyright notice in the Description page of Project Settings.

#include "LogTimerSystem.h"

DEFINE_LOG_CATEGORY(LogTimerSystem);

void FLogTimerSystem::Info(const FString& String)
{
	UE_LOG(LogTimerSystem, Display, TEXT("%s"), *String);
}

void FLogTimerSystem::Warning(const FString& String)
{
	UE_LOG(LogTimerSystem, Warning, TEXT("%s"), *String);
}

void FLogTimerSystem::Error(const FString& String)
{
	UE_LOG(LogTimerSystem, Error, TEXT("%s"), *String);
}