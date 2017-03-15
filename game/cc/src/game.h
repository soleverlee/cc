#ifndef _GAME_H_
#define _GAME_H_

#include "camera.h"
#include "map.h"

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace cc
{
enum GameState { PLAYING, PAUSED, GAMEOVER, READY };

class Game
{
public:
    Game(const std::string& name, int width, int height);
    ~Game();

private:
    void init();
    void deinit();
    void loadMedia();

public:
    SDL_Window* getWindow();
    SDL_Renderer* getRenderer();
    TTF_Font* getFont();
    const Camera& getCamera() const;

public:
    void handleEvents();
    void update();
    void render();
    void execute();

public:
    void moveCamera(int x, int y);

private:
    std::string _name;
    int _width;
    int _height;

    SDL_Window* _window;
    SDL_Renderer* _renderer;
    TTF_Font* _font;

    bool _quit;

    Camera _camera;

    Map* _map;
};
};

#endif