/*
 * PantallaContract.c
 *
 *  Created on: 7 oct. 2020
 *      Author: nico
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <conio.h>
#include "arrayContrat.h"
#include "harcodArrayContrat.h"
#include "arrayPantalla.h"
#include "harcodArrayPantalla.h"
#include "PantallaContract.h"
#include "utn_input.h"




int contratPantalla_chargeArray (Contrat *listC, int lenC,Pantalla *listP, int lenP)
{
  Contrat auxContrat;
  Pantalla auxPantalla;
  int auxIdPantalla;
  int retorno = -1;

  if (listC != NULL && lenC > 0)
    {
      if (utn_getNumero ("Ingrese id pantalla: ", "\nError al ingresar. Por favor ", &auxContrat.idPantalla, 0, 999, 5)!= 0)
      		{
      		  return -1;
      		}
      if (pantalla_findArrayById (listP, lenP,  auxContrat.idPantalla) == -1)
      					{

    	  	  	  	  	  printf("\nEl ID NO existe\n");

      					}
      if (utn_getAlfanumerico ("Ingrese nombre del archivo: ", "\nError al ingresar.\n", auxContrat.nombreArchivo, LONG_NAME_CONTRAT, 5) != 0)
		{
		  return -1;
		}

      if (utn_getNumero ("Ingrese cantidad de dias: ", "\nError al ingresar. Por favor ", &auxContrat.cantDias, 0, 99999, 5)!= 0)
		{
		  return -1;
		}
      if (utn_getNumeroLong ("Ingrese CUIL: ", "\nError al ingresar. Por favor ", &auxContrat.cuil, 20010000000, 20999999999, 5)!= 0)
     		{
     		  return -1;
     		}
      if (utn_getAceptaRechaza ("\nAcepta el ingreso? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	{
	  auxContrat.id = utn_idIncremental ();
	  if(contrat_addArray (listC, lenC,
				auxContrat.id,
				auxContrat.idPantalla,
				auxContrat.nombreArchivo,
				auxContrat.cantDias,
				auxContrat.cuil
				)==0)
	  {
	      retorno = 0;
	  }
	  printf ("\n*****************************************************");
          printf ("\n                    ALTA EXITOSA!                  \n");
	  printf ("*****************************************************\n\n");
	}
      else
	{
	  retorno = 0;
	}
    }
  return retorno;
}





int pantalla_printForIdSinHeader  (Pantalla *list, int len, int id)
{
	 int retorno = -1;
	  int i;
	  	if(list != NULL && len > 0)
	  	{
	  	  //  pantalla_headerArray();
	  		for( i=0;i<len;i++)
	  		{
	  			if(list[i].id == id && list[i].isEmpty == FALSE &&
	  			    ///Se agrega una condicion mas por si lo que trae es basura
	  			    list[i].tipoPantalla > 0)
	  			{
	  				printf(

	////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	  				       "%-12d " ///NO TOCAR///////
	  				       "%-10d "
	  				       "%-13s "
	  				       "%-13s "
	  				       "%-12.2f "
	  				       "\n"

	  				   ,list[i].id ///NO TOCAR///////
					   ,list[i].tipoPantalla
					   ,list[i].nombrePantalla
					   ,list[i].direccion
					   ,list[i].precio

	////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
					    );
	  			}
	  		}
	  		retorno = 0;
	  	}
	 return retorno;
}






void pantallasXCuil(Contrat *listC, int lenC,Pantalla *listP, int lenP, long long int* cuil)
{
	int i;
	for (i = 0; i < lenC; i++)
	{
		if (cuil == listC[i].cuil && listC[i].isEmpty == FALSE)
		{
			pantalla_printForIdSinHeader(listP, lenP, listC[i].idPantalla);
		}
	}
}




void contratosdXCuil(Contrat *listC, int lenC,Pantalla *listP, int lenP, long long int *cuil)
{

	int i;
	for (i = 0; i < lenC; i++)
	{
		if (cuil == listC[i].cuil && listC[i].isEmpty == FALSE)
		{
			pantalla_printForIdSinHeader(listP, lenP, listC[i].idPantalla);
		}
	}
}





long long int contrat_findArrayByCuil (Contrat *list, int len, long long int cuil)
{
  int i;
  long long int retorno = -1;

  if (list != NULL && len > 0 && cuil != 0)
    {
      for (i = 0; i < len; i++)
	{
	  if (list[i].cuil == cuil)
	    {
	      retorno = cuil;
	      break;
	    }
	}
    }
return retorno;
}





long long int contrat_findIdArrayByCuil (Contrat *list, int len, long long int cuil, int* id)
{
	  int i;
	  long long int retorno = -1;

	  if (list != NULL && len > 0 && cuil != 0)
	    {
	      for (i = 0; i < len; i++)
		{
		  if (list[i].cuil == cuil)
		    {
		      *id = list[i].id;
		      retorno = 0;
		      break;
		    }
		}
	    }
	return retorno;
}






int contratPantalla_updateDias (Contrat *listC, int lenC,Pantalla *listP, int lenP)
{
  int bufferID;
  int bufferIdAux;
  int retorno = -1;
  int opcion;
  Contrat auxContrat;
  Pantalla auxPantalla;

  if (listC != NULL && lenC > 0)
    {
	utn_getNumeroLong ("Ingrese CUIL: ", "\nError al ingresar. Por favor ", &auxContrat.cuil, 20010000000, 20999999999, 5);
	contrat_findIdArrayByCuil (listC, lenC, auxContrat.cuil, &bufferID);

      if (contrat_findArrayByCuil (listC, lenC, auxContrat.cuil) != -1)
	{
    	  pantalla_headerArray();
    	  pantallasXCuil(listC, lenC, listP, lenP, auxContrat.cuil);
    	  utn_getNumero ("\nIngresar id de la pantalla: ","\nOpcion Invalida. ", &auxContrat.idPantalla, 1, 999, 3);
    	  contrat_findIdArrayByIdAux (listC, lenC,auxContrat.idPantalla, &bufferID);
       retorno = 0;
	   contrat_arrayToBuffer(listC, &auxContrat,  lenC,  bufferID);
	  do
	     {
		  contrat_printForIdAux  (&auxContrat,lenC,  bufferID);
////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	      printf ("\n"
		      "1-CANT. DIAS\n"
	      	  "2-Aceptar Cambios\n"//////NO TOCAR////////////////////////
	      	  "3-Salir\n"//////NO TOCAR////////////////////////
		  );
	       if (utn_getNumero ("\nPor favor ingrese una opcion: ","\nOpcion Invalida. ", &opcion, 1, 10, 3) != -1)
	 	{
	 	  switch (opcion)
	 	    {
	 	    case 1:
			printf ("\n"
			"CANTIDAD DIAS"
				"\n********\n");
			 if (utn_getNumero ("\nIngresar cant. de dias: ","\nOpcion Invalida. ", &auxContrat.cantDias, 1, 999, 3) != 0)
			  {
				 printf("\nENTRO EN EL IF\n");
			    return -1;
		  }
			break;

////////////////////////////////////////////////////////MODIFICABLE/////////////////////////////////////////////////////////////////////
	 	   case 2:
	 		 if(utn_getAceptaRechaza ("\nGrabar cambios? s/n: ", "ERROR al ingresar opcion. \n", 's', 'n')==1)
	 		   {
	 		    contrat_bufferToArray (listC, &auxContrat,  lenC, bufferID);
	 		    printf ("\n*************************************\n");
	 		    printf ("\nLOS CAMBIOS SE GRABARON EXITOSAMENTE!\n");
	 		    printf ("\n*************************************\n\n");
	 		   }
	 	      break;
	 	    }
	 	}
	       else
	 	{
	 	  printf ("\nSE TERMINARON LOS REINTENTOS\n");
	 	  system ("pause");
	 	  return EXIT_SUCCESS;
	 	}
	     }
	   while (opcion != 3);

	  if(opcion == 3)
	    {
	      return EXIT_SUCCESS;
	    }
	}
      else
	{
	  printf ("\nEl ID NO existe\n");
	}
    }
  return retorno;
}






int cancelarContratacion(Contrat *listC, int lenC, Pantalla *listP, int lenP)
{
	int retorno = -1;
	int bufferID;
	int bufferIdPantalla;
	long long int cuil;

	if (listC != NULL && lenC > 0)
	{
		utn_getNumeroLong("Ingrese CUIL: ", "\nError al ingresar. Por favor ",&cuil, 20010000000, 20999999999, 5);
		contrat_findIdArrayByCuil(listC, lenC, cuil, &bufferID);

		if (contrat_findArrayByCuil(listC, lenC, cuil) != -1)
		{
			pantalla_headerArray();
			pantallasXCuil(listC, lenC, listP, lenP, cuil);
			utn_getNumero("\nIngresar id de la pantalla: ","\nOpcion Invalida. ", &bufferIdPantalla, 1, 999, 3);
			contrat_findIdArrayByIdAux(listC, lenC, bufferIdPantalla,&bufferID);
			retorno = 0;
			contrat_printForId(listC, lenC, bufferID);
			retorno = utn_getAceptaRechaza("\nAcepta eliminar contratacion? s/n: ","ERROR al ingresar opcion. \n", 's', 'n');
			if (retorno == 1)
			{
				contrat_removeArray(listC, lenC, bufferID);
				retorno = 1;
				printf("\n*****************************************************");
				printf("\n             ELIMINACION EXITOSA!\n");
				printf("*****************************************************\n\n");
			}
		}
		else
		{
			printf("\nEl ID NO existe\n");
		}
	}
	return retorno;
}






//PUNTO 7 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void contratMasImportaTotal_headerArray(void)

{
    printf("\n"
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s"
	    "%*s"
		"%*s",
	   -7, " ID Contr.",
	   -10, " ID Pant.",
	   -14," Cant.Dias",
	   -25," Nomb. Arch.",
	    -12," CUIL",
		 0," Importe Total"
	   "\n---------------------------------------------------------------------------------------\n");
}



int importeAPagarXContrato_printForId(Contrat *listC, int lenC, Pantalla *listP,
		int lenP, int id)
{
	int retorno = -1;
	int i;
	int j;

	if (listC != NULL && lenC > 0)
	{
		for (i = 0; i < lenC; i++)
		{
			if (listC[i].id == id && listC[i].isEmpty == FALSE &&
					listC[i].cantDias > 0)
			{

				for (j = 0; j < lenP; j++)
				{
					if (listP[j].id == listC[i].idPantalla)
					{
						printf(

								"%-12d "
										"%-12d "
										"%-10d "
										"%-20s "
										"%-20lld"
										"%.2f"
										"\n"


								,
								listC[i].id
								, listC[i].idPantalla, listC[i].cantDias,
								listC[i].nombreArchivo, listC[i].cuil,
								(listP[j].precio * (float) listC[i].cantDias)
								);
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}



void  contratosdXCuilImporteApagar(Contrat *listC, int lenC,Pantalla *listP, int lenP, long long int *cuil)
{
	int i;


	for (i = 0; i < lenC; i++)
	{

		if (cuil == listC[i].cuil && listC[i].isEmpty == FALSE)
		{
			importeAPagarXContrato_printForId(listC,lenC,listP, lenP, listC[i].idPantalla);
		}
	}
}


void consultaFacturacion(Contrat *listC, int lenC, Pantalla *listP, int lenP)
{
	int retorno = -1;
	int bufferID;
	//	int bufferIdPantalla;
	long long int cuil;

	if (listC != NULL && lenC > 0)
	{
		utn_getNumeroLong("Ingrese CUIL: ", "\nError al ingresar. Por favor ",
				&cuil, 20010000000, 20999999999, 5);
		contrat_findIdArrayByCuil(listC, lenC, cuil, &bufferID);
		if (contrat_findArrayByCuil(listC, lenC, cuil) != -1)
		{
			retorno = 0;
			contratMasImportaTotal_headerArray();
			contratosdXCuilImporteApagar(listC, lenC, listP, lenP, cuil);
		}
		else
		{
			printf("\nEl ID NO existe\n");
		}

	}

}


//PUNTO 8 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int contratMasNomPantalla_printArray(Contrat *listC, int lenC, Pantalla *listP, int lenP)
{
	int retorno = -1;
	if(listC != NULL && lenC > 0)
	{
		for(int i=0;i<lenC;i++)
		{
			if(listC[i].isEmpty == FALSE)
			{


				for(int j=0;j<lenP;j++)
				{
					if(listC[i].idPantalla == listP[j].id)
					{
				printf(

				    "%-13s "
				    "%-13s "
				    "%-10d "
				    "%-30lld"
				    " \n"
					,listP[j].nombrePantalla
					,listC[i].nombreArchivo
				    ,listC[i].cantDias
				    ,listC[i].cuil
				   );

					}

				}
			}
		}
		retorno = 0;
	}
	return retorno;
}



void contratMasNomPantalla_headerArray(void)
{
    printf("\n"
	    "%*s"
	    "%*s"
	    "%*s"

		"%*s",
	   -10, " Nomb. Pant.",
	   -15," Nomb. Arch.",
	   -14," Cant.Dias",
	    0," CUIL"

	   "\n---------------------------------------------------------------------------------------\n");
}



//PUNTO 10 (1) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int calcularCantContratacionesDeUnCliente(Contrat *listC, int lenC, long long int cuil)
{
	int i;
	int contador = 0;


	for (i = 0; i < lenC; i++)
	{
		if (listC[i].cuil == cuil)
		{
			contador++;
		}
	}
	return contador;
}




void listaClieteCantidadContEImporte(Contrat *listC, int lenC, Pantalla *listP, int lenP)
{

	long long int cuilAux;
	int i;
	int j;
	int n;

	long long int cuil;

	if (listC != NULL && lenC > 0)
	{

		for (i = 0; i < lenP; i++)
		{

			for (j = 0; j < lenC; j++)
			{
				if (listP[i].isEmpty == FALSE && listC[j].idPantalla == listP[i].id && cuilAux != listC[j].cuil)
				{
					printf("\nCliente : %lld  |  Cantidad de contratos: %d\n",
							listC[j].cuil,
							calcularCantContratacionesDeUnCliente(listC, lenC,listC[j].cuil));
					cuilAux = listC[j].cuil;
					break;
				}
			}
			for (n = 0; n <= lenP; n++)
			{
				if (listP[n].isEmpty == FALSE && listC[j].idPantalla == listP[n].id)
				{
					contratMasImportaTotal_headerArray();
					cuil = listC[j].cuil;
					if (contrat_findArrayByCuil(listC, lenC, cuil) != -1)
					{
						contratosdXCuilImporteApagar(listC, lenC, listP, lenP,cuil);
					}
					else
					{
						printf("\nEl ID NO existe\n");
					}
				}
			}
		}

	}

}



//PUNTO 10 (2) /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void clienteConMasImportaAFacturar(Contrat *listC, int lenC, Pantalla *listP, int lenP)
{

	long long int cuilAux;
	float totalAcum;
	int i;
	int j;


	for (j = 0; j < lenP; j++)

{
		for(i=0;i<=lenC;i++)

				{
//		           total =listP[j].precio * (float) listC[i].cantDias
					if (listP[j].id == listC[i].idPantalla && (listP[j].precio * (float) listC[i].cantDias) > totalAcum)
					{

						totalAcum = listP[j].precio * (float) listC[i].cantDias;
						cuilAux = listC[i].cuil;
					}
				}

}

printf("\nEL CLIENTE CON IMPORTE MAS ALTO: [%lld]\n",cuilAux );



}


