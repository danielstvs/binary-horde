#pragma once

#include "raylib.h"
#include <stdbool.h>

#define TAM_INIMIGO 32

typedef struct Inimigo {
    Vector2 posicao;
    int idInimigo;
    float raio;
    float velocidade;
    float pontosVida;
    bool ativo;
} Inimigo;

Inimigo criarInimigo( Vector2 posJogador, float raio, float velocidade, float pontosVida, int id );

/**
 * @brief Atualiza os atributos do inimigo.
 * 
 * @param inimigo Endereço do inimigo.
 * @param jogador Endereço do inimigo.
 * @param delta Tempo que o ultimo quadro do jogo levou para ser desenhado. 
 */
void atualizarInimigo( Inimigo *inimigo, Vector2 posJogador, float delta );

/**
 * @brief Desenha o inimigo na tela.
 * 
 * @param inimigo Endereço do inimigo.
 */
void desenharInimigo( Inimigo *inimigo );