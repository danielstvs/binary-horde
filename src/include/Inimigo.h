#pragma once

#include "raylib.h"
#include <stdbool.h>

typedef struct Jogador Jogador;

typedef struct Inimigo {
    int idInimigo;
    Vector2 posicao;
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
Inimigo criarInimigo( Vector2 dimensao, Vector2 posicaoJogador, float velocidade, Color cor ); // A FUNÇÃO DE CONTROLE DE INIMIGOS DEVE INFORMAR QUAIS PARAMETROS PARA GERAR O TIPO DE ININMIGO DE ACORDO COM A DIFICULDADE.

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