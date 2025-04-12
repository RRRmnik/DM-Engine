#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include "GameSettings.h"
#include "Color.h"
#include "Vector.h"
#include "Rect.h"
#include "Circle.h"
#include "Texture.h"

class Game
{
public:
	void Run();
	void Quit();

	void DrawPixel(Vector2f position, Color color);
	void DrawRect(FloatRect rect, Color color);
	void DrawCircle(FloatCircle circle, Color color);
	void DrawCircleOutline(FloatCircle circle, Color color);
	void DrawTexture(Texture texture, FloatRect rect, Color color);
	void Clear(Color color);
	
	bool IsKeyPressed(SDL_Scancode key) { return m_pKeyboardInput[key]; }
	bool GetLeftMouseButton() { return (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(1)) == SDL_BUTTON(1); }
	bool GetRightMouseButton() { return (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(3)) == SDL_BUTTON(3); }
	float GetMousePositionX() { int x; SDL_GetMouseState(&x, nullptr); return x; }
	float GetMousePositionY() { int y; SDL_GetMouseState(nullptr, &y); return y; }
	Vector2i GetMousePosition() { int x; int y; SDL_GetMouseState(&x, &y); return Vector2i{ x, y }; }
	float GetDt() { return dt; }
	float GetTimer() { return timer; }
	float GetFps() { return fps; }
	SDL_Window* GetWindow() { return m_pWindow; }
	SDL_Renderer* GetRenderer() { return m_pRenderer; }
	GameSettings* GetGameSettings() { return m_pGameSettings; }

	void SetGameSettings(GameSettings* pGameSettings) { delete m_pGameSettings; m_pGameSettings = pGameSettings; }
	void SetStart(void (*start)()) { m_pStart = start; }
	void SetUpdate(void (*update)()) { m_pUpdate = update; }
	void SetRender(void (*render)()) { m_pRender = render; }

private:
	bool m_IsRunning;

	const Uint8* m_pKeyboardInput;

	float dt = 0;
	float timer = 0;
	float fps = 0;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameSettings* m_pGameSettings = new GameSettings();

	bool Setup();
	void ProcessTime();
	void PollEvents();
	void GetInput();
	void Display();
	
	void (*m_pStart)();
	void (*m_pUpdate)();
	void (*m_pRender)();
};

#endif