#pragma once
#include "Actor.h"
class APlayer : public AActor
{
public:
	APlayer();
	~APlayer();
	
	void BeginPlay() override;
	void Tick() override;
	void Render() override;
};

