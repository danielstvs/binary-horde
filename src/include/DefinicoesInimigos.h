#pragma once

#include "raylib.h"

typedef enum TipoInimigo {
    PEQUENO,
    MEDIO,
    GRANDE,
    CHEFE,
    QTD_TIPOS_INIMIGOS,
} TipoInimigo;

typedef struct DadosInimigo {
    TipoInimigo tipo;
    float raio;
    float velocidade;
    float pontosVida;
} DadosInimigo;

const DadosInimigo *obterDadosInimigo( TipoInimigo id );