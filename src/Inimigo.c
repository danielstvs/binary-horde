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

/**
 * Move o centro do inimigo em direção ao centro personagem utilizando
 * a função da biblioteca raylib Vector2MoveTowards. A função Vector2Subtract
 * somente ajusta para que o centro do inimigo busque o centro do personagem.
 */
void atualizarInimigo( Inimigo *inimigo, Vector2 posJogador, float delta ) {
    inimigo->posicao = 
        Vector2MoveTowards(
            inimigo->posicao, 
            posJogador, 
            inimigo->velocidade * delta 
        );
    // inimigo->posicao = Vector2Subtract(
    //     Vector2MoveTowards(
    //         Vector2Add( inimigo->posicao, Vector2Scale(inimigo->dimensao, 0.5f ) ),
    //         Vector2Add( jogador->posicao, Vector2Scale( jogador->dimensao, 0.5f ) ),
    //         inimigo->velocidade * delta
    //     ),
    //     Vector2Scale(inimigo->dimensao, 0.5f ));
}

/**
 * @brief Desenha inimigo na tela.
 * 
 * @param inimigo Endereço do inimigo;
 */
void desenharInimigo( Inimigo *inimigo ){
    DrawCircleV( 
        inimigo->posicao,
        inimigo->raio,
        RED
    );
}