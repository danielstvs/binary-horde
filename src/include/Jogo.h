#pragma once

#include "raylib.h"
#include "Inimigo.h"
#include "Jogador.h"

#define QTD_MAX_INIMIGOS 50
#define SUAVIDADE_CAMERA 8.0f

typedef struct Jogo {
    Jogador jogador;
    Inimigo inimigo[QTD_MAX_INIMIGOS];
    int qtdInimigosAtivos;
    Camera2D camera;
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
 * @brief Cria uma intância da câmera e inicializa seus atributos.
 * 
 * @param jogador Endereço jogador. 
 * @return Camera2D
 */
Camera2D criarCamera( Jogador *jogador );

/**
 * @brief Move o foco da camera para seguir o centro do jogador. 
 * 
 * @param camera Endereço da camera.
 * @param jogador Endereço do jogador.
 * @param velSuavidadeCamera Atribudo do Jogo que define quão suave será o movimento da camera.
 * @param delta 
 */
void moverCamera( Camera2D *camera, Jogador *jogador, float velSuavidadeCamera, float delta);

/**
 * @brief Percorre o array até o fim e cria inimigos.
 * 
 * @param jogo 
 */
void percorerCriarInimigos(Jogo *jogo);

/**
 * @brief Percorre o array até o fim e atualiza os inimigos ativos.
 * 
 * @param jogo 
 * @param delta 
 */
void percorrerAtualizarInimigos( Jogo *jogo, float delta );

/**
 * @brief Percorre o array até o fim e desenha inimigos ativos.
 * 
 * @param jogo 
 */
void percorrerDesenharInimigos( Jogo *jogo );

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