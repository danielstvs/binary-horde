#pragma once

#include <stdbool.h>
#include "Jogo.h"

typedef struct Janela {

    int width;
    int height;
    const char *title;

    int targetFPS;
    bool antialiasing;
    bool resizable;
    bool fullScreen;
    bool undecorated;
    bool alwaysOnTop;
    bool invisibleBackground;
    bool alwaysRun;
    bool loadResources;
    bool initAudio;

    Jogo *jogo;

    bool initialized;

} Janela;

/**
 * @brief Cria uma instância da struct Janela alocada dinamicamente.
 */
Janela *criarJanela(
        int width, 
        int height, 
        const char *title, 
        int targetFPS,
        bool antialiasing, 
        bool resizable, 
        bool fullScreen,
        bool undecorated, 
        bool alwaysOnTop, 
        bool invisibleBackground, 
        bool alwaysRun, 
        bool loadResources, 
        bool initAudio 
);

/**
 * @brief Inicializa a Janela, começa o loop de jogo e, quando termina, a janela será finalizada e também destruída.
 */
void inicializarJanela( Janela *janela );

/**
 * @brief Destroi o objeto Janela e suas dependências.
 */
void destruirJanela( Janela *janela );