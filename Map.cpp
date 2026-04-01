#include <fstream>
#include <iostream>
#include "Map.h"
#include "Actor.h"
#include "Monster.h"
#include "Wall.h"
#include "Goal.h"
#include "Floor.h"
#include "Player.h"
#include "Engine.h"


UMap::UMap()
{

}

UMap::~UMap()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}

	Actors.clear();
}

void UMap::Tick()
{
	for (auto actor : Actors)
	{
		actor->Tick();
	}
}
void UMap::Render()
{
	GEngine->Clear();

	for (auto actor : Actors)
	{
		actor->Render();
	}
	
	GEngine->Flip();
}

void UMap::Load(string s)
{
	int YlineCount = 0;
	std::ifstream file(s);
	std::string line;
	if (file.is_open()) {
		// 더 이상 읽을 줄이 없을 때까지 반복
		while (std::getline(file, line))
		{
			YlineCount++;
			for (int i = 0; i < line.size(); i++)//맵은 잘 불러짐
			{
				if (line[i] == 'P')
				{
					SpawnActors<AFloor>()->SetActorLocation(i, YlineCount);
					SpawnActors<APlayer>()->SetActorLocation(i, YlineCount);
				}
				else if (line[i] == 'M')
				{
					SpawnActors<AFloor>()->SetActorLocation(i, YlineCount);
					SpawnActors<AMonster>()->SetActorLocation(i, YlineCount);

				}
				else if (line[i] == 'G')
				{
					SpawnActors<AFloor>()->SetActorLocation(i, YlineCount);
					SpawnActors<AGoal>()->SetActorLocation(i, YlineCount);

				}
				else if (line[i] == '#')
				{
					SpawnActors<AFloor>()->SetActorLocation(i, YlineCount);
					SpawnActors<AWall>()->SetActorLocation(i, YlineCount);

				}
				else
				{
					SpawnActors<AFloor>()->SetActorLocation(i, YlineCount);
				}
			}
		
		}
		file.close();
	}
	Sort();
}

void UMap::Sort()
{
	for (int FirstIndex = 0; FirstIndex < Actors.size(); FirstIndex++)
	{
		for (int SecondIndex = 0; SecondIndex < Actors.size(); SecondIndex++)
		{
			if (Actors[FirstIndex]->ZOrder < Actors[SecondIndex]->ZOrder)
			{
				auto Temp = Actors[FirstIndex];
				Actors[FirstIndex] = Actors[SecondIndex];
				Actors[SecondIndex] = Temp;
			}
		}
	}
}


