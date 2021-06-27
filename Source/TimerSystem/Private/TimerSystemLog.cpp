// Fill out your copyright notice in the Description page of Project Settings.

#include "TimerSystemLog.h"

DEFINE_LOG_CATEGORY(LogTimerSystem);

void PrintInfoTimerSystem(const FString& String)
{
	UE_LOG(LogTimerSystem, Display, TEXT("%s"), *String);
}

void PrintWarningTimerSystem(const FString& String)
{
	UE_LOG(LogTimerSystem, Warning, TEXT("%s"), *String);
}

void PrintErrorTimerSystem(const FString& String)
{
	UE_LOG(LogTimerSystem, Error, TEXT("%s"), *String);
}