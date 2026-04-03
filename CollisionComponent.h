#pragma once
#include "Component.h"
class UCollisionComponent : public UComponent
{
public:
	UCollisionComponent();
	virtual ~UCollisionComponent();

	virtual void Tick() override;//순수 가상 함수 없는거기에 구현 안해도됨

	virtual void BeginPlay() override;//순수 가상 함수 없는거기에 구현 안해도됨

	int bIsGenerateOverlap : 1;

	int bIsGenerateHit : 1;

};

