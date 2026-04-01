#include "Engine.h"
//#include <conio.h>
#include "Map.h"
#include <SDL.h>

UEngine* UEngine::Instance = nullptr;
//int UEngine::KeyCode = 0;

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{


	SDL_Init(SDL_INIT_EVERYTHING);

	//도화지
	MyWindow = SDL_CreateWindow("Hello", 100, 100, 1024, 768, SDL_WINDOW_SHOWN);

	//GPU, 붓
	MyRender = SDL_CreateRenderer(MyWindow, -1, 0);

	Map = new UMap;
	InitBuffer();
	IsRunning = true;
}

void UEngine::Term()
{
	SDL_DestroyWindow(MyWindow);
	SDL_DestroyRenderer(MyRender);

	SDL_Quit();

	delete Map;
	TermBuffer();
	Map = nullptr;
}

void UEngine::Run()
{
	while (IsRunning)
	{
		SDL_PollEvent(&MyEvent);
		Input();
		Tick();
		Render();
	}
}

void UEngine::Input()
{
	//KeyCode = _getch();
}

void UEngine::Tick()
{
	if (MyEvent.type == SDL_QUIT)
	{
		IsRunning = false;
	}
	Map->Tick();
}
void UEngine::Render()
{
	//백지로 만들기
	SDL_SetRenderDrawColor(MyRender, 255, 255, 255, 255);
	SDL_RenderClear(MyRender);


	Map->Render();

	//그려 CPU->GPU
	SDL_RenderPresent(MyRender);
}
void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO ConsoleCUrsorInfo;
	ConsoleCUrsorInfo.dwSize = 1;
	ConsoleCUrsorInfo.bVisible = FALSE;

	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCUrsorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCUrsorInfo);
}
void UEngine::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25,
		COORD{0,0}, &DW);
}
void UEngine::Draw(int InX, int InY, char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;
	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex],
			COORD{(SHORT)InX, (SHORT)InY});
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);

}

void UEngine::Draw(int InX, int InY, int R, int G, int B)
{
	TileSize = 30;
	SDL_SetRenderDrawColor(MyRender, R, G, B, 255);
	SDL_Rect MyRect = { InX * TileSize, InY * TileSize ,TileSize ,TileSize };
	SDL_RenderFillRect(MyRender, &MyRect);
}

void UEngine::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}
void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}

//void UEngine::LoadMap()
//{
//	Map->Load();
//}
