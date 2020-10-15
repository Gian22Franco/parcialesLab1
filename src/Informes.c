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


/** \brief Permite calcular el cliente con mas avisos
 * \param Publicaciones* Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArrayCliente, Pointer to pArrayCliente array
 * \param int limiteCliente, cliente lenght

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_clienteConMasAvisos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente)
{
	int retorno=-1;
	int indiceCliente;
	int cantidadAvisos;
	int auxBuffer=TRUE;
	int maximoAvisos;
	int idMaximoAvisos;
	int indiceAImprimir;

	if(pArray!=NULL && limite>0 && pArrayCliente!=NULL && limiteCliente>0)
	{
		for(indiceCliente=0;indiceCliente<limiteCliente;indiceCliente++)
		{
			if(informes_contarAvisos(pArray,limite,pArrayCliente[indiceCliente].idCliente, &cantidadAvisos)==0)
			{
				if(auxBuffer == 0 || maximoAvisos < cantidadAvisos)
				{
					auxBuffer=FALSE;
					maximoAvisos=cantidadAvisos;
					idMaximoAvisos=pArrayCliente[indiceCliente].idCliente;
					retorno=0;
				}
			}
		}
	}
	if(cliente_buscarIndicePorId(pArrayCliente,limiteCliente, idMaximoAvisos, &indiceAImprimir)==0)
	{
		printf("CLIENTE CON MAS AVISOS");
		printf("\n Nombre Cliente - %s - Apellido Cliente %s - ID Cliente: %d - CANTIDAD AVISOS: %d\n",pArrayCliente[indiceAImprimir].nombreCliente,pArrayCliente[indiceAImprimir].apellidoCliente,idMaximoAvisos, maximoAvisos);
	}

	return retorno;
}
/** \brief cuenta cuantos avisos tiene un cliente
 * \param Publicaciones* pArrays, Pointer to Publicaciones array
 * \param int limite, Publicaciones array lenght
 * \param int idCliente, client ID
 * \param int* avisos, pointer to the memory space where the calculated value will be saved
 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_contarAvisos (Publicaciones* pArrays, int limite, int idCliente, int* avisos)
{
	int retorno = -1;
	int i;
	int bufferCounter=0;
	if(pArrays!=NULL && limite>0 && avisos!=NULL && idCliente>0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArrays[i].isEmpty==0 && pArrays[i].idCliente==idCliente && pArrays[i].estadoPublicacion==ACTIVA)
			{
				bufferCounter++;
			}
		}
		retorno = 0;
		*avisos = bufferCounter;
	}
	return retorno;
}

/* \brief  	*Función que permite averiguar cantidad de publicaciones pausadas,
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
			if(pArray[i].isEmpty==FALSE && pArray[i].estadoPublicacion == PAUSADA)
			{
				contadorPausados++;
			}
		}
		printf("PUBLICACIONES PAUSADAS");
		printf("\nLa cantidad de publicaciones pausadas son: %d\n", contadorPausados);
	}
	return retorno;
}


/** \brief Permite calcular que rubro tiene mas avisos
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArrayCliente, Pointer to Cliente array
 * \param int limiteCliente, Clients's array lenght

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_rubroConMasAvisos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente)
{
	int retorno=-1;
	int indice;
	int cantidadRubros;
	int auxBuffer=TRUE;
	int maxRubros;

	if(pArray!=NULL && limite>0 && pArrayCliente!=NULL && limiteCliente>0)
	{
		for(indice=0;indice<limiteCliente;indice++)
		{
			if(informes_contarRubro(pArray,limite,pArray[indice].numeroRubro, &cantidadRubros)==0)
			{
				if(auxBuffer==TRUE || maxRubros < cantidadRubros)
				{
					auxBuffer=FALSE;
					maxRubros=cantidadRubros;
					retorno=0;
				}
			}
		}
	}
		printf("RUBRO CON MAS AVISOS");
		printf("\nEl número del rubro con mas avisos es %d\n", maxRubros);
	return retorno;
}
/** \brief Cuenta cuantas publicaciones tiene un rubro
 * \param Advertisement* pArray, Pointer to Ads's array
 * \param int len, Ads's array lenght
 * \param int idClient, client ID
 * \param int* activeAdsCounter, pointer to the memory space where the calculated value will be saved
 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_contarRubro (Publicaciones* pArrays, int limite, int numeroRubro, int* rubros)
{
	int retorno = -1;
	int i;
	int bufferCounter=0;
	if(pArrays!=NULL && limite>0 && rubros!=NULL && numeroRubro>0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArrays[i].isEmpty == FALSE && pArrays[i].numeroRubro == numeroRubro && pArrays[i].estadoPublicacion == ACTIVA)
			{
				bufferCounter++;
			}
		}
		retorno = 0;
		*rubros = bufferCounter;
	}
	return retorno;
}

