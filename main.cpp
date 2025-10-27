#include <C:\SDL2\SDL2-devel-2.32.6-mingw\SDL2-2.32.6\x86_64-w64-mingw32\include\SDL2\SDL.h>
#include <iostream>

using namespace std;

class PrimitivePainter {
    public:
    void draw_circle(SDL_Renderer* renderer, int centerx, int centery, int radius) {
        for (int y = -radius; y <= radius; y++) {
            for (int x = -radius; x <= radius; x++) {
                if (x*x + y*y <= radius*radius) {
                    SDL_RenderDrawPoint(renderer, centerx + x, centery + y);
                }
            }
        }
    }
};

int main(int argc, char* argv[]) {
    cout << "Hello, world!" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* win = SDL_CreateWindow("SDL2 Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 360, 0);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    SDL_Event e;

    PrimitivePainter painter = PrimitivePainter();

    bool running = true;
    while (running) {
        while (SDL_PollEvent(&e)) if (e.type == SDL_QUIT) running = false;
        
        // Clear screen first
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
        SDL_RenderClear(ren);
        
        // Set color for drawing and draw circle
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        painter.draw_circle(ren, 100, 100, 50);
        
        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
