#pragma once

#include <stdbool.h>
#include "Jogador.h"
#include "raylib.h"

typedef struct Inimigo {
    Vector2 posicao;
    Vector2 direcao;    // CASO UTILIZAR A FUNÇÃO DA RAYLIB PARA MOVER PERSONAGEM, RETIRAR ESSE ATRIBUTO, POIS AINDA NÃO É UTILIZADO EM OUTRA FUNÇÃO.
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
Inimigo criarInimigo( Vector2 dimensao, Color cor ); // DEVE RECEBER COMO PARAMETRO SOMENTE QUAL DEVERÁ SER O INIMIGO CRIADO

/**
 * @brief Calcula uma posição aleatória fora da visão da câmera.
 * 
 * @return Vector2      Retorna um ponto (x,y) na circunferência.
 */
Vector2 calcularPosicao( void );

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