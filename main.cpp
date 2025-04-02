#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "graphics.h"
#include "defs.h"
#include "obstacles.h"
#include "events.h"
#include "cars.h"

using namespace std;

int main(int argc, char* argv[]) {

    Graphics graphics;
    graphics.init();

    bool running = true;
    bool play = true;
    SDL_Texture* menuTexture = graphics.loadTexture("image/menu.png");
    SDL_Texture* playTexture = graphics.loadTexture("image/playmenu.png");
    SDL_Texture* exitTexture = graphics.loadTexture("image/exitmenu.png");
    SDL_Texture* currentTexture = menuTexture;
    handleMenu(graphics, play, running, menuTexture, playTexture, exitTexture, currentTexture);
    SDL_DestroyTexture(menuTexture);
    SDL_DestroyTexture(playTexture);
    SDL_DestroyTexture(exitTexture);
    SDL_DestroyTexture(currentTexture);

    Mix_Music *bgrMusic = graphics.loadMusic("music\\bgrMusic.mp3");
    Mix_Chunk *clsMusic = graphics.loadSound("music\\clsMusic.wav");
    Mix_Chunk *clapHand = graphics.loadSound("music\\clapHand.wav");
    graphics.play(bgrMusic);
    SDL_Texture* background = graphics.loadTexture("image/bgr.png");
    TTF_Font* font = graphics.loadFont("font/RubikGlitch.ttf",25);
    TTF_Font* levelFont = graphics.loadFont("font/RubikGlitch.ttf",50);
    SDL_Texture* pmenu = graphics.loadTexture("image/pausedmenu.png");
    if(running)
    {

    SDL_Delay(16);
    graphics.prepareScene(background);
    graphics.presentScene();
    waitUntilKeyPressed();

    int score = 0;
    int level = 1;
    SDL_Color color = {255, 255, 255, 0};
    SDL_Color levelColor = {255, 0, 0, 0};
    SDL_Texture*pausedText = graphics.renderText(" ll ESC", font, color);
    string currentScore = " SCORE " + to_string(score/30);
    SDL_Texture* scoreText = graphics.renderText(currentScore.c_str(), font, color);
    string currentLevel = " LEVEL " + to_string(level);
    SDL_Texture* levelText = graphics.renderText(currentLevel.c_str(), font, color);
    SDL_Texture* currentlevelText = graphics.renderText(currentLevel.c_str(), levelFont, levelColor);
    graphics.renderTexture(currentlevelText, 140, 250);
    graphics.renderTexture(levelText, 310, 0);
    graphics.renderTexture(pausedText, 80, 0);
    graphics.renderTexture(scoreText, 170, 0);
    graphics.presentScene();

    Cars car;
    car.texture = graphics.loadTexture("image/rcar.png");
    car.x = rand() % 4 * 77 + 110;
    car.y = SCREEN_HEIGHT - 100 - 50;
    car.renderCar(graphics);

    const int numObstacles = 3;
    Obstacle obstacles[numObstacles];
    Obstacle obs;
    for (int i = 0; i < numObstacles; i++) {
        obs.loadObstacleTexture(obstacles,i,graphics);
    }
    graphics.presentScene();
    int xSpeed = 0;
    int moveSpeed = 7;
    int bgY = 0;
    bool paused = false;
    while (running) {
        moveCar(running, paused, moveSpeed, xSpeed);
        if(paused)
        {
          pausedMenu(running, paused, graphics, pmenu);
        }
        else
        {

        score++;
        level = score / 600 + 1;
        car.x += xSpeed;
        car.checkOutside();

        graphics.moveBackground(background, bgY , 6);
        obs.moveObstacles(obstacles, numObstacles, 6 + level, graphics);
        obs.renderObstacles(obstacles, numObstacles, graphics);
        car.renderCar(graphics);

        SDL_Rect carRect = {car.x, car.y, 50, 100};
        bool rectCollision = false;
        for (int i = 0; i < numObstacles; i++) {
            SDL_Rect obstacleRect = {obstacles[i].x, obstacles[i].y, 50, 100};
            if (checkCollision(carRect, obstacleRect)) {
                rectCollision = true;
                graphics.play(clsMusic);
                SDL_Delay(200);
                break;
            }
        }

        if (rectCollision || level == 9) {
            running = false;
            SDL_Delay(110);
        }

        string currentScore = " SCORE " + to_string(score/30);
        SDL_Texture* scoreText = graphics.renderText(currentScore.c_str(), font, color);
        string currentLevel = " LEVEL " + to_string(level);
        SDL_Texture* levelText = graphics.renderText(currentLevel.c_str(), font, color);
        if( score % 600 < 40){
        if( score % 600 == 0) graphics.play(clapHand);
        SDL_Texture* currentlevelText = graphics.renderText(currentLevel.c_str(), levelFont, levelColor);
        graphics.renderTexture(currentlevelText, 140, 250);
        }
        graphics.renderTexture(levelText, 310, 0);
        graphics.renderTexture(pausedText, 80, 0);
        graphics.renderTexture(scoreText, 170, 0);
        graphics.presentScene();
        SDL_Delay(16);
        }
    }

    SDL_Texture* gameOver = graphics.loadTexture("image/gameover.png");
    graphics.renderTexture(gameOver,0,0);
    graphics.presentScene();
    SDL_Delay(500);

    if (bgrMusic != nullptr) Mix_FreeMusic(bgrMusic);
    if (clapHand != nullptr) Mix_FreeChunk(clapHand);
    if (clsMusic != nullptr) Mix_FreeChunk(clsMusic);
    SDL_DestroyTexture(car.texture);
    SDL_DestroyTexture(pmenu);
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(pausedText);
    SDL_DestroyTexture(scoreText);
    SDL_DestroyTexture(levelText);
    SDL_DestroyTexture(currentlevelText);
    SDL_DestroyTexture(gameOver);
    for (int i = 0; i < numObstacles; i++) {
        SDL_DestroyTexture(obstacles[i].texture);
    }
    TTF_CloseFont(font);
    }
    graphics.quit();
    return 0;
}
