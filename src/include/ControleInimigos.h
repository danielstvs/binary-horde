#pragma once

#include "Jogo.h"

/**
 * @brief Verifica se o acumulador de inimigos a serem spawnados é
 * maior que 1 e se a quantidade de inimigos ativos é menor que a
 * quantidade máxima suportada. Se verdadeiro, insere a quantidade
 * inteira do acumulador por meio de um loop, e atualiza as variáveis.
 * 
 * @param jogo 
 */
void gerenciarNascInimigos( Jogo *jogo );

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