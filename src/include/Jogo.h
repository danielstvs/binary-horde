#pragma once

#include "Jogador.h"

typedef struct Jogo {
    Jogador jogador;
} Jogo;

/**
 * @brief Cria uma instância da struct Jogo alocada dinamicamente.
 * 
 * @return Jogo* Ponteiro para o jogo criado ou NULL se falhar.
 */
Jogo *criarJogo( void );

/**
 * @brief Distroi o objeto Jogo e suas dependências.
 */
void destruirJogo( Jogo *jogo );

/**
 * @brief Lê os comandos do usuário e atualiza o estado do jogo.
 */
void atualizarJogo( Jogo *jogo, float delta );

/**
 * @brief Desenha o estado atual do jogo.
 */
void desenharJogo( Jogo *jogo );