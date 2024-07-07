#include "main.h"
#include "Entity.h"

bool isRunning = true;

int main(int argc, char** argv)
{
	// Init
	SDL_Init(SDL_INIT_EVERYTHING);
	Width windowSize = { 480, 640 };
	SDL_Window* window = SDL_CreateWindow("Rhythm Master", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowSize.w, windowSize.h, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;
	Uint32 frameStart, frameTime, frameCount = 0;
	if (renderer)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}
	if (TTF_Init() == -1)
	{
		return 0;
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 8, 2048);

	// Surface
	SDL_Surface* tmpSurface = { 0 };

	// Texture
	Entity* aa = new Entity;
	tmpSurface = IMG_Load("./resource/aa.png");
	SDL_Texture* aaTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	aa->onScreen = true;
	aa->rect.w = 64;
	aa->rect.h = 64;

	// FPS
	const int FPS = 80;
	const int frameDelay = 1000 / FPS;

	// Main Loop
	while (isRunning)
	{
		// FPS
		frameStart = (Uint32)SDL_GetTicks64();

		// Get Most Recent Window Size
		SDL_GetWindowSize(window, &windowSize.w, &windowSize.h);

		// Event
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

		aa->rect.x = (windowSize.w / 2) - (aa->rect.w / 2);
		aa->rect.y = (windowSize.h / 2) - (aa->rect.h / 2);

		// Renderer
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, aaTex, NULL, &aa->rect);
		SDL_RenderPresent(renderer);

		// FPS
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