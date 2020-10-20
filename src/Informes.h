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
int informes_catidadAvisosActivos(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente);
int informes_rubroConMasAvisos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente);
int informes_clienteConMasAvisosActivos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente);
int informes_contarAvisosActivos(Publicaciones* pArrays, int limite, int idCliente, int* avisos);
int informes_clienteConMasAvisosPausados(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente);
int informes_contarAvisosPausados (Publicaciones* pArrays, int limite, int idCliente, int* avisos);
int informes_contarRubro (Publicaciones* pArrays, int limite, int numeroRubro, int* rubros);
int informes_imprimirRubrosOrdenados(Publicaciones* pArray, int limite, Cliente* pArrayCliente,int limiteCliente);
int informe_ordenarRubros(Publicaciones *pArrays, int limite, int orden);
int informes_clienteConMenosAvisos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente);
int informes_contarAvisosTotales(Publicaciones* pArrays, int limite, int idCliente, int* avisos);
int informes_contarRubros(Publicaciones* pArrays, int limite, int numeroRubro, int*cantidad);
int informes_cantidadPorRubro(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente);
int informes_contarAvisosCliente(Publicaciones* pArrays, int limite, Cliente * pArraysCliente, int limiteCliente ,int numeroCuit, int*cantidad);
int informes_cantidadPorCliente(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente);
int informes_publicacionesPorCliente(Publicaciones* pArray, int limite ,int id ,int *pResultado);
int informe_buscarIndicePorCuit(Cliente *pArrays, int limite, int cuitBuscar,int *pIndice);
int informe_buscaridClientePorCuit(Cliente *pArrays, int limite, int cuitBuscar,int *pIndice);


#endif /* INFORMES_H_ */
