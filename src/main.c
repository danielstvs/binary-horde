#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Janela.h"

int main( void ) {

    Janela *janela = criarJanela(
        1280,            // width
        720,             // height
        "Binary Horde",  // title
        60,              // target FPS
        true,            // antialiasing
        false,           // resizable
        false,           // full screen
        false,           // undecorated
        false,           // always on top
        false,           // invisible background
        false,           // always run
        false,           // load resources
        false            // init audio
    );

    inicializarJanela( janela );

    return 0;

}