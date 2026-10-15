#include "ControleInimigos.h"

#define TAM_INIMIGO 32
#define VEL_INIMIGO 50.0f

void gerenciarNascInimigos( Jogo *jogo ) {
    while( jogo->acumuladorNascInimigos >= 1.0f && 
            jogo->qtdInimigosAtivos < QTD_MAX_INIMIGOS ) {
        
                jogo->inimigo[jogo->qtdInimigosAtivos] = criarInimigo( // CRIAR FUNÇÃO QUE GERENCIA OS ATRIBUTOS DOS INIMIGOS A SEREM GERADOS DE ACORDO COM O AUMENTO DE DIFICULDADE.
            (Vector2){ TAM_INIMIGO, TAM_INIMIGO }, jogo->jogador.posicao, VEL_INIMIGO, RED );
        jogo->qtdInimigosAtivos += 1;
        jogo->acumuladorNascInimigos -= 1.0f;
    }
}

void atualizaInimigosAtivos( Jogo *jogo, float delta ) {
    for ( int i = 0; i < jogo->qtdInimigosAtivos; i++ ) {
        if ( jogo->inimigo[i].ativo )
            atualizarInimigo( &jogo->inimigo[i], &jogo->jogador, delta ); 
    }
}

void desenhaInimigosAtivos( Jogo *jogo ) {
    for ( int i = 0; i < jogo->qtdInimigosAtivos; i++ ) {
        if ( jogo->inimigo[i].ativo )
            desenharInimigo( &jogo->inimigo[i] );
    }
}