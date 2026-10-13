#pragma once

#include "Inimigo.h"
#include "Jogador.h"
#include "raylib.h"

#define QTD_MAX_INIMIGOS 50

typedef struct Jogo {
    Jogador jogador;
    Camera2D camera;
    Inimigo inimigo[QTD_MAX_INIMIGOS];
    
    int qtdInimigosAtivos;
    float velSuavidadeCamera;
    float tempoDecorrido;       // Contador de tempo para fases
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