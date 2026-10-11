#pragma once

#include "raylib.h"

typedef struct ResourceManager {
    Texture2D textureExample;
    Sound soundExample;
    Music musicExample;
} ResourceManager;

/**
 * @brief Apenas leitura fora deste módulo. Use rm->field para acessar os recursos.
 * 
 */
extern const ResourceManager * const rm;

/**
 * @brief Carrega recursos globais do jogo, vinculando-os na instância global do Gerenciador de recursos chamado rm.
 */
void loadResourcesResourceManager( void );

/**
 * @brief Descarrega recursos globais do jogo.
 */
void unloadResourcesResourceManager( void );