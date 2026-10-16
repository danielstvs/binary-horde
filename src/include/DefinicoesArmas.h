#pragma once

/**
 * @file DefinicoesArmas.h
 * @brief Dados das armas, somente para leitura.
 * 
 */

typedef enum IdentificadorArma {
    ARMA_VARINHA,
    ARMA_TREM,
    ARMA_ESPIRITO,
    ARMA_QUEIMAR,
    
    ARMA_ELETRICA,
    QTD_TIPOS_ARMA  // Somente para representar a quantidade total de armas.
} IdentificadorArma;

typedef enum TipoArma {
    PROJETIL_TELEGUIADO,    // Nasce no jogador e vai em direção ao inimigo mais próximo.
    PROJETIL_DIRECIONADO,   // Nasce no jogador, voa em linha reta em uma direção.
    PROJETIL_ORBITAL,       // Gira em torno do jogador por um tempo.
    AURA,                   // Área fixa em torno do jogador, dano periódico.
    GOLPE_INSTANTANEO,      // Hitbox temporária em uma direção (como um chicote).
    AREA_LANCADA            // Efeito em uma área, depois de um atraso.
} TipoArma;

typedef struct DefinicaoArma {
    TipoArma comportamento;
    float dano;
    float recarga;
    float velocidade;
    float areaAlcance;
    float duracao;
    int quantidade;
    int perfuracao;
} DefinicaoArma;

/**
 * @brief Busca as estatísticas padrão de uma arma.
 * 
 * @param id Identificador da arma buscada.
 * @return const DefinicaoArma* Retorna o endereço de memória 
 * das definições da arma.
 */
const DefinicaoArma *obterDefinicaoArma( IdentificadorArma id );