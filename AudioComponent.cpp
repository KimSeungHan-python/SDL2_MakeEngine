#include "AudioComponent.h"
#include "SDL_mixer.h"

UAudioComponent::UAudioComponent()
{

}
UAudioComponent::~UAudioComponent()
{
	if (Music)
	{
		Mix_FreeMusic(Music);
	}
}

void UAudioComponent::BeginPlay() 
{
	Play();
}
void UAudioComponent::Tick() 
{

}

void UAudioComponent::Play()
{
	Mix_PlayMusic(Music,1);
}

void UAudioComponent::Stop()
{
	Mix_PauseMusic();
}

void UAudioComponent::Load(std::string InFilename)
{
	//Mix_LoadMUS 배경음악
	//MIx_LoadWAV 펀치나 검 처럼 타격감 있어야하는 것, 효과음

	Filename = InFilename;

	Music = Mix_LoadMUS(Filename.c_str());
}