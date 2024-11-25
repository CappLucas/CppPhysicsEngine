// file used for testing the features

#include <iostream>

#include "Object.h"
#include "ObjectManager.h"
#include "PhysicsEquations.h"
#include "Types.h"
#include "BoundingBox.h"
#include "CollisionDetectionManager.h"
#include "PhysicsEquations.h"
#include "Circle.h"
#include "Rectangle.h"

#include <SDL2/SDL.h>
#include <iostream>
#define SDL_MAIN_HANDLED

int main(int argc, char* argv[]){
    int width = 1024;
    int height = 800;

    SDL_Window* window = SDL_CreateWindow("Physics Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

    
}
