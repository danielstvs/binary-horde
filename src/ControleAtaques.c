#include "ControleAtaques.h"
#include "Util.h"

void atualizarArmasJogador( Jogador *jogador, Projetil *projetil, Inimigo *inimigo, float delta ) {
    for (int x = 0; x < QTD_MAX_ARMAS_JOGADOR; x++) {
        if( jogador->armas[x].ativa ) {
            atualizarArma(&jogador->armas[x], jogador, projetil, inimigo, delta);
        }
    }
}

void atualizarArma( ArmaDoJogador *arma, Jogador *jogador, Projetil *projetil, Inimigo *inimigo, float delta ) {
    arma->tmpRecargaRestante -= delta;
    while ( arma->tmpRecargaRestante <= 0 ) { // Usar while permite que a cadência de disparos seja mantida.
        if( disparar( arma, jogador, projetil, inimigo, delta) ){
            arma->tmpRecargaRestante += arma->tmpRecargaBase;
            // atualizarProjeteis( centro2V( jogador->posicao, jogador->dimensao ), projetil, delta);
        } else { // Caso não encontre nenhum alvo.
           arma->tmpRecargaRestante = 0.0f;
           break; 
        }
        
    }
}

bool disparar( ArmaDoJogador *arma, Jogador *jogador, Projetil *projetil, Inimigo *inimigos, float delta ) {
    switch ( obterDefinicaoArma(arma->idArma)->comportamento ) {
    case PROJETIL_TELEGUIADO:
        return true;
    case PROJETIL_DIRECIONADO:
        if (jogador->direcao.x != 0.0f || jogador->direcao.y != 0.0f)

        ataqueDirecionado( arma, projetil, jogador->posicao, jogador->direcao, delta);
        return true;
    case PROJETIL_ORBITAL:
        return true;
    case AURA:
        return true;
    case GOLPE_INSTANTANEO:
        return true;
    case AREA_LANCADA:
        return true;
        
    default:
        return false;
    }
    return false;
}

void ataqueDirecionado( ArmaDoJogador *arma, Projetil *projetil, Vector2 posJogador, Vector2 direcaoJogador, float delta ) {
    criarProjetil( projetil, arma, posJogador, direcaoJogador, delta );
}