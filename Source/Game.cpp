//
// Created by Giovanni on 30/11/2021.
//

#include "Game.h"

Game::Game()
    : mWindow()
    , mRenderer()
    , mIsRunning(false)
{
    std::cout << "Starting game" << std::endl;
}

Game::~Game()
{

    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();

    std::cout << "Finishing game" << std::endl;
}

void Game::Run()
{
    Setup();

    while (mIsRunning)
    {
        HandleInput();
        Update(0);
        Render();
    }
}

void Game::Setup()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "Failed to initialize SDL" << std::endl;
        return;
    }

	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
	{
		printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		return;
	}


    mWindow = SDL_CreateWindow(
            "2D Game Engine",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            800, 600,
            0);

    if (!mWindow)
    {
        std::cerr << "Failed to initialize SDL Window" << std::endl;
        return;
    }

    mRenderer = SDL_CreateRenderer(mWindow, -1, 0);
    if (!mRenderer)
    {
        std::cerr << "Failed to initialize SDL Renderer" << std::endl;
        return;
    }

   mIsRunning = true;
}

void Game::HandleInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                mIsRunning = false;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    mIsRunning = false;
                }
        }
    }
}

void Game::Update(float dt)
{

}

void Game::Render()
{
	SDL_SetRenderDrawColor(mRenderer, 33, 33, 33, 255);
    SDL_RenderClear(mRenderer);

	SDL_Surface* surface = IMG_Load("Assets/images/tank-tiger-right.png");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect dest = {10, 10, 32, 32};
	SDL_RenderCopy(mRenderer, texture, nullptr, &dest);

	SDL_DestroyTexture(texture);
    SDL_RenderPresent(mRenderer);
}