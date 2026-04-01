#pragma once
class AActor
{
public:
	AActor();
	AActor(int InX, int InY, char InMesh);
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();
	virtual void SetActorLocation(int InX, int InY);
	
	int ZOrder = 0;

protected:
	int X;
	int Y;
	int R;
	int G;
	int B;

	char Mesh;
};

