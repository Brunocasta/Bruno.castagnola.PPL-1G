/*
 * validacionesPPL.c
 *
 *  Created on: 27 oct. 2022
 *      Author: Lenovo
 */
#include "validacionesPPL.h"



int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
 int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
 int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		//__fpurge(stdin); // Linux
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
 int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

 int utn_getNumeroInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
 {
 	int retorno;
 	int numeroValido;
 	while(reintentos>0)
 	{
 		printf(mensaje);
 		if(getInt(&numeroValido)==1)
 		{
 			if(numeroValido<=maximo && numeroValido>=minimo){
 				break;
 			}
 		}
 			fflush(stdin);
 			reintentos--;
 			printf(mensajeError);
 	}
 	if(reintentos==0)
 	{
 		retorno=-1;
 	}else{
 		retorno=0;
 		*pResultado = numeroValido;
 	}
 	return retorno;
 }
 int getInt(int* pResultado)
 {
 	char buffer[64];
 	scanf("%s",buffer);
 	*pResultado = atoi(buffer);
 	return 1;
 }

 int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
 {
 	float bufferFloat;
 	int retorno = -1;
 	while(reintentos>=0)
 	{
 		reintentos--;
 		printf("%s",mensaje);
 		if(getFloat(&bufferFloat) == 0)
 		{
 			if(bufferFloat >= minimo && bufferFloat <= maximo)
 			{
 				*pResultado = bufferFloat;
 				retorno = 0;
 				break;
 			}
 		}
 		printf("%s",mensajeError);
 	}
 	return retorno;
 }
 int getFloat(float* pResultado)
 {
     int retorno=-1;
     char buffer[64];

     if(pResultado != NULL)
     {
     	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
     	{
 			*pResultado = atof(buffer);
 			retorno = 0;
 		}
     }
     return retorno;
 }
 int esFlotante(char* cadena)
 {
 	int i=0;
 	int retorno = 1;
 	int contadorPuntos=0;

 	if(cadena != NULL && strlen(cadena) > 0)
 	{
 		for(i=0 ; cadena[i] != '\0'; i++)
 		{
 			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
 			{
 				continue;
 			}
 			if(cadena[i] < '0' || cadena[i] > '9' )
 			{
 				if(cadena[i] == '.' && contadorPuntos == 0)
 				{
 					contadorPuntos++;
 				}
 				else
 				{
 					retorno = 0;
 					break;
 				}
 			}
 		}
 	}
 	return retorno;
 }


