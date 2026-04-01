#include <iostream>
#include <vector> //Container
#include "Engine.h"
#include "SDL.h"
#include "SDL_main.h"
#include <random>
#include <cmath>
#include "Map.h"


#pragma comment(lib,"SDL2")
#pragma comment(lib,"SDL2main")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* MyWindow;
	SDL_Renderer* MyRender;
	SDL_Event MyEvent;
	//µµÈ­Áö
	MyWindow = SDL_CreateWindow("Hello", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);

	//GPU, º×
	MyRender = SDL_CreateRenderer(MyWindow, -1, 0);









	delete MyWindow;
	delete MyRender;
	//GEngine->GetMap()->Load("TestMap.txt");
	//GEngine->Run();

	//delete GEngine;

	return 0;
}



//int main()
//{
//
//	//cout << Compare << endl;
//
//	//int (*CompareFunction)(void);
//	//CompareFunction = Compare;
//	//
//	//cout << (*CompareFunction)() << endl;
//
//
//	GEngine->GetInstance();
//	GEngine->GetMap()->Load("TestMap.txt");
//	GEngine->Run();
//
//
//
//	//search and sort
//	//selection and bubble
//	//SelectionSort(Data, 10);
//
//
//	return 0;
//
//}