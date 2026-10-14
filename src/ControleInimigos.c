#include "ControleInimigos.h"

void gerenciarNascInimigos( Jogo *jogo ) {
    while( jogo->acumuladorNascInimigos >= 1.0f && 
            jogo->qtdInimigosAtivos < QTD_MAX_INIMIGOS ) {
        jogo->inimigo[jogo->qtdInimigosAtivos] = criarInimigo( 
            (Vector2){ 16, 16 }, RED );
        jogo->qtdInimigosAtivos += 1;
        jogo->acumuladorNascInimigos -= 1.0f;
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