#include "Inimigo.h"
#include "raymath.h"

Inimigo criarInimigo( 
    Vector2 posicao, 
    Vector2 direcao, 
    Vector2 dimensao, 
    Color cor ) {

    return (Inimigo){
        .posicao = posicao,
        .direcao = direcao,
        .dimensao = dimensao,
        .cor = cor,
        .velocidade = VELOCIDADE_INICIAL_INIMIGO,
    } ;
}

void atualizarInimigo( Inimigo *inimigo, Jogador *jogador, float delta ) {
    inimigo->direcao = Vector2Normalize( Vector2Subtract( jogador->posicao, inimigo->posicao ) );
    inimigo->posicao.x += inimigo->direcao.x * inimigo->velocidade * delta;
    inimigo->posicao.y += inimigo->direcao.y * inimigo->velocidade * delta;
}

void desenharInimigo( Inimigo *inimigo ){
    DrawRectangle(
        inimigo->posicao.x,
        inimigo->posicao.y,
        inimigo->dimensao.x,
        inimigo->dimensao.y,
        inimigo->cor
    );
}