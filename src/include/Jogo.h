#pragma once

#include "Inimigo.h"
#include "Jogador.h"
#include "Projeteis.h"
#include "raylib.h"

#define QTD_MAX_INIMIGOS 5000
#define TAXA_INIMIGO_POR_SEGUNDO 5.75f

typedef struct Jogo {
    Jogador jogador;
    Camera2D camera;
    Inimigo inimigo[QTD_MAX_INIMIGOS];
    Projetil projeteis[QTD_MAX_PROJETEIS];
    
    int qtdInimigosAtivos;
    float acumuladorNascInimigos;
    float velSuavidadeCamera;
    float tempoDecorrido;
    float tempoPartida;
} Jogo;

/**
 * @brief Aloca dinâmicamente a estrutura
 * do jogo e zera todos os atributos.
 * 
 * @return Jogo*
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