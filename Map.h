#pragma once
#include <vector>
#include <string>
using namespace std;
class AActor;
class AMonster;
class AFloor;
class APlayer;
class AGoal;
class AWall;


class UMap
{
public:
	UMap();
	virtual ~UMap();


	void Tick();
	void Render();

	void Load(string s);

	template <typename T>
	AActor* SpawnActors()
	{
		AActor* NewActor = new T;

		Actors.push_back(NewActor);
		return NewActor;
	}

	inline std::vector<class AActor*>& GetActors()
	{
		return Actors;
	}

	void Sort();

protected:
	vector<class AActor*> Actors;
};

