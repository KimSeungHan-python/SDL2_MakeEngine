#include "YouDieActor.h"
#include "TextRenderComponent.h"

AYouDieActor::AYouDieActor()
{
	TextRenderComponent->SetText("You DIed");
	X = 200;
	Y = 150;
	TextRenderComponent->ZOrder = 200;
	TextRenderComponent->bIsVisible = false;
}

AYouDieActor::~AYouDieActor()
{

}
