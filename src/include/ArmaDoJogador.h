#pragma once

/**
 * @file ArmaDoJogador.h
 * @brief Gerencia o estado atual de cada arma do jogador.
 * Instancia uma nova arma e atualiza seus atributos.
 * 
 */

#include "DefinicoesArmas.h"
#include "stdbool.h"

typedef struct Jogador Jogador;

typedef struct ArmaDoJogador {
    IdentificadorArma idArma;   // Qual arma
    int nivel;                  // Nivel atual
    
    float tmpRecargaRestante;   // Tempo até o próximo lançamento.
    float tmpRecargaBase;       // Tempo base de recarga. Evita consultas a cada disparo.
    float dano;

    float velocidade;
    float areaAlcance;
    float duracao;
    int qtdProjeteis;           // Uma arma pode disparar vários projeteis ao mesmo tempo.
    int perfuracao;

    bool ativa;
} ArmaDoJogador;

/**
 * @brief Busca as estatísticas na tabela de definições
 * para criar uma nova instância.
 * 
 * @param id Identificador da arma.
 * @return ArmaDoJogador Retorna as estatísticas base. 
 */
ArmaDoJogador inicializarArma( IdentificadorArma id );

bool equiparNovaArma( Jogador *jogador, IdentificadorArma id );

/**
 * @brief Aplica modificadores de nível aprimorando a arma atual do jogador.
 * 
 * @param id Identificador da arma.
 * @param armaBase Estado atual da instância equipada pelo jogador.
 * @return ArmaDoJogador Retorna nonvas estatísticas para a arma equipada.
 */
ArmaDoJogador atualizarStatsArma( IdentificadorArma id, ArmaDoJogador *armaBase );