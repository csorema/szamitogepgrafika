#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL inicializálása sikertelen: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Egér pozíció kiolvasása",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Az ablak létrehozása sikertelen: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;
    while (1) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
        }

        int x, y;
        SDL_GetMouseState(&x, &y);

        printf("Egér pozíció: x = %d, y = %d\n", x, y);

        SDL_Delay(100);
    }

    return 0;
}