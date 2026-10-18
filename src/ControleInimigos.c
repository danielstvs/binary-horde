#include "ControleInimigos.h"

#define VEL_INIMIGO 50.0f
#define PV_INIMIGO 10

void gerarInimigos( Jogo *jogo ) {
    while( jogo->acumuladorNascInimigos >= 1.0f && 
            jogo->qtdInimigosAtivos < QTD_MAX_INIMIGOS ) {
// CRIAR FUNÇÃO QUE GERENCIA OS ATRIBUTOS DOS INIMIGOS A SEREM GERADOS DE ACORDO COM O TEMPO.
        jogo->inimigo[jogo->qtdInimigosAtivos] = criarInimigo( 
            jogo->jogador.posicao,
            TAM_INIMIGO / 2,
            VEL_INIMIGO,
            PV_INIMIGO,
            jogo->qtdInimigosAtivos
        );
        jogo->qtdInimigosAtivos += 1;
        jogo->acumuladorNascInimigos -= 1.0f;
    }
}

void atualizaInimigosAtivos( Inimigo *inimigo, Vector2 posJogador, int qtdAtivos, float delta ) {
    for ( int i = 0; i < qtdAtivos; i++ ) {
        if ( inimigo[i].ativo )
            atualizarPosInimigo( &inimigo[i], posJogador, delta ); 
    }
}

void desenhaInimigosAtivos( Inimigo *inimigo, int qtdAtivos ) {
    for ( int i = 0; i < qtdAtivos; i++ ) {
        if ( inimigo[i].ativo )
            desenharInimigo( &inimigo[i] );
    }
}