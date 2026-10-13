#include "Inimigo.h"
#include "raymath.h"

Inimigo criarInimigo(
    Vector2 dimensao, 
    Color cor ) {

    return (Inimigo){
        .posicao = calcularPosicao(),  
        .direcao = Vector2Zero(),
        .dimensao = dimensao,
        .cor = cor,
        .velocidade = GetRandomValue( 5, 40 ),  // Adicionar variáveis para controle de velocidade MIN e MAX, ou adicionar  multiplicador ao gerar inimigos mais fortes.
        .ativo = true
    } ;
}

/**
 * Calcula o centro da tela, e, aleatóriamente, gera um valor de angulo em
 * radianos e um tamanho de raio. Retorna uma coordenada na circunferencia
 * calculada pela formula:
 *          X = x' + cos(angulo) * raio
 *          Y = y' + sen(angulo) * raio
 */
Vector2 calcularPosicao( void ) {
    Vector2 centroTela = (Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2 };
    float angulo = GetRandomValue( 0, 359 ) * DEG2RAD;
    float raio = GetRandomValue( 700, 800 );    // CAUSARÁ PROBLEMAS CASO A TELA SEJA MAIOR QUE 1280x720.

    return (Vector2) {
        centroTela.x + cosf( angulo ) * raio,
        centroTela.y + sinf( angulo ) * raio
    };
}

/**
 * Move o centro do inimigo em direção ao centro personagem.
 * Cálculo do centro de cada elemento: 
 *          centro = posicaoElemento + tamanhoElemento / 2
 * A direção do movimento é o cálculo normalizado da distância das coordenadas x e y do
 * jogador e inimigo: 
 *          direçãoMovimento = Normalizar( centroJogador - centroInimigo )
 */
void atualizarInimigo( Inimigo *inimigo, Jogador *jogador, float delta ) {
    inimigo->posicao = Vector2Subtract(
        Vector2MoveTowards(
            Vector2Add( inimigo->posicao, Vector2Scale(inimigo->dimensao, 0.5f ) ),
            Vector2Add( jogador->posicao, Vector2Scale( jogador->dimensao, 0.5f ) ),
            inimigo->velocidade * delta
        ),
        Vector2Scale(inimigo->dimensao, 0.5f )
    );
    // CODIGO NOVO (A CIMA) NÃO PRECISA INIMIGO GUARDAR O ATRIBUTO DIREÇÃO. CONSIDERAR
    // DEPOIS QUAL MELHOR SOLUÇÃO.
    // PENSAR SE VALE A PENA MANTER O CODIGO ANTERIOR (ABAIXO) OU USAR A FUNÇÃO DA RAYLIB.

    // inimigo->direcao = Vector2Normalize( 
    //     Vector2Subtract( 
    //         Vector2Add( // Centro do personagem
    //             jogador->posicao, Vector2Scale( jogador->dimensao, 0.5f ) ),
    //         Vector2Add( // Centro do inimigo  
    //             inimigo->posicao, Vector2Scale(inimigo->dimensao, 0.5f ) )    
    //     ) 
    // );
    // inimigo->posicao.x += inimigo->direcao.x * inimigo->velocidade * delta;
    // inimigo->posicao.y += inimigo->direcao.y * inimigo->velocidade * delta;
}

/**
 * @brief Desenha inimigo na tela.
 * 
 * @param inimigo Endereço do inimigo;
 */
void desenharInimigo( Inimigo *inimigo ){
    DrawRectangleV(
        inimigo->posicao,
        inimigo->dimensao,
        inimigo->cor
    );
}