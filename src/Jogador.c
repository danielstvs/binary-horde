#include "Jogador.h"
#include "ControleColisoes.h"
#include "Jogo.h"
#include "raymath.h"

Jogador criarJogador( void ) {

    return (Jogador) {
        (Vector2) { 
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f 
        },
        Vector2Zero(),
        (Vector2) { JOGADOR_TAM, JOGADOR_TAM },
        BLUE,
        .velocidade = VELOCIDADE_INICIAL,
        .pontosVida = 100.0f
    };
}
/**
 *  Garante que o personagem fique parado caso haja 
 *  interrupção das instruções de movimento;
 *  Lê os atalhos de teclado correspondente à direção dos comandos;
 *  Calcula a normalização para evitar ganho de velocidade
 *  ao se movimentar nas diagonais.
 */
void processarEntradaJogador( Jogador *jogador ) {
    jogador->direcao = Vector2Zero();
    
    if ( IsKeyDown( KEY_A ) ) jogador->direcao.x -= 1.0f;
    if ( IsKeyDown( KEY_D ) ) jogador->direcao.x += 1.0f;
    if ( IsKeyDown( KEY_W ) ) jogador->direcao.y -= 1.0f;
    if ( IsKeyDown( KEY_S ) ) jogador->direcao.y += 1.0f;
  
    jogador->direcao = Vector2Normalize( jogador->direcao );
}

void movimentarJogador( Jogador *jogador, float delta ) {
    jogador->posicao.x += jogador->direcao.x * jogador->velocidade * delta;
    jogador->posicao.y += jogador->direcao.y * jogador->velocidade * delta;
}

void calcDanoSofrido( Jogo *jogo ) {
    if( checarColisaoJogador(&jogo->jogador, jogo->inimigo, jogo->qtdInimigosAtivos) )  {
        jogo->jogador.pontosVida -= 10.0f;

    }
}

void atualizarJogador( Jogo *jogo, float delta )  {
    movimentarJogador( &jogo->jogador, delta);
    calcDanoSofrido( jogo );
}

void desenharJogador( Jogador *jogador ) {
    DrawRectangleV(
        jogador->posicao,
        jogador->dimensao,
        jogador->cor
    );
}