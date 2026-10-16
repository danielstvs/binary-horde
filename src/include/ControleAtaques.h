#pragma once

/**
 * @file ControleAtaques.h
 * @brief Gerencia o ciclo de uso das instâncias. Percorre as armas equipadas,
 * atualiza seus temporizadores e decide quando executar o comportamento
 * definido para cada arma.
 * 
 */

#include "Jogo.h"

/**
 * @brief Percorre todo o arsenal do jogador e atualiza somente
 * as armas ativas.
 * 
 * @param jogador 
 * @param delta 
 */
void atualizarArmasJogador( Jogador *jogador, Projetil *projetil, Inimigo *inimigo, float delta );

/**
 * @brief Ciclo de disparo de uma arma.
 * 
 * @param arma 
 * @param jogador 
 * @param delta 
 */
void atualizarArma( ArmaDoJogador *arma, Jogador *jogador, Projetil *projetil, Inimigo *inimigo, float delta ) ;

bool disparar( ArmaDoJogador *arma, Jogador *jogador, Projetil *projetil, Inimigo *inimigos, float delta );

void ataqueDirecionado( ArmaDoJogador *arma, Projetil *projetil, Vector2 posJogador, Vector2 direcaoJogador, float delta );