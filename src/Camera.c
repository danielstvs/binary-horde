#include "Camera.h"
#include "raymath.h"

Camera2D criarCamera( void ) {
    return (Camera2D){
        .target =  (Vector2){
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f,
        },
        .offset = (Vector2){
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f,
        },
        .rotation = 0.0f,
        .zoom = 1.0f
    };
}

/**
 *  Move o foco da camera para o centro do jogador de forma suave.
 */
void moverCamera( Camera2D *camera, Jogador *jogador, float velSuavidadeCamera, float delta) {
    camera->target = Vector2Lerp( 
        camera->target,
        (Vector2){  // Calcula o centro do personagem no quadro atual.
            jogador->posicao.x + ( jogador->dimensao.x / 2.0f ),
            jogador->posicao.y + ( jogador->dimensao.y / 2.0f )
        },
        velSuavidadeCamera * delta
    );
}