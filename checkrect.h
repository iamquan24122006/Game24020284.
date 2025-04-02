#ifndef _CHECKRECTS_H
#define _CHECKRECTS__H

#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>

bool checkCollision(SDL_Rect& rect1, SDL_Rect& rect2) {
    return rect1.x + rect1.w > rect2.x && rect1.x < rect2.x + rect2.w && rect1.y + rect1.h > rect2.y && rect1.y < rect2.y + rect2.h;
    }

bool isInside(int x, int y, SDL_Rect rect) {
    return (x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h);
    }
#endif // _CHECKRECTS__H


