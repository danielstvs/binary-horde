#include "Inimigo.h"
#include "raymath.h"

Inimigo criarInimigo( 
    Vector2 posicao, 
    Vector2 direcao, 
    Vector2 dimensao, 
    Color cor ) {

    return (Inimigo){
        .posicao = calcularPosicao( (Vector2){
            GetScreenWidth() / 2, GetScreenHeight() / 2 },
            GetRandomValue( 700, 800 ) ),   // Alterar o primeiro valor para uma variavel que calcula o raio a partir do centro da tela. Alterar o segundo valor para calcular jiter.
        .direcao = direcao,
        .dimensao = dimensao,
        .cor = cor,
        .velocidade = GetRandomValue( 5, 40 ),  // Adicionar variáveis para controle de velocidade MIN e MAX, ou adicionar  multiplicador ao gerar inimigos mais fortes.
        .ativo = true
    } ;
}

/**
 * Gera um angulo aleatório em Radianos que é multiplicado pelo
 * cosseno de x e pelo seno de y, e depois somado com os pontos
 *  x e y respectivamente gerando coordenadas na circunferencia.
 * 
 * Formula: X = x' + cos(angulo) * raio
 *          Y = y' + sen(angulo) * raio
 */
Vector2 calcularPosicao( Vector2 centroTela, float raio ) {
    float angulo = GetRandomValue( 0, 359 ) * DEG2RAD;
    return (Vector2) {
        centroTela.x + cosf( angulo ) * raio,
        centroTela.y + sinf( angulo ) * raio
    };
}

/**
 *  Move o inimigo em direção ao personagem.
 *  A direção do movimento é o cálculo normalizado da distância das coordenadas x e y dos centros
 *  dos elementos: direçãoMovimento = Normalizar( centroJogador - centroInimigo )
 * 
 *  Cálculo do centro do elemento: centro = posicaoElemento + tamanhoElemento / 2.
 */
void atualizarInimigo( Inimigo *inimigo, Jogador *jogador, float delta ) {
    inimigo->direcao = Vector2Normalize( 
        Vector2Subtract( 
            Vector2Add( 
                jogador->posicao, Vector2Scale( jogador->dimensao, 0.5f ) ), // Centro do personagem
            Vector2Add( 
                inimigo->posicao, Vector2Scale(inimigo->dimensao, 0.5f ) )   // Centro do inimigo      
        ) 
    );
    inimigo->posicao.x += inimigo->direcao.x * inimigo->velocidade * delta;
    inimigo->posicao.y += inimigo->direcao.y * inimigo->velocidade * delta;
}

/**
 * @brief Desenha inimigo na tela.
 * 
 * @param inimigo Endereço do inimigo;
 */
void desenharInimigo( Inimigo *inimigo ){
    DrawRectangle(
        inimigo->posicao.x,
        inimigo->posicao.y,
        inimigo->dimensao.x,
        inimigo->dimensao.y,
        inimigo->cor
    );
}