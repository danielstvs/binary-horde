#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

#include "Jogo.h"
#include "Recursos.h"

/**
 * @brief Cria uma instância da struct Jogo alocada dinamicamente.
 * 
 * @return Jogo* Ponteiro para o jogo criado ou NULL se falhar.
 */
Jogo *criarJogo( void ) {

    Jogo *jogo = (Jogo*) malloc( sizeof( Jogo ) );

    jogo->jogador = criarJogador(
        (Vector2) { 
            GetScreenWidth() / 2,
            GetScreenHeight() / 2 
        },
        (Vector2) { 0, 0 },
        (Vector2) { 32, 32 },
        BLUE
    );

    return jogo;
}

/**
 * @brief Distroi o objeto Jogo e suas dependências.
 */
void destruirJogo( Jogo *jogo ) {
    free( jogo );
}

/**
 * @brief Lê os comandos do usuário e atualiza o estado do jogo. 
 * 
 */
void atualizarJogo( Jogo *jogo, float delta ) {
    processarEntradaJogador( &jogo->jogador );
    atualizarJogador( &jogo->jogador, delta);
}

/**
 * @brief Desenha o estado atual do jogo.
 */
void desenharJogo( Jogo *jogo ) {

    BeginDrawing();
    ClearBackground( WHITE );

    desenharJogador( &jogo->jogador );

    DrawFPS( 10, 10 );

    EndDrawing();

}