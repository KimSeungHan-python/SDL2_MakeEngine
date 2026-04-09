#include "Map.h"
#include "Engine.h"

#include <fstream>
#include <algorithm>

#include "Actor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Wall.h"
#include "Floor.h"
#include "IRenderableComponent.h"
#include "SpriteComponent.h"
#include "GameMode.h"
#include "YouDieActor.h"
#include "BGActor.h"
#include "MyGM.h"

UWorld::UWorld()
{

}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UWorld::SetGameMode(AGameMode* NewGameMode)
{
	Actors.push_back(NewGameMode);
}

void UWorld::Load(std::string MapName)
{
	SetGameMode(new AMyGM);
	std::ifstream MapStream(MapName);

	int Y = 0;
	int MaxX = -1;
	int MaxY = -1;
	while (!MapStream.eof())
	{
		std::string Line;
		std::getline(MapStream, Line);
		for (int X = 0; X < Line.length(); ++X)
		{
			if (Line[X] == '#')
			{
				SpawnActor<AWall>()->SetActorLocation(X, Y);
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == ' ')
			{
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'P')
			{
				SpawnActor<APlayer>()->SetActorLocation(X, Y);
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'M')
			{
				SpawnActor<AMonster>()->SetActorLocation(X, Y);
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}
			else if (Line[X] == 'G')
			{
				SpawnActor<AGoal>()->SetActorLocation(X, Y);
				SpawnActor<AFloor>()->SetActorLocation(X, Y);
			}

			if (MaxX < X + 1)
			{
				MaxX = X + 1;
			}

		}
		Y++;
	}

	MaxY = Y;

	SDL_SetWindowSize(GEngine->GetWindow(), (MaxX) * 30, MaxY * 30);

	//map에 추가해야하는데 작업할게 많아서 패스한다.
	SpawnActor<AYouDieActor>();
	SpawnActor<ABGActor>();

	Sort();
	std::sort(Actors.begin(), Actors.end(),
		[](AActor* First, AActor* Second) -> int {


			IRenderableComponent* FirstRenderComponent = nullptr;
			for (auto Component : First->Components)
			{
				FirstRenderComponent = dynamic_cast<IRenderableComponent*>(Component);
				if (FirstRenderComponent)
				{
					break;
				}
			}

			if (!FirstRenderComponent)
			{
				return 0;
			}

			IRenderableComponent* SecondRenderComponent = nullptr;
			for (auto Component : Second->Components)
			{
				SecondRenderComponent = dynamic_cast<IRenderableComponent*>(Component);
				if (SecondRenderComponent)
				{
					break;
				}
			}

			if (!SecondRenderComponent)
			{
				return 0;
			}

			return (FirstRenderComponent->ZOrder < SecondRenderComponent->ZOrder ? 1 : 0);
		}
	);
}

void UWorld::Sort()
{
	//for (int FirstIndex = 0; FirstIndex < Actors.size(); ++FirstIndex)
	//{
	//	for (int SecondIndex = 0; SecondIndex < Actors.size(); ++SecondIndex)
	//	{
	//		if (Actors[FirstIndex]->GetZOrder() < Actors[SecondIndex]->GetZOrder())
	//		{
	//			auto Temp = Actors[FirstIndex];
	//			Actors[FirstIndex] = Actors[SecondIndex];
	//			Actors[SecondIndex] = Temp;
	//		}
	//	}
	//}
}

void UWorld::BeginPlay()
{
	for (auto Actor : Actors)
	{
		Actor->BeginPlay();
	}
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();//Tick 이벤트 
	}
}

void UWorld::Render()
{
	GEngine->Clear();

	for (auto Actor : Actors)
	{

		//모든 액터중에서 Render가능한 컴포넌트가 있으면 렌더 하세여.
		//Actor->Render();
		for (auto Component : Actor->Components)
		{
			//SpriteComponent.h 차이
			//가진 컴포넌트중에 SpriteRenderComponent가 있냐 물어보는거임
			IRenderableComponent* RenderComponent = dynamic_cast<IRenderableComponent*>(Component);
			if (RenderComponent && RenderComponent->bIsVisible)
			{
				RenderComponent->Render();
			}
		}
	}

	GEngine->Flip();
}