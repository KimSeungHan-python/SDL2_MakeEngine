#pragma once
#include "Actor.h"
class AFloor : public AActor
{
public:
	AFloor(int InX = 0, int InY = 0, char InMesh = ' ');
	~AFloor();

	void BeginPlay() override;
	void Tick() override;
	void Render() override;
};

