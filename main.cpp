#include <SDL2/SDL.h>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  SDL_Init(SDL_INIT_EVERYTHING);
  auto window = SDL_CreateWindow(
      "title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480,
      SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);

  auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  while (true) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
      break;

    SDL_SetRenderTarget(renderer, NULL);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect box{50, 50, 50, 50};
    SDL_RenderFillRect(renderer, &box);
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
