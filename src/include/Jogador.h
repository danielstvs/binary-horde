#pragma once

#include "raylib.h"

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
 * @param posicao       Coordenadas x e y do jogador.
 * @param direcao       Direção do jogador no eixo X e Y.
 * @param dimensao      Tamanho do jogador.
 * @param cor           Cor do jogador.
 * @param velocidade    Velocidade do movimento do jogador.
 * @return Retorna o elemento do tipo Jogador.
 */
Jogador criarJogador( Vector2 posicao, Vector2 direcao, Vector2 dimensao, Color cor );

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