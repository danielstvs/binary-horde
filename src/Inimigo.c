#include "Inimigo.h"
#include "Util.h"
#include "raymath.h"

Inimigo criarInimigo(
    Vector2 posJogador,
    float raio,
    float velocidade,
    float pontosVida,
    int id ) {

    return (Inimigo){
        .idInimigo = id + 1,
        .posicao = calcularPosicaoCircunferencia( posJogador ),
        .raio = raio,
        .velocidade = velocidade,
        .pontosVida = pontosVida,
        .ativo = true
    };
}

void atualizarPosInimigo( Inimigo *inimigo, Vector2 posJogador, float delta ) {
    inimigo->posicao = 
        Vector2MoveTowards(
            inimigo->posicao, 
            posJogador, 
            inimigo->velocidade * delta 
        );
}

void desenharInimigo( Inimigo *inimigo ){
    DrawCircleV( 
        inimigo->posicao,
        inimigo->raio,
        RED
    );
    DrawText(
        TextFormat("%d", inimigo->idInimigo),
        inimigo->posicao.x,
        inimigo->posicao.y,
        10,
        BLACK
    );
}