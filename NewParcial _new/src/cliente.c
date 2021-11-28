/*
 * cliente.c
 *
 *  Created on: 18 oct. 2021
 *      Author: Gian
 */
#include "cliente.h"


int menuPrincipal(){
	int opcion;

	printf("\n 1) Alta de Cliente \n");
	printf("\n 2) Modificar de Cliente\n");
	printf("\n 3) Baja de Cliente\n");
	printf("\n 4) Crear Pedido de Recoleccion\n");
	printf("\n 5) Procesar Residuos\n");
	printf("\n 6) Imprimir Clientes\n");
	printf("\n 7) Imprimir Pedidos Pendientes\n");
	printf("\n 8) Imprimir Pedidos Procesados\n");
	printf("\n 9) Pedidos Pendientes por Localidad\n");
	printf("\n 10) Kilos de Polipropileno reciclado promedio por Cliente \n");
	printf("\n 11) Mayor Medio de Transporte Utilizado \n");
	printf("\n 12) Salir \n");
	scanf("%d", &opcion);

	return opcion;
}

int menuModificar() {
	int opcion;

	printf("1) Modificar Direccion \n");
	printf("2) Modificar Localidad \n");
	printf("3) Salir \n");
	scanf("%d", &opcion);

	return opcion;
}

int subMenu(){

	printf("\n Seleccione 1- Mostrar Productos 2- Mostrar Por precio 3- Mostrar por Descipcion");
	int option;

	printf("\n Opcion 1 Cargar HDPE \n");
	printf("\n Opcion 2 Cargar LDPE \n");
	printf("\n Opcion 3 Cargar PP \n");
	printf("\n Opcion 4 Salir \n")	;
	scanf("%d", &option);

	return option;

}

int InicializarLista(eCliente lista[],int tam)

{
	int initCorrecta;
	int i;

	initCorrecta=0;

	if(lista != NULL && tam >0)
	{
		for(i =0 ; i< tam ; i++)
		{
			lista[i].isEmpty= VACIO;
		}
		initCorrecta=1;
	}
	return initCorrecta;
}

///------------------------
/// /*Mientras no sea un numFlotante y no sea un numero*/

int BuscarEspacioVacio(eCliente lista[],int tam)
{
	int index;
	int i;

	index=-1;
	if(lista != NULL && tam >0)
	{
		for(i =0 ; i< tam ; i++)
		{
			if(lista[i].isEmpty== VACIO)
			{
				index= i;
				break;
			}
		}
	}
	return index;
}


eCliente CargarCliente(int* idAuto)
{
	eCliente auxCliente;
	*idAuto+=1;
	auxCliente.idCliente=*idAuto;
	getStringSoloLetras("\n Ingrese nombre de empresa: \n", "\n ERROR, Ingrese nombre de empresa valido: \n", auxCliente.empresa, 51, 3);
	getStringAlfaNumerico("\n Ingrese la direccion de la empresa: \n","ERROR, Ingrese la direccion nuevamente: ",auxCliente.direccion,51,3);
	getStringTelefonoCuit("\n Ingrese CUIT de empresa: \n", "\n ERROR, Ingrese CUIT de empresa valido: \n", auxCliente.cuit, 51, 3);
	getStringSoloLetras("\n Ingrese Localidad de la empresa: \n", "\n ERROR, Ingrese localidad valida: \n", auxCliente.localidad, 51, 3);


	return auxCliente;

}
///-------------FX Muestra por Pantalla
///
///



int AltaCliente(int* idAuto, eCliente lista[],int tam)
{
	int altaOk;
	int index;
	if(lista != NULL && tam >0)
	{

		index=BuscarEspacioVacio(lista,tam);
		if(index!= -1)
		{

			lista[index] = CargarCliente(idAuto);
			mostrarUnCliente(lista[index]);
			lista[index].isEmpty=OCUPADO;


			altaOk=1;
		}
	}
	return altaOk;
}

void mostrarUnCliente(eCliente unCliente) {

	printf("\n %d\t%s\t%s\t%s\t%s \n\n", unCliente.idCliente, unCliente.empresa,
			unCliente.cuit, unCliente.direccion, unCliente.localidad);
}

void mostrarListaClientes(eCliente lista[], int tam) {

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == OCUPADO) {
				mostrarUnCliente(lista[i]);
			}
		}
	}
}



int modificarUnCliente(eCliente lista[], int tam) {
	int retorno = 0;
	int IdCliente;
	int index = -1;
	int opcion;

	mostrarListaClientes(lista, tam);
	IdCliente = getValidInt("Ingrese el ID de Cliente a modificar",
			"ERROR. Intente nuevamente", 1000, 2000);
	index = buscarClientePorId(lista, tam, IdCliente);
	if (lista != NULL && tam > 0) {
		if (index != -1) {
			do {
				opcion = menuModificar();
				printf(
						"Ingrese una opcion 1)Modificar Direccion - 2) Modificar Localdiad - 3) SALIR");
				switch (opcion) {
				case 1:
					printf("\n 1) Usted selecciono modificar direccion ");
					getStringAlfaNumerico("\n Ingrese la nueva direccion",
							"\n Error. Intente nuevamente",
							lista[index].direccion, tam, 3);
					break;
				case 2:
					printf("\n 2) Usted selecciono modificar Localidad");
					getStringSoloLetras("\n Ingrese la Nueva Localidad",
							"\n Error. Intente nuevamente",
							lista[index].localidad, tam, 3);
					break;
				case 3:
					printf("\n 3) Hasta luego");
					retorno = 0;
					break;
				}
			} while (opcion != 3);
			retorno = 1;
		}
	}
	return retorno;
}

int modificarClientes(eCliente lista[], int tam) {
	int retorno = 0;

	if (modificarUnCliente(lista, tam) == 1) {
		printf("\n La modificacion ha sido exitosa \n");
		retorno=1;
	}
	return retorno;
}

int buscarClientePorId(eCliente lista[], int tam, int IdCliente) {

	int retorno = -1;

	for (int i = 0; i < tam; i++) {

		if (lista[i].isEmpty == OCUPADO && lista[i].idCliente == IdCliente) {

			retorno = i;

			break;
		}

	}

	return retorno;
}

int BajaDeCliente(eCliente lista[], int TAM) {
	int IdCliente;
	int retorno = -1;
	char respuesta;
	int index;

	mostrarListaClientes(lista, TAM);

	IdCliente = getValidInt("Ingrese el ID de Cliente a Eliminar",
			"Error. Ingrese un ID valido", 0, 1000);

	printf("Esta seguro de ELIMINAR el Cliente %d ? s/n", IdCliente);
	fflush(stdin);
	scanf("%c", &respuesta);

	if (respuesta == 's') {
		{
			index = buscarClientePorId(lista, TAM, IdCliente);
			if (index != -1) {
				lista[index].isEmpty = VACIO;
				retorno = 1;
				printf("Se ha eliminado el ID %d correctamente \n", IdCliente);
			} else {
				printf("ID incorrecto, intente nuevamente \n");
			}
		}
		while (respuesta != 's' && respuesta != 'n') {
			printf(
					"\n ERROR. SOLO s/n. Esta seguro de ELIMINAR el Cliente %d ? s/n \n",
					IdCliente);
			scanf("%c", &respuesta);
		}
	}
	return retorno;
}



