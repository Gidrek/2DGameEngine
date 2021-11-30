//
// Created by Giovanni on 30/11/2021.
//

#ifndef INC_2DGAMEENGINE_GAME_H
#define INC_2DGAMEENGINE_GAME_H

#include <iostream>
#include <SDL2/SDL.h>

class Game {
public:
    Game();
    ~Game();
    void Run();

private:
    void Setup();
    void HandleInput();
    void Update(float dt);
    void Render();

    SDL_Window* mWindow;
    SDL_Renderer *mRenderer;
    bool mIsRunning;
};


#endif //INC_2DGAMEENGINE_GAME_H
