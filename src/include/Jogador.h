#pragma once

#include "raylib.h"

#define JOGADOR_TAM 32
#define VELOCIDADE_INICIAL 100

typedef struct Jogador {
    Vector2 posicao;
    Vector2 direcao;
    Vector2 dimensao;
    Color cor;
    float velocidade;
} Jogador;

/**
 * @brief Cria a instância do jogador.
 * 
 * @return Retorna o elemento do tipo Jogador.
 */
Jogador criarJogador( void );

/**
 * @brief Lê os comandos de movimento do jogador.
 *
 */
void processarEntradaJogador( Jogador *jogador );

/**
 * @brief Atualiza os atributos do jogador.
 * 
 * @param jogador Endereço do jogador.
 * @param delta Tempo que o ultimo quadro do jogo levou para ser desenhado. 
 */
void atualizarJogador( Jogador *jogador, float delta );

/**
 * @brief Desenha o jogador na tela.
 * 
 * @param jogador Endereço do jogador.
 */
void desenharJogador( Jogador *jogador );