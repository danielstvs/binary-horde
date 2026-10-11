#pragma once

#include "Jogador.h"
#include "raylib.h"

#define VELOCIDADE_INICIAL_INIMIGO 60

typedef struct Inimigo {
    Vector2 posicao;
    Vector2 direcao;
    Vector2 dimensao;
    Color cor;
    float velocidade;
} Inimigo;

/**
 * @brief Cria a instância do Inimigo.
 * 
 * @param posicao   Coordenadas x e y do inimigo.
 * @param direcao   Target do movimento, se move na direção do jogador.
 * @param dimensao  Tamanho do inimigo.
 * @param cor       Cor do inimigo.
 * @return Inimigo 
 */
Inimigo criarInimigo( Vector2 posicao, Vector2 direcao, Vector2 dimensao, Color cor );

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