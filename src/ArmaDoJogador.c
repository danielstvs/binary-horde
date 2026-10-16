#include "ArmaDoJogador.h"
#include "Jogador.h"

ArmaDoJogador inicializarArma( IdentificadorArma id ) {
    const DefinicaoArma *armaBase = obterDefinicaoArma( id );
    return (ArmaDoJogador){
            .idArma = id,
            .nivel = 1,

            .tmpRecargaRestante = 0.0f,
            .tmpRecargaBase     = armaBase->recarga,
            .dano               = armaBase->dano,

            .velocidade         = armaBase->velocidade,
            .areaAlcance        = armaBase->areaAlcance,
            .duracao            = armaBase->duracao,
            .qtdProjeteis       = armaBase->quantidade,
            .perfuracao         = armaBase->perfuracao,

            .ativa = true
    };
}

bool equiparNovaArma( Jogador *jogador, IdentificadorArma id ) {
    for( int x = 0; x < QTD_MAX_ARMAS_JOGADOR; x++ ) {
        if(!jogador->armas[x].ativa) {
            jogador->armas[x] = inicializarArma( id );
            jogador->qtdArmasAtivas++;
            return true;
        }
    }
    return false;
}

// DEFINIR MELHORIAS NAS DEFINIÇÕES DAS ARMAS.
ArmaDoJogador atualizarStatsArma( IdentificadorArma id, ArmaDoJogador *armaBase ) {
    return (ArmaDoJogador){
        .nivel          = armaBase->nivel + 1,
        .tmpRecargaBase = armaBase->tmpRecargaBase * ( 1 - 10 ), // Calcular o piso para redução de cd.
        .dano           = armaBase->dano * ( 1 + 10 ),
        .velocidade     = armaBase->velocidade * ( 1 + 10 ),
        .areaAlcance    = armaBase->areaAlcance * ( 1 + 10 ),
        .duracao        = armaBase->duracao * ( 1 + 10 ),
        .qtdProjeteis   = armaBase->qtdProjeteis * ( 1 + 10 ),
        .perfuracao     = armaBase->perfuracao * ( 1 + 10 ),
    };
}