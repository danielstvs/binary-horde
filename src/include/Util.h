#pragma once

#include "raylib.h"
#include "raymath.h"

/**
 * @brief Calcula uma posição aleatória fora da visão da câmera.
 * Para gerar inimigos fora da visão do jogador.
 * 
 * @return Vector2      Retorna um ponto (x,y) na circunferência.
 */
Vector2 calcularPosicaoCircunferencia( void );