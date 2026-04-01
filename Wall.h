#pragma once
#include "Actor.h"
class AWall : public AActor
{
public:
	AWall();
	~AWall();

	void BeginPlay() override;
	void Tick() override;
	void Render() override;
};

