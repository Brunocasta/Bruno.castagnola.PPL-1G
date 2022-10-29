/*
 ============================================================================
 Name        : PrimerParcialLaboratorio.c
 Author      : Bruno Castagnola 1G
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "funcionesPPLabo.h"

int main(void) {
	setbuf(stdout,NULL);

		int opcionMenu;
		int opcionMenuMostrar;
		int codigo=0;
		int idNote=1;
		int idTrabajo=1;
		eNotebook notebook[CANT];
		eTrabajo trabajos[CANTTRAB];
		eTipo tipos[CANTTIPOS]={{5000,"GAMER"},{5001,"DISENIO"},{5002,"ULTRABOOK"},{5003,"NORMALITA"}};
		eMarca marcas[CANTMARCAS]={{1000,"COMPAQ"},{1001,"ASUS"},{1002,"ACER"},{1003,"HP"}};
		eServicio servicios[CANTSERV]={{2000,"BATERIA",2250},{2001,"DISPLAY",103000},{2002,"TECLADO",4400},{2003,"FUENTE", 5600}};
		eCliente cliente[CANTCLIENTE]={{10,"Pedro",'m'},{11,"Juan",'m'},{12,"Maria",'f'}};
		inicioVectores(notebook,CANT);
		inicioTrabajos(trabajos,CANTTRAB);
		do{
			opcionMenu=menuDeOpciones(	"\n1. ALTA  \n2. MODIFICAR  \n3. BAJA  \n4. LISTAR NOTEBOOKS  \n5. LISTAR MARCAS  \n6. LISTAR TIPOS \n7. LISTAR SERVICIOS "
										"\n8. ALTA TRABAJO \n9. LISTAR TRABAJO \n10. LISTAR  \n11. SALIR" );
				switch(opcionMenu){
					case 1:
						if(alta(notebook,CANT,idNote,marcas,tipos,cliente)==1)
						{
							codigo++;
							idNote++;
							printf("\nAlta exitosa..\n");
						}else
						{
							printf("\nERROR... No se encontro espacio de carga");
						}
					break;
					case 2:
						if(codigo>0)
						{
							if(modificar(CANT,notebook,marcas,tipos,cliente)==1)
							{
								printf("\nModificaion exitosa \n");
							}

						}else
						{
							printf("\nERROR... No se encontro espacio de carga\n");
						}
					break;
					case 3:
						if(codigo>0)
						{
							if(baja(CANT,notebook,marcas,tipos,cliente)==1)
							{
								codigo--;
							}

						}else
						{
							printf("\nERROR... No se encontro espacio de carga");
						}
					break;
					case 4:
						 //harcodeoNotebooks(&idNote, notebook,CANT,3, marcas, tipos);
						 //ordenamiento(CANT,notebook,marcas,tipos);
						if(codigo>0)
						{
							ordenamiento(CANT,notebook,marcas,tipos,cliente);
						}else
						{
							printf("\nERROR... No se encontro espacio de carga");
						}
					break;
					case 5:
						mostrarMarca(marcas,CANTMARCAS);
					break;
					case 6:
						mostrarTipos(tipos,CANTTIPOS);
					break;
					case 7:
						mostrarServicio(servicios,CANTSERV);

					break;
					case 8:
						if(codigo>0){
							if((altaTrabajo(trabajos,CANTTRAB,idTrabajo,servicios,notebook,marcas,tipos,cliente)==1))
							{
								idTrabajo++;
								printf("\nAlta exitosa..\n");
							}else
							{
								printf("\nERROR... No se encontro espacio de carga");
							}
						}
					break;
					case 9:
						if(idTrabajo>0){
							mostrarTrabajo(trabajos,CANTTRAB,notebook,servicios);
						}else
						{
							printf("\nERROR... No se encontro carga que mostrar");
						}

					break;
					case 10:
						if(codigo>0)
						{
							do{
								opcionMenuMostrar=menuDeOpciones(	"\n1. Mostrar Notebooks por tipo  \n2. Mostrar Notebooks por Marca  \n3. Mostrar Notebooks mas barata  "
																	"\n4. Listado por marcas \n5. Listado por marcas y tipo \n6. Listado por marcas mas elegidas \n7. SALIR" );
								switch(opcionMenuMostrar)
								{
								case 1:
									if( mostrarNotebookPorTipo(CANT, notebook, marcas, tipos,cliente)==1){
										printf("\n tipo encontrado");
									}else{
										printf("\n No se encontro");
									}
									break;
								case 2:
									if( mostrarNotebookPorMarca(CANT, notebook, marcas, tipos,cliente)==1){
										printf("\n Marca encontrada");
									}else{
										printf("\n No se encontro");
									}
									break;
								case 3:
									if( notebookMaasBarata(CANT, notebook, marcas, tipos,cliente)==1){
										printf("\n Mas barata");
									}else{
										printf("\n No se encontro");
									}

									break;
								case 4:
									if( listadoNotebookPormarca(CANT, notebook, marcas, tipos,cliente)==1){
										printf("\n OK");
									}else{
										printf("\n No se encontro");
									}
									break;
								case 5:
									if( listadoNotebookPorMarcaYTipo(CANT, notebook, marcas, tipos,cliente)==1){
										printf("\n OK");
									}else{
										printf("\n No se encontro");
									}
									break;
								case 6:
									if( mostrarMarcaXCliente(CANT, notebook, marcas, tipos,cliente)==1){
										printf("\n OK");
									}else{
										printf("\n No se encontro");
									}
									break;
								case 7:
									break;
								default:
									break;
								}
							}while(opcionMenuMostrar!=7);

						}else
						{
							printf("\nERROR... No se encontro carga que mostrar");
						}
					break;
					case 11:
						printf("\nGracias por utilizar el programa");
					break;
					default:
						printf("\nIngrese datos correctos por favor...\n");
					break;
				}
			}while(opcionMenu!=11);

	return 0;
}
