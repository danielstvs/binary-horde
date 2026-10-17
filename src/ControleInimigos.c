#include "ControleInimigos.h"

#define VEL_INIMIGO 50.0f

void gerenciarNascInimigos( Jogo *jogo ) {
    while( jogo->acumuladorNascInimigos >= 1.0f && 
            jogo->qtdInimigosAtivos < QTD_MAX_INIMIGOS ) {
// CRIAR FUNÇÃO QUE GERENCIA OS ATRIBUTOS DOS INIMIGOS A SEREM GERADOS DE ACORDO COM O TEMPO.
        jogo->inimigo[jogo->qtdInimigosAtivos] = criarInimigo( 
            jogo->jogador.posicao,
            TAM_INIMIGO / 2, 80,
            10,
            jogo->qtdInimigosAtivos
        );
        jogo->qtdInimigosAtivos += 1;
        jogo->acumuladorNascInimigos -= 1.0f;
    }
}
// Verificar se enviar a posição do jogador para atualizar os inimigos
// pode fazer que eles se movam para uma posição anterior do jogador.
// Caso isso ocorra, passar como parâmetro o endereço do jogador.
void atualizaInimigosAtivos( Inimigo *inimigo, Vector2 posJogador, int qtdAtivos, float delta ) {
    for ( int i = 0; i < qtdAtivos; i++ ) {
        if ( inimigo[i].ativo )
            atualizarInimigo( &inimigo[i], posJogador, delta ); 
    }
}

void desenhaInimigosAtivos( Inimigo *inimigo, int qtdAtivos ) {
    for ( int i = 0; i < qtdAtivos; i++ ) {
        if ( inimigo[i].ativo )
            desenharInimigo( &inimigo[i] );
    }
}