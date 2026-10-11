#include "Jogador.h"
#include "raymath.h"

Jogador criarJogador( 
    Vector2 posicao, 
    Vector2 direcao, 
    Vector2 dimensao, 
    Color cor ) {

    return (Jogador) {
        .posicao = posicao,
        .direcao = direcao,
        .dimensao = dimensao,
        .cor = cor,
        .velocidade = VELOCIDADE_INICIAL,
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
    jogador->direcao = (Vector2){ 0.0f, 0.0f };
    
    if ( IsKeyDown( KEY_A ) ) jogador->direcao.x -= 1.0f;
    if ( IsKeyDown( KEY_D ) ) jogador->direcao.x += 1.0f;
    if ( IsKeyDown( KEY_W ) ) jogador->direcao.y -= 1.0f;
    if ( IsKeyDown( KEY_S ) ) jogador->direcao.y += 1.0f;
  
    jogador->direcao = Vector2Normalize( jogador->direcao );
}

void atualizarJogador( Jogador *jogador, float delta )  {
    jogador->posicao.x += jogador->direcao.x * jogador->velocidade * delta;
    jogador->posicao.y += jogador->direcao.y * jogador->velocidade * delta;
}

void desenharJogador( Jogador *jogador ) {
    DrawRectangle(
        jogador->posicao.x,
        jogador->posicao.y,
        jogador->dimensao.x,
        jogador->dimensao.y,
        jogador->cor
    );
}