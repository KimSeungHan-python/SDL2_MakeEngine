#pragma once
#include "Character.h"
class USpriteComponent;
class UCollisionComponent;

class AMonster : public ACharacter
{
public:
	AMonster(int InX = 0, int InY = 0, char InMesh = 'M');
	virtual ~AMonster();

	virtual void Tick() override;

	virtual void ReceiveHit(AActor* other) override;

	//void ProcessBeginOverlap(class AActor* OtherActor);

protected:
	float ElapsedTime = 0;
	float ExecutionTime = 0.1f;

	USpriteComponent* SpriteComponent;
	//bool PredictMove(int InX, int InY); // Movement Component·Î ¸¸µå¼À
	UCollisionComponent* CollisionComponent;
};