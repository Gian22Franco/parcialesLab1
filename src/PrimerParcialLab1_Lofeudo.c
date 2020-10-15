/*
 ============================================================================
 Name        : Pantallas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Publicaciones.h"
#include "Informes.h"

int main(void)
{
	setbuf(stdout, NULL);
	int op;
	int opInforme;

	Cliente arrayCliente[QTY_CLIENTES];
	Publicaciones arrayPublicaciones[QTY_PUBLICACIONES];

	cliente_init(arrayCliente, QTY_CLIENTES);
	publicaciones_init(arrayPublicaciones, QTY_PUBLICACIONES);

		cliente_altaForzada(arrayCliente, QTY_CLIENTES,"Gianfranco","Lofeudo",111111);
		cliente_altaForzada(arrayCliente, QTY_CLIENTES,"Mateo","Melli",222222);
		cliente_altaForzada(arrayCliente, QTY_CLIENTES,"Carolina","Torrado",33333);
		cliente_altaForzada(arrayCliente, QTY_CLIENTES,"Alberto","Lofeudo",44444);
		cliente_altaForzada(arrayCliente, QTY_CLIENTES,"Flavia","Forin",55555);
		cliente_altaForzada(arrayCliente, QTY_CLIENTES,"Fernando","Lofeudo",66666);


		publicaciones_altaForzada(arrayPublicaciones,QTY_PUBLICACIONES,2,3,"aaaaaaaaaa");
		publicaciones_altaForzada(arrayPublicaciones,QTY_PUBLICACIONES,3,3,"bbbbbbbbbb");
		publicaciones_altaForzada(arrayPublicaciones,QTY_PUBLICACIONES,1,2,"cccccccccc");
		publicaciones_altaForzada(arrayPublicaciones,QTY_PUBLICACIONES,1,3,"dddddddddd");
		publicaciones_altaForzada(arrayPublicaciones,QTY_PUBLICACIONES,5,5,"eeeeeeeeee");
		publicaciones_altaForzada(arrayPublicaciones,QTY_PUBLICACIONES,4,5,"ffffffffff");
		publicaciones_altaForzada(arrayPublicaciones,QTY_PUBLICACIONES,6,5,"gggggggggg");

	do {

		utn_getInt(
				"\n1-Alta Cliente\n2-Modificar Cliente\n3-Baja Cliente\n4-Alta publicación\n5-Pausar publicación\n6-Reanudar publicación\n7-Imprimir Clientes\n8-Informar\n9-Salir\n",
				"\nError", &op, 2, 9, 1);

		switch (op) {
		case 1:
			if (cliente_alta(arrayCliente, QTY_CLIENTES) == 0) {
				printf("\n-----------------------------------------------------------------------------------------------\n");
				printf("\nCarga realizada con exito!!\n");
				printf("\n-----------------------------------------------------------------------------------------------\n");
			}
			break;
		case 2:
			printf("\n                            \n");
			printf("\n-----------------------------------------------------------------------------------------------\n");
			if (cliente_modificar(arrayCliente, QTY_CLIENTES) == 0) {
				printf("\n-----------------------------------------------------------------------------------------------\n");
				printf("\nModificación realizada con exito!!\n");
				printf("\n-----------------------------------------------------------------------------------------------\n");
			}
			break;
		case 3:
			printf("\n                            \n");
			printf("\n-----------------------------------------------------------------------------------------------\n");
			if (publicaciones_bajaClientes(arrayPublicaciones, QTY_PUBLICACIONES, arrayCliente, QTY_CLIENTES)==0) {
				printf("\n-----------------------------------------------------------------------------------------------\n");
				printf("\nBaja realizada con exito!!\n");
				printf("\n-----------------------------------------------------------------------------------------------\n");
			}
			break;
		case 4:
			if (publicaciones_alta(arrayPublicaciones, QTY_PUBLICACIONES, arrayCliente, QTY_CLIENTES )
					== 0) {
				printf("\n-----------------------------------------------------------------------------------------------\n");
				printf("\nAlta publicación realizada con exito!!\n");
				printf("\n-----------------------------------------------------------------------------------------------\n");
			}
			break;
		case 5:
				printf("\n----------------------------\n");
				publicaciones_pausarPublicacion(arrayPublicaciones, QTY_PUBLICACIONES, arrayCliente, QTY_CLIENTES);
				printf("\n----------------------------\n");
			break;
		case 6:
				printf("\n-----------------------------------------------------------------------------------------------\n");
				publicaciones_reanudarPublicacion(arrayPublicaciones, QTY_PUBLICACIONES, arrayCliente, QTY_CLIENTES);
				printf("\n-----------------------------------------------------------------------------------------------\n");

			break;
		case 7:
				printf("\n-----------------------------------------------------------------------------------------------\n");
				publicaciones_imprimirListaClientes(arrayPublicaciones, QTY_PUBLICACIONES, arrayCliente, QTY_CLIENTES);
				printf("\n-----------------------------------------------------------------------------------------------\n");

			break;
		case 8:

			do{
				if(utn_getInt("\n1- Cliente con más avisos.\n2- Cantidad de avisos pausados.\n3- Rubro con mas avisos.\n4- Salir.\n","\nError", &opInforme, 2, 4, 1)==0)
				{
					switch (opInforme) {
					case 1:
						printf("\n-----------------------------------------------------------------------------------------------\n");
						informes_clienteConMasAvisos(arrayPublicaciones,	QTY_PUBLICACIONES, arrayCliente, QTY_CLIENTES);
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					case 2:
						printf("\n-----------------------------------------------------------------------------------------------\n");
						informes_catidadAvisosPausados(arrayPublicaciones, QTY_PUBLICACIONES, arrayCliente, QTY_CLIENTES);
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					case 3:
						printf("\n-----------------------------------------------------------------------------------------------\n");
						informes_rubroConMasAvisos(arrayPublicaciones,	QTY_PUBLICACIONES, arrayCliente, QTY_CLIENTES);
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
			 }
			}while(opInforme != 4);
		}
	} while (op != 9);

	return EXIT_SUCCESS;
}
