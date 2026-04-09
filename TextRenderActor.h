#pragma once
#include "Actor.h"

class UTextRenderComponent;

class ATextRenderActor : public AActor
{
public:
	ATextRenderActor();
	~ATextRenderActor();

	UTextRenderComponent* TextRenderComponent;
};

