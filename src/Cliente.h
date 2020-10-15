/*
 * pPantallas.h
 *
 *  Created on: 1 oct. 2020
 *      Author: Gian
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define LONG 50
#define QTY_CLIENTES 100
#define TRUE 1
#define FALSE 0
#define MIN_NUMEROS 0
#define MAX_NUMEROS 99999999



typedef struct {
	char nombreCliente[LONG];
	char apellidoCliente[LONG];
	int cuitCliente;
	int isEmpty;
	int idCliente;
} Cliente;

int cliente_init(Cliente *pArray, int limite);

int cliente_alta(Cliente *pArray, int limite);
int cliente_baja(Cliente *pArrays, int limite);
int cliente_modificar(Cliente *pArray, int limite);

int cliente_imprimir(Cliente *pArray, int limite);

int cliente_buscarLibre(Cliente *pArray, int limite);
int cliente_buscarLibreRef(Cliente *pArray, int limite, int *pIndice);
int cliente_buscarIndicePorId(Cliente *pArray, int limite, int idBuscar,int *pIndice);
int cliente_ordenarPorNombre(Cliente *pArrays, int limite, int orden);

int cliente_altaForzada(Cliente * pArray, int limite , char * nombreCliente, char * apellidoCliente, int  cuitCliente);

#endif /* CLIENTE_H_ */
