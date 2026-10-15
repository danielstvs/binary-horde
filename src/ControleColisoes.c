#include "ControleColisoes.h"

//deve retornar o hashGrid
void gerarHashGrid( int largura, int altura ) {

}

bool checarColisaoJogador( Jogador *jogador, Inimigo *inimigos, int qtdAtivos ) {
    for( int x = 0; x < qtdAtivos; x++ ) {
        if ( CheckCollisionRecs(
            (Rectangle){
                jogador->posicao.x,
                jogador->posicao.y,
                jogador->dimensao.x,
                jogador->dimensao.y
            },
            (Rectangle){
                inimigos[x].posicao.x,
                inimigos[x].posicao.y,
                inimigos[x].dimensao.x,
                inimigos[x].dimensao.y
            }) ){
            return true;
        }
    }
}

