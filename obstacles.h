#ifndef _OBSTACLES__H
#define _OBSTACLES__H

#include <SDL.h>
#include <SDL_image.h>


struct Obstacle {
    int x, y;
    SDL_Texture* texture;
    void loadObstacleTexture(Obstacle obstacles[], int idx, Graphics& graphics )
    {
     obstacles[idx].y = - 100 ;
     obstacles[idx].x = rand() % 4 * 77 + 110;
     int randomObstacleTexture = rand() % 3 + 1;
     switch (randomObstacleTexture) {
     case 1:
            obstacles[idx].texture = graphics.loadTexture("image/greencar.png");
            break;
     case 2:
            obstacles[idx].texture = graphics.loadTexture("image/yellowcar.png");
            break;
     case 3:
            obstacles[idx].texture = graphics.loadTexture("image/bluecar.png");
            break;
     default:
            break;
        }
    }
    void moveObstacles(Obstacle obstacles[], int numObstacles, int obstacleSpeed, Graphics& graphics) {
        for (int i = 0; i < numObstacles; i++) {
            obstacles[i].y += obstacleSpeed;

            if (obstacles[i].y >= SCREEN_HEIGHT) {
                loadObstacleTexture(obstacles,i,graphics);
            }
        }
    }

    void renderObstacles(Obstacle obstacles[], int numObstacles, Graphics& graphics) {
        for (int i = 0; i < numObstacles; i++) {
            SDL_Rect rect = {obstacles[i].x, obstacles[i].y, 50, 100};
            SDL_RenderCopy(graphics.renderer, obstacles[i].texture, nullptr, &rect);
        }
    }
};
#endif // _OBSTACLES__H



