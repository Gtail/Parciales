
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputUtn.h"

void PedirChar(char mensaje[],char* caracter)
{
	printf("%s\n",mensaje);
	fflush(stdin);
	scanf("%c",caracter);
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

void getStringOne(char cadena[],char mensaje[],int tam)
{
    char auxiliar[tam];

    printf("%s\n", mensaje);
    fflush(stdin);
   // __fpurge(stdin);
   scanf("%[^\n]s", auxiliar);
    //gets()
   // fgets(cadena,tam,stdin);
    strcpy(cadena, auxiliar);
}

int PedirNumeroEntero(char mensaje[]){
    int numero;

    printf("%s\n",mensaje);
    scanf("%d",&numero);
    return numero;
}

//---------------------

void PedirNumeroEnteroPuntero(int* numero,char mensaje[])
{
    printf("%s\n",mensaje);
    scanf("%d",numero);
}

void PedirNumeroEnteroExcluyente(int numeroExcluyente,int* numero,char mensaje[],char mensajeError[])
{
    printf("%s \n",mensaje);//"Ingrese un numero dentro del rango %d - %d : \n"
    scanf("%d",numero);

    while(*numero == numeroExcluyente){

        printf("%s \n",mensajeError);
        scanf("%d",numero);
    }
}

void PedirNumeroEnteroConRangoPuntero(int* numero,char mensaje[],char mensajeError[],int min, int max)
{
    printf("\n%s ",mensaje);//"Ingrese un numero dentro del rango %d - %d : \n"
    printf("%d - %d : \n",min,max);
    scanf("%d",numero);

    while(*numero<min || *numero>max){

        printf("%s ",mensajeError);
        printf("%d - %d : \n",min,max);
        scanf("%d",numero);
    }
}



void mostrarEntero (char mensaje[],int numero){
    printf("%s\n",mensaje);
    printf("%d",numero);
}

void MostrarArrayEnteros(int lista[],int tam)
{
	printf("Listado de numeros \n");
	if(lista != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			//printf("%d - ", lista[i]);
			mostrarEntero("| ", lista[i]);
		}
		printf("\n\n");
	}
	else
	{
		printf("--No hay elementos que mostrar--\n");
	}

}

int DeterminarParidad(int numero)
{
	int esPar;

	esPar=0;
	if(numero %2 == 0 )
	{
		esPar=1;
	}
	return esPar;
}



int esNumerico(char cadena[])
{
    int i;
    int retorno;

    retorno=1;
    for(i=0 ;cadena[i] != '\0';i++ )
    {
        if(!(isdigit(cadena[i]) ))		//(cadena[i]<'0' || cadena[i]> '9')
        {
            retorno=0;
        }
    }
    return retorno;
}

int esNumericoFlotante(char cadena[])
{
	int retorno;
	int cantPuntos;

	retorno=0;
	cantPuntos=0;
	for(int i=0 ; cadena[i] != '\0';i++)
	{
		if(cadena[i]== '.' && cantPuntos ==0)
		{
			cantPuntos++;
			continue;
		}
		if(cadena[i] <'0' || cadena[i] > '9')
		{
			retorno=0;
		}
	}
	return retorno;
}

int esTelefonoCuit(char cadena[])
{
	int i;
    int retorno;
    int contadorGuiones;

    contadorGuiones=0;

    for(i=0 ;cadena[i] != '\0';i++ )
    {
    	if(!( (isspace(cadena[i])) || (isdigit(cadena[i])) || (cadena[i] == '-')) )
    	{
            retorno=0;
        }
    	if(cadena[i]=='-')
		{
			contadorGuiones+=1;
		}
    }
    if(	contadorGuiones>0 && contadorGuiones<3)  //los celulares y cuits usan dos guiones
    {
    	retorno=1;
    }
    return retorno;
}

int esAlfaNumerico(char cadena[])
{
    int i;
    int retorno;

    retorno=1;
    for(i=0 ;cadena[i] != '\0';i++ )
    { //  if((cadena[i]!= ' ') && (cadena[i]< 'a'|| cadena[i]> 'z') && ( cadena[i]< 'A'|| cadena[i]> 'Z') && (cadena[i]<'0' || cadena[i]> '9') )
        if( !((isspace(cadena[i])) || (isalpha(cadena[i])) || isdigit(cadena[i])) )
    	{
           retorno=0;
        }
    }
    return retorno;
}


int esSoloLetras(char cadena[])
{
    int retorno;

    retorno=1;
    for(int i=0 ;cadena[i] != '\0';i++ )
    {
    	if(!( (isspace(cadena[i])) || (isalpha(cadena[i])) ))
    	{//optimizaDA //funciona if( ! ( (cadena[i] == ' ') || ( cadena[i]>'a'&& cadena[i]< 'z') || ( cadena[i]> 'A'|| cadena[i]< 'Z')) )
             retorno=0;
        }
    }
    return retorno;
}

/*-------------------*/

int getStringNumber(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
    char aux[lenInput];
    int retorno;

    retorno=1;

    getStringOne(aux,mensaje,lenInput);
    reintentos--;
    while( reintentos != 0 && (esNumerico(aux)==0) )
    {
    	getStringOne(aux,mensajeError,lenInput);
    	reintentos--;
    	retorno=0;
    }
    strcpy(input,aux);

    return retorno;
}

int getStringSoloLetras(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
    char aux[lenInput];
    int retorno;

    retorno=1;

    getStringOne(aux,mensaje,lenInput);
    reintentos--;
    while( reintentos != 0 && (esSoloLetras(aux)==0) )
    {
    	getStringOne(aux,mensajeError,lenInput);
    	reintentos--;
    	retorno=0;
    }
    strcpy(input,aux);

    return retorno;
}



int getStringAlfaNumerico(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
    char aux[lenInput];
    int retorno;

    retorno=1;

    getStringOne(aux,mensaje,lenInput);
    reintentos--;
    while( reintentos != 0 && (esAlfaNumerico(aux)==0) )
    {
    	getStringOne(aux,mensajeError,lenInput);
    	reintentos--;
    	retorno=0;
    }

    strcpy(input,aux);


    return retorno;
}


int getStringTelefonoCuit(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
    char aux[lenInput];
    int retorno;

    retorno=1;

    getStringOne(aux,mensaje,lenInput);
    reintentos--;
    while( reintentos != 0 && (esTelefonoCuit(aux)==0) )
    {
    	getStringOne(aux,mensajeError,lenInput);
    	reintentos--;
    	retorno=0;
    }
    strcpy(input,aux);

    return retorno;
}

int getStringNumeroFlotante(char mensaje[],char mensajeError[],char input[],int lenInput,int reintentos)
{
	char aux[lenInput];
	int retorno;

	retorno=0;

	 getStringOne(aux, mensaje, lenInput);
	 reintentos--;

	 while( reintentos != 0 && (esNumericoFlotante(aux) ==0))
	 {
		 getStringOne(aux, mensajeError, lenInput);
		 strcpy(input,aux);
		 retorno=1;
	}
	 //if(esNumericoFlotante(aux)==1))
	 //{
		 //strcpy(input,aux);
//	 }
	return retorno;
}



void MostrarMensaje(char mensaje[])
{
	printf(" %s \n",mensaje);
}

void MostrarMensajesRetornoFunciones(int estado, char mensaje1[],char mensaje2[],char mensaje3[],char mensaje4[])
{
	switch(estado)
	{
		case 0 :
			MostrarMensaje(mensaje1);
		break;

		case 1 :
			MostrarMensaje(mensaje2);
		break;

		case -1 :
			MostrarMensaje(mensaje3);
		break;

		default:
			MostrarMensaje(mensaje4);
		break;
	}
}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;

        }
        return auxInt;

    }


}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * @fn void chargeSalary(float*, char[], char[])
 * @brief solicita un flotante al usuario y valida que sea uno
 *
 * @param salario flotante a ingresar
 * @param mensaje mensaje de solicitud al usuario
 * @param mensajeError error ante un ingreso incorrecto
 */
void chargeSalary(float *salario, char mensaje[], char mensajeError[]) {
	char auxSalario[51];

	printf("%s", mensaje);
	scanf("%s", auxSalario);

	while (esNumericoFlotante(auxSalario)==0 && esNumerico(auxSalario)==0) {
		printf("%s", mensajeError);
		scanf("%s", auxSalario);
	}

	*salario = atof(auxSalario);

}

/**
 * \brief Solicita un string
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param input Array donde se cargar? el texto ingresado
 * \return -
 *
 */
void getValidString(char requestMessage[],char errorMessage[], char input[], int tam)
{

    while(1)
    {
        if (!getStringLetras(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }

}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

