#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int utn_getNombre (char *mensaje, char *mensajeError, char *pResultado,
	       int intentos, int limite)
{

  char auxliar[limite];
  int retorno = -1;
  int contador = intentos;

  if (mensaje != NULL &&
      mensajeError != NULL &&
      pResultado != NULL &&
      intentos > 0 &&
      limite > 0)
    {
      do
	{
	  printf (mensaje);
	  fflush (stdin);
	  scanf ("%s", auxliar);

	  if (utn_esSoloLetras (auxliar) != -1)
	    {
	      strncpy (pResultado, auxliar, limite);
	      retorno = 0;
	    }
	  else
	    {
	      printf (mensajeError);
	      contador--;
	    };
	}
      while (retorno != 0 && contador > 0);
    }
  return retorno;
}




int utn_esSoloLetras(char str[])
{
   int i=0;

   while(str[i] != '\0')
   {
       if((str[i] == ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
	 return -1;
       i++;
   }
   return 0;
}




