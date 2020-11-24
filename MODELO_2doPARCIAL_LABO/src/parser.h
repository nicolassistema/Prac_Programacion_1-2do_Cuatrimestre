/*
 * parser.h
 *
 *  Created on: 14 nov. 2020
 *      Author: nico
 */

#ifndef PARSER_H_
#define PARSER_H_
int parser_EnvioFromText(FILE* pFile , LinkedList* pArrayListEnvio);
int parser_EnvioFromBinary(FILE* pFile , LinkedList* pArrayListEnvio);


#endif /* PARSER_H_ */
