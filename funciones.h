#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stddef.h>

#define MAX_NINOS 10000

typedef struct
{
    size_t codigo;
    size_t comportamiento;
    size_t pesoRegalos;
} datosNino;

/* Busca un código; devuelve cantidad si no está en el arreglo. */
size_t buscarNino(const datosNino ninos[], size_t cantidad, size_t codigo);

/* Lee las cartas y conserva sólo la primera de cada niño. */
int leerNinos(datosNino ninos[], size_t totalCartas, size_t *cantidadNinos);

/* Indica si a debe recibir su regalo antes que b. */
int tienePrioridad(datosNino a, datosNino b);

/* Ordena por prioridad y mantiene el orden de llegada en los empates. */
void ordenarParaEntrega(datosNino ninos[], size_t cantidad);

/* Muestra una lista con las columnas indicadas en el enunciado. */
void mostrarListado(const char *titulo, const datosNino ninos[],
                    size_t cantidad);

#endif
