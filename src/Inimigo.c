#include "Inimigo.h"
#include "Jogador.h"
#include "Util.h"
#include "raymath.h"

Inimigo criarInimigo(
    Vector2 dimensao, 
    Vector2 posicaoJogador,
    float velocidade,
    Color cor ) {

    return (Inimigo){
        .posicao = calcularPosicaoCircunferencia( posicaoJogador ),
        .dimensao = dimensao,
        .cor = cor,
        .velocidade = GetRandomValue( velocidade * 0.9f, velocidade * 1.10f ), // Velocidade pode ser até 10% menor ou maior.  Pensar se vale a pena trocar isso por uma variável que controla o multiplicador de MAX e MIN
        .ativo = true
    };
}

/**
 * Move o centro do inimigo em direção ao centro personagem utilizando
 * a função da biblioteca raylib Vector2MoveTowards. A função Vector2Subtract
 * somente ajusta para que o centro do inimigo busque o centro do personagem.
 */
void atualizarInimigo( Inimigo *inimigo, Jogador *jogador, float delta ) {
    inimigo->posicao = Vector2Subtract(
        Vector2MoveTowards(
            Vector2Add( inimigo->posicao, Vector2Scale(inimigo->dimensao, 0.5f ) ),
            Vector2Add( jogador->posicao, Vector2Scale( jogador->dimensao, 0.5f ) ),
            inimigo->velocidade * delta
        ),
        Vector2Scale(inimigo->dimensao, 0.5f )
    );
}

/**
 * @brief Desenha inimigo na tela.
 * 
 * @param inimigo Endereço do inimigo;
 */
void desenharInimigo( Inimigo *inimigo ){
    DrawRectangleV(
        inimigo->posicao,
        inimigo->dimensao,
        inimigo->cor
    );
}