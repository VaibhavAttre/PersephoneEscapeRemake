#pragma once
#include "Sprite.h"
#include <SDL/SDL.h>
#include <Gl/glew.h>
#include "GLSLProgram.h"
#include <iostream>
#include "Errors.h"

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:
	void initSystems();
	void gameLoop();
	void initShaders();
	void processInput();
	void drawGame();



	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;

	Sprite _sprite;

	GLSLProgram _colorShaderProgram;
};

