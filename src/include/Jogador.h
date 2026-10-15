#pragma once

#include "raylib.h"

typedef struct Jogo Jogo;   //forward declaration.
//  Estava causando problemas de inclusão circulares
//  RESOLVER DEPOIS !!

typedef struct Jogador {
    Vector2 posicao;
    Vector2 direcao;
    Vector2 dimensao;
    Color cor;
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
 * @brief Lê os comandos de movimento do jogador.
 *
 */
void processarEntradaJogador( Jogador *jogador );

void movimentarJogador( Jogador *jogador, float delta );

void verificarColisaoJogador( Jogo *jogo, float delta );

/**
 * @brief Atualiza os atributos do jogador.
 * 
 * @param jogador Endereço do jogador.
 * @param delta Tempo que o ultimo quadro do jogo levou para ser desenhado. 
 */
void atualizarJogador( Jogo *jogo, float delta );

void desenharPV( Jogador *jogador );

/**
 * @brief Desenha o jogador na tela.
 * 
 * @param jogador Endereço do jogador.
 */
void desenharJogador( Jogador *jogador );