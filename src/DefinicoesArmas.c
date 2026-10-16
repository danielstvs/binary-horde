#include "DefinicoesArmas.h"
#include "stdlib.h"

const DefinicaoArma tabelaArmas[QTD_TIPOS_ARMA] = {  
    [ARMA_VARINHA] = {
        .comportamento =  PROJETIL_TELEGUIADO,
        .dano = 5.0f,
        .recarga = 2.0f,
        .velocidade = 10.0f,
        .areaAlcance = 0.0f,
        .duracao = 5.0f, // Até detectar colisão ou sair da visão.
        .quantidade = 1,
        .perfuracao = 1
    },
    [ARMA_TREM] = {
        .comportamento =  PROJETIL_DIRECIONADO,
        .dano = 5.0f,
        .recarga = 2.0f,
        .velocidade = 400.0f,
        .areaAlcance = 0.0f,
        .duracao = 5.0f, // Até detectar colisão ou sair da visão.
        .quantidade = 1,
        .perfuracao = 1
    },  
    [ARMA_ESPIRITO] = {
        .comportamento =  PROJETIL_ORBITAL,
        .dano = 5.0f,
        .recarga = 10.0f,
        .velocidade = 10.0f,
        .areaAlcance = 60.0f,
        .duracao = 5.0f,
        .quantidade = 1,
        .perfuracao = 1
    },
    [ARMA_QUEIMAR] = {
        .comportamento =  AURA,
        .dano = 5.0f,
        .recarga = 1.0f,
        .velocidade = 0,
        .areaAlcance = 80.0f,
        .duracao = 0.0f,
        .quantidade = 1,
        .perfuracao = 0
    },
    [ARMA_ELETRICA] = {
        .comportamento =  AREA_LANCADA, //TROCAR DEPOIS
        .dano = 5.0f,
        .recarga = 10.0f,
        .velocidade = 20.0f,
        .areaAlcance = 100.0f,
        .duracao = 1.0f,
        .quantidade = 1,
        .perfuracao = 1
    },
};

const DefinicaoArma *obterDefinicaoArma( IdentificadorArma id ) {
    switch( id ) {        
    case ARMA_VARINHA:
        return &tabelaArmas[ARMA_VARINHA];
    case ARMA_TREM:
        return &tabelaArmas[ARMA_TREM];
    case ARMA_ESPIRITO:
        return &tabelaArmas[ARMA_ESPIRITO];
    case ARMA_QUEIMAR:
        return &tabelaArmas[ARMA_QUEIMAR];
    case ARMA_ELETRICA:
        return &tabelaArmas[ARMA_ELETRICA];
    
    default:
        return NULL;
        break;
    }
}
