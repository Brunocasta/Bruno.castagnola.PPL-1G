/*
 * validacionesPPL.h
 *
 *  Created on: 27 oct. 2022
 *      Author: Lenovo
 */

#ifndef VALIDACIONESPPL_H_
#define VALIDACIONESPPL_H_
#include "funcionesPPLabo.h"

/// @fn int menuDeOpciones(char[])
/// @brief permite por parametro escribir una cadena de caraceres
///
/// @param mensaje
/// @return 0 si ess ok o -1 si es error
int menuDeOpciones(char mensaje[]);
/// @fn int utn_getNombre(char*, int, char*, char*, int)
/// @brief
///
/// @param pResultado
/// @param longitud
/// @param mensaje
/// @param mensajeError
/// @param reintentos
/// @return 0 si ess ok o -1 si es error
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
/// @fn int getNombre(char*, int)
/// @brief
///
/// @param pResultado
/// @param longitud
/// @return 0 si ess ok o -1 si es error
int getNombre(char* pResultado, int longitud);
/// @fn int getString(char*, int)
/// @brief
///
/// @param cadena
/// @param longitud
/// @return 0 si ess ok o -1 si es error
int getString(char* cadena, int longitud);
/// @fn int esNombre(char*, int)
/// @brief
///
/// @param cadena
/// @param longitud
/// @return 0 si ess ok o -1 si es error
int esNombre(char* cadena,int longitud);
/// @fn int utn_getNumeroInt(int*, char*, char*, int, int, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo de seleccion
/// @param maximo de seleccion
/// @param reintentos cant determinada
/// @return  0 si ess ok o -1 si es error
int utn_getNumeroInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
/// @fn int getInt(int*)
/// @brief
///
/// @param pResultado
/// @return 0 si ess ok o -1 si es error
int getInt(int* pResultado);
/// @fn float utn_getNumeroFloat(float*, char*, char*, int, int, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo de selaccion
/// @param maximo de seleccion
/// @param reintentos cant determinada
/// @return 0 si ess ok o -1 si es error
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
/// @fn int getFloat(float*)
/// @brief
///
/// @param pResultado
/// @return 0 si ess ok o -1 si es error
int getFloat(float* pResultado);
/// @fn int esFlotante(char*)
/// @brief
///
/// @param cadena
/// @return 0 si ess ok o -1 si es error
int esFlotante(char* cadena);

#endif /* VALIDACIONESPPL_H_ */
