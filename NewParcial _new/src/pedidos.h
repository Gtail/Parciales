
#include "cliente.h"


#define FULL 1
#define EMPTY 0
#define PENDIENTE 50
#define COMPLETADO 100
#ifndef PEDIDOS_H_
#define PEDIDOS_H_


typedef struct{
	int idPedido;
	int idCliente;
	int idTransporte;
	int estadoPedido;
	float HDPE;
	float LDPE;
	float PP;
	float kilos;
	int isEmpty;
}ePedidos;



void inicializarPedidos(ePedidos pedidos[], int tam);
void cargaDeUnPedido(ePedidos pedido[], int index);

void mostrarUnPedidoPendiente(ePedidos unPedido);
void mostrarListaPedidos(ePedidos pedido[], int top);
int procesarResiduos(ePedidos pedido[], int top);
int validarEstadoPedido(ePedidos pedido[], int top, int IdPedido);
int contarPedidosPendientes(eCliente lista[], int tam, ePedidos pedido[], int top);
int buscarCliente(eCliente lista[], int tam, ePedidos pedido[], int top);
int buscarPedidoPendiente(eCliente lista[], int tam, ePedidos pedido[], int top);
void mostrarListaClientesPendientes(eCliente lista[], int tam,  ePedidos pedido[], int top);
void pedidosPendientes(eCliente lista[], int tam, ePedidos pedido[], int top);
void pedidosProcesados(eCliente lista[], int tam, ePedidos pedido[], int top);
int pendientesPorLocalidad(eCliente lista[], int tam, ePedidos pedido[], int top);
int calcularPromedioPp(eCliente lista[], int tam, ePedidos pedido[], int top);
int buscarEspacioPedido(ePedidos pedido[], int tam);


#endif /* PEDIDOS_H_ */


