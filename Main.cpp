//file used for testing the features
#include <iostream>

#include "Include/Header/ObjectManager.h"
#include "Include/Header/Object.h"
#include "Include/Header/PhysicsEquations.h"

// int main(){
//     ObjectManager myManager;
//     myManager.addObject("Buddy","Circle", {100,100}, 20);

//     myManager.printObjectInfo();

//     std::cout << findDisplacement(10,10,20);

//     return 0; 
// }
// g++ main.cpp -o sdl_example -IC:\\Libraries\\SDL2\\include\\SDL2 -LC:\\Libraries\\SDL2\\lib\\libSDL2.a -lSDL2

#include <C:/Libraries/SDL2/include/SDL2>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
//"C:\Libraries\SDL2\include\SDL2\SDL.h"
    // Create a window
    SDL_Window* window = SDL_CreateWindow("Working..", 
                                          SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED, 
                                          800, 600, 
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Wait for 3 seconds
    SDL_Delay(3000);

    // Clean up and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}