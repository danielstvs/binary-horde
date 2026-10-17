#include "DefinicoesInimigos.h"
#include "stdlib.h"

#define RAIO_PEQUENO 8
#define RAIO_MEDIO 16
#define RAIO_GRANDE 24
#define RAIO_CHEFE 32

#define VEL_PEQUENO 110
#define VEL_MEDIO 85
#define VEL_GRANDE 70
#define VEL_CHEFE 30

#define PV_PEQUENO 8
#define PV_MEDIO 16
#define PV_GRANDE 24
#define PV_CHEFE 32

const DadosInimigo tabelaInimigos[QTD_TIPOS_INIMIGOS] = {
    [PEQUENO] = {
        .tipo       = PEQUENO,
        .raio       = RAIO_PEQUENO,
        .pontosVida = PV_PEQUENO,
        .velocidade = VEL_PEQUENO,
    },
    [MEDIO] = {
        .tipo       = MEDIO,
        .raio       = RAIO_MEDIO,
        .pontosVida = PV_MEDIO,
        .velocidade = VEL_MEDIO,

    },
    [GRANDE] = {
        .tipo       = GRANDE,
        .raio       = RAIO_GRANDE,
        .pontosVida = PV_GRANDE,
        .velocidade = VEL_GRANDE,
    },
    [CHEFE] = {
        .tipo       = CHEFE,
        .raio       = RAIO_CHEFE,
        .pontosVida = PV_CHEFE,
        .velocidade = VEL_CHEFE,
    },
};

const DadosInimigo *obterDadosInimigo( TipoInimigo id ) {
    switch( id ) {        
    case PEQUENO:
        return &tabelaInimigos[PEQUENO];
    case MEDIO:
        return &tabelaInimigos[MEDIO];
    case GRANDE:
        return &tabelaInimigos[GRANDE];
    case CHEFE:
        return &tabelaInimigos[CHEFE];
    
    default:
        return NULL;
    }
}