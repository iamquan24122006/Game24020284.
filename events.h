#ifndef _EVENTS_H
#define _EVENTS__H

#include <SDL.h>
#include <SDL_image.h>
#include "checkrect.h"
void handleMenu(Graphics& graphics, bool& play, bool& running, SDL_Texture* menuTexture, SDL_Texture* playTexture, SDL_Texture* exitTexture, SDL_Texture* currentTexture)
{
    SDL_Rect playButton = {250, 170, 170, 70};
    SDL_Rect exitButton = {50, 270, 170, 70};
    SDL_Event e;
    while (play) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) running = false;
            if (e.type == SDL_MOUSEMOTION) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (isInside(x, y, playButton)) {
                    currentTexture = playTexture;
                } else if (isInside(x, y, exitButton)) {
                    currentTexture = exitTexture;
                } else {
                    currentTexture = menuTexture;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (isInside(x, y, playButton)) {
                    running = true;
                    play = false;
                }
                if (isInside(x, y, exitButton)) {
                    running = false;
                    play = false;
                }
            }
        }
        graphics.renderTexture(currentTexture, 0, 0);
        graphics.presentScene();
    }
}
void pausedMenu(bool& running, bool& pause, Graphics& graphics, SDL_Texture* pmenu)
{
    graphics.renderTexture(pmenu, 0, 0);
    graphics.presentScene();
    SDL_Delay(100);
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_r) {
                    pause = false;;
                } else if (e.key.keysym.sym == SDLK_s) {
                    running = false;
                }
        }
    }
}
void waitUntilKeyPressed() {
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(110);
    }
}
void moveCar(bool& running, bool& paused, int moveSpeed, int& xSpeed){
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            } else if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_LEFT) {
                    xSpeed = -moveSpeed;
                } else if (e.key.keysym.sym == SDLK_RIGHT) {
                    xSpeed = moveSpeed;
                } else if (e.key.keysym.sym == SDLK_ESCAPE) {
                    paused = true;
                }
            } else if (e.type == SDL_KEYUP) {
                xSpeed = 0;
            }
        }
}
#endif // _EVENTS__H





