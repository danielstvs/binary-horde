#pragma once

#include "Inimigo.h"
#include "Jogador.h"
#include "ControleColisoes.h"
#include "raylib.h"

#define QTD_MAX_INIMIGOS 500
#define TAXA_POR_SEGUNDO 1.5f

typedef struct Jogo {
    Jogador jogador;
    Camera2D camera;
    Inimigo inimigo[QTD_MAX_INIMIGOS];
    
    int qtdInimigosAtivos;
    float acumuladorNascInimigos;
    float velSuavidadeCamera;
    float tempoDecorrido;
} Jogo;

/**
 * @brief Cria uma instância da struct Jogo alocada dinamicamente.
 * 
 * @return Jogo* Ponteiro para o jogo criado ou NULL se falhar.
 */
Jogo *criarJogo( void );

/**
 * @brief Atualiza o estado do jogo.
 */
void atualizarJogo( Jogo *jogo, float delta );

/**
 * @brief Desenha o estado atual do jogo.
 */
void desenharJogo( Jogo *jogo );

/**
 * @brief Distroi o objeto Jogo e suas dependências.
 */
void destruirJogo( Jogo *jogo );