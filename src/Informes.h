/*
 * Informes.h
 *
 *  Created on: 12 oct. 2020
 *      Author: Gian
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#define LONG 50
#define TRUE 1
#define FALSE 0
#define ACTIVA 1
#define PAUSADA 0
#define MIN_NUMEROS 0
#define MAX_NUMEROS 99999999
#include "Cliente.h"
#include "Publicaciones.h"

typedef struct
{
	char cuit[20];
	int isEmpty;

}ListaCliente;


void informes_generarListaClientes(Publicaciones* pArrays, int limite, Cliente * ArrayCliente, int limiteCliente);
void informes_inicializarArray(ListaCliente cuits[], int lenCuits);
int informes_catidadAvisosPausados(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente);
int informes_clienteConMasAvisos(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente);

#endif /* INFORMES_H_ */
