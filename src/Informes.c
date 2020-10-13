/*
 * Informes.c
 *
 *  Created on: 12 oct. 2020
 *      Author: Gian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Informes.h"
#include "Publicaciones.h"
#include "utn.h"

static int informes_estaEnMiListaDeCuits(ListaCliente *cuits, int lenCuits, char * cuit);
static void informes_listaClientesConPublicaciones(ListaCliente *cuits, int lenCuits, Cliente * ArrayCliente);

/** \brief  To indicate that all position in the array are empty, *
 *           this function put the flag (isEmpty) in TRUE in all *
 *           position of the array
 *           * \param list informes* Pointer to array of employees
 *           * \param len lenCuits Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
void informes_inicializarArray(ListaCliente cuits[], int lenCuits)
{
	for(int i = 0; i<lenCuits ; i++)
	{
		cuits[i].isEmpty = TRUE;
	}
}
/** \brief  Función que permite ver si un cuit esta dentro de la lista, *
 *           * \param list ListaCliente* Pointer to array of ListaCliente
 *           * \param len lenCuits Array length
 *           * \param list *cuit
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
static int informes_estaEnMiListaDeCuits(ListaCliente* cuits, int lenCuits, char * cuit)
{
	int i;
	int retorno = 0 ;
	for(i=0; i<lenCuits;i++)
	{
		if(cuits[i].isEmpty == FALSE && strncmp(cuit, cuits[i].cuit, lenCuits)==0)
		{
			retorno = 1;
			break;
		}
	}
	return retorno;
}
/** \brief  Función que permite generar una lista de clientes, *
 *           * \param list ListaCliente* Pointer to array of ListaCliente
 *           * \param len lenCuits Array length
 *           * \param list *cuit
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
static void informes_listaClientesConPublicaciones(ListaCliente *cuits, int lenCuits, Cliente * ArrayCliente)
{

	int indexCont;
	int indexCuits=0;
	informes_inicializarArray(cuits, lenCuits);
	for(indexCont= 0; indexCont < lenCuits; indexCont++ )
	{
		if(informes_estaEnMiListaDeCuits(cuits, lenCuits, ArrayCliente[indexCont].cuitCliente)==0)
		{
			strcpy(cuits[indexCuits].cuit, ArrayCliente[indexCont].cuitCliente);
			cuits[indexCuits].isEmpty = FALSE;
			indexCuits++;
		}
	}
}
/** \brief  Función que permite generar una lista de clientes, *
 *           * \param list ListaCliente* Pointer to array of ListaCliente
 *           * \param len lenCuits Array length
 *           * \param list *cuit
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
void informes_generarListaClientes(Publicaciones* pArrays, int limite, Cliente * ArrayCliente, int limiteCliente)
{
	// generar la lista de clientes
	ListaCliente cuit[1000];
	informes_listaClientesConPublicaciones(cuit,1000, ArrayCliente);
	printf("\nNombre CLiente: %s - \nApellido CLiente: %s -\nCUIT CLiente: %d", ArrayCliente[limite].nombreCliente,ArrayCliente[limite].apellidoCliente, ArrayCliente[limite].cuitCliente);
	// pasar la maqueta del lgoritmo del informe aca.

}

/** \brief  Función que permite averiguar cantidad del  publicaciones pausadas, *
 *           * \param list ListaCliente* Pointer to array of ListaCliente
 *           * \param len lenCuits Array length
 *           * \param list *cuit
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int informes_catidadAvisosPausados(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int contadorPausados = 0;
	if(pArray != NULL && limite > 0 && ArrayCliente != NULL && limiteCliente > 0 )
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArray[i].estadoPublicacion == PAUSADA)
			{
				contadorPausados++;
			}
		}
		printf("\nLa cantidad de publicaciones pausadas son: %d\n", contadorPausados);
	}
	return retorno;
}
/** \brief  Función que permite averiguar cantidad del publicaciones reanudadas, *
 *           * \param list ListaCliente* Pointer to array of ListaCliente
 *           * \param len lenCuits Array length
 *           * \param list *cuit
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int informes_clienteConMasAvisos(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	int auxBuffer;
	if(pArray != NULL && limite > 0 && ArrayCliente != NULL && limiteCliente > 0 )
		{
			for(int i = 0; i < limite; i++)
			{
				if(publicaciones_buscarIndicePorId(pArray, limite, idBuscar,&indiceAModificar) == 0)
				{
					auxBuffer++;
				}
			}
		}
	return retorno;
}
