/*
 * funcionesPPLabo.c
 *
 *  Created on: 20 oct. 2022
 *      Author: Lenovo
 */
#include "funcionesPPLabo.h"



void inicioVectores(eNotebook notebook[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		notebook[i].isEmpty=1;
	}
}

void mostrarMarca(eMarca marcas[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("\n %d    %s",marcas[i].idMarca,marcas[i].descripcion);
	}
}
void mostrarTipos(eTipo tipos[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("\n %d    %s",tipos[i].idTipo,tipos[i].descripcion);
	}
}
void mostrarCliente(eCliente clientes[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("\n %d    %s  %c ",clientes[i].idCliente,clientes[i].nombre,clientes[i].sexo);
	}
}
void mostrarServicio(eServicio servicios[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		printf("\n %d    %s   $7%.2f",servicios[i].idServicio,servicios[i].descripcion,servicios[i].precio);
	}
}


int alta(eNotebook notebook[],int tam,int indiceAutom,eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=-1;
	for(int i=0;i<tam;i++)
	{
		if(notebook[i].isEmpty==1&&notebook!=NULL)
		{
			notebook[i]=crear(tam,indiceAutom,marcas,tipos,cliente);
			return 1;
		}
	}

	return retorno;
}
eNotebook crear(int tam,int indiceAutom,eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	eNotebook notebook;
	int respuestaEntero;
	float respuestaFlotante;
	notebook.idNotebook=indiceAutom;

	utn_getNombre(notebook.modelo,51,"Ingrese el modelo : \n","Error...Ingrese el modelo correcto\n",3);

	mostrarMarca(marcas,CANTMARCAS);
	respuestaEntero=utn_getNumeroInt(&notebook.idMarca,"\nIngrese id Marca: \n","Error...Ingrese un valor correcto\n",1000,1003,3);
	while(respuestaEntero!=0)
	{
		mostrarMarca(marcas,CANTMARCAS);
		respuestaEntero=utn_getNumeroInt(&notebook.idMarca,"\nIngrese id Marca: \n","Error...Ingrese un valor correcto\n",1000,1003,3);
	}

	mostrarTipos(tipos,CANTTIPOS);
	respuestaEntero=utn_getNumeroInt(&notebook.idtipo,"\nIngrese id de  Tipo: \n","Error...Ingrese un valor correcto\n",5000,5003,3);
	while(respuestaEntero!=0)
	{
		mostrarTipos(tipos,CANTTIPOS);
		respuestaEntero=utn_getNumeroInt(&notebook.idtipo,"\nIngrese id de  Tipo: \n","Error...Ingrese un valor correcto\n",5000,5003,3);
	}

	mostrarCliente(cliente,CANTCLIENTE);
	respuestaEntero=utn_getNumeroInt(&notebook.idCliente,"\nIngrese id de cliente: \n","Error...Ingrese un valor correcto\n",10,12,3);
	while(respuestaEntero!=0)
	{
		mostrarCliente(cliente,CANTCLIENTE);
		respuestaEntero=utn_getNumeroInt(&notebook.idCliente,"\nIngrese id de cliente: \n","Error...Ingrese un valor correcto\n",10,12,3);
	}

	respuestaFlotante=utn_getNumeroFlotante(&notebook.precio,"nIngrese precio: \n","Error...Ingrese un valor correcto\n",0,5000000,6);
	while(respuestaFlotante!=0)
	{
		respuestaFlotante=utn_getNumeroFlotante(&notebook.precio,"nIngrese precio: \n","Error...Ingrese un valor correcto\n",0,5000000,6);
	}

	notebook.isEmpty=0;

	return notebook;
}

int buscarId(int* pIndice,int tam,eNotebook notebook[],int auxId)
{
	int indice=-1;
	int retorno=0;
	if(pIndice!=NULL&&notebook!=NULL&&tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(notebook[i].isEmpty==0&&notebook[i].idNotebook==auxId)
			{
				indice=i;
				break;
			}
		}
		*pIndice=indice;
		 retorno=1;
	}

	return retorno;
}

int baja(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=0;
	int auxAlumno;
	int indice;
	char respuesta;
	if(tam>0 && notebook!=NULL)
	{
		printf("  *****BAJA******* \n");
		mostrar(notebook,CANT,marcas,tipos,cliente);
		printf("\nIngrese el id a dar de Baja :");
		scanf("%d",&auxAlumno);

		buscarId(&indice,tam,notebook,auxAlumno);
		if(indice==-1)
		{
			printf("\nNo existe el id %d ",auxAlumno);
		}
		else{
			printf("\nDesea confirmar la Baja ? S/N");
			fflush(stdin);
			scanf("%c",&respuesta);
			respuesta=toupper(respuesta);
			if(respuesta=='S'){

				notebook[indice].isEmpty=1;
				printf("\nSe ha dado de baja la notebook");

				retorno=1;
			}else
			{
				printf("\n Se ha cancelado la baja de la notebook");
			}
		}
	}
	return retorno;
}

int modificar(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=0;
	int auxAlumno,opcionSubMenu;
	int indice;
	char respuesta;
	int auxNumero;
	float auxPrecio;
	int respuestaEntero;
	float respuestaFlotante;

	if(tam>0 && notebook!=NULL)
	{
		printf("  *****MODIFICAR******* \n");
		mostrar(notebook,CANT,marcas,tipos,cliente);
		printf("\nIngrese el id a modificar :");
		scanf("%d",&auxAlumno);

		buscarId(&indice,tam,notebook,auxAlumno);
		if(indice==-1)
		{
			printf("\nNo existe el id %d ",auxAlumno);
		}
		else{
			printf("\nDesea confirmar hacer la modificacion ? S/N");
			fflush(stdin);
			scanf("%c",&respuesta);
			respuesta=toupper(respuesta);
			if(respuesta=='S'){

				do{
					opcionSubMenu=menuDeOpciones("\n1. TIPO \n2. PRECIO \n3. SALIR ");
					switch(opcionSubMenu){

						case 1:
								mostrarTipos(tipos,CANTTIPOS);
								respuestaEntero=utn_getNumeroInt(&auxNumero,"\nIngrese id de  Tipo: \n","Error...Ingrese un valor correcto\n",5000,5003,3);
								while(respuestaEntero!=0)
								{
									mostrarTipos(tipos,CANTTIPOS);
									respuestaEntero=utn_getNumeroInt(&auxNumero,"\nIngrese id de  Tipo: \n","Error...Ingrese un valor correcto\n",5000,5003,3);
								}
								notebook[indice].idtipo=auxNumero;
						break;
						case 2:
								respuestaFlotante=utn_getNumeroFlotante(&auxPrecio,"nIngrese precio: \n","Error...Ingrese un valor correcto\n",0,5000000,6);
								while(respuestaFlotante!=0)
								{
									respuestaFlotante=utn_getNumeroFlotante(&auxPrecio,"nIngrese precio: \n","Error...Ingrese un valor correcto\n",0,5000000,6);
								}

								notebook[indice].precio=auxPrecio;
						break;
						case 3:
						break;
						default:
							printf("\nIngrese datos correctos por favor...\n");
						break;

					}
				}while(opcionSubMenu!=3);
				retorno=1;
			}else
			{
				printf("\n Se ha cancelado la modificacion de la notebook \n");
			}
		}
	}
	return retorno;
}

void ordenamiento(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	//eMarca auxMarcas;
	eNotebook notes;
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{

			if(notebook[i].isEmpty==0&&notebook[i].idMarca>notebook[j].idMarca)
			{
				notes=notebook[i];
				notebook[i]=notebook[j];
				notebook[j]=notes;
			}
		}
	}
	for(int i=0;i<tam-1;i++)
	{
		for(int j=i+1;j<tam;j++)
		{

			if(notebook[i].isEmpty==0&&notebook[i].precio<notebook[j].precio&&notebook[i].idMarca>notebook[j].idMarca)
			{
				notes=notebook[i];
				notebook[i]=notebook[j];
				notebook[j]=notes;
			}
		}
	}


	mostrar(notebook,CANT,marcas,tipos,cliente);
}

int mostrarNotebookPorTipo(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=0;
	int respuestaEntero;
	int auxRespuesta;

	mostrarTipos(tipos,CANTTIPOS);
	respuestaEntero=utn_getNumeroInt(&auxRespuesta,"\nIngrese id tipo de notebook a mostrar: \n","Error...Ingrese un valor correcto\n",5000,5003,3);
	while(respuestaEntero!=0)
	{
		mostrarTipos(tipos,CANTTIPOS);
		respuestaEntero=utn_getNumeroInt(&auxRespuesta,"\nIngrese id tipo de notebook a mostrar: \n","Error...Ingrese un valor correcto\n",5000,5003,3);
	}
	if(notebook!=NULL&&marcas!=NULL&&tipos!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(auxRespuesta==notebook[i].idtipo&&notebook[i].isEmpty==0)
			{
				printf(" \nModelo :%s",notebook[i].modelo);
				retorno=1;
			}
		}

	}

	return retorno;
}

int mostrarMarcaXCliente(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=0;
	if(notebook!=NULL&&marcas!=NULL&&tipos!=NULL&&cliente!=NULL)
	{
		for (int i=0;i<CANTMARCAS;i++)
		{
			for (int j=0;j<tam;j++)
			{
				if(notebook[j].idMarca==marcas[i].idMarca&&notebook[j].isEmpty==0)
				{
					printf("\n Nombre Marcas :%s",marcas[i].descripcion);
				}
			}
		}
		retorno=1;
	}
	return retorno;
}
int mostrarNotebookPorMarca(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=0;
	int respuestaEntero;
	int auxRespuesta;

	mostrarMarca(marcas,CANTMARCAS);
	respuestaEntero=utn_getNumeroInt(&auxRespuesta,"\nIngrese id Marca: \n","Error...Ingrese un valor correcto\n",1000,1003,3);
	while(respuestaEntero!=0)
	{
		mostrarMarca(marcas,CANTMARCAS);
		respuestaEntero=utn_getNumeroInt(&auxRespuesta,"\nIngrese id Marca: \n","Error...Ingrese un valor correcto\n",1000,1003,3);
	}

	if(notebook!=NULL&&marcas!=NULL&&tipos!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			if(auxRespuesta==notebook[i].idMarca&&notebook[i].isEmpty==0)
			{
				printf(" \nModelo :%s",notebook[i].modelo);
				retorno=1;
			}
		}
	}

	return retorno;
}

int notebookMaasBarata(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=0;
	int minimo=0;
	int flag=0;

	for (int i=0;i<tam;i++)
	{
		if((notebook[i].isEmpty==0&&notebook[i].precio<minimo)||flag==0){
			minimo=notebook[i].precio;
			flag=1;
		}
	}
	printf("NOOTBOOKS MAS BARATA");
	for(int i=0;i<tam;i++)
	{
		if(notebook[i].isEmpty==0&&minimo==notebook[i].precio)
		{
			printf(" \nModelo :%s",notebook[i].modelo);
			retorno=1;
		}
	}


	return retorno;
}

int listadoNotebookPormarca(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=0;
	if(notebook!=NULL&&marcas!=NULL&&tipos!=NULL)
	{
		for (int i=0;i<CANTMARCAS;i++)
		{
			printf("Marca notebooks :%s ",marcas[i].descripcion);
			for (int j=0;j<CANT;j++)
			{
				if(marcas[i].idMarca==notebook[j].idMarca&&notebook[j].isEmpty==0)
				{
					 printf("\n%10s %10.2f\n", notebook[j].modelo,
												 notebook[j].precio);
				}
			}
		}
		retorno=1;
	}

	return retorno;
}

int listadoNotebookPorMarcaYTipo(int tam,eNotebook notebook[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=0;
	int contadorNote=0;
	if(notebook!=NULL&&marcas!=NULL&&tipos!=NULL&&cliente!=NULL)
	{
		for(int i=0;i<CANTMARCAS;i++)
		{
			for(int j=0;j<CANTTIPOS;j++)
			{
				for(int k=0;k<CANT;k++)
				{

					if(notebook[k].idMarca==marcas[i].idMarca&&tipos[j].idTipo==5000&&marcas[i].idMarca==1000)
					{
						contadorNote++;
					}
				}
			}
		}
		printf("\nCanidad notebook marca Compaq y tipo Gamer son :%d",contadorNote);
		retorno=1;
	}
	return retorno;
}

void inicioTrabajos(eTrabajo trabajos[],int tam)
{
	for(int i=0;i<tam;i++)
	{
		trabajos[i].isEmpty=1;
	}
}

int altaTrabajo(eTrabajo trabajos[],int tam,int indiceAutom,eServicio servicios[],eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	int retorno=-1;
	for(int i=0;i<tam;i++)
	{
		if(trabajos[i].isEmpty==1&&trabajos!=NULL)
		{
			trabajos[i]=crearTrabajo(tam,indiceAutom,servicios,notebooks,marcas,tipos,cliente);
			return 1;
		}
	}

	return retorno;
}

eTrabajo crearTrabajo(int tam,int indiceAutom,eServicio servicios[],eNotebook notebooks[],eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	eTrabajo trabajo;
	int respuestaEntero;
	trabajo.idTrabajo=indiceAutom;

	respuestaEntero=utn_getNumeroInt(&trabajo.fecha.dia,"\nIngrese dia de Trabajo:: \n","Error...Ingrese un valor correcto\n",1,31,3);

	respuestaEntero=utn_getNumeroInt(&trabajo.fecha.mes,"\nIngrese mes de Trabajo: \n","Error...Ingrese un valor correcto\n",1,12,3);

	respuestaEntero=utn_getNumeroInt(&trabajo.fecha.anio,"\nIngrese anio de Trabajo: \n","Error...Ingrese un valor correcto\n",2000,2022,3);

	mostrar(notebooks,CANT,marcas,tipos,cliente);
	respuestaEntero=utn_getNumeroInt(&trabajo.idNotebook,"\nIngrese id de Notebook: \n","Error...Ingrese un valor correcto\n",0,200,3);
	while(respuestaEntero!=0)
	{
		mostrar(notebooks,CANT,marcas,tipos,cliente);
		respuestaEntero=utn_getNumeroInt(&trabajo.idNotebook,"\nIngrese id de Notebook: \n","Error...Ingrese un valor correcto\n",0,200,3);
	}

	mostrarServicio(servicios,CANTSERV);
	respuestaEntero=utn_getNumeroInt(&trabajo.idServicio,"\nIngrese el id de servicio: \n","Error...Ingrese un valor correcto\n",2000,2003,3);
	while(respuestaEntero!=0)
	{
		mostrarServicio(servicios,CANTSERV);
		respuestaEntero=utn_getNumeroInt(&trabajo.idServicio,"\nIngrese el id de servicio: \n","Error...Ingrese un valor correcto\n",2000,2003,3);
	}

	trabajo.isEmpty=0;

	return trabajo;
}
void mostrar(eNotebook notebook[],int tam,eMarca marcas[],eTipo tipos[],eCliente cliente[])
{
	printf("\n====================================================================");
	printf("\n| ID   |    MODELO   |   TIPO  | MARCA   |   CLIENTE     | PRECIO  |");
	printf("\n=====================================================================");

	for(int i=0;i<tam;i++)
	{
		if(notebook[i].isEmpty==0)
		{
			for(int j=0;j<CANTTIPOS;j++)
			{
				for(int k=0;k<CANTTIPOS;k++)
				{
					for(int l=0;l<CANTCLIENTE;l++)
					{
						if(notebook[i].idtipo==tipos[j].idTipo&&notebook[i].idMarca==marcas[k].idMarca&&notebook[i].idCliente==cliente[l].idCliente)
						{
							printf("\n|%4d  |%8s     |%8s |%8s  |%10s | %6.2f |",notebook[i].idNotebook,
																			notebook[i].modelo,
																			tipos[j].descripcion,
																			marcas[k].descripcion,
																			cliente[l].nombre,
																			notebook[i].precio);
						}
					}

				}
			}

		}
	}
	printf("\n====================================================");
}
void mostrarTrabajo(eTrabajo trabajos[],int tam,eNotebook notebook[],eServicio servicios[])
{
	printf("\n====================================================");
	printf("\n| ID   |    SERVICIO  |   NOTEBOOK  |    FECHA     |");
	printf("\n====================================================");

	for(int i=0;i<tam;i++)
	{
		if(trabajos[i].isEmpty==0)
		{
			for(int j=0;j<CANTSERV;j++)
			{
				for(int k=0;k<CANT;k++)
				{
					if(trabajos[i].idServicio==servicios[j].idServicio&&trabajos[i].idNotebook==notebook[k].idNotebook)
						{
							printf("\n|%4d  |%8s     |%10s   |%6d/%d/%d   |",	trabajos[i].idTrabajo,
																			servicios[j].descripcion,
																			notebook[k].modelo,
																			trabajos[i].fecha.dia,
																			trabajos[i].fecha.mes,
																			trabajos[i].fecha.anio);
						}


				}
			}
		}
	}
	printf("\n===================================================");
}
