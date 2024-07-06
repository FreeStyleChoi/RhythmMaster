#include <SDL.h>

bool isRunning = true;

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Rhythm Master", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 640, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;
	Uint32 frameStart, frameTime, frameCount = 0;

	// Texture
	SDL_Surface* tmpSurface;


	// FPS
	const int FPS = 80;
	const int frameDelay = 1000 / FPS;

	while (isRunning)
	{
		// Get Ticks
		frameStart = (Uint32)SDL_GetTicks64();

		// Get Event
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			break;
		case SDL_KEYUP:
			break;
		case SDL_MOUSEMOTION:
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		case SDL_MOUSEWHEEL:
			break;
		default:
			break;
		}

		// Update

		// Control iteration time for Specific FPS
		frameTime = (Uint32)SDL_GetTicks64() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

		frameCount++;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}