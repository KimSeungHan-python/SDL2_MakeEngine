#include "USpriteAnimationComponent.h"
#include "Player.h"
#include "GamePlayStatics.h"
#include "Engine.h"
#include "SDL.h"

USpriteAnimationComponent::USpriteAnimationComponent()
{

	ExecutionTime = 0.1f;
	ElapsedTime = 0;

	//SpriteIndexY = 0;
	//SpriteIndexX = 0;

	//SpriteSizeX = Image->w / 5;
	//SpriteSizeY = Image->h / 5;

}

USpriteAnimationComponent::~USpriteAnimationComponent()
{

}

void USpriteAnimationComponent::Render()
{ 
	int TileSize = 30;
	int SpriteSizeX = Image->w / 5;
	int SpriteSizeY = Image->h / 5;//이거 때메 안됨 왜 그런거지?
	//Texture 위치 설정
	SDL_Rect SourceRect = { SpriteIndexX * SpriteSizeX, SpriteIndexY * SpriteSizeY, SpriteSizeX, SpriteSizeY };
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &SourceRect, &DestinationRect);
}

void USpriteAnimationComponent::Tick()
{
	ElapsedTime += UGamePlayStatics::GetWorldDeltaSeconds();
	if (ElapsedTime >= ExecutionTime)
	{
		SpriteIndexX++;
		SpriteIndexX = SpriteIndexX % 5;
		ElapsedTime = 0;
	}
}

