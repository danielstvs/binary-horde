#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "raylib.h"

#define LARGURA_CEL_GRID 144.0f
#define ALTURA_CEL_GRID 182.8571f

typedef struct CelulaGrid {
    Vector2 posicao[20];
    Vector2 tamanho[20];
    int quantidadeElementos;
} CelulaGrid;

typedef struct HashGrid {
    CelulaGrid matrizTabela[5][7];
} HashGrid;

void gerarHashGrid( int largura, int altura );

bool checarColisaoJogador( Jogador *jogador, Inimigo *inimigos, int qtdAtivos );

