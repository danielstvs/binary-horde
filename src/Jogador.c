#include "Jogador.h"
#include "ControleColisoes.h"
#include "Jogo.h"
#include "raymath.h"

#define TAM_JOGADOR 48
#define VELOCIDADE_INICIAL 150
#define PV_INICIAL 100.0f

#define ESPACO_VAZIO 6 // Usado para o espaço entre o personagem e a barra de PV.

Jogador criarJogador( void ) {

    return (Jogador) {
        (Vector2) { 
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f 
        },
        Vector2Zero(),
        (Vector2) { TAM_JOGADOR, TAM_JOGADOR },
        BLUE,
        .velocidade = VELOCIDADE_INICIAL,
        .pontosVida = PV_INICIAL,
        .tempoInvulneravel = 0.0f
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
    // CALCULO DE TEMPO DE INVULNERABILIDADE AO TOMAR DANO
    if( jogo->jogador.tempoInvulneravel > 0.0f ) {
        jogo->jogador.tempoInvulneravel -= delta;
    }
    if( jogo->jogador.tempoInvulneravel < 0.0f ) {
        jogo->jogador.tempoInvulneravel = 0.0f;
    }  
    if( jogo->jogador.tempoInvulneravel == 0.0f ) {
        if( checarColisaoJogador(&jogo->jogador, jogo->inimigo, jogo->qtdInimigosAtivos) )  {
            jogo->jogador.pontosVida -= 10.0f;
            jogo->jogador.tempoInvulneravel = 1.0f;
            //  JOGA O JOGADOR PARA TRAZ QUANDO TOMA DANO. DEPOIS TROCAR PARA UMA FUNÇÃO
            jogo->jogador.posicao = Vector2Add(jogo->jogador.posicao,Vector2Scale(jogo->jogador.direcao, -30)); 
        }
    }
}

void atualizarJogador( Jogo *jogo, float delta )  {  
    movimentarJogador( &jogo->jogador, delta);
    verificarColisaoJogador( jogo, delta );
}

void desenharPV( Jogador *jogador ) {
    DrawRectangleV(
        (Vector2){ jogador->posicao.x,
            jogador->posicao.y + jogador->dimensao.y + ESPACO_VAZIO },
        (Vector2){ jogador->dimensao.x, ESPACO_VAZIO },
        RED
    );
    DrawRectangleV(
        (Vector2){ jogador->posicao.x,
            jogador->posicao.y + jogador->dimensao.y + ESPACO_VAZIO },
        (Vector2){ jogador->dimensao.x * jogador->pontosVida / 100.0f, ESPACO_VAZIO },
        GREEN
    );
}

void desenharJogador( Jogador *jogador ) {
    DrawRectangleV(
        jogador->posicao,
        jogador->dimensao,
        jogador->cor
    );
    desenharPV(jogador);
}