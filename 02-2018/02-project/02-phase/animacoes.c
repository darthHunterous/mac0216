#include "estruturas.h"

void estressar(Aventureiro* aventureiro) {
    /* Funcao que incrementa o nivel de stress do aventureiro */ 
    aventureiro->nivel_stress++;
}

void descarrega_celular(Elemento* celular) {
    /* Funcao que muda o estado do objeto celular */
    celular->detalhe->objeto.adjetivos[0] = "descarregado";
}
