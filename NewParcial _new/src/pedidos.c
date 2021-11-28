/*
 * pedidos.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Gian
 */
#include "pedidos.h"

void inicializarPedidos(ePedidos pedidos[], int tam) {

	if (pedidos != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			pedidos[i].isEmpty=EMPTY;
		}
	}
}

void cargaDeUnPedido(ePedidos pedido[], int index) {


	chargeSalary(&(pedido[index].kilos), "Ingrese la cantidad de Kilos \n", "Error. Ingrese SOLO numeros \n");

}


int buscarEspacioPedido(ePedidos pedido[], int top) {
	int index;
	index = -1;
	if (pedido != NULL && top > 0) {
		for (int i = 0; i < top; i++) {
			if (pedido[i].isEmpty == EMPTY) {
				index = i;
				break;
			}
		}
	}
	return index;
}

void mostrarUnPedidoPendiente(ePedidos unPedido) {

	printf("\n |ID PEDIDO %4d|ID CL %4d |KG TOTALES %4f \n", unPedido.idPedido,unPedido.idCliente,
			 unPedido.kilos);
}

void mostrarListaPedidos(ePedidos pedido[], int top) {

	if (pedido != NULL && top > 0) {
		for (int i = 0; i < top; i++) {
			if (pedido[i].estadoPedido == PENDIENTE) {
				mostrarUnPedidoPendiente(pedido[i]);
			}
		}
	}
}

int procesarResiduos(ePedidos pedido[], int top) {
	int retorno = 0;
	int index;
	int opcion;
	int acumPeso = 0;
	int IdPedido;

	mostrarListaPedidos(pedido, top);
	IdPedido = getValidInt("Ingrese el ID de Pedido a Procesar",
			"Error. Ingrese un ID de Pedido valido", 0, 1000);
	index = validarEstadoPedido(pedido, top, IdPedido);
	if (validarEstadoPedido(pedido, top, IdPedido) != -1) {
		printf("La cantidad de KG TOTALES es de %f", pedido[index].kilos);
		printf("\n Elija: 1- Cargar HDPE \t 2- Cargar LDPE \t  3- Cargar PP \t 4- SALIR ");
		do {
			opcion = subMenu();
			switch (opcion) {
			case 1:
				printf("\n 1- Ingrese SOLO los kilos de HDPE");
				scanf("%f", &pedido[index].HDPE);
				acumPeso += pedido[index].HDPE;
				retorno = 1;
				break;
			case 2:
				printf("\n 2- Ingrese SOLO los kilos de LDPE");
				scanf("%f", &pedido[index].LDPE);
				acumPeso += pedido[index].LDPE;
				retorno = 1;
				break;
			case 3:
				printf("\n 3- Ingrese SOLO los kilos de PP");
				scanf("%f", &pedido[index].PP);
				acumPeso += pedido[index].PP;
				retorno = 1;
				break;
			case 4:
				printf("\n 4- SALIR");
			}
		} while (opcion != 4);
	}
	if (acumPeso > pedido[index].kilos) {
		retorno = 0;
		pedido[index].estadoPedido = PENDIENTE;
	} else {
		retorno = 1;
		pedido[index].estadoPedido = COMPLETADO;
	}

	return retorno;
}

int validarEstadoPedido(ePedidos pedido[], int top, int IdPedido) {
	int retorno = -1;
	for (int i = 0; i < top; i++) {

		if (pedido[i].estadoPedido == PENDIENTE
				&& pedido[i].idPedido == IdPedido) {
			retorno = i;
			break;
		}
	}
	return retorno;
}

int contarPedidosPendientes(eCliente lista[], int tam, ePedidos pedido[],
		int top) {
	int contadorPendientes = 0;
	int indexCliente;

	if (lista != NULL && tam > 0 && pedido != NULL && top > 0) {
		printf("nada dio NULL en contar pedidos \n");
		indexCliente = buscarCliente(lista, tam, pedido, top);
		for (int i = 0; i < top; i++) {
			if (indexCliente != -1) {
				if (lista[indexCliente].idPedido
						== pedido[indexCliente].idPedido && pedido[indexCliente].estadoPedido== PENDIENTE) {
					contadorPendientes++;
				}
			}

		}
	}
	return contadorPendientes;
}


int buscarPedidoPendiente(eCliente lista[], int tam, ePedidos pedido[], int top){
	int retorno=-1;
	if (lista != NULL && tam > 0) {
			for (int i = 0; i < tam; i++) {
				if (lista[i].isEmpty == OCUPADO && pedido[i].idPedido == lista[i].idPedido) {
					if (pedido[i].estadoPedido == PENDIENTE){
						retorno=i;
						break;
					}
				}
			}
	}
	return retorno;
}


int buscarCliente(eCliente lista[], int tam, ePedidos pedido[], int top) {
	int retorno = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (pedido[i].idCliente == lista[i].idCliente) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/




