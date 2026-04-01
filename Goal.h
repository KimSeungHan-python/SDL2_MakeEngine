#pragma once
#include "Actor.h"
class AGoal : public AActor
{
public:
	AGoal();
	~AGoal();

	void BeginPlay() override;
	void Tick() override;
	void Render() override;
};

