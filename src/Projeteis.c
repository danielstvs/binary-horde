#include "Projeteis.h"
#include "raymath.h"

void criarProjetil( Projetil *projetil, ArmaDoJogador *arma, Vector2 posJogador, Vector2 direcaoAlvo, float delta ) {
    for (int x = 0; x < QTD_MAX_PROJETEIS; x++) {
        if( !projetil[x].ativo ) {
            projetil[x] = (Projetil){
                .ativo = true,
                .dadosArma = (*arma),
                .raio = TAM_PROJETIL / 2,
                .posicao = posJogador,
                .direcao = direcaoAlvo
            };
            return;
        }
    }
}

void atualizarProjeteis( Vector2 posJogador, Projetil *projetil, float delta ) {
    for( int x = 0; x < QTD_MAX_PROJETEIS; x++ ) {
        if( projetil[x].ativo ){
            projetil[x].posicao.x += projetil[x].direcao.x * projetil[x].dadosArma.velocidade * delta;
            projetil[x].posicao.y += projetil[x].direcao.y * projetil[x].dadosArma.velocidade * delta;
            
            if( Vector2DistanceSqr( posJogador, projetil[x].posicao ) > 2000000.0f ) {
                projetil[x].ativo = false;
            }
        }
    }
}

void desenharProjeteis( Projetil *projetil ) {
    for( int x = 0; x < QTD_MAX_PROJETEIS; x++ ) {
        if( projetil[x].ativo ){
            DrawCircleV(
                projetil[x].posicao,
                projetil[x].raio,
                BLACK
            );
        }
    }
}