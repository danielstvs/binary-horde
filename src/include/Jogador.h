#pragma once

#include "ArmaDoJogador.h"

#include "raylib.h"

#define QTD_MAX_ARMAS_JOGADOR 6

typedef struct Jogo Jogo;

typedef struct Jogador {
    ArmaDoJogador armas[QTD_MAX_ARMAS_JOGADOR];
    Vector2 posicao;
    Vector2 direcao;
    int qtdArmasAtivas;
    float raio;
    float velocidade;
    float pontosVida;
    float tempoInvulneravel;
} Jogador;

/**
 * @brief Cria a instância do jogador.
 * 
 * @return Retorna o elemento do tipo Jogador.
 */
Jogador criarJogador( void );

/**
 * @brief Processa a os comandos de entrada, movimenta
 * o jogador e verifica colisões.
 * 
 * @param jogador
 * @param delta
 */
void atualizarJogador( Jogador *jogador, float delta );

/**
 * @brief Desenha o jogador na tela.
 * 
 * @param jogador
 */
void desenharJogador( Jogador *jogador );
void desenharPV( Jogador *jogador );