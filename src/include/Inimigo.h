#pragma once

#include <stdbool.h>
#include "Jogador.h"
#include "raylib.h"

typedef struct Inimigo {
    Vector2 posicao;
    Vector2 direcao;
    Vector2 dimensao;
    Color cor;
    float velocidade;
    bool ativo;
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
 * @brief Calcula uma posição aleatória fora da visão da câmera.
 * 
 * @param centroTela    A posição do centro da tela (x,y).
 * @param raio          Metade da diagonal da tela.
 * @return Vector2      Retorna um ponto (x,y) na circunferência.
 */
Vector2 calcularPosicao( Vector2 centroTela, float raio );

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