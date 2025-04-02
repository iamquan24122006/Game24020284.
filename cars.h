#ifndef _CARS_H
#define _CARS__H

#include <SDL.h>
#include <SDL_image.h>

struct Cars {
    int x,y;
    SDL_Texture* texture;
    void renderCar(Graphics& graphics) {
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        dest.w = 50;
        dest.h = 100;
        SDL_RenderCopy(graphics.renderer, texture, NULL, &dest);
    }
    int checkOutside()
    {
        if (x < 110) x = 110;
        if (x > 341) x = 341;
    }
};

#endif // _CARS__H






