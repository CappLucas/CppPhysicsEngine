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

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
  //rectangle from object class.
  Object drawrect{"FirstRect","Rectangle",{{10,10},{20,30}}};

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create a resizable SDL window
    SDL_Window* window = SDL_CreateWindow("Resizable SDL2 Window with Blue Rectangle",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Create an SDL renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Set the draw color to blue (RGB: 0, 0, 255)
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue color

    // Define the blue rectangle's dimensions and position
    int x = int(drawrect.objectRectangle->getLeftX());
    int y = int(drawrect.objectRectangle->getBottomY());
    int length = int(drawrect.objectRectangle->getLength());
    int height = int(drawrect.objectRectangle->getHeight());
    
    SDL_Rect blueRect = {10,30,40,100}; // x, y, width, height

    // Start the timer to wait for 1 minute
    Uint32 startTime = SDL_GetTicks(); // Get the current time in milliseconds
    Uint32 endTime = startTime + 60000; // Set end time to 60 seconds later (60000 milliseconds)

    // Main loop
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Poll for events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true; // Exit if the user closes the window
            }
        }

        // Clear the screen
        SDL_RenderClear(renderer);

        // Render the blue rectangle
        SDL_RenderFillRect(renderer, &blueRect);

        // Present the rendered content to the window
        SDL_RenderPresent(renderer);

        // Check if 60 seconds have passed
        if (SDL_GetTicks() >= endTime) {
            quit = true; // Exit the loop after 60 seconds
        }
    }

    // Clean up and close
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
