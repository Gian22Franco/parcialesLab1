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




int informes_clienteConMasAvisos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente);
int informes_contarAvisos (Publicaciones* pArrays, int limite, int idCliente, int* avisos);
int informes_catidadAvisosPausados(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente);
int informes_rubroConMasAvisos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente);
int informes_contarRubro (Publicaciones* pArrays, int limite, int numeroRubro, int* rubros);


#endif /* INFORMES_H_ */
