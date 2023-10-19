#include <SDL2/SDL.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
// Function to draw the fractal tree
void draw(SDL_Renderer *renderer, int x1, int y1, float angle, int depth) {
    if (depth == 0) return;

    int x2 = x1 + (int)(cos(angle * M_PI / 180) * depth * 10.0);
    int y2 = y1 + (int)(sin(angle * M_PI / 180) * depth * 10.0);

    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

    draw(renderer, x2, y2, angle - 30, depth - 1);
    draw(renderer, x2, y2, angle + 30, depth - 1);
}

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Call the draw function here
    draw(renderer, 400, 600, -90, 9);

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
