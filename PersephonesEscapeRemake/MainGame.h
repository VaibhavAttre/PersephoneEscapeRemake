#pragma once
#include "Sprite.h"
#include <SDL/SDL.h>
#include <Gl/glew.h>
#include <iostream>
#include "Errors.h"

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();
	void initSystems();
	void gameLoop();

	void processInput();
	void drawGame();

private:

	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	Sprite _sprite;
};

