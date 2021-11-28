/*
 * informes.c
 *
 *  Created on: 25 nov. 2021
 *      Author: Gian
 */

#include "nexoLib.h"


int altaPedido(eCliente lista[], ePedidos pedido[], eTransporte medio[],int max, int top, int tam, int* idAutoPedido)
{
	int retorno=0;
	int index;
	int IdCliente;

	mostrarListaClientes(lista, tam);
	IdCliente = getValidInt("\n Ingrese el ID de Cliente a Cargar el Pedido \n","\n Error. Ingrese un ID valido \n ", 0, 5000);

	if(buscarClientePorId(lista, tam, IdCliente)!=-1)
	{
			index = buscarEspacioPedido(pedido, top);
			if(index!=-1){
			cargaDeUnPedido(pedido, index);
			pedido[index].estadoPedido=PENDIENTE;
			*idAutoPedido = *idAutoPedido + 1;
			pedido[index].idCliente=IdCliente;
			pedido[index].idPedido=*idAutoPedido;
			pedido[index].isEmpty=FULL;
			retorno=1;
			if(determinarTransporte(medio, max, &(pedido[index]) ) != 1)
			{
				printf("No se han cargado los kilos, se eliminara el pedido\n");
				pedido[index].isEmpty=VACIO;
			}
		}else{
			printf("\n No Existe ese ID de Cliente \n");
		}
	}
	return retorno;

}




//---------------------------PUNTO 6----------------------------------------------------------
int contarPendiente_PorCliente(ePedidos pedido[], int top, int idCliente){
	int contP;
	int i;
	contP=0;

	if(pedido!=NULL && top>0){
		for(i=0;i<top;i++){
			if(pedido[i].estadoPedido==PENDIENTE && pedido[i].idCliente==idCliente){
				contP++;
			}
		}
	}
	return contP;
}

int mostrarClientes_CantidadPendiente(eCliente lista[], int tam, ePedidos pedido[], int top){
	int retorno=-1;
	int i;
	int acumP;
	acumP=0;

	if(lista!=NULL && pedido !=NULL && tam>0 && top>0){
		for(i=0;i<tam;i++){
			if(lista[i].isEmpty==OCUPADO){
				acumP=contarPendiente_PorCliente(pedido, top, lista[i].idCliente);
				if(acumP>0){
					mostrarUnClientePendiente(lista[i], pedido, top, acumP);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

void mostrarUnClientePendiente(eCliente unCliente, ePedidos pedido[], int top,int acumP) {
	acumP = contarPendiente_PorCliente(pedido, top, unCliente.idCliente);
	printf("\n|ID CL %4d |EMPRESA %-15s | CUIT %-15s |DIRECC %-18s |LOCALIDAD %-16s |PENDIENTES %4d ",
			unCliente.idCliente, unCliente.empresa, unCliente.cuit,
			unCliente.direccion, unCliente.localidad, acumP);

}

//------------------------PUNTO 7----------------------------------------------------

void imprimirPedidosPendientes(eCliente unCliente, ePedidos pedido[], int top, float acumKg) {
	acumKg=contarKgPendiente_PorCliente(pedido, top, unCliente.idCliente);

	printf("\n|CUIT %-15s |DIRECC %-18s |KG TOTALES %4f ",
			 unCliente.cuit, unCliente.direccion,  acumKg);

}

float contarKgPendiente_PorCliente(ePedidos pedido[], int top, int idCliente){
	float acumKg;
	int i;
	acumKg=0;

	if(pedido!=NULL && top>0){
		for(i=0;i<top;i++){
			if(pedido[i].estadoPedido==PENDIENTE && pedido[i].idCliente==idCliente){
				acumKg+=pedido[i].kilos;
			}
		}
	}
	return acumKg;
}

int imprimirKg_Pendientes(eCliente lista[], int tam, ePedidos pedido[], int top){
	int retorno=-1;
	int i;
	float acumKg;
	acumKg=0;

	if(lista!=NULL && pedido !=NULL && tam>0 && top>0){
		for(i=0;i<tam;i++){
			if(lista[i].isEmpty==OCUPADO){
				acumKg=contarKgPendiente_PorCliente(pedido, top, lista[i].idCliente);

				if(acumKg>0){
					imprimirPedidosPendientes(lista[i], pedido, top, acumKg);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

//------------------------------------- PUNTO 8-----------------------------------------

void imprimirPedidosCompletados(eCliente unCliente, ePedidos pedido[], int top, float acumHDPE, float acumLDPE, float acumPP) {
	acumHDPE=contarHDPE_PorCliente(pedido, top, unCliente.idCliente);
	acumLDPE=contarLDPE_PorCliente(pedido, top, unCliente.idCliente);
	acumPP=contarPP_PorCliente(pedido, top, unCliente.idCliente);

	printf("\n|CUIT %-15s |DIRECC %-18s |KG HDPE %4f|KG LDPE %4f |KG PP %4f  ",
			 unCliente.cuit, unCliente.direccion,  acumHDPE, acumLDPE,acumPP);

}

float contarHDPE_PorCliente(ePedidos pedido[], int top, int idCliente){
	float acumKg;
	int i;
	acumKg=0;

	if(pedido!=NULL && top>0){
		for(i=0;i<top;i++){
			if(pedido[i].estadoPedido==COMPLETADO && pedido[i].idCliente==idCliente){
				acumKg+=pedido[i].HDPE;

			}
		}
	}
	return acumKg;
}

float contarPP_PorCliente(ePedidos pedido[], int top, int idCliente){
	float acumKg;
	int i;
	acumKg=0;

	if(pedido!=NULL && top>0){
		for(i=0;i<top;i++){
			if(pedido[i].estadoPedido==COMPLETADO && pedido[i].idCliente==idCliente){
				acumKg+=pedido[i].PP;
			}
		}
	}
	return acumKg;
}

float contarLDPE_PorCliente(ePedidos pedido[], int top, int idCliente){
	float acumKg;
	int i;
	acumKg=0;

	if(pedido!=NULL && top>0){
		for(i=0;i<top;i++){
			if(pedido[i].estadoPedido==COMPLETADO && pedido[i].idCliente==idCliente){
				acumKg+=pedido[i].LDPE;
			}
		}
	}
	return acumKg;
}


int imprimirKg_Completados(eCliente lista[], int tam, ePedidos pedido[], int top){
	int retorno=-1;
	int i;
	float acumHDPE=0;
	float acumLDPE=0;
	float acumPP=0;


	if(lista!=NULL && pedido !=NULL && tam>0 && top>0){

		for(i=0;i<tam;i++){
			if(lista[i].isEmpty==OCUPADO){
				acumHDPE=contarHDPE_PorCliente(pedido, top, lista[i].idCliente);
				acumLDPE=contarLDPE_PorCliente(pedido, top, lista[i].idCliente);
				acumPP=contarPP_PorCliente(pedido, top, lista[i].idCliente);

				if(acumHDPE>=0 && acumLDPE>=0 && acumPP>=0){
					imprimirPedidosCompletados(lista[i], pedido, top, acumHDPE, acumLDPE, acumPP);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}

//----------------------------------------PUNTO 9------------------------------------------------------


int pendientesPorLocalidad(eCliente lista[], int tam, ePedidos pedido[],
		int top) {
	int retorno = 0;
	int i;
	int contadorPendientes = 0;
	char auxLocalidad[51];

	getValidString("\n Ingrese la localidad de la Empresa \n",
			"\n Error, ingrese SOLO letras \n", auxLocalidad, 51);
	if (lista != NULL && pedido != NULL && tam > 0 && top > 0) {
		for (i = 0; i < tam; i++) {
			if (lista[i].isEmpty == OCUPADO
					&& strcmp(auxLocalidad, lista[i].localidad) == 0) {
				if (lista[i].idPedido == pedido[i].idPedido) {
					contadorPendientes++;
					retorno = 1;
				}

			}
		}
	}

	if (contadorPendientes > 0) {
		printf("\n Los pedidos pendientes para la localidad %s son %d \n",
				auxLocalidad, contadorPendientes);
	} else {
		printf("\n No hay pedidos pendientes para la localidad %s \n",
				auxLocalidad);
	}
	return retorno;
}


int validarLocalidad(eCliente lista[], int tam, char auxLocalidad[])
{
	int retorno=1;
	int i;
	if(lista!=NULL && tam>0){
		for(i=0;i<tam;i++){
			if(strcmp(auxLocalidad,lista[i].localidad)==0){
				retorno=1;
			}
		}
	}
	return retorno;
}

//--------------------------------------------PUNTO 10-------------------------------------------------
/*
 * 10 acumular los kg de polipropileno
 * 10.1 contador de clientes con pedidos completados
 * un for anidado
 *
 *
 *
 */

int promedio_Clientes(eCliente lista[], int tam, ePedidos pedido[], int top) {
	int retorno = -1;
	int acumPP;
	int contC;
	float promedio = 0;
	int i;

	acumPP = 0;
	contC = 0;

	if (lista != NULL && tam > 0 && pedido != NULL && top > 0) {
		for (i = 0; i < tam; i++) {
			if (lista[i].isEmpty == OCUPADO && lista[i].idPedido==pedido[i].idPedido) {
						if(pedido[i].estadoPedido==COMPLETADO){
							contC++;
						acumPP= contarPP_Clientes( pedido, top, lista[i].idCliente);
						}
				}
			}
		}
		if (contC > 0 && acumPP > 0) {
			promedio = acumPP / contC;
			printf("El promedio de kg de polipropileno reciclado por cliente es %f \n", promedio);
			retorno=1;
		}else{
			printf("No hubo PP reciclado \n");
		}

	return retorno;
}

float contarPP_Clientes( ePedidos pedido[], int top, int idCliente){
	float acumKg;
	int i;
	acumKg=0;

	if(pedido!=NULL && top>0){
		for(i=0;i<top;i++){
			if(pedido[i].estadoPedido==COMPLETADO && pedido[i].idCliente==idCliente){
				acumKg+=pedido[i].PP;

			}
		}

	}
	return acumKg;
}


