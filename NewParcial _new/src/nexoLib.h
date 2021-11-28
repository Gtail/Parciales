/*
 * informes.h
 *
 *  Created on: 25 nov. 2021
 *      Author: Gian
 */

#include "transporte.h"




#ifndef INFORMES_H_
#define INFORMES_H_

int altaPedido(eCliente lista[], ePedidos pedido[], eTransporte medio[],int max, int top, int tam, int* idAutoPedido);

int pendientesPorLocalidad(eCliente lista[], int tam, ePedidos pedido[], int top);
int calcularPromedioPp(eCliente lista[], int tam, ePedidos pedido[], int top);
int buscarPedidoPorId(ePedidos pedido[], int top, int idPedido);

int validarLocalidad(eCliente lista[], int tam, char auxLocalidad[]);

int contarPendiente_PorCliente(ePedidos pedido[], int top, int idCliente);
int mostrarClientes_CantidadPendiente(eCliente lista[], int tam, ePedidos pedido[], int top);
void mostrarUnClientePendiente(eCliente unCliente, ePedidos pedido[], int top,int acumP);

float contarKgPendiente_PorCliente(ePedidos pedido[], int top, int idCliente);
int imprimirKg_Pendientes(eCliente lista[], int tam, ePedidos pedido[], int top);
void imprimirPedidosPendientes(eCliente unCliente, ePedidos pedido[], int top, float acumKg);

void imprimirPedidosCompletados(eCliente unCliente, ePedidos pedido[], int top, float acumHDPE, float acumLDPE, float acumPP);
float contarHDPE_PorCliente(ePedidos pedido[], int top, int idCliente);
float contarPP_PorCliente(ePedidos pedido[], int top, int idCliente);
float contarLDPE_PorCliente(ePedidos pedido[], int top, int idCliente);
int imprimirKg_Completados(eCliente lista[], int tam, ePedidos pedido[], int top);



int promedio_Clientes(eCliente lista[], int tam, ePedidos pedido[], int top);
float contarPP_Clientes(ePedidos pedido[], int top, int idCliente);

#endif /* INFORMES_H_ */
