#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <time.h>
#include <windows.h>

int PlayMusic();

int die(const char *message)
{
    SDL_Log("%s %s", message, SDL_GetError);
    return 1;
}

int end()
{
    SDL_Quit();
    return 0;
}
int Win(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 340, 340);
    if (!texture)
    {
        return die("unable to create texture");
    }
    Uint8 *pixels = NULL;
    int pitch = 0;

    if (SDL_LockTexture(texture, NULL, (void **)&pixels, &pitch))
    {
        return die("unable to map texture inside address space");
    }
    int width, height, comp;

    unsigned char *image = stbi_load("win.png", &width, &height, &comp, 4);
    if (!image)
    {
        return die("unable to load image");
    }

    memcpy(pixels, image, pitch * 340);
    free(image);
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    uint32_t delay = 2000;
    SDL_Delay(delay);
    return end();
}
int YourTurn(SDL_Renderer *renderer, uint32_t delay)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 170, 170);
    if (!texture)
    {
        return die("unable to create texture");
    }
    Uint8 *pixels = NULL;
    int pitch = 0;

    if (SDL_LockTexture(texture, NULL, (void **)&pixels, &pitch))
    {
        return die("unable to map texture inside address space");
    }
    int width, height, comp;

    unsigned char *image = stbi_load("icon.png", &width, &height, &comp, 4);
    if (!image)
    {
        return die("unable to load image");
    }

    memcpy(pixels, image, pitch * 170);
    free(image);
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    SDL_Delay(delay);
    return 0;
}
int PcTurn(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 480, 480);
    if (!texture)
    {
        return die("unable to create texture");
    }
    Uint8 *pixels = NULL;
    int pitch = 0;

    if (SDL_LockTexture(texture, NULL, (void **)&pixels, &pitch))
    {
        return die("unable to map texture inside address space");
    }
    int width, height, comp;

    unsigned char *image = stbi_load("pc.png", &width, &height, &comp, 4);
    if (!image)
    {
        return die("unable to load image");
    }

    memcpy(pixels, image, pitch * 480);
    free(image);
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    uint32_t delay = 2000;
    SDL_Delay(delay);
    return 0;
}

int Lose(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 480, 480);
    if (!texture)
    {
        return die("unable to create texture");
    }
    Uint8 *pixels = NULL;
    int pitch = 0;

    if (SDL_LockTexture(texture, NULL, (void **)&pixels, &pitch))
    {
        return die("unable to map texture inside address space");
    }
    int width, height, comp;

    unsigned char *image = stbi_load("lose.png", &width, &height, &comp, 4);
    if (!image)
    {
        return die("unable to load image");
    }

    memcpy(pixels, image, pitch * 480);
    free(image);
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    PlayMusic();
    
    return end();
}

int PlayAndColorGreen(SDL_Renderer *renderer, const SDL_Rect *rect)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);
    Beep(523,500); 
    uint32_t delay = 300;
    SDL_Delay(delay);

    SDL_SetRenderDrawColor(renderer, 0, 230, 0, 0);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);

    delay = 300;
    SDL_Delay(delay);

    return 0;
}

int PlayAndColorRed(SDL_Renderer *renderer, const SDL_Rect *rect)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);
    Beep(784,500); 
    uint32_t delay = 300;
    SDL_Delay(delay);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);

    delay = 300;
    SDL_Delay(delay);

    return 0;
}

int PlayAndColorPink(SDL_Renderer *renderer, const SDL_Rect *rect)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);
    Beep(698,500); 
    uint32_t delay = 300;
    SDL_Delay(delay);

    SDL_SetRenderDrawColor(renderer, 255, 20, 147, 0);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);

    delay = 300;
    SDL_Delay(delay);

    return 0;
}

int PlayAndColorBlue(SDL_Renderer *renderer, const SDL_Rect *rect)
{

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);
    Beep(659,500); 
    uint32_t delay = 300;
    SDL_Delay(delay);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);

    delay = 300;
    SDL_Delay(delay);

    return 0;
}



int PlayMusic()
{
    //AUDIO
    SDL_AudioDeviceID dev;
    SDL_AudioSpec want, have;
    SDL_memset(&want, 0, sizeof(want));
    want.freq = 44100;
    want.format = AUDIO_S16;
    want.channels = 2;
    want.samples = 4096;
    want.callback = 0;


    for (size_t i = 0; i < SDL_GetNumAudioDevices(0); i++)
    {
        const char *audioDevice = SDL_GetAudioDeviceName(i, 0);
        printf("nome audioDevice = %s\n", audioDevice);
    }

    dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);

    if (dev == 0)
    {
        SDL_Log("Failed to open audio: %s", SDL_GetError());
    }
    else
    {

        if (have.format != want.format)
        {
            SDL_Log("Failed to open audio: %s", SDL_GetError());
        }
    }

    SDL_AudioSpec spec;
    Uint8 *audio_buf;
    Uint32 audio_len;
    SDL_AudioSpec *data = SDL_LoadWAV("C:/Users/Lyno9/Desktop/aiv/C/simon/Registrazione.WAV", &spec, &audio_buf, &audio_len);
    int16_t *audio0 = (int16_t *)audio_buf;

    SDL_QueueAudio(dev, audio0, audio_len);
    SDL_PauseAudioDevice(dev, 0);
    uint32_t delay = 5000;
    SDL_Delay(delay);
    
    return 0;
}




int main(int argc, char **argv)
{

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO))
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("Game", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (!window)
    {
        return die("unable to create window");
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        return die("unable to create renderer");
    }

    if (SDL_NumJoysticks() > 0)
    {
        for (size_t i = 0; i < SDL_NumJoysticks(); i++)
        {
            const char *controller = SDL_GameControllerNameForIndex(i);
            printf("nome joystick = %s\n", controller);
        }
    }
    else
    {
        return die("unable to find Controller");
    }

    SDL_GameController *joy = SDL_GameControllerOpen(0);

    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 128, 128);
    if (!texture)
    {
        return die("unable to create texture");
    }

    SDL_Event event;

    SDL_Rect green;
    green.x = 256;
    green.y = 10;
    green.w = 128;
    green.h = 128;

    SDL_Rect pink;
    pink.x = 80;
    pink.y = 165;
    pink.w = 128;
    pink.h = 128;

    SDL_Rect blue;
    blue.x = 256;
    blue.y = 320;
    blue.w = 128;
    blue.h = 128;

    SDL_Rect red;
    red.x = 430;
    red.y = 165;
    red.w = 128;
    red.h = 128;

    int8_t playerIndex = 0;
    int8_t playerRound = 0;
    int8_t lenght = 1;
    int8_t computerSequence[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
    int8_t PlayerSequence[10] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5};

    for (;;)
    {

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 230, 0, 0);
        SDL_RenderFillRect(renderer, &green);

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
        SDL_RenderFillRect(renderer, &blue);

        SDL_SetRenderDrawColor(renderer, 255, 20, 147, 0);
        SDL_RenderFillRect(renderer, &pink);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
        SDL_RenderFillRect(renderer, &red);

        SDL_RenderPresent(renderer);

        if (playerRound == 0)
        {
            uint32_t delay = 500;
            SDL_Delay(delay);
        }

        if (playerRound == 1)
        {

            SDL_GameControllerRumble(joy, 10000, 10000, 1000);

            uint32_t playerDelay = 100;

            Uint8 ics = SDL_GameControllerGetButton(joy, SDL_CONTROLLER_BUTTON_A);
            Uint8 triangolo = SDL_GameControllerGetButton(joy, SDL_CONTROLLER_BUTTON_Y);
            Uint8 quadrato = SDL_GameControllerGetButton(joy, SDL_CONTROLLER_BUTTON_X);
            Uint8 cerchio = SDL_GameControllerGetButton(joy, SDL_CONTROLLER_BUTTON_B);

            if (triangolo)
            {
                PlayerSequence[playerIndex] = 0;
                SDL_Delay(playerDelay);
                PlayAndColorGreen(renderer, &green);

                if (PlayerSequence[playerIndex] == computerSequence[playerIndex])
                {
                    playerIndex++;
                }
                else
                {
                    return Lose(renderer);
                }
            }

            if (ics)
            {
                PlayerSequence[playerIndex] = 3;
                PlayAndColorBlue(renderer, &blue);

                if (PlayerSequence[playerIndex] == computerSequence[playerIndex])
                {
                    playerIndex++;
                }
                else
                {
                    return Lose(renderer);
                }
            }

            if (cerchio)
            {
                PlayerSequence[playerIndex] = 1;
                SDL_Delay(playerDelay);
                PlayAndColorRed(renderer, &red);

                if (PlayerSequence[playerIndex] == computerSequence[playerIndex])
                {
                    playerIndex++;
                }
                else
                {
                    return Lose(renderer);
                }
            }

            if (quadrato)
            {
                PlayerSequence[playerIndex] = 2;
                PlayAndColorPink(renderer, &pink);

                if (PlayerSequence[playerIndex] == computerSequence[playerIndex])
                {
                    playerIndex++;
                }
                else
                {
                    return Lose(renderer);
                }
            }

            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    return end();
                }
            }

            if (computerSequence[playerIndex] == 5)
            {
                if (lenght < 10)
                {
                    lenght++;
                    playerRound = 0;
                    PcTurn(renderer);
                }
            }
            if (playerIndex >= 10)
            {
                Win(renderer);
            }
        }
        else if (playerRound == 0)
        {

            if (computerSequence[9] == 5)
            {
                srand(time(0));
                for (int i = lenght - 1; i < lenght; i++)
                {
                    computerSequence[i] = rand() % 4;
                }

                for (int i = 0; i < 10; i++)
                {
                    switch (computerSequence[i])
                    {

                    case 0: //se il numero scelto è 0 esegui questo caso
                        PlayAndColorGreen(renderer, &green);
                        break;

                    case 1:
                        PlayAndColorRed(renderer, &red);
                        break;

                    case 2:
                    {
                        PlayAndColorPink(renderer, &pink);
                        break;

                        break;
                    }
                    case 3:
                        PlayAndColorBlue(renderer, &blue);
                        break;

                    default:
                        playerRound = 1;
                        playerIndex = 0;
                        YourTurn(renderer, 200);
                        break;
                    }
                }
            }
            else
            {
                playerRound = 1;
                playerIndex = 0;
                YourTurn(renderer, 700);
            }
            
        }
    }
}