#include "Util.h"

/**
 * Calcula o centro da tela, e, aleatóriamente, gera um valor de angulo em
 * radianos e um tamanho de raio. Retorna uma coordenada na circunferencia
 * calculada pela formula:
 *          X = x' + cos(angulo) * raio
 *          Y = y' + sen(angulo) * raio
 */
Vector2 calcularPosicaoCircunferencia( void ) {
    Vector2 centroTela = (Vector2){GetScreenWidth() / 2, GetScreenHeight() / 2 };
    float angulo = GetRandomValue( 0, 359 ) * DEG2RAD;
    float raio = GetRandomValue( 700, 800 );    // CAUSARÁ PROBLEMAS CASO A TELA SEJA MAIOR QUE 1280x720.

    return (Vector2) {
        centroTela.x + cosf( angulo ) * raio,
        centroTela.y + sinf( angulo ) * raio
    };
}