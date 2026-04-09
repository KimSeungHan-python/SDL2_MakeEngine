#include "GamePlayStatics.h"
#include "Engine.h"
#include "GameMode.h"
#include "Map.h"

UGamePlayStatics::UGamePlayStatics()
{
}

UGamePlayStatics::~UGamePlayStatics()
{
}

AGameMode* UGamePlayStatics::GetGameMode()
{
	AActor* Actor = GEngine->GetWorld()->GetActorOfClass<AGameMode>();
	return dynamic_cast<AGameMode*>(Actor);
}
