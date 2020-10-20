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
	int auxBuffer=FALSE;
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
					auxBuffer=TRUE;
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
			if(pArrays[i].isEmpty== FALSE && pArrays[i].idCliente==idCliente && pArrays[i].estadoPublicacion == ACTIVA)
			{
				bufferCounter++;
				retorno=0;
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

int informes_catidadAvisosActivos(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int contadorPausados = 0;
	if(pArray != NULL && limite > 0 && ArrayCliente != NULL && limiteCliente > 0 )
	{
		for(int i = 0; i < limite; i++)
		{
			if(pArray[i].isEmpty==FALSE && pArray[i].estadoPublicacion == ACTIVA)
			{
				contadorPausados++;
			}
		}
		printf("PUBLICACIONES ACTIVAS");
		printf("\nLa cantidad de publicaciones Activas son: %d\n", contadorPausados);
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
 * \param Publicaciones* pArray, Pointer to Ads's array
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
/** \brief Permite calcular el cliente con mas avisos pausados
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArrayCliente, Pointer to Cliente array
 * \param int limiteCliente, Clients's array lenght

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_clienteConMasAvisosPausados(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente)
{
	    int retorno = -1;
		int indiceCliente;
		int cantidadAvisosPausados;
		int auxBuffer=TRUE;
		int maximoAvisosPausados;
		Cliente auxBufferCliente;


		if(pArray!=NULL && limite>0 && pArrayCliente!=NULL && limiteCliente>0)
		{
			for(indiceCliente=0; indiceCliente<limiteCliente; indiceCliente++)
			{
				if(informes_contarAvisosPausados(pArray,limite,pArrayCliente[indiceCliente].idCliente, &cantidadAvisosPausados)==0)
				{
					if(auxBuffer == TRUE || maximoAvisosPausados < cantidadAvisosPausados)
					{
						auxBuffer= FALSE;
						maximoAvisosPausados=cantidadAvisosPausados;
						strncpy(auxBufferCliente.nombreCliente,pArrayCliente[indiceCliente].nombreCliente,LONG);
						strncpy(auxBufferCliente.apellidoCliente,pArrayCliente[indiceCliente].apellidoCliente,LONG);
						auxBufferCliente.idCliente = pArrayCliente[indiceCliente].idCliente;

						retorno=0;
					}
				}

			}
		}
		if(retorno == 0)
		{
			printf("CLIENTE CON MAS AVISOS PAUSADOS");
			printf("\n Nombre Cliente - %s - Apellido Cliente %s - ID Cliente: %d \n",auxBufferCliente.nombreCliente,auxBufferCliente.apellidoCliente, auxBufferCliente.idCliente);
		}

		return retorno;
}

/** \brief Permite contar avisos por cliente
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArrayCliente, Pointer to Cliente array
 * \param int limiteCliente, Clients's array lenght

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_contarAvisosPausados (Publicaciones* pArrays, int limite, int idCliente, int* avisos)
{
	int retorno = -1;
	int i;
	int bufferCounter=0;
	if(pArrays!=NULL && limite>0 && avisos!=NULL && idCliente>0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArrays[i].idCliente == idCliente && pArrays[i].estadoPublicacion == PAUSADA)
			{
				bufferCounter++;
			}
		}
		retorno = 0;
		*avisos = bufferCounter;
	}
	return retorno;
}
/** \brief permite calcular cliente con mas avisos activos
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArrayCliente, Pointer to Cliente array
 * \param int limiteCliente, Clients's array lenght

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_clienteConMasAvisosActivos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente)
{
	 	 	int retorno = -1;
			int indice;
			int cantidadAvisos;
			int auxBuffer=FALSE;
			int maximoAvisos;
			//int indiceAImprimir;
			Cliente auxBufferCliente;

			if(pArray!=NULL && limite>0 && pArrayCliente!=NULL && limiteCliente>0)
			{
				for(indice=0;indice<limiteCliente;indice++)
				{
					if(informes_contarAvisosActivos(pArray,limite,pArrayCliente[indice].idCliente, &cantidadAvisos)==0)
					{

						if(auxBuffer == TRUE || maximoAvisos < cantidadAvisos)
						{

							auxBuffer=FALSE;
							maximoAvisos=cantidadAvisos;
							strncpy(auxBufferCliente.nombreCliente,pArrayCliente[indice].nombreCliente,LONG);
							strncpy(auxBufferCliente.apellidoCliente,pArrayCliente[indice].apellidoCliente,LONG);
							auxBufferCliente.idCliente = pArrayCliente[indice].idCliente;

							retorno=0;
						}
					}
				}
			}
			printf("CLIENTE CON MAS AVISOS ACTIVOS");
			printf("\n Nombre Cliente - %s - Apellido Cliente %s - ID cliente: %d \n",auxBufferCliente.nombreCliente,auxBufferCliente.apellidoCliente,auxBufferCliente.idCliente);

			return retorno;
}
/** \brief permite contar avisos activos por cliente
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArrayCliente, Pointer to Cliente array
 * \param int limiteCliente, Clients's array lenght

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_contarAvisosActivos(Publicaciones* pArrays, int limite, int idCliente, int* avisos)
{
	int retorno = -1;
	int i;
	int bufferCounter=0;
	if(pArrays!=NULL && limite>0 && avisos!=NULL && idCliente>0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArrays[i].idCliente==idCliente && pArrays[i].estadoPublicacion == ACTIVA)
			{
				bufferCounter++;
			}
		}
		*avisos = bufferCounter;
		retorno = 0;
	}
	return retorno;
}
/** \brief permite imprimir rubros ordenados
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArrayCliente, Pointer to Cliente array
 * \param int limiteCliente, Clients's array lenght

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
 int informes_imprimirRubrosOrdenados(Publicaciones* pArray, int limite, Cliente* pArrayCliente,int limiteCliente)
 {
	 int retorno=-1;
	 	int i;
	 	//int cantidadAvisos=0;
	 	if(pArray!=NULL && limite>0 && pArrayCliente!=NULL && limiteCliente>0)
	 	{
	 		printf("\nRUBROS ORDENADOS:\n");
	 		printf("\n--------------------------------------\n");
	 		for(i=0; i<limite; i++)
	 		{
	 			if(pArray[i].isEmpty == FALSE  && informe_ordenarRubros(pArray,limite,1)==0)
	 			{
	 				if(pArray[i].numeroRubro != pArray[i+1].numeroRubro )
	 				{
	 					printf("\nNumero de Rubro: %d\n",pArray[i].numeroRubro);
	 						 				retorno=0;
	 				}
	 			}
	 		}
	 	}

	 	return retorno;
 }

 /** \brief permite ordenar rubros segun el orden que se necesite
  * \param Publicaciones* pArray, Pointer to Publicaciones array
  * \param int limite, Ads's array lenght
  * \param Cliente* pArrayCliente, Pointer to Cliente array
  * \param int limiteCliente, Clients's array lenght

  * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
  */
 int informe_ordenarRubros(Publicaciones *pArrays, int limite, int orden)
 {
 	int retorno = -1;
 	int estadoDesordenado = 1;
 	Publicaciones aux;
 	if (pArrays != NULL && limite > 0 )
 	{
 		while (estadoDesordenado) //mientras este desordenado
 		{
 			estadoDesordenado = 0;
 			for (int i = 0; i < (limite - 1); i++)
 			{
 				if ((orden == 1 && pArrays[i].numeroRubro > pArrays[i + 1].numeroRubro) ||( orden == 0  && pArrays[i].isEmpty == FALSE && pArrays[i].numeroRubro < pArrays[i + 1].numeroRubro)) // @suppress("Suggested parenthesis around expression")
 				{

 					aux = pArrays[i];
 					pArrays[i] = pArrays[i + 1];
 					pArrays[i + 1] = aux;
 					estadoDesordenado = 1;
 				}
 			}
 		}
 		retorno = 0;
 	}
 	return retorno;
 }
 /** \brief permite imprimir el cliente con menos avisos
  * \param Publicaciones* pArray, Pointer to Publicaciones array
  * \param int limite, Ads's array lenght
  * \param Cliente* pArrayCliente, Pointer to Cliente array
  * \param int limiteCliente, Clients's array lenght

  * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
  */
 int informes_clienteConMenosAvisos(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente)
 {
 	 	 	int retorno = -1;
 			int indice;
 			int cantidadAvisos;
 			int auxBuffer=FALSE;
 			int minimoAvisos;
 			int indiceAImprimir;
 			int idMinimoAvisos;


 			if(pArray!=NULL && limite>0 && pArrayCliente!=NULL && limiteCliente>0)
 			{
 				for(indice=0;indice<limiteCliente;indice++)
 				{
 					if(informes_contarAvisosTotales(pArray,limite,pArrayCliente[indice].idCliente, &cantidadAvisos)==0)
 					{

 						if(auxBuffer == 0 || cantidadAvisos <  minimoAvisos  )
 										{
 											auxBuffer=TRUE;
 											minimoAvisos=cantidadAvisos;
 											idMinimoAvisos = pArrayCliente[indice].idCliente;
 											retorno=0;
 										}
 									}
 								}
 							}
 							if(cliente_buscarIndicePorId(pArrayCliente,limiteCliente, idMinimoAvisos, &indiceAImprimir)==0)
 							{
 								printf("\nCLIENTE CON MENOS AVISOS\n");
 								printf("\n Nombre Cliente - %s - Apellido Cliente %s - ID Cliente: %d - CANTIDAD AVISOS: %d\n",pArrayCliente[indiceAImprimir].nombreCliente,pArrayCliente[indiceAImprimir].apellidoCliente,idMinimoAvisos, minimoAvisos);
 							}
 					return retorno;
 }
 /** \brief permite calcular los avisos que tiene un rubro
  * \param Publicaciones* pArray, Pointer to Publicaciones array
  * \param int limite, Ads's array lenght
  * \param int idCliente id a buscar en el array
  * \param int avisos, puntero para guardar el contador

  * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
  */
 int informes_contarAvisosTotales(Publicaciones* pArrays, int limite, int idCliente, int* avisos)
 {
 	int retorno = -1;
 	int i;
 	int bufferCounter=0;
 	if(pArrays!=NULL && limite>0 && avisos!=NULL && idCliente>0)
 	{
 		for(i=0;i<limite;i++)
 		{
 			if(pArrays[i].idCliente==idCliente)
 			{
 				bufferCounter++;
 				//retorno=0;
 			}
 		}
 		*avisos = bufferCounter;
 		retorno = 0;
 	}
 	return retorno;
 }

 /** \brief permite imprimir el cliente con menos avisos
  * \param Publicaciones* pArray, Pointer to Publicaciones array
  * \param int limite, Ads's array lenght
  * \param Cliente* pArrayCliente, Pointer to Cliente array
  * \param int limiteCliente, Clients's array lenght

  * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
  */
 int informes_cantidadPorRubro(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente)
 {
	 int retorno = -1;
	 int auxBuffer;
	 int contadorRubros;

	 printf("\n----------------------\n");
	 informes_imprimirRubrosOrdenados(pArray, limite, pArrayCliente, limiteCliente);
	 printf("\n----------------------\n");

	 if(pArray != NULL && pArrayCliente != NULL && limite > 0 && limiteCliente > 0)
	 {
		 if (utn_getInt("\nIngrese el numero de Rubro a buscar:\n","ERROR", &auxBuffer,3, MAX_NUMEROS, MIN_NUMEROS) == 0)
		 {
			 if(informes_contarRubros(pArray, QTY_PUBLICACIONES, auxBuffer, &contadorRubros )==0)
			 {
				 printf("La cantidad de avisos que tiene el rubro %d es %d", auxBuffer, contadorRubros);
			 }
		 }
	 }
	 return retorno;
 }

 /** \brief permite calcular los avisos que tiene un rubro
  * \param Publicaciones* pArray, Pointer to Publicaciones array
  * \param int limite, Ads's array lenght
  * \param int numeroRubro numero a buscar en el array
  * \param int cantidad, puntero para guardar el contador

  * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
  */
int informes_contarRubros(Publicaciones* pArrays, int limite, int numeroRubro, int*cantidad)
{
	int retorno = -1;
	int bufferCounter = 0;
	if(pArrays != NULL && limite > 0 && cantidad != NULL && numeroRubro > 0 )
	{
		for(int i = 0; i<limite; i++)
		{
			if(pArrays[i].numeroRubro == numeroRubro)
			{
				bufferCounter++;
				retorno=0;
			}
		}
		*cantidad = bufferCounter;
	}
	return retorno;
}
/** \brief permite imprimir el cliente con menos avisos
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArrayCliente, Pointer to Cliente array
 * \param int limiteCliente, Clients's array lenght

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_cantidadPorCliente(Publicaciones* pArray,int limite ,Cliente* pArrayCliente,int limiteCliente)
{
	 int retorno = -1;
	 int auxBuffer;
	 int indiceAImprimir;
	 int contadorAvisos;
	 int idABuscar;

	 printf("\n----------------------\n");
	 cliente_imprimir(pArrayCliente, limiteCliente);
	 printf("\n----------------------\n");

	 if(pArray != NULL && pArrayCliente != NULL && limite > 0 && limiteCliente > 0)
	 {
		 if (utn_getInt("\nIngrese el numero de cuit a buscar:\n","ERROR", &auxBuffer,3, MAX_NUMEROS, MIN_NUMEROS) == 0)
		 {
			 if(informe_buscaridClientePorCuit(pArrayCliente,limite,auxBuffer, &idABuscar)==0)
			 {
				 if(informes_publicacionesPorCliente(pArray, limite, idABuscar, &contadorAvisos )==0)
				 		{
					 if(informe_buscarIndicePorCuit(pArrayCliente,limite,auxBuffer, &indiceAImprimir)==0)
					 	 	 {
						 	 printf("\nLa cantidad de avisos que tiene el cliente %s %s es %d\n",pArrayCliente[indiceAImprimir].nombreCliente,pArrayCliente[indiceAImprimir].apellidoCliente ,contadorAvisos);
					 	 	 }
				 		}
			 }
		 }
	 }
	 return retorno;
}
/** \brief permite calcular los avisos que tiene un rubro
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param Cliente* pArray, Pointer to Cliente array
 * \param int limiteCliente, Clientes array lenght
 * \param int numeroCuit numero a buscar en el array
 * \param int cantidad, puntero para guardar el contador

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_contarAvisosCliente(Publicaciones* pArrays, int limite, Cliente * pArraysCliente, int limiteCliente ,int numeroCuit, int*cantidad)
{
	int retorno = -1;
	int bufferCounter = 0;
	if(pArrays != NULL && pArraysCliente != NULL && limite > 0 && limiteCliente > 0 && cantidad != NULL && numeroCuit > 0 )
	{
		for(int i = 0; i<limite; i++)
		{
			if(pArraysCliente[i].cuitCliente == numeroCuit)
			{
				bufferCounter++;
				retorno=0;
			}
		}
		*cantidad = bufferCounter;
		//retorno=0;
	}
	return retorno;
}

/** \brief permite imprimir el cliente con menos avisos
 * \param Publicaciones* pArray, Pointer to Publicaciones array
 * \param int limite, Ads's array lenght
 * \param int id, id del cliente a buscar publicaciones
 * \param int *pResultado, puntero donde se guarda el contador

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informes_publicacionesPorCliente(Publicaciones* pArray, int limite ,int id ,int *pResultado)
{
	int retorno=-1;
	int indiceAviso;
	int contadorAvisos=0;

	if(pArray!=NULL &&limite>0 && id>0 && pResultado!=NULL)
	{
		for(indiceAviso=0;indiceAviso<limite;indiceAviso++)
		{
			if(pArray[indiceAviso].isEmpty==FALSE && id==pArray[indiceAviso].idCliente && pArray[indiceAviso].estadoPublicacion== ACTIVA)
			{
				contadorAvisos++;
			}
		}
	}
	*pResultado=contadorAvisos;
	retorno=0;
	return retorno;
}
/** \brief permite buscar el indice de un cliente por cuit
 * \param Cliente* pArrayCliente, Pointer to Cliente array
 * \param int limite, Ads's array lenght
 * \param int cuitBuscar cuit que se utiliza para buscar el cliente
 * \param int *pIndice, puntero donde se guarda el indice encontrado

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informe_buscarIndicePorCuit(Cliente *pArrays, int limite, int cuitBuscar,int *pIndice) {
	int retorno = -1;
	int i;
	if (pArrays != NULL && limite > 0 && pIndice != NULL && cuitBuscar >= 0) {
		for (i = 0; i < limite; i++) {
			if (pArrays[i].cuitCliente == cuitBuscar) {
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	} else {
		printf("ERROR");
	}
	return retorno;
}
/** \brief permite buscar un cliente por su cuit
 * \param Cliente* pArrays, Pointer to Cliente array
 * \param int limite, Ads's array lenght
 * \param int cuitBuscar, cuit a utilizar para buscar el id
 * \param int * pIndice puntero donde se guarda el id del cliente

 * \return (0) if OK or (-1) if [Invalid lenght or NULL pointer received or employee not found
 */
int informe_buscaridClientePorCuit(Cliente *pArrays, int limite, int cuitBuscar,int *pIndice) {
	int retorno = -1;
	int i;
	if (pArrays != NULL && limite > 0 && pIndice != NULL && cuitBuscar >= 0) {
		for (i = 0; i < limite; i++) {
			if (pArrays[i].cuitCliente == cuitBuscar) {
				*pIndice = pArrays[i].idCliente;
				retorno = 0;
				break;
			}
		}
	} else {
		printf("ERROR");
	}
	return retorno;
}
