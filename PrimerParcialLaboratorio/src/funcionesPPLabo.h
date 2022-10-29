/*
 * funcionesPPLabo.h
 *
 *  Created on: 20 oct. 2022
 *      Author: Lenovo
 */

#ifndef FUNCIONESPPLABO_H_
#define FUNCIONESPPLABO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "validacionesPPL.h"


#define CANT 20
#define CANTTIPOS 4
#define CANTMARCAS 4
#define CANTSERV 4
#define CANTTRAB 5
#define CANTCLIENTE 3
typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int idMarca;
	char descripcion[20];
}eMarca;
typedef struct{
	int idTipo;
	char descripcion[20];
}eTipo;
typedef struct{
	int idCliente;
	char nombre[20];
	char sexo;
}eCliente;
typedef struct{
	int idNotebook;
	char modelo[20];
	int idMarca;
	int idtipo;
	int idCliente;
	float precio;
	int isEmpty;
}eNotebook;
typedef struct{
	int idServicio;
	char descripcion[25];
	float precio;
}eServicio;
typedef struct{
	int idTrabajo;
	int idNotebook;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;


/// @fn void mostrarMarca(eMarca[], int)
/// @brief muestra las marcas
///
/// @param marcas
/// @param tam
void mostrarMarca(eMarca marcas[],int tam);
/// @fn void mostrarServicio(eServicio[], int)
/// @brief muestar los servicios
///
/// @param servicios
/// @param tam
void mostrarServicio(eServicio servicios[],int tam);
/// @fn void mostrarTipos(eTipo[], int)
/// @brief muestra los tipos
///
/// @param tipos
/// @param tam
void mostrarTipos(eTipo tipos[],int tam);
/// @fn void inicioVectores(eNotebook[], int)
/// @brief carga en 0 las posiciones del array
///
/// @param notebook
/// @param tam
void inicioVectores(eNotebook notebook[],int tam);
/// @fn int alta(eNotebook[], int, int, eMarca[], eTipo[])
/// @brief  genera el alta de una notebook donde si esta inicializada la posicion le permite entrar a cargar los datos
///
/// @param notebook
/// @param tam
/// @param indiceAutom
/// @param marcas
/// @param tipos
/// @return 1 ok 0 esta mal
int alta(eNotebook notebook[],int tam,int indiceAutom,eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn eNotebook crear(int, int, eMarca[], eTipo[])
/// @brief crea una notebook pidiendo los datos de la estrucvtura
///
/// @param tam
/// @param indiceAutom
/// @param marcas
/// @param tipos
/// @return 1 ok 0 esta mal
eNotebook crear(int tam,int indiceAutom,eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn void mostrar(eNotebook[], int, eMarca[], eTipo[])
/// @brief muestra las notebook cargadas
///
/// @param notebook
/// @param tam
/// @param marcas
/// @param tipos
void mostrar(eNotebook notebook[],int tam,eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn int buscarId(int*, int, eNotebook[], int)
/// @brief
///
/// @param pIndice
/// @param tam
/// @param notebook
/// @param auxId
/// @return
int buscarId(int* pIndice,int tam,eNotebook notebook[],int auxId);
/// @fn int baja(int, eNotebook[], eMarca[], eTipo[])
/// @brief genera la baja logica d euna notebook cargada
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
/// @return 1 es ok 0 es esta mal
int baja(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn int modificar(int, eNotebook[], eMarca[], eTipo[])
/// @brief permite la modiifcaion de una notebook  si existe la carga de la misma
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
/// @return 1 es ok 0 es esta mal
int modificar(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn void ordenamiento(int, eNotebook[], eMarca[], eTipo[])
/// @brief ordena por marca y por precio los productos cargados
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
void ordenamiento(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn void mostrarTrabajo(eTrabajo[], int, eNotebook[], eServicio[])
/// @brief  muestra los trabajos cargados
///
/// @param trabajos
/// @param tam
/// @param notebook
/// @param servicios
void mostrarTrabajo(eTrabajo trabajos[],int tam,eNotebook notebook[],eServicio servicios[]);
/// @fn eTrabajo crearTrabajo(int, int, eServicio[], eNotebook[], eMarca[], eTipo[])
/// @brief  crea un trabajo dsp de tener notebook cargadas
///
/// @param tam
/// @param indiceAutom
/// @param servicios
/// @param notebooks
/// @param marcas
/// @param tipos
/// @return 1 es ok 0 es esta mal
eTrabajo crearTrabajo(int tam,int indiceAutom,eServicio servicios[],eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn void inicioTrabajos(eTrabajo[], int)
/// @brief carga en 0 las posiciones del array
///
/// @param trabajos
/// @param tam
void inicioTrabajos(eTrabajo trabajos[],int tam);
/// @fn int altaTrabajo(eTrabajo[], int, int, eServicio[], eNotebook[], eMarca[], eTipo[])
/// @brief  genera el alta del trabajo donde si esta inicializada la posicion le permite entrar a cargar los datos
///
/// @param trabajos
/// @param tam
/// @param indiceAutom
/// @param servicios
/// @param notebooks
/// @param marcas
/// @param tipos
/// @return  1 es ok 0 es esta mal
int altaTrabajo(eTrabajo trabajos[],int tam,int indiceAutom,eServicio servicios[],eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn int mostrarNotebookPorTipo(int, eNotebook[], eMarca[], eTipo[], eCliente[])
/// @brief da a elegir al usuario un id para elegir que notebook mostrar a traves del tipo
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
/// @param cliente
/// @return  1 es ok 0 es esta mal
int mostrarNotebookPorTipo(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn void mostrarCliente(eCliente[], int)
/// @brief muestra la entidad cliente y sus datos
///
/// @param clientes
/// @param tam
void mostrarCliente(eCliente clientes[],int tam);
/// @fn int mostrarNotebookPorMarca(int, eNotebook[], eMarca[], eTipo[], eCliente[])
/// @brief da a elegir al usuario un id para elegir que notebook mostrar a traves de su marca
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
/// @param cliente
/// @return 1 es ok 0 es esta mal
int mostrarNotebookPorMarca(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn int notebookMaasBarata(int, eNotebook[], eMarca[], eTipo[], eCliente[])
/// @brief muestra cual es la notebook mas barata de todas las que estan cargadas
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
/// @param cliente
/// @return 1 es ok 0 es esta mal
int notebookMaasBarata (int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn int listadoNotebookPormarca(int, eNotebook[], eMarca[], eTipo[], eCliente[])
/// @brief muestra todas las marcas que existen y cual notebook pertenece a cada una
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
/// @param cliente
/// @return   1 es ok 0 es esta mal
int listadoNotebookPormarca(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn int listadoNotebookPorMarcaYTipo(int, eNotebook[], eMarca[], eTipo[], eCliente[])
/// @brief muestra el listad ode notebooks por marca y tipo que esta de tallado en la eleccion de usuario
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
/// @param cliente
/// @return 1 es ok 0 es esta mal
int listadoNotebookPorMarcaYTipo(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);
/// @fn int mostrarMarcaXCliente(int, eNotebook[], eMarca[], eTipo[], eCliente[])
/// @brief muestra las marcas mas elegidas por los cliente a la de elegir
///
/// @param tam
/// @param notebook
/// @param marcas
/// @param tipos
/// @param cliente
/// @return 1 es ok 0 es esta mal
int mostrarMarcaXCliente(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[]);





#endif /* FUNCIONESPPLABO_H_ */
