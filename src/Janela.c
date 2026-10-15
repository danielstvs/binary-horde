#include "Janela.h"
#include "Recursos.h"

#include "raylib.h"

#include <stdlib.h>

/**
 * @brief Cria uma instância da struct Janela alocada dinamicamente.
 * 
 * @return Janela* Ponteiro para a janela criada ou NULL se falhar.
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
        bool initAudio ) {

    Janela *janela = (Janela*) malloc( sizeof( Janela ) );

    janela->width = width;
    janela->height = height;
    janela->title = title;
    janela->targetFPS = targetFPS;
    janela->antialiasing = antialiasing;
    janela->resizable = resizable;
    janela->fullScreen = fullScreen;
    janela->undecorated = undecorated;
    janela->alwaysOnTop = alwaysOnTop;
    janela->invisibleBackground = invisibleBackground;
    janela->alwaysRun = alwaysRun;
    janela->loadResources = loadResources;
    janela->initAudio = initAudio;
    janela->jogo = NULL;
    janela->initialized = false;

    return janela;

}

/**
 * @brief Inicializa a Janela, começa o loop de jogo e, quando termina, a janela será finalizada e também destruída.
 */
void inicializarJanela( Janela *janela ) {

    if ( !janela->initialized ) {

        janela->initialized = true;

        if ( janela->antialiasing ) {
            SetConfigFlags( FLAG_MSAA_4X_HINT );
        }

        if ( janela->resizable ) {
            SetConfigFlags( FLAG_WINDOW_RESIZABLE );
        }

        if ( janela->fullScreen ) {
            SetConfigFlags( FLAG_FULLSCREEN_MODE );
        }

        if ( janela->undecorated ) {
            SetConfigFlags( FLAG_WINDOW_UNDECORATED );
        }

        if ( janela->alwaysOnTop ) {
            SetConfigFlags( FLAG_WINDOW_TOPMOST );
        }

        if ( janela->invisibleBackground ) {
            SetConfigFlags( FLAG_WINDOW_TRANSPARENT );
        }

        if ( janela->alwaysRun ) {
            SetConfigFlags( FLAG_WINDOW_ALWAYS_RUN );
        }

        InitWindow( janela->width, janela->height, janela->title );

        if ( janela->initAudio ) {
            InitAudioDevice();
        }

        SetTargetFPS( janela->targetFPS );    

        if ( janela->loadResources ) {
            loadResourcesResourceManager();
        }

        janela->jogo = criarJogo();

        // loop de jogo
        while ( !WindowShouldClose() ) {

            // The delta time is capped at 1/30s to prevent excessively long
            // frames (e.g.: slowness during initialization) from causing
            // large displacements that make characters pass through
            // obstacles (tunneling)
            float delta = GetFrameTime();
            if ( delta > 1.0f / 30.0f ) {
                delta = 1.0f / 30.0f;
            }

            atualizarJogo( janela->jogo, delta );
            desenharJogo( janela->jogo );
            
        }

        if ( janela->loadResources ) {
            unloadResourcesResourceManager();
        }

        if ( janela->initAudio ) {
            CloseAudioDevice();
        }

        destruirJanela( janela );
        CloseWindow();

    }

}

/**
 * @brief Destroi o objeto Janela e suas dependências.
 */
void destruirJanela( Janela *janela ) {
    if ( janela != NULL ) {
        destruirJogo( janela->jogo );
        free( janela );
    }
}