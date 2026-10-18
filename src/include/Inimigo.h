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

/**
 * @brief Cria um novo inimigo com os parâmetros recebidos.
 * O número de id é o contador de inimigos ativos + 1.
 * 
 * @param posJogador Posição atual do jogador.
 * @param raio Raio do inimigo.
 * @param velocidade Velocidade do inimigo.
 * @param pontosVida Quantidade de pontos de vida do inimigo.
 * @param id Contador de inimigos ativos.
 * @return Inimigo
 */
Inimigo criarInimigo( Vector2 posJogador, float raio, float velocidade, float pontosVida, int id );

/**
 * @brief Atualiza a posição dos inimigos.
 * 
 * @param inimigo 
 * @param posJogador 
 * @param delta 
 */
void atualizarPosInimigo( Inimigo *inimigo, Vector2 posJogador, float delta );

/**
 * @brief Desenha o inimigo na tela.
 * 
 * @param inimigo
 */
void desenharInimigo( Inimigo *inimigo );