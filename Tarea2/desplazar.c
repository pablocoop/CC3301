#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "desplazar.h"

void desplazar(char *str, int from, int nbytes, int by) {
  // complete
  /* La función desplazar mueve _nbytes_ partiendo de la posición _from_ de _str_ en _by_ caracteres hacia la derecha si _by_ es
positivo o en |by| caracteres hacia la izquierda si by es negativo. Esta función altera el mismo string str que recibe
como parámetro. */
  int len = strlen(str);
  char *lectura = str + from; //puntero al inicio de la lectura (y como iremos hacia adelante, empezaremos desde el inicio de los nbytes)
  //char *final = str + strlen(str) - 1; //puntero al final
  char *paste = str + from + by;
  int i = nbytes;
  int p = from + by;
  
  if (by > 0){
    lectura += nbytes - 1; //puntero al inicio de la lectura (y como iremos hacia atrás, empezaremos desde el fin de los nbytes)
    //char *final = str + strlen(str) - 1; //puntero al final
    paste += nbytes - 1;
    p += nbytes-1;
    while(i > 0) {
      if (p < len){
        *paste = *lectura; //pegamos la lectura en su lugar (desplazamos)
      }
      //los punteros de lectura y pegado irán hacia atrás
      lectura--;
      paste--;
      //para retroceder los punteros 
      i--;
      p--;
    }
  } else {
     //solo cambiaremos nbytes
    while(i > 0) {
      if (p >= 0){
        *paste = *lectura; //pegamos la lectura en su lugar (desplazamos)
      }
      //los punteros de lectura y pegado irán hacia atrás
      lectura++;
      paste++;
      //para retroceder los punteros 
      i--;
      p++;
    }
  }
}

char *desplazamiento(char *str, int from, int nbytes, int by) {
  char *new = malloc(strlen(str)+1); //sizeof(char) == 1
  strcpy(new,str);
  desplazar(new, from, nbytes, by);
  return new;
  // complete
}