#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster();
	~AMonster();

	void BeginPlay() override;
	void Tick() override;
	void Render() override;
};

