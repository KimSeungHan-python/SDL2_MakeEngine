#pragma once
#include "Component.h"
#include "IRenderableComponent.h"
#include "SDL.h"

class USpriteComponent : public UComponent,public IRenderableComponent
{
public:
	USpriteComponent();
	~USpriteComponent();

	//UComponent의 구현, Abstract Class,
	virtual void Tick() override;//순수 가상 함수 없는거기에 구현 안해도됨

	virtual void BeginPlay() override;//순수 가상 함수 없는거기에 구현 안해도됨

	//IRenderableComponent를 구현, Interface라는 구현(C++ 문법이 없음, Blueprint, C# ,java 있음)
	//UE 있음
	virtual void Render() override;

	int ZOrder = 0;

	SDL_Surface* Image;
	SDL_Texture* Texture;
};

