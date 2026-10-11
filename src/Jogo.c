#include <stdio.h>
#include <stdlib.h>

//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h
#include "Jogo.h"
#include "Recursos.h"
#include "raymath.h"

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

    jogo->camera = criarCamera( &jogo->jogador );
    jogo->velSuavidadeCamera = VEL_SUAVIDADE_CAMERA;

    return jogo;
}

Camera2D criarCamera( Jogador *jogador ) {
    return (Camera2D){
        .target = Vector2Zero(),
        .offset = (Vector2){
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f,
        },
        .rotation = 0.0f,
        .zoom = 1.0f
    };
}
/**
 *  Move o foco da camera para o centro do jogador de forma suave.
 */
void moverCamera( Camera2D *camera, Jogador *jogador, float velSuavidadeCamera, float delta) {
    camera->target = Vector2Lerp( 
        camera->target, 
        Vector2Add( jogador->posicao, jogador->dimensao ), 
        velSuavidadeCamera * delta
    );
}

void destruirJogo( Jogo *jogo ) {
    free( jogo );
}

void atualizarJogo( Jogo *jogo, float delta ) {
    processarEntradaJogador( &jogo->jogador );
    atualizarJogador( &jogo->jogador, delta);
    atualizarInimigo( &jogo->inimigo, &jogo->jogador, delta);
    moverCamera( &jogo->camera, &jogo->jogador, jogo->velSuavidadeCamera, delta);
}

void desenharJogo( Jogo *jogo ) {

    BeginDrawing();
    ClearBackground( WHITE );

    BeginMode2D(jogo->camera);
        desenharJogador( &jogo->jogador );
        desenharInimigo( &jogo->inimigo );
    EndMode2D();

    DrawFPS( 5, 5 );

    EndDrawing();

}