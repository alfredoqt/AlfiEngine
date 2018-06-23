#pragma once

#include "Engine.h"
#include "Engine\Public\Core\GraphicsContext.h"

struct SDL_Window;
struct SDL_Renderer;
struct Color;
struct Vector2;
class IGame;

// I don't want to include SDL here
typedef void* SDL_GLContext;

// Defines the entry point for the engine
class EngineGL : public Engine
{
public:

	virtual int Init(IGame* pGame, const char* pTitle, const int& pWidth, const int& pHeight) override;

	// Run
	virtual void Run(IGame* pGame) override;

	virtual void Quit(IGame* pGame) const override;

	// TODO: Provide functionality for order in layer
	virtual void DrawLine(const Vector2& pOrigin, const Vector2& pTarget, const Color& pColor, const int& pOrderInLayer) override;
	virtual void DrawFillCircle(const Vector2& pPosition, const float& pRadius, const Color& pColor, const int& pOrderInLayer) override;
	virtual void DrawCircle(const Vector2& pPosition, const float& pRadius, const Color& pColor, const int& pOrderInLayer) override;
	virtual void DrawRect(const Vector2& pTopLeft, const Vector2& pBotRight, const Color& pColor, const int& pOrderInLayer) override;

	// This will open and close the font everytime, so it may be a little slow, but I can set different sizes every time
	// Drawn on top left
	virtual void DrawText(std::string pFontFile, const int& pFontSize, const std::string pMessage, const Vector2& pPosition, const Color& pColor, const int& pOrderInLayer) override;

private:

	// The opengl context
	SDL_GLContext mGLContext;

	// For the box
	GraphicsContext mGCBox;

	// For the circle
	GraphicsContext mGCCircle;
};
