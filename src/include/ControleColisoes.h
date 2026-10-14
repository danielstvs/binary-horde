#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "raylib.h"

#define TAMANHO_GRID 64

typedef struct CelulaGrid {
    Vector2 posicao[20];
    Vector2 tamanho[20];
    int quantidadeElementos;
} CelulaGrid;

typedef struct HashGrid {
    CelulaGrid matrizTabela[16][16];
} HashGrid;

//bool checarColisao(  );

void gerarHashGrid( int largura, int altura );

bool checarColisaoJogador( Jogador *jogador, Inimigo *inimigos, int qtdAtivos );