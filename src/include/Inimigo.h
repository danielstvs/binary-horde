#pragma once

#include "Jogador.h"
#include "raylib.h"
#include <stdbool.h>

typedef struct Inimigo {
    Vector2 posicao;
    //Vector2 direcao;    // CASO UTILIZAR A FUNÇÃO DA RAYLIB PARA MOVER PERSONAGEM, RETIRAR ESSE ATRIBUTO, POIS AINDA NÃO É UTILIZADO EM OUTRA FUNÇÃO.
    Vector2 dimensao;
    float velocidade;
    bool ativo;
    Color cor;
} Inimigo;

/**
 * @brief Cria a instância do Inimigo.
 * 
 * @param dimensao  Tamanho do inimigo.
 * @param cor       Cor do inimigo.
 * @return Inimigo 
 */
Inimigo criarInimigo( Vector2 dimensao, Vector2 posicaoJogador, Color cor ); // DEVE RECEBER COMO PARAMETRO SOMENTE QUAL DEVERÁ SER O INIMIGO CRIADO

/**
 * @brief Atualiza os atributos do inimigo.
 * 
 * @param inimigo Endereço do inimigo.
 * @param jogador Endereço do inimigo.
 * @param delta Tempo que o ultimo quadro do jogo levou para ser desenhado. 
 */
void atualizarInimigo( Inimigo *inimigo, Jogador *jogador, float delta );

/**
 * @brief Desenha o inimigo na tela.
 * 
 * @param inimigo Endereço do inimigo.
 */
void desenharInimigo( Inimigo *inimigo );