#pragma once

#include "Inimigo.h"
#include "raylib.h"
#include "raymath.h"

/**
 * @brief Calcula uma posição aleatória fora da visão da câmera.
 * Para gerar inimigos fora da visão do jogador.
 * 
 * @return Vector2      Retorna um ponto (x,y) na circunferência.
 */
Vector2 calcularPosicaoCircunferencia( Vector2 posAtualJogador );

void agruparInicioVetor( Inimigo *inimigo, int quantidadeVivos);

/**
 * @brief Calcula o centro de um retangulo.
 * 
 * @param retangulo 
 * @return Vector2 
 */
Vector2 centro2V(Vector2 pos, Vector2 tam);