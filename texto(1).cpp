/* 4661528 */
/*
  Módulo de definición de `texto'.

  `texto_t' es un puntero a una estructura (opaca, que debe definirse en
  texto.cpp) cuyo contenido es un texto (arreglo de elementos de tipo char).

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */

#ifndef _TEXTO_H
#define _TEXTO_H

#include "../include/utils.hpp"
#include "../include/texto.hpp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Longitud máxima de los textos. */
const nat TXT_MAX_LNG = 80;

/* representación de `texto', definida en texto.cpp */
struct rep_texto {
  char caracteres[TXT_MAX_LNG + 1];
  nat longitud;
};

/* El tipo `texto_t' es un puntero a elementos de tipo `rep_texto'. */
typedef rep_texto *texto_t;

/*  Devuelve un `texto' cuyo contenido es nulo (de longitud 0). */
texto_t texto_nulo() {
  texto_t res = new rep_texto;
  res->longitud = 0;
  return res;
}


/*  Devuelve un `texto' cuyo contenido es `simbolo'. */
texto_t char_a_texto(char simbolo) {
  texto_t res = new rep_texto;
  res->caracteres[0] = simbolo;
  res->caracteres[1] = '\0';
  res->longitud = 1;
  return res;
}

/*
  Devuelve un `texto' cuyo contenido es una copia de `cadena'.
  Precondición: la longitud de `cadena' no es mayor a TXT_MAX_LNG.
 */
texto_t cadena_a_texto(const char *cadena) {
  texto_t res = new rep_texto;
  res->caracteres[0] = *strdup(cadena);
  res->caracteres[strlen(res->caracteres)] = '\0';
  res->longitud = strlen(res->caracteres);
  assert(strlen(res->caracteres) <= TXT_MAX_LNG);
  return res;
}

/*
  Devuelve un `texto' leído desde la entrada estándar luego de ignorar los
  espacios en blanco iniciales.
  Lee hasta encontrar un espacio en blanco.
  Precondición: la longitud de la palabra no es mayor a TXT_MAX_LNG.
 */
texto_t leer_palabra() {
  texto_t res = new rep_texto;
  scanf("%s",res->caracteres);
  res->caracteres[strlen(res->caracteres)] = '\0';
  res->longitud = strlen(res->caracteres);
  assert(res->longitud <= TXT_MAX_LNG);
  return res;
} 

/*
  Devuelve un `texto' leído desde la entrada estándar.
  Lee hasta encontrar el carácter de `fin de línea' o de `fin de archivo'.
  Ese carácter es leído pero no se incluye en el `texto' devuelto.
  Precondición: la longitud del resto de la línea no es mayor a TXT_MAX_LNG.
 */
texto_t leer_resto_linea() {
  texto_t res = new rep_texto;
  fgets(res->caracteres, TXT_MAX_LNG, stdin);
  res->caracteres[strlen(res->caracteres) - 1] = '\0';
  res->longitud = strlen(res->caracteres);
  assert(res->longitud <= TXT_MAX_LNG);
  assert(res->caracteres[res->longitud] == '\0');
  return res;
}


/*  Escribe en la salida estándar el contenido de `t'. */
void escribir_texto(texto_t t) {
  printf("%s",t->caracteres);
}
/*
  Inserta en la salida estándar `nueva línea' (inserta una línea y mueve el
  cursor a la primera columna de la línea insertada).
 */
void escribir_nueva_linea() {
  printf("\n");
}
/*
  Devuelve un `texto' cuyo contenido es la concatenación de las copias de
  los de `t1' y `t2'.
  Si la suma de las longitudes de `t1' y `t2' es mayor a TXT_MAX_LNG
  se concatenan los primeros caracteres de `t2' hasta completar TXT_MAX_LNG.
 */
texto_t concatenar_texto(texto_t t1, texto_t t2) {
  texto_t res = new rep_texto;
  texto_t aux1 = t1;
  texto_t aux2 = t2;
  
  if((aux1->longitud + aux2->longitud) <= TXT_MAX_LNG) {
    res->caracteres[0] = aux1->caracteres[0];
    res->caracteres[aux1->longitud] = aux2->caracteres[0];
    res->caracteres[strlen(res->caracteres)] = '\0';   
    res->longitud = (aux1->longitud + aux2->longitud);
  }
  return res;
}
/*  Devuelve un `texto' cuyo contenido es una copia del de `t'. */
texto_t copiar_texto(texto_t t) {
    texto_t res = t;
    return res;
}

/*  Devuelve `true' si y sólo si `t' es nulo. */
bool es_texto_nulo(texto_t t) {
   int res = 0;   
   if ( t->longitud == 0 )
        res = 1;
   return res;
}


/*  Devuelve la longitud del contenido de `t'. */
nat longitud_texto(texto_t t) {
    return t->longitud;
}
/*
  Devuelve el resultado de la comparación lexicográfica de los contenidos de
  `t1' y `t2'.
 */
comp_t comparar_texto(texto_t t1, texto_t t2) {
    comp_t res;
    int aux;
    aux = strncmp(t1->caracteres, t2->caracteres, TXT_MAX_LNG);
    if(aux>0)
        res = mayor;
    else if (aux<0)
        res = menor;
    else
        res = igual;
    
    return res;    
}
/*  Devuelve el resultado de convertir el contenido de `t' en un entero. */
int texto_a_int(texto_t t) {
  int res;
  for(nat i = 0; i <= (t->longitud); i++) {
      res += t->caracteres[i];
  }
  return res;
}

/* Devuelve el resultado de convertir `i' a texto_t. */
texto_t int_a_texto(int i) {
  texto_t res = new rep_texto;
  res->longitud = sprintf(res->caracteres, "%d", i);
  for(nat j = 0; j <= (res->longitud); j++) {
	  char aux = (char) (res->caraceres[i] + 48);
	  res->caracteres[j] = aux;
  }
  assert((res->longitud > 0) && (res->longitud < TXT_MAX_LNG));
  assert(res->caracteres[res->longitud] == '\0');
  return res;
}
/*  Libera la memoria asignada a `t'. */
void liberar_texto(texto_t &t) {
  delete t;
}
#endif
