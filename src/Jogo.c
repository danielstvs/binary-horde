#include "Jogo.h"
#include "Camera.h"
#include "ControleInimigos.h"
#include "Recursos.h"

#include"raylib.h"
#include "raymath.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "raylib/raymath.h"
//#define RAYGUI_IMPLEMENTATION    // to use raygui, comment these three lines.
//#include "raylib/raygui.h"       // other compilation units must only include
//#undef RAYGUI_IMPLEMENTATION     // raygui.h

Jogo *criarJogo( void ) {

    Jogo *jogo = (Jogo*) malloc( sizeof( Jogo ) );
    jogo->jogador = criarJogador();
    jogo->camera = criarCamera();
    memset( jogo->inimigo, 0, sizeof( jogo->inimigo ) );
    jogo->qtdInimigosAtivos = 0;
    jogo->acumuladorNascInimigos = 0.0f;
    jogo->velSuavidadeCamera = 8.0f;
    jogo->tempoDecorrido = 0.0f;

    return jogo;
}

void atualizarJogo( Jogo *jogo, float delta ) {
    jogo->tempoDecorrido = GetTime();
    jogo->acumuladorNascInimigos += TAXA_POR_SEGUNDO * delta;
    
    gerenciarNascInimigos( jogo );
    processarEntradaJogador( &jogo->jogador );
    atualizarJogador( &jogo->jogador, delta);
    atualizaInimigosAtivos( jogo, delta);
    moverCamera( &jogo->camera, &jogo->jogador, jogo->velSuavidadeCamera, delta);
}

void desenharJogo( Jogo *jogo ) {
    
    BeginDrawing();
    ClearBackground( WHITE );

    // FUNÇÕES DE MENU AQUI !

    BeginMode2D(jogo->camera);
        desenharJogador( &jogo->jogador );
        desenhaInimigosAtivos( jogo );
    EndMode2D();

// LINHAS SOMENTE PARA TESTES
    DrawText(
        TextFormat( "Tempo: %.2f s\n\n   Inimigos: %d",
            jogo->tempoDecorrido, jogo->qtdInimigosAtivos),
        GetScreenWidth() / 2 - 75,
        20,
        20,
        BLACK
    );
    DrawLine(0, GetRenderHeight() / 2.0f, GetRenderWidth(), GetRenderHeight() / 2.0f, GREEN);
    DrawLine(GetRenderWidth() / 2.0f, 0, GetRenderWidth() / 2.0f, GetRenderHeight(), GREEN);

    DrawFPS( 5, 5 );

    EndDrawing();

}

void destruirJogo( Jogo *jogo ) {
    free( jogo );
}