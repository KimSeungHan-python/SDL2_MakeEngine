#include "Character.h"
#include "Engine.h"
#include "Map.h"
#include "CollisionComponent.h"
//#include "Actor.h"
//#include "Component.h"

ACharacter::ACharacter()
{
}


ACharacter::~ACharacter()
{
}

bool ACharacter::PredictMove(int InX, int InY)
{
	for (auto Other : GEngine->GetWorld()->GetActors())
	{
		if (Other == this)
		{
			continue;
		}
		for (auto Component : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(Component);
			if (OtherCollision)
			{

				if (OtherCollision->bIsGenerateHit && InX == Other->GetX() && InY == Other->GetY())
				{
					ReceiveHit(Other);
					return false;
				}

				//if (OtherCollision->bIsGenerateOverlap && InX == Other->GetX() && InY == Other->GetY())
				//{
				//	OnActorBeginOverlap(Other);
				//	return false;
				//}
			}
		}
	}



	return true;
}