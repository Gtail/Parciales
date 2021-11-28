/*
 * cliente.h
 *
 *  Created on: 18 oct. 2021
 *      Author: Gian
 */


#include "inputUtn.h"


#ifndef CLIENTE_H_
#define CLIENTE_H_

#define VACIO 0
#define OCUPADO 1

typedef struct{
	int idCliente;
	int idPedido;
	char empresa[51];
	char cuit[51];
	char direccion[51];
	char localidad[51];
	int isEmpty;
}eCliente;

int menuPrincipal();
int menuModificar();
int subMenu();
int InicializarLista(eCliente lista[],int tam);
int BuscarEspacioVacio(eCliente lista[],int tamC);
eCliente CargarCliente(int* idAuto);
int AltaCliente(int* idAuto, eCliente lista[],int tam);
int BajaDeCliente(eCliente lista[], int TAM);
void mostrarUnCliente(eCliente unCliente);
int modificarUnCliente(eCliente lista[], int tam);
int modificarClientes(eCliente lista[], int tam);
int buscarClientePorId(eCliente lista[], int tam, int idCliente);
void mostrarListaClientes(eCliente lista[], int tam);


#endif
