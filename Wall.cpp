#include "Wall.h"

AWall::AWall()
{
	X = 0;
	Y = 0;
	Mesh = '#';
	ZOrder = 1;
	R = 255;
	G = 255;
	B = 0;
}

AWall::~AWall()
{

}



void AWall::BeginPlay()
{
}

void AWall::Tick()
{

}

void AWall::Render()
{
	__super::Render();
}
