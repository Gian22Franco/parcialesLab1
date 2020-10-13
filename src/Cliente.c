/*
 * pPantallas.c
 *
 *  Created on: 1 oct. 2020
 *      Author: Gian
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Publicaciones.h"
#include "utn.h"

static int cliente_generarNuevoId(void);

/** \brief  To indicate that all position in the array are empty, *
 *           this function put the flag (isEmpty) in TRUE in all *
 *           position of the array
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_init(Cliente *pArrays, int limite) {
	int retorno = -1;
	if (pArrays != NULL && limite > 0) {
		for (int i = 0; i < limite; i++) {
			pArrays[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}
/** \brief  Función que permite dar de alta un Cliente, *
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_alta(Cliente *pArrays, int limite) {
	int retorno = -1;
	int indice;

	Cliente bufferCliente;

	if (pArrays != NULL && limite > 0) {
		if (cliente_buscarLibreRef(pArrays, limite, &indice) == 0) {
			if (utn_getNombre("\nIngrese el nombre del cliente:\n", "error",bufferCliente.nombreCliente, 2, LONG) == 0 &&
					utn_getNombre("\nIngrese el apellido del cliente:\n","ERROR", bufferCliente.apellidoCliente, 3, LONG) == 0 &&
					utn_getInt("\nIngrese el cuit del cliente:\n","\nError!\n", &bufferCliente.cuitCliente, 3,MAX_NUMEROS, MIN_NUMEROS) == 0) {
				pArrays[indice] = bufferCliente;
				pArrays[indice].idCliente = cliente_generarNuevoId();
				pArrays[indice].isEmpty = FALSE;
				retorno = 0;
			} else {
				printf("horror");
			}
		} else {
			printf(" \n No quedan espacios libres");
		}
	}
	return retorno;
}
/** \brief  Función que permite imprimir un Cliente, *
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_imprimir(Cliente *pArrays, int limite) {
	int retorno = -1;
	if (pArrays != NULL && limite > 0) {
		for (int i = 0; i < limite; i++) {
			if (pArrays[i].isEmpty == FALSE) {
				printf(
						"\nID %d - Nombre Cliente: %s - Apellido Cliente: %s - Cuit cliente: %d",
						pArrays[i].idCliente, pArrays[i].nombreCliente,
						pArrays[i].apellidoCliente,	pArrays[i].cuitCliente);
			}
		}
		retorno = 0;
	}
	return retorno;
}
/** \brief  Función que permite dar de baja un Cliente, *
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_baja(Cliente *pArrays, int limite) {
	int retorno = -1;
	int idABorrar;
	int indiceABorrar;

	if (pArrays != NULL && limite > 0 ) {
		cliente_imprimir(pArrays, limite);
		if (utn_getInt("\nIngrese id del cliente a borrar:\n", "\nError\n", &idABorrar,3, 9999, 0) == 0) {
			if (cliente_buscarIndicePorId(pArrays, limite, idABorrar, &indiceABorrar) == 0) {
				pArrays[indiceABorrar].isEmpty = TRUE;
				retorno = 0;
			}
		}
	}
	return retorno;
}
/** \brief  Función que permite modificar un Cliente, *
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_modificar(Cliente *pArrays, int limite) {
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	Cliente bufferCliente;

	if (pArrays != NULL && limite > 0) {
		cliente_imprimir(pArrays, limite);
		printf("\n                            \n");
		if (utn_getInt("\nID del cliente a modificar:\n", "\nERROR!\n", &idBuscar, 2, 9999, 0) == 0) {
			if (cliente_buscarIndicePorId(pArrays, limite, idBuscar,&indiceAModificar) == 0) {
				bufferCliente = pArrays[indiceAModificar]; // IMPORTANTE!
				if (utn_getNombre("\nNuevo nombre del cliente?\n", "\nerror\n", bufferCliente.nombreCliente, 2, LONG) == 0) {
					if (utn_getNombre("\nNuevo apellido del cliente?\n", "\nerror\n", bufferCliente.apellidoCliente, 2, LONG) == 0) {
						if (utn_getInt("\nNuevo cuit del cliente?\n", "\nERROR\n",&bufferCliente.cuitCliente, 3, MAX_NUMEROS,	MIN_NUMEROS) == 0) {
								pArrays[indiceAModificar] = bufferCliente; // COPIAMOS AL ARRAY
								retorno = 0;
							}
						}
					}
				}
			}
		}
	return retorno;
}
/** \brief  Función que permite buscar la posición libre del array de Clientes, *
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_buscarLibre(Cliente *pArrays, int limite) {
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
/** \brief  Función que permite buscar la posición libre por referencia del array de Clientes, *
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_buscarLibreRef(Cliente *pArrays, int limite, int *pIndice) {
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
/** \brief  Función que genera automaticamente y de manera autoincremental el id de los Clientes, *
 *
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
static int cliente_generarNuevoId(void) {
	static int id = 0;
	id = id + 1;
	return id;
}
/** \brief  Función que permite buscar a los clientes por el id, *
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *             \param idBuscar id a buscar
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_buscarIndicePorId(Cliente *pArrays, int limite, int idBuscar,
		int *pIndice) {
	int retorno = -1;
	int i;
	if (pArrays != NULL && limite > 0 && pIndice != NULL && idBuscar >= 0) {
		for (i = 0; i < limite; i++) {
			if (pArrays[i].idCliente == idBuscar) {
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
/** \brief  Función que permite ordenar a los clientes por nombre *
 *           * \param list Cliente* Pointer to array of employees
 *           * \param len limite Array length
 *             \param idBuscar id a buscar
 *           * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok *
 *
 **/
int cliente_ordenarPorNombre(Cliente *pArrays, int limite, int orden) {
	int retorno = -1;
	int estadoDesordenado = 1;
	Cliente aux;
	if (pArrays != NULL && limite > 0) {
		while (estadoDesordenado) //mientras este desordenado
		{
			estadoDesordenado = 0;
			for (int i = 0; i < (limite - 1); i++) {
				if ((orden == 1	&& strncmp(pArrays[i].nombreCliente,pArrays[i + 1].nombreCliente, LONG) > 0) || (orden == 0 && strncmp(pArrays[i].nombreCliente,	pArrays[i + 1].nombreCliente, LONG) < 0)) {
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
