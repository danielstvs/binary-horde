#include "Jogo.h"
#include "Camera.h"
#include "ControleInimigos.h"
#include "ControleAtaques.h"
#include "Recursos.h"
#include "Util.h"

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

    Jogo *jogo = (Jogo*) calloc( sizeof( Jogo ), 1 );
    jogo->jogador = criarJogador();
    jogo->camera = criarCamera();
    jogo->velSuavidadeCamera = 8.0f;

    return jogo;
}

void atualizarJogo( Jogo *jogo, float delta ) {
    jogo->tempoDecorrido = GetTime();
    jogo->acumuladorNascInimigos += TAXA_INIMIGO_POR_SEGUNDO * delta;
    
    atualizarJogador( &jogo->jogador, delta );
    moverCamera( &jogo->camera, &jogo->jogador, jogo->velSuavidadeCamera, delta);
    gerarInimigos( jogo );
    atualizarArmasJogador( &jogo->jogador, jogo->projeteis, jogo->inimigo, delta );

    atualizarProjeteis( jogo->jogador.posicao, jogo->projeteis, delta );
    atualizaInimigosAtivos( jogo->inimigo, jogo->jogador.posicao, jogo->qtdInimigosAtivos, delta);
    
    // COLISOES TODAS!
    // MORTES
    // XP E LEVEL UP
}

void desenharJogo( Jogo *jogo ) {
    
    BeginDrawing();
    ClearBackground( WHITE );

    // FUNÇÕES DE MENU AQUI !

    BeginMode2D(jogo->camera);
        desenharProjeteis( jogo->projeteis );
        desenharJogador( &jogo->jogador );
        desenhaInimigosAtivos( jogo->inimigo, jogo->qtdInimigosAtivos );
    EndMode2D();

// LINHAS SOMENTE PARA TESTES
    // for(int i = 0; i < 7; i++ ){ //  linhas
    //     for(int j = 0; j < 5; j++ ){  // colunas
    //         DrawLine(0, j * 144, GetRenderWidth(), j * 144, GREEN); //  linha
    //         DrawLine(i * 182.8574, 0, i * 182.8574, GetRenderHeight(), GREEN);// coluna
    //     }
    // }
    DrawText(
        TextFormat( "Tempo: %.2f s\n"
                "Inimigos: %d\n"
                "Jogador: \nX = %.1f\nY = %.1f\n"
                "PV %.1f\n",
                jogo->tempoDecorrido,
                jogo->qtdInimigosAtivos,
                jogo->jogador.posicao.x, jogo->jogador.posicao.y,
                jogo->jogador.pontosVida),
        GetScreenWidth() - 200,
        5,
        20,
        BLACK
    );
    DrawText(TextFormat("%.2f",GetFrameTime() * 1000),100,20,20,BLACK);

    DrawFPS( 5, 5 );
    
    
    EndDrawing();

}

void destruirJogo( Jogo *jogo ) {
    free( jogo );
}