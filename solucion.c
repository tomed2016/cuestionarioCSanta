#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
    datosNino ninos[MAX_NINOS];
    datosNino ordenEntrega[MAX_NINOS];
    size_t totalCartas;
    size_t cantidadNinos;
    size_t i;

    if (scanf("%zu", &totalCartas) != 1 ||
        totalCartas == 0 || totalCartas > MAX_NINOS)
    {
        fprintf(stderr, "Error: la cantidad de cartas no es válida.\n");
        return EXIT_FAILURE;
    }

    if (!leerNinos(ninos, totalCartas, &cantidadNinos))
    {
        fprintf(stderr, "Error: no se pudieron leer los datos de las cartas.\n");
        return EXIT_FAILURE;
    }

    printf("Se recibieron %zu cartas, se procesarán %zu.\n",
           totalCartas, cantidadNinos);

    mostrarListado("LISTADO ORDEN DE ENVIO CARTAS", ninos, cantidadNinos);

    /* Se ordena una copia para conservar la lista original de llegada. */
    for (i = 0; i < cantidadNinos; i++)
    {
        ordenEntrega[i] = ninos[i];
    }

    ordenarParaEntrega(ordenEntrega, cantidadNinos);
    mostrarListado("LISTADO ORDEN ENTREGA REGALOS",
                   ordenEntrega, cantidadNinos);

    return EXIT_SUCCESS;
}
