#include "Actor.h"
#include "Engine.h"
#include <iostream>
#include <Windows.h>
#include "SpriteComponent.h"
#include "Component.h"

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY)
{

}

AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}
}

void AActor::BeginPlay()
{
	for (auto Component : Components)
	{
		Component->BeginPlay();
	}
}

void AActor::Tick()
{
	for (auto Component : Components)
	{
		Component->Tick();
	}
}

//void AActor::Render()
//{
//	int TileSize = 30;
//	SDL_Rect DestinationRect = { X * TileSize, Y * TileSize, TileSize, TileSize };
//	SDL_RenderCopy(GEngine->GetRenderer(), Texture, nullptr, &DestinationRect);
//}

void AActor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}

void AActor::ReceiveHit(AActor* other)
{


}
