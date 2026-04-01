#include "Actor.h"
#include <Windows.h>
#include <iostream>
#include "Engine.h"

AActor::AActor()
{
	X = 0;
	Y = 0;
	Mesh = ' ';
}

AActor::AActor(int InX = 0, int InY = 0, char InMesh = ' ')
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	R = 0;
	B = 0;
	G = 0;
}

AActor::~AActor()
{

}

void AActor::BeginPlay()
{

}

void AActor::Tick()
{

}
void AActor::Render()
{
	//COORD pos = { X,Y }; //x, y 좌표 설정
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서 설정
	//
	//std::cout << Mesh;

	GEngine->Draw(X, Y, Mesh);
	GEngine->Draw(X,Y,R,G,B);
}
void AActor::SetActorLocation(int InX, int InY)
{
	X = InX;
	Y = InY;
}
