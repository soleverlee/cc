#ifndef _CC_OBJECT_H_
#define _CC_OBJECT_H_

#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "point.h"
#include "camera.h"

namespace cc
{
class Object
{
public:
    Object(const std::string& name, SDL_Renderer* renderer);
    virtual ~Object();

public:
    static std::vector<Object*> objects;
    static std::vector<Object*> addedObjects;
    static void applyAdd();
    static void removeDead();
    static void removeAll();
    static void renderObjects(const Camera& camera);

public:
    virtual void remove();
    virtual void update(float deltaTime);
    virtual void render(const Camera& camera) = 0;

protected:
    std::string _name;
    bool _dead;
    float _speed;
    Point _position;

    SDL_Renderer* _renderer;
};
};
#endif