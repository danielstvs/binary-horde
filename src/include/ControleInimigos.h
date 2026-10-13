#pragma once

#include "Jogo.h"

/**
 * @brief Percorre o array até o fim e cria inimigos.
 * 
 * @param jogo 
 */
void criaInimigosAtivos(Jogo *jogo);

/**
 * @brief Percorre o array até o fim e atualiza os inimigos ativos.
 * 
 * @param jogo 
 * @param delta 
 */
void atualizaInimigosAtivos( Jogo *jogo, float delta );

/**
 * @brief Percorre o array até o fim e desenha inimigos ativos.
 * 
 * @param jogo 
 */
void desenhaInimigosAtivos( Jogo *jogo );