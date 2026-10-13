#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h
#include"raylib.h"
#include "raymath.h"
#include "Jogo.h"
#include "Recursos.h"

Jogo *criarJogo( void ) {

    Jogo *jogo = (Jogo*) malloc( sizeof( Jogo ) );

    jogo->jogador = criarJogador(
        (Vector2) { 
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f 
        },
        (Vector2) { 0.0f, 0.0f },
        (Vector2) { 32, 32 },
        BLUE
    );
    
    memset( jogo->inimigo, 0, sizeof( jogo->inimigo ) );
    jogo->qtdInimigosAtivos = 0;

    jogo->camera = criarCamera( &jogo->jogador );
    jogo->velSuavidadeCamera = SUAVIDADE_CAMERA;
    
    jogo->tempoDecorrido = 0.0f;

    return jogo;
}

Camera2D criarCamera( Jogador *jogador ) {
    return (Camera2D){
        .target = (Vector2){
            jogador->posicao.x + ( jogador->dimensao.x / 2.0f ),
            jogador->posicao.y + ( jogador->dimensao.y / 2.0f )
        },
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
        (Vector2){  // Calcula o centro do personagem no quadro atual.
            jogador->posicao.x + ( jogador->dimensao.x / 2.0f ),
            jogador->posicao.y + ( jogador->dimensao.y / 2.0f )
        },
        velSuavidadeCamera * delta
    );
}

void percorerCriarInimigos(Jogo *jogo) {
  for (int i = 0; i < QTD_MAX_INIMIGOS; i++) {
    if ( !jogo->inimigo[i].ativo ) {
        jogo->inimigo[i] = criarInimigo(
            (Vector2){ GetScreenWidth() - 30 - 10 * i, GetScreenHeight() - 30 - 10 * i},
            (Vector2){0.0f, 0.0f}, 
            (Vector2){16, 16}, 
            RED
        );
        jogo->qtdInimigosAtivos += 1;
    }
  }
}

void percorrerAtualizarInimigos( Jogo *jogo, float delta ) {
    for ( int i = 0; i < QTD_MAX_INIMIGOS; i++ ) {
        if ( jogo->inimigo[i].ativo )
            atualizarInimigo( &jogo->inimigo[i], &jogo->jogador, delta );
    }
}

void percorrerDesenharInimigos( Jogo *jogo ) {
    for ( int i = 0; i < QTD_MAX_INIMIGOS; i++ ) {
        if ( jogo->inimigo[i].ativo )
            desenharInimigo( &jogo->inimigo[i] );
    }
}

void atualizarJogo( Jogo *jogo, float delta ) {
    percorerCriarInimigos( jogo );
    processarEntradaJogador( &jogo->jogador );
    atualizarJogador( &jogo->jogador, delta);
    percorrerAtualizarInimigos( jogo, delta);
    moverCamera( &jogo->camera, &jogo->jogador, jogo->velSuavidadeCamera, delta);
}

void desenharJogo( Jogo *jogo ) {

    BeginDrawing();
    ClearBackground( WHITE );

    // FUNÇÕES DE MENU AQUI!

    BeginMode2D(jogo->camera);
        desenharJogador( &jogo->jogador );
        percorrerDesenharInimigos( jogo );
    EndMode2D();
    
    // Linhas para testes, depois tirar
    DrawLine(0, GetRenderHeight() / 2.0f, GetRenderWidth(), GetRenderHeight() / 2.0f, GREEN);
    DrawLine(GetRenderWidth() / 2.0f, 0, GetRenderWidth() / 2.0f, GetRenderHeight(), GREEN);

    DrawFPS( 5, 5 );

    EndDrawing();

}

void destruirJogo( Jogo *jogo ) {
    free( jogo );
}