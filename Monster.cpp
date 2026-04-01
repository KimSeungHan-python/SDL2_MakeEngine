#include "Monster.h"

AMonster::AMonster()
{
	X = 1;
	Y = 1;
	Mesh = 'M';
	R = 0;
	G = 255;
	B = 0;
}

AMonster::~AMonster()
{

}



void AMonster::BeginPlay()
{
}

void AMonster::Tick()
{

}

void AMonster::Render()
{
	__super::Render();
}
