#pragma once
#include "Engine.h"

class AGameMode;

class UGamePlayStatics
{
public:
	UGamePlayStatics();
	virtual ~UGamePlayStatics();

	inline static float GetWorldDeltaSeconds()
	{
		return GEngine->GetDeltaSeconds();
	}
	
	static AGameMode* GetGameMode();
	

};