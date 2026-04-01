#include "Player.h"
#include "Engine.h"

APlayer::APlayer()
{
	X = 1;
	Y = 1;
	Mesh = 'P';
	ZOrder = 10;
	R = 255;
	G = 0;
	B = 0;
}

APlayer::~APlayer()
{

}



void APlayer::BeginPlay()
{
	__super::BeginPlay();
}

void APlayer::Tick()
{
	//__super::Tick();

	SDL_Event Event = GEngine->GetEvent();
	int KeyCode = Event.key.keysym.sym;
	if (Event.type == SDL_KEYDOWN)
	{
		if (KeyCode == SDLK_w)
		{
			Y--;
			//callback
		}
		if (KeyCode == SDLK_s)
		{
			Y++;
		}
		if (KeyCode == SDLK_a)
		{
			X--;
		}
		if (KeyCode == SDLK_d)
		{
			X++;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}

	}
	

}

void APlayer::Render()
{
	__super::Render();
}

