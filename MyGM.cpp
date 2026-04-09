#include "MyGM.h"
#include "SDL.h"
#include "Engine.h"
#include "Map.h"
#include "YouDieActor.h"
#include "TextRenderActor.h"
#include "TextRenderComponent.h"

AMyGM::AMyGM()
{
	//Name = "MyGM";
}

AMyGM::~AMyGM()
{
}

void AMyGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		AYouDieActor* TextActor = dynamic_cast<AYouDieActor*>(GEngine->GetWorld()->GetActorOfClass<AYouDieActor>());
		if (TextActor)
		{
			TextActor->TextRenderComponent->bIsVisible = true;
		}

		SDL_Log("Game Over");
		bGameOver = true;
		//GEngine->Stop();
	}
}

void AMyGM::GameComplete()
{
	static bool bGameComplte = false;

	if (!bGameComplte)
	{
		SDL_Log("Game Complete");

		bGameComplte = true;
		//GEngine->Stop();

	}
}