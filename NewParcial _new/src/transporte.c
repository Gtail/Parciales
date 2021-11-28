

#include "transporte.h"



int determinarTransporte(eTransporte medio[],int max,ePedidos* unPedido)
{
	int retorno=-1;
	int i;
	if(medio!=NULL)
	{

		if(unPedido->estadoPedido==PENDIENTE)
		{
			for(i=0;i<max;i++)
			{
				if(unPedido->kilos>0)
				{

					if(unPedido->kilos<500)
					{
						unPedido->idTransporte=medio[i].idTransporte;

					}else if(unPedido->kilos<1100)
					{
						unPedido->idTransporte=medio[i].idTransporte;

					}else
					{
						unPedido->idTransporte=medio[i].idTransporte;
					}
					retorno =1;
			  }
			}
		}
	}
	return retorno;
}

void HardcodearTransporte(eTransporte medio[], int max) {
	int i;

	int idTransporte[] = { 100, 101, 102 };
	char medioTransporte[][256] = { "Auto", "Camioneta", "Camion" };

	for (i = 0; i < max; i++) {
		medio[i].idTransporte = idTransporte[i];
		strcpy(medio[i].medioTransporte, medioTransporte[i]);
	}
}



int contador_TransportePorId(int idTransporte, ePedidos pedido[], int top, eCliente lista[], int tam,int* idCliente){
	int retorno=-1;
	int contMedio;
	int i;

	contMedio=0;
	if(pedido!=NULL && top>0)
	{
		for(i=0;i<top;i++)
		{
			if(pedido[i].idTransporte==idTransporte)
			{

				contMedio = cant_PedidosPorCliente(pedido, tam, pedido[i].idCliente);
				*idCliente=pedido[i].idCliente;
			}
		}
		if(contMedio>0){
			retorno=contMedio;
		}
	}
	return retorno;
}

int mayorMedio_Transporte(ePedidos pedido[], int top, eTransporte medio[], int max, eCliente lista[], int tam){
	int retorno;
	int i;
	int idCliente;
	int indexIdCliente=-1;
	int acumT;
	acumT=0;


	if(pedido!=NULL && medio!=NULL && top>0 && max>0)
	{
		for(i=0;i<max;i++)
		{
			acumT=contador_TransportePorId(medio[i].idTransporte, pedido, top, lista, tam,&idCliente);
			indexIdCliente=buscarClientePorId(lista, tam, idCliente);
			if(acumT>0)
			{
				printf("\n|ID CL %4d |EMPRESA %-18s |TRANSPORTE %-18s|VECES UTILIZADO %4d|  \n",lista[indexIdCliente].idCliente, lista[indexIdCliente].empresa, medio[i].medioTransporte, acumT);
				retorno=1;
			}
		}

	}

	return retorno;
}


int cant_PedidosPorCliente(ePedidos lsPedidos[], int tam, int idCliente){
	int retorno=-1;
	int cont;
	int i;
	cont=0;

	if(lsPedidos!=NULL && tam>0)
	{
		for(i=0;i<tam;i++){
			if(lsPedidos[i].idCliente==idCliente){
				cont++;
			}
		}
		retorno=cont;
	}

	return retorno;
}




