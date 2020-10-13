/*
 * contrataciones.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Gian
 */

#ifndef PUBLICACIONES_H_
#define PUBLICACIONES_H_

#define LONG 50
#define QTY_PUBLICACIONES 1000
#define TRUE 1
#define FALSE 0
#define ACTIVA 1
#define PAUSADA 0
#define MIN_NUMEROS 0
#define MAX_NUMEROS 99999999
#include "Cliente.h"

typedef struct {
	char textoAviso[64];
	int numeroRubro;
	int estadoPublicacion;
	int isEmpty;
	int idPublicaciones;
	int idCliente;
} Publicaciones;




int publicaciones_init(Publicaciones *pArray, int limite);
int publicaciones_alta(Publicaciones *pArray, int limite, Cliente *ArrayCliente, int limiteCliente);
int publicaciones_baja(Publicaciones *pArray, int limite,Cliente *ArrayCliente, int limiteCliente);
int publicaciones_modificar(Publicaciones *pArray, int limite, Cliente *ArrayCliente, int limiteCliente);
int publicaciones_imprimir(Publicaciones *pArray, int limite, Cliente *ArrayCliente, int limiteCliente);
int publicaciones_imprimirPorId(Publicaciones*pArrays, int limite, Cliente* ArrayCliente, int limiteCliente,int idImprimir);
int publicaciones_buscarLibre(Publicaciones *pArray, int limite);
int publicaciones_buscarLibreRef(Publicaciones *pArray, int limite, int *pIndice);
int publicaciones_buscarIndicePorId(Publicaciones *pArray, int limite, int idBuscar,int *pIndice);
int publicaciones_pausarPublicacion(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente);
int publicaciones_reanudarPublicacion(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente);
int publicaciones_ordenarPorNombre(Publicaciones *pArrays, int limite, int orden);

#endif /* PUBLICACIONES_H_ */
