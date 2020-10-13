/*
 * pContratacioness.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Gian
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Publicaciones.h"
#include "Cliente.h"


static int publicaciones_generarNuevoId(void);

/** \brief  To indicate that all position in the array are empty, *
 *           this function put the flag (isEmpty) in TRUE in all *
 *           position of the array
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_init(Publicaciones *pArrays, int limite) {
	int retorno = -1;
	if (pArrays != NULL && limite > 0) {
		for (int i = 0; i < limite; i++) {
			pArrays[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}
/** \brief  Función que permite dar de alta una Publicación *
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limiteCliente Array length
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_alta(Publicaciones *pArray, int limite,	Cliente *pArrayCliente, int limiteCliente) {
	int retorno = -1;
	int indice;
	Publicaciones bufferPublicaciones;

	printf("\n-------------------------------\n");
	cliente_imprimir(pArrayCliente, QTY_CLIENTES);
	printf("\n                               \n");
	printf("\n-------------------------------\n");

	if (pArray != NULL && limite > 0 && pArrayCliente != NULL&& limiteCliente > 0) {
				if (publicaciones_buscarLibreRef(pArray, limite, &indice)== 0)
				{
					if (    utn_getInt("\nIngrese el ID del cliente:\n","ERROR", &bufferPublicaciones.idCliente,3, MAX_NUMEROS, MIN_NUMEROS) == 0
							&& utn_getNombre("\nIngrese el texto del aviso:\n","error", bufferPublicaciones.textoAviso, 2,LONG) == 0
							&& utn_getInt("\nIngrese el numero del rubro:\n","ERROR", &bufferPublicaciones.numeroRubro,3, MAX_NUMEROS, MIN_NUMEROS) == 0)
					{
						pArray[indice] = bufferPublicaciones;
						pArray[indice].idPublicaciones =publicaciones_generarNuevoId();
						pArray[indice].estadoPublicacion = ACTIVA;
						pArray[indice].isEmpty = FALSE;
						retorno = 0;
					}
					else
					{
						printf("horror");
					}
				}
				else
				{
					printf("\nNo quedan espacios libres");
				}
			}
	return retorno;
}

/** \brief  Función que permite imprimir una Publicación *
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limiteCliente Array length
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_imprimir(Publicaciones *pArrays, int limite, Cliente *pArrayCliente, int limiteCliente) {
	int retorno = -1;

	if (pArrays != NULL && limite > 0 && pArrayCliente != NULL && limiteCliente > 0) {
		for (int i = 0; i < limite; i++) {
			if (pArrays[i].isEmpty == FALSE) {
				printf(
						"\nID Cliente: %d -Numero de rubro: %d - Texto Aviso: %s- ID Publicaciones: %d ",
						pArrayCliente[i].idCliente, pArrays[i].numeroRubro,
						pArrays[i].textoAviso, pArrays[i].idPublicaciones);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/** \brief  Función que permite dar de baja una Publicación *
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limiteCliente Array length
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_baja(Publicaciones *pArrays, int limite, Cliente *pArrayCliente, int limiteCliente ) {
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;
	int auxBuffer;

			printf("\n-------------------------------\n");
			publicaciones_imprimir(pArrays, limite, pArrayCliente, limiteCliente);
			printf("\n                               \n");
			printf("\n-------------------------------\n");

	if (pArrays != NULL && limite > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{
		if(utn_getInt("\nIngrese el cuit del cliente: \n","\nError!\n",	&auxBuffer, 3,MAX_NUMEROS, MIN_NUMEROS)==0)
		{
			cliente_imprimir(pArrayCliente, QTY_CLIENTES);
		}
			if (utn_getInt("Ingrese id de pantalla a borrar", "Error", &idABorrar,3, 0, 9999) == 0)
			{
				// busco la posicion a borrar
				if (publicaciones_buscarIndicePorId(pArrays, limite, idABorrar,&indiceABorrar) == 0)
				{
					// borro esa posicion
					pArrays[indiceABorrar].isEmpty = TRUE;
					retorno = 0;
				}
			}
	}
	return retorno;
}
/** \brief  Función que permite modificar una Publicación *
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limiteCliente Array length
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_modificar(Publicaciones *pArrays, int limite,  Cliente *pArrayCliente, int limiteCliente)
{

	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	int auxBuffer;
	Publicaciones bufferPublicaciones;


	    printf("\n-------------------------------\n");
	    publicaciones_imprimirPorId(pArrays, limite, pArrayCliente, limiteCliente, auxBuffer);
		printf("\n                               \n");
		printf("\n-------------------------------\n");

	if (pArrays != NULL && limite > 0 && pArrayCliente != NULL && limiteCliente > 0)
	{
		if(utn_getInt("\nIngrese el cuit del cliente: \n","\nError!\n",	&auxBuffer, 3,MAX_NUMEROS, MIN_NUMEROS)==0)
		{
			cliente_imprimir(pArrayCliente, QTY_CLIENTES);
		}
		//publicaciones_imprimir(pArrays, limite, pArrayCliente, limiteCliente);
		if (utn_getInt("ID a modificar:", "ERROR!", &idBuscar, 2, 9999, 0) == 0)
		{
			if (publicaciones_buscarIndicePorId(pArrays, limite, idBuscar,	&indiceAModificar) == 0)
			{
				bufferPublicaciones = pArrays[indiceAModificar]; // IMPORTANTE!
						if (utn_getInt("\nIngrese el nuevo numero de rubro", "ERROR",&bufferPublicaciones.numeroRubro, 3, MAX_NUMEROS,	MIN_NUMEROS) == 0)
						{
								pArrays[indiceAModificar] = bufferPublicaciones; // COPIAMOS AL ARRAY
								retorno = 0;
						}
				}
			}
		}
	return retorno;
	}

/** \brief  Función que permite encontrar la posicion libre del array Publicaciónes *
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limiteCliente Array length
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_buscarLibre(Publicaciones *pArrays, int limite) {
	int retorno = -1;
	int i;
	if (pArrays != NULL && limite > 0) {
		for (i = 0; i < limite; i++) {
			if (pArrays[i].isEmpty == TRUE) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/** \brief  Función que permite encontrar la posicion libre por referencia del array Publicaciónes*
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limiteCliente Array length
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_buscarLibreRef(Publicaciones *pArrays, int limite, int *pIndice) {
	int retorno = -1;
	int i;
	if (pArrays != NULL && limite > 0 && pIndice != NULL) {
		for (i = 0; i < limite; i++) {
			if (pArrays[i].isEmpty == TRUE) {
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief  Función que genera auatomaticamente y de manera autoincremental un id a las publicacioens*
 *          void
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
static int publicaciones_generarNuevoId(void) {
	static int id = 0;
	id = id + 1;
	return id;
}
/** \brief  Función que permite encontrar la posicion libre por referencia del array Publicaciónes*
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \param int  idBuscar dato recibido del usuario
 *           * \param *pIndice se guarda el indice de ese id,
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_buscarIndicePorId(Publicaciones *pArrays, int limite, int idBuscar,
		int *pIndice) {
	int retorno = -1;
	int i;
	if (pArrays != NULL && limite > 0 && pIndice != NULL && idBuscar >= 0) {
		for (i = 0; i < limite; i++) {
			if (pArrays[i].idPublicaciones == idBuscar) {
				*pIndice = i;
				retorno = 0;
				break;
			}
		}
	} else {
		printf("errrror");
	}
	return retorno;
}
/** \brief  Función que permite ordenar por nombre las Publicaciónes*
 *           * \param list Publicaciones* Pointer to array of employees
 *           * \param len limite Array length
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limiteCliente Array length
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int publicaciones_ordenarPorNombre(Publicaciones *pArrays, int limite, int orden) {
	int retorno = -1;
	int estadoDesordenado = 1;
	Publicaciones aux;
	if (pArrays != NULL && limite > 0) {
		while (estadoDesordenado) //mientras este desordenado
		{
			estadoDesordenado = 0;
			for (int i = 0; i < (limite - 1); i++) {
				if ((orden == 1
						&& strncmp(pArrays[i].textoAviso,
								pArrays[i + 1].textoAviso, LONG) > 0)
						|| (orden == 0
								&& strncmp(pArrays[i].textoAviso,
										pArrays[i + 1].textoAviso, LONG) < 0)) {
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


int publicaciones_imprimirPorId(Publicaciones*pArrays, int limite, Cliente* pArrayCliente, int limiteCliente,int idImprimir)
{
	int retorno = -1;
	if (pArrays != NULL && limite > 0 && pArrayCliente != NULL && limiteCliente > 0) {
		for (int i = 0; i < limite; i++) {
			if (pArrays[i].idCliente == idImprimir) {
				printf(
						"\nID Cliente %d -Numero de rubro:%d - Texto publicación:%s - ID publicacion: %d - Estado Publicacion: %d",
						pArrayCliente[i].idCliente, pArrays[i].numeroRubro,
						pArrays[i].textoAviso, pArrays[i].idPublicaciones,  pArrays[i].estadoPublicacion);			}
		}
		retorno = 0;
	}

	return retorno;
}

int publicaciones_pausarPublicacion(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int auxBuffer;
	int opcion;
	printf("\n-------------------------------\n");
	publicaciones_imprimir(pArray, limite, ArrayCliente, limiteCliente);
	printf("\n                               \n");
	printf("\n-------------------------------\n");

	if(pArray != NULL && limite > 0 && ArrayCliente != NULL && limiteCliente > 0 )
	{
		if(utn_getInt("\nIngrese el id de la publicacion que quiere pausar: \n","\nError!\n",	&auxBuffer, 3,MAX_NUMEROS, MIN_NUMEROS)==0)
				{
					for (int i = 0; i < limiteCliente; i++ )
					{
						if(auxBuffer == ArrayCliente[i].idCliente)
						{
							printf("\nNombre %s - Apellido %s - CUIT: %d - ID: %d\n", ArrayCliente[i].nombreCliente, ArrayCliente[i].apellidoCliente, ArrayCliente[i].cuitCliente, ArrayCliente[i].idCliente );
							printf("\n-------------------------------\n");
							if(utn_getInt("\nSeguro quiere pausar su publicacion? (SI = 1 / NO = 2)\n","\nError!\n",&opcion, 3,MAX_NUMEROS, MIN_NUMEROS)==0)
							{
								switch(opcion)
								{
									case 1:
										pArray[i].estadoPublicacion = PAUSADA ;
										printf("\n-------------------------------\n");
										printf("\nSu publicación esta PAUSADA\n");
										printf("\n-------------------------------\n");

									break;
									case 2:
										printf("\n-------------------------------\n");
										printf("\nSu publicación sigue ACTIVA\n");
										 printf("\n-------------------------------\n");
									break;
								}
							}
						}
					}
				}
	}

	return retorno;
}



int publicaciones_reanudarPublicacion(Publicaciones *pArray, int limite, Cliente * ArrayCliente, int limiteCliente)
{
	int retorno = -1;
	int auxBuffer;
	int opcion;

	printf("\n-------------------------------\n");
	publicaciones_imprimir(pArray, limite, ArrayCliente, limiteCliente);
	printf("\n                               \n");
	printf("\n-------------------------------\n");

	if(pArray != NULL && limite > 0 && ArrayCliente != NULL && limiteCliente > 0 )
	{
		if(utn_getInt("\nIngrese el id de la publicacion que quiere reanudar: \n","\nError!\n",	&auxBuffer, 3,MAX_NUMEROS, MIN_NUMEROS)==0)
				{
					for (int i = 0; i < limiteCliente; i++ )
					{
						if(auxBuffer == ArrayCliente[i].idCliente)
						{
							printf("\nNombre %s - Apellido %s - CUIT: %d - ID: %d\n", ArrayCliente[i].nombreCliente, ArrayCliente[i].apellidoCliente, ArrayCliente[i].cuitCliente, ArrayCliente[i].idCliente );
							printf("\n-------------------------------\n");
							if(utn_getInt("\nSeguro quiere pausar su publicacion? (SI = 1 / NO = 2)\n","\nError!\n",&opcion, 3,MAX_NUMEROS, MIN_NUMEROS)==0)
							{
								switch(opcion)
								{
									case 1:
										pArray[i].estadoPublicacion = ACTIVA ;
										printf("\n-------------------------------\n");
										printf("\nSu publicación esta ACTIVA\n");
										printf("\n-------------------------------\n");
									break;
									case 2:
										printf("\n-------------------------------\n");
										printf("\nSu publicación sigue PAUSADA\n");
										printf("\n-------------------------------\n");
									break;
								}
							}
						}
					}
				}
	}
	return retorno;
}





