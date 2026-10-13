#include "ControleInimigos.h"

void criaInimigosAtivos(Jogo *jogo) {
  for (int i = 0; i < QTD_MAX_INIMIGOS; i++) {
    if ( !jogo->inimigo[i].ativo ) {
        jogo->inimigo[i] = criarInimigo(
            (Vector2){16, 16}, 
            RED
        );
        jogo->qtdInimigosAtivos += 1;
    }
  }
}

void atualizaInimigosAtivos( Jogo *jogo, float delta ) {
    for ( int i = 0; i < QTD_MAX_INIMIGOS; i++ ) {
        if ( jogo->inimigo[i].ativo )
            atualizarInimigo( &jogo->inimigo[i], &jogo->jogador, delta );
    }
}

void desenhaInimigosAtivos( Jogo *jogo ) {
    for ( int i = 0; i < QTD_MAX_INIMIGOS; i++ ) {
        if ( jogo->inimigo[i].ativo )
            desenharInimigo( &jogo->inimigo[i] );
    }
}