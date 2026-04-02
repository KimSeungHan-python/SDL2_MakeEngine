#pragma once
#include "Engine.h"

class UGamePlayStatics
{
public:
	UGamePlayStatics();
	virtual ~UGamePlayStatics();

	inline static float GetWorldDeltaSeconds()
	{
		return GEngine->GetDeltaSeconds();
	}

};