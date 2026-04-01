#include "Goal.h"

AGoal::AGoal()
{
	X = 3;
	Y = 3;
	Mesh = 'G';
	ZOrder = 30;

	R = 0;
	G = 0;
	B = 255;
}

AGoal::~AGoal()
{
}



void AGoal::BeginPlay()
{
}

void AGoal::Tick()
{

}

void AGoal::Render()
{
	__super::Render();
}
