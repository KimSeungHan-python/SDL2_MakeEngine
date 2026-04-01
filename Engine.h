#pragma once
#include <string>
#include <Windows.h>
#include <SDL.h>

class UMap;

class UEngine
{
public:
	virtual ~UEngine();

	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine();
		}

		return Instance;
	}

	inline UMap* GetMap()
	{
		return Map;
	}
	void Init();
	void Term();
	void Run();
	void Input();
	void Tick();
	void Render();
	//void LoadMap();

	//static int KeyCode;

	//Renderer
	HANDLE ScreenBufferHandle[2];// ¹öÆÛ 2°³ ¾¸
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Draw(int InX, int InY, char InMesh);
	void Draw(int InX, int InY, int R, int G, int B);
	void Flip();
	void TermBuffer();

	inline const SDL_Event& GetEvent()
	{
		return MyEvent;
	}

protected:
	UEngine();

	static UEngine* Instance;

	bool IsRunning;
	UMap* Map;
	SDL_Window* MyWindow;
	SDL_Renderer* MyRender;
	SDL_Event MyEvent;
	int TileSize;

};

#define GEngine			UEngine::GetInstance()
