/*
 * PantallaContract.h
 *
 *  Created on: 7 oct. 2020
 *      Author: nico
 */

#ifndef PANTALLACONTRACT_H_
#define PANTALLACONTRACT_H_


//PUNTO 3


int contratPantalla_chargeArray (Contrat *listC, int lenC,Pantalla *listP, int lenP);
void pantallasXCuil(Contrat *listC, int lenC,Pantalla *listP, int lenP, long long int *cuil);
long long int contrat_findArrayByCuil (Contrat *list, int len, long long int cuil);
int pantalla_printForIdSinHeader  (Pantalla *list, int len, int id);
int contratPantalla_updateDias (Contrat *listC, int lenC,Pantalla *listP, int lenP);
int cancelarContratacion (Contrat *listC, int lenC,Pantalla *listP, int lenP);
void contratosdXCuil(Contrat *listC, int lenC,Pantalla *listP, int lenP, long long int *cuil);


//Punto 7
void  contratosdXCuilImporteApagar(Contrat *listC, int lenC,Pantalla *listP, int lenP, long long int *cuil);
int importeAPagarXContrato_printForId  (Contrat *listC, int lenC,Pantalla *listP, int lenP, int id);
void consultaFacturacion(Contrat *listC, int lenC, Pantalla *listP,int lenP);
void contratMasImportaTotal_headerArray(void);

//Punto 8
int contratMasNomPantalla_printArray(Contrat *listC, int lenC, Pantalla *listP, int lenP);
void contratMasNomPantalla_headerArray(void);


//punro 10 (1)
void listaClieteCantidadContEImporte(Contrat *listC, int lenC, Pantalla *listP, int lenP);
int calcularCantContratacionesDeUnCliente(Contrat *listC, int lenC, long long int cuil);

//punro 10 (2)
void clienteConMasImportaAFacturar(Contrat *listC, int lenC, Pantalla *listP, int lenP);

#endif /* PANTALLACONTRACT_H_ */
