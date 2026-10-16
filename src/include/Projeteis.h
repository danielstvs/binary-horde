#pragma once
/**
 * @brief Mantém os projéteis ativos, sua movimentação, seus dados de dano e seu ciclo de vida.
 * 
 */

#include "ArmaDoJogador.h"
#include "raylib.h"

#define TAM_PROJETIL 12
#define QTD_MAX_PROJETEIS 10

typedef struct Projetil {
    ArmaDoJogador dadosArma;
    Vector2 posicao;
    Vector2 dimensao;
    Vector2 direcao;
    bool ativo;
} Projetil;

void criarProjetil( Projetil *projetil, ArmaDoJogador *arma, Vector2 posJogador, Vector2 direcaoAlvo, float delta);

void atualizarProjeteis( Vector2 posJogador, Projetil *projetil, float delta );

void desenharProjeteis( Projetil *projetil );