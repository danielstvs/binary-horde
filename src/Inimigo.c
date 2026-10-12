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
        .ativo = true
    } ;
}

/**
 *  Move o inimigo em direção ao personagem.
 *  A direção do movimento é o cálculo normalizado da distância das coordenadas x e y dos centros
 *  dos elementos: direçãoMovimento = Normalizar( centroJogador - centroInimigo )
 * 
 *  Cálculo do centro do elemento: centro = posicaoElemento + tamanhoElemento / 2.
 */
void atualizarInimigo( Inimigo *inimigo, Jogador *jogador, float delta ) {
    inimigo->direcao = Vector2Normalize( 
        Vector2Subtract( 
            Vector2Add( 
                jogador->posicao, Vector2Scale( jogador->dimensao, 0.5f ) ), // Centro do personagem
            Vector2Add( 
                inimigo->posicao, Vector2Scale(inimigo->dimensao, 0.5f ) )   // Centro do inimigo      
        ) 
    );
    inimigo->posicao.x += inimigo->direcao.x * inimigo->velocidade * delta;
    inimigo->posicao.y += inimigo->direcao.y * inimigo->velocidade * delta;
}

/**
 * @brief Desenha inimigo na tela.
 * 
 * @param inimigo Endereço do inimigo;
 */
void desenharInimigo( Inimigo *inimigo ){
    DrawRectangle(
        inimigo->posicao.x,
        inimigo->posicao.y,
        inimigo->dimensao.x,
        inimigo->dimensao.y,
        inimigo->cor
    );
}