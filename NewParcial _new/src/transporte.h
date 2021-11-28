/*
 * transporte.h
 *
 *  Created on: 27 nov. 2021
 *      Author: Gian
 */

#include "pedidos.h"
#include "cliente.h"

#ifndef TRANSPORTE_H_
#define TRANSPORTE_H_

typedef struct{

	int idTransporte;
	int idPedido;
	float kgCarga;
	char medioTransporte[256];

}eTransporte;


int determinarTransporte(eTransporte medio[],int max,ePedidos* unPedido);
void HardcodearTransporte(eTransporte medio[], int max);
int contador_TransportePorId(int idTransporte, ePedidos pedido[], int top, eCliente lista[], int tam,int* idCliente);
int mayorMedio_Transporte(ePedidos pedido[], int top, eTransporte medio[], int max, eCliente lista[], int tam);
int cant_PedidosPorCliente(ePedidos pedido[], int top, int idPedido);

#endif /* TRANSPORTE_H_ */


