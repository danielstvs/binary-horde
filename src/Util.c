#include "Util.h"
#include "Jogador.h"

/**
 * Calcula o centro da tela, e, aleatóriamente, gera um valor de angulo em
 * radianos e um tamanho de raio. Retorna uma coordenada na circunferencia
 * calculada pela formula:
 *          X = x' + cos(angulo) * raio
 *          Y = y' + sen(angulo) * raio
 */
Vector2 calcularPosicaoCircunferencia( Vector2 posAtualJogador ) {
    Vector2 centroTela = posAtualJogador;
    float angulo = GetRandomValue( 0, 359 ) * DEG2RAD;
    float raio = 1470.0f;   // CAUSARÁ PROBLEMAS CASO A TELA SEJA MAIOR QUE 1280x720.
    // AO COLOCAR O RAIO DE 1470px OS INIMIGOS DEMORAM ~= 20s PARA APARECER NA TELA,
    // PENSAR EM UMA SOLUÇÃO QUE, A PARTIR DO TEMPO, CHAMA EVENTOS NO MAPA ( GERA CHEFES, ITENS DE CURA, EVENTOS ALEATÓRIOS).
    // POR HORA, TESTAR SE O TEMPO DE JOGO É MENOR QUE 15s TEM RESOLVIDO. VERIFICAR DEPOIS.

    if( GetTime() > 15.0f ){
        return (Vector2) {
            centroTela.x + cosf( angulo ) * raio,
            centroTela.y + sinf( angulo ) * raio
        };
    }
    raio = GetRandomValue( 700, 710 );
    return (Vector2) {
        centroTela.x + cosf( angulo ) * raio,
        centroTela.y + sinf( angulo ) * raio
    };
}

void agruparInicioVetor( Inimigo *inimigo, int quantidadeVivos) {
    // SWAP-AND-POP
    // VALIDO QUANDO PRECISAR ELIMINAR INIMIGOS 
}