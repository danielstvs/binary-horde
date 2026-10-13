#pragma once

#include "Jogador.h"
#include "raylib.h"

/**
 * @brief Cria uma intância da câmera e inicializa seus atributos.
 * 
 * @return Camera2D
 */
Camera2D criarCamera( void );

/**
 * @brief Move o foco da camera para seguir o centro do jogador. 
 * 
 * @param camera Endereço da camera.
 * @param jogador Endereço do jogador.
 * @param velSuavidadeCamera Atribudo do Jogo que define quão suave será o movimento da camera.
 * @param delta 
 */
void moverCamera( Camera2D *camera, Jogador *jogador, float velSuavidadeCamera, float delta);