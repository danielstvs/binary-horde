#include "Jogador.h"
#include "ControleColisoes.h"
#include "Jogo.h"
#include "raymath.h"

#define TAM_JOGADOR 48
#define VELOCIDADE_INICIAL 150
#define PV_INICIAL 100.0f
#define TEMP_INVULNERAVEL 1.0f

#define ESPACO_VAZIO 6 // Usado para o espaço entre o personagem e a barra de PV.

Jogador criarJogador( void ) {
    return (Jogador){
        .armas = {
            [0] = inicializarArma( ARMA_TREM ),
        },
        .posicao = (Vector2){ 
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f 
        },
        .direcao = Vector2Zero(),
        .raio = TAM_JOGADOR / 2,
        .qtdArmasAtivas = 1,
        .velocidade = VELOCIDADE_INICIAL,
        .pontosVida = PV_INICIAL,
        .tempoInvulneravel = 0.0f,
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

void verificarColisaoJogador( Jogo *jogo, float delta ) {
    if( jogo->jogador.tempoInvulneravel > 0.0f ) {
        jogo->jogador.tempoInvulneravel -= delta;
    } else if( checarColisaoJogador(&jogo->jogador, jogo->inimigo, jogo->qtdInimigosAtivos) ) {
        jogo->jogador.pontosVida -= 10.0f; // CALCULAR DANO INIMIGO
        jogo->jogador.tempoInvulneravel = TEMP_INVULNERAVEL;
        jogo->jogador.posicao = Vector2Add(jogo->jogador.posicao,Vector2Scale(jogo->jogador.direcao, -30));
    }
}

void atualizarJogador( Jogo *jogo, float delta )  {  
    processarEntradaJogador( &jogo->jogador );
    movimentarJogador( &jogo->jogador, delta);
    // Essa verificação de colisão deve ficar no ControleColisoes? Acredito que sim.
    verificarColisaoJogador( jogo, delta );
}

void desenharPV( Jogador *jogador ) {
    DrawRectangleV(
        (Vector2){ 
            jogador->posicao.x - TAM_JOGADOR / 2,
            jogador->posicao.y + TAM_JOGADOR / 2 + ESPACO_VAZIO 
        },
        (Vector2){ 
            TAM_JOGADOR, 
            ESPACO_VAZIO / 2
        },
        RED
    );
    DrawRectangleV(
        (Vector2){ 
            jogador->posicao.x - TAM_JOGADOR / 2,
            jogador->posicao.y + TAM_JOGADOR / 2 + ESPACO_VAZIO 
        },
        (Vector2){ 
            TAM_JOGADOR * jogador->pontosVida / 100.0f,
            ESPACO_VAZIO
        },
        GREEN
    );
}

void desenharJogador( Jogador *jogador ) {
    DrawCircleV(
        jogador->posicao,
        jogador->raio,
        BLUE
    );
    desenharPV(jogador);
}