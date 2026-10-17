#include "ControleColisoes.h"

//deve retornar o hashGrid
void gerarHashGrid( int largura, int altura ) {

}

bool checarColisaoJogador( Jogador *jogador, Inimigo *inimigos, int qtdAtivos ) {
    for( int x = 0; x < qtdAtivos; x++ ) {
        if ( CheckCollisionCircles( 
                jogador->posicao, 
                jogador->raio, 
                inimigos[x].posicao, 
                inimigos[x].raio
            ) ){
            return true;
        }
    }
    return false;
}