/*
 ============================================================================
 Name        : NewParcial.c
 Author      : Gian Franzoso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "nexoLib.h"

#define TAM 20
#define TOP 20
#define MAX 3
int main(void) {

	setbuf(stdout,NULL);
	int opcion;
	eCliente lista[TAM];
	ePedidos pedido[TAM];
	eTransporte medio[MAX];
	int idAutoPedido=0;
	int idAuto = 999;

	printf("Bienvenido, elija una opcion \n\n");
	InicializarLista(lista,TAM);
	inicializarPedidos(pedido,TAM);
	HardcodearTransporte(medio, MAX);
	do{
	opcion=menuPrincipal();
	switch (opcion) {
	case 1:
		if(AltaCliente(&idAuto,lista,TAM)==1){
			printf("\n El Alta ha sido Exitosa \n");
		}
		break;
	case 2:
		if(modificarClientes(lista, TAM)==1){
			printf("\n Modificacion Exitosa \n");
		}
		break;
	case 3:
		if(BajaDeCliente(lista, TAM)==1){
			printf("\n Baja Exitosa \n");
		}
		break;
	case 4:
		if(altaPedido(lista, pedido,medio, MAX, TOP, TAM, &idAutoPedido)==1){
			printf("\n Alta de Pedido Exitosa \n");
		}
		break;
	case 5:
		if(procesarResiduos(pedido, TOP)==1){
			printf("\n Procesado Exitoso \n");
		}
		break;
	case 6:
		if(mostrarClientes_CantidadPendiente(lista, TAM, pedido, TOP)==1)
		{
			printf("\n Muestra Exitosa \n");
		}
		break;
	case 7:
		if(imprimirKg_Pendientes(lista, TAM, pedido, TOP)==1)
		{
			printf("\n Muestra Exitosa \n");
		}
		break;
	case 8:
		if(imprimirKg_Completados(lista, TAM, pedido,TOP)==1){
			printf("\n Muestra Exitosa \n");
		}
		break;
	case 9:
		if(pendientesPorLocalidad(lista, TAM, pedido,TOP)==1){
			printf("\n Pendientes por Localidad Exitoso \n");
		}
		break;
	case 10:
		if(promedio_Clientes(lista, TAM, pedido, TOP)==1){
			printf("\n Polipropileno Ok \n");
		}
		break;
	case 11:
		if(mayorMedio_Transporte(pedido, TOP, medio, MAX, lista, TAM)==1)
		{
			printf("Mayor transporte ok \n");
		}
		break;
	}
	case 12:
		printf("Hasta Luego\n");
		break;

	}while(opcion!=12);
	return 0;
}
