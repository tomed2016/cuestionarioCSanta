#include <stdio.h>

#include "funciones.h"

/*
 * Recorre los niños ya registrados y devuelve la posición del código.
 * Si no lo encuentra, devuelve cantidad, que es la primera posición libre.
 */
size_t buscarNino(const datosNino ninos[], size_t cantidad, size_t codigo)
{
    size_t i;

    /* La búsqueda lineal basta para el tamaño máximo de entrada. */
    for (i = 0; i < cantidad; i++)
    {
        if (ninos[i].codigo == codigo)
        {
            return i;
        }

    }

    return cantidad;
}

/*
 * Lee una línea por carta. Sólo guarda los datos cuando el código todavía
 * no ha aparecido, de modo que las cartas posteriores del mismo niño se ignoran.
 */
int leerNinos(datosNino ninos[], size_t totalCartas, size_t *cantidadNinos)
{
    size_t i;
    size_t codigo;
    size_t comportamiento;
    size_t pesoRegalos;

    *cantidadNinos = 0;

    for (i = 0; i < totalCartas; i++)
    {
        /* Se esperan tres enteros por carta; ante una entrada incompleta se informa error. */
        if (scanf("%zu %zu %zu", &codigo, &comportamiento, &pesoRegalos) != 3)
        {
            return 0;
        }

        /* La cantidad también señala la posición donde agregar al siguiente niño. */
        if (buscarNino(ninos, *cantidadNinos, codigo) == *cantidadNinos)
        {
            ninos[*cantidadNinos].codigo = codigo;
            ninos[*cantidadNinos].comportamiento = comportamiento;
            ninos[*cantidadNinos].pesoRegalos = pesoRegalos;
            (*cantidadNinos)++;
        }
    }

    return 1;
}

/* Compara dos niños según las reglas de prioridad para recibir los regalos. */
int tienePrioridad(datosNino a, datosNino b)
{
    /* Primero va quien tuvo mejor comportamiento. */
    if (a.comportamiento != b.comportamiento)
    {
        return a.comportamiento > b.comportamiento;
    }

    /* Con el mismo comportamiento, se prioriza el menor peso solicitado. */
    return a.pesoRegalos < b.pesoRegalos;
}

/*
 * Ordena mediante inserción: cada elemento se desplaza a la izquierda
 * mientras tenga más prioridad que los anteriores. Los empates no se mueven,
 * por lo que se conserva el orden en que llegaron las cartas.
 */
void ordenarParaEntrega(datosNino ninos[], size_t cantidad)
{
    size_t i;

    for (i = 1; i < cantidad; i++)
    {
        datosNino actual = ninos[i];
        size_t j = i;

        /* Abre espacio para insertar el elemento en su posición ordenada. */
        while (j > 0 && tienePrioridad(actual, ninos[j - 1]))
        {
            ninos[j] = ninos[j - 1];
            j--;
        }

        ninos[j] = actual;
    }
}

/* Imprime título, encabezados y una fila con los datos de cada niño. */
void mostrarListado(const char *titulo, const datosNino ninos[],
                    size_t cantidad)
{
    size_t i;

    printf("\n----- %s -----\n", titulo);
    printf("CODIGO | COMPORTAMIENTO | PESO\n");
    printf("-------------------------------\n");

    /* Cada fila conserva el mismo orden del arreglo recibido. */
    for (i = 0; i < cantidad; i++)
    {
        printf("%6zu | %14zu | %4zu\n",
               ninos[i].codigo,
               ninos[i].comportamiento,
               ninos[i].pesoRegalos);
    }
}
