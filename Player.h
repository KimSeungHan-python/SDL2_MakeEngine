#pragma once
#include "Character.h"


class USpriteAnimationComponent;
class UCollisionComponent;

class APlayer : public  ACharacter
{
public:
	APlayer(int InX = 1, int InY = 1, char InMesh = 'P');
	virtual ~APlayer();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	virtual void ReceiveHit(AActor* other) override;

	void ProcessBeginOverlap(class AActor* OtherActor);


	USpriteAnimationComponent* SpriteAnimationComponent;

	UCollisionComponent* CollisionComponent;



protected:



};