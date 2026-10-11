#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

#include "Jogo.h"
#include "Recursos.h"

Jogo *criarJogo( void ) {

    Jogo *jogo = (Jogo*) malloc( sizeof( Jogo ) );

    jogo->jogador = criarJogador(
        (Vector2) { 
            GetScreenWidth() / 2,
            GetScreenHeight() / 2 
        },
        (Vector2) { 0.0f, 0.0f },
        (Vector2) { 32, 32 },
        BLUE
    );
    
    jogo->inimigo = criarInimigo(
        (Vector2) { 
            GetScreenWidth() - 30,
            GetScreenHeight() - 30 
        },
        (Vector2) { 0.0f, 0.0f },
        (Vector2) { 16, 16 },
        RED
    );

    return jogo;
}

void destruirJogo( Jogo *jogo ) {
    free( jogo );
}

void atualizarJogo( Jogo *jogo, float delta ) {
    processarEntradaJogador( &jogo->jogador );
    atualizarJogador( &jogo->jogador, delta);
    atualizarInimigo( &jogo->inimigo, &jogo->jogador, delta);
}

void desenharJogo( Jogo *jogo ) {

    BeginDrawing();
    ClearBackground( WHITE );

    desenharInimigo( &jogo->inimigo );
    desenharJogador( &jogo->jogador );

    DrawFPS( 10, 10 );

    EndDrawing();

}