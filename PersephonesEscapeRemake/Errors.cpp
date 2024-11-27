#include "Errors.h"
#include <iostream>
#include <SDL/SDL.h>

void fatalError(std::string errorString) {

	std::cout << errorString << std::endl;
	std::cout << "...";
	int a;
	std::cin >> a;
	SDL_Quit();
}
