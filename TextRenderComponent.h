#pragma once

#include "Component.h"
#include "IRenderableComponent.h"
#include <string>

struct SDL_Texture;
struct SDL_Surface;

class UTextRenderComponent : public UComponent, public IRenderableComponent
{
public:
	UTextRenderComponent();
	virtual ~UTextRenderComponent();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	virtual void Render() override;

	void SetText(std::string InText);

protected:
	std::string Text;
	SDL_Texture* Texture;
	SDL_Surface* Surface;
};