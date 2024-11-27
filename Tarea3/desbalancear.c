#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "desbalancear.h"
void desbalancear(Nodo **pa, Nodo **pult) {
  if (*pa== NULL){
    *pult=NULL;
    return;
  }
  Nodo *I=(*pa)->izq;
  Nodo *D=(*pa)->der;

  Nodo *UI = NULL;
  Nodo *UD = NULL;

  desbalancear(&I, &UI); 
  desbalancear(&D,&UD);

  (*pa)->izq = NULL;

  if (D == NULL){
    *pult = *pa;
  } 
  else{ 
    (*pa)->der = D;
    *pult = UD;
  }

  if (I!=NULL){
    UI->der=*pa;
    *pa=I;
  }
  


  
}

Nodo *desbalanceado(Nodo *a, Nodo **pult) {
  if (a== NULL){
    *pult=NULL;
    return NULL;
  }
  Nodo *UI = NULL;
  Nodo *ID = desbalanceado(a->izq, &UI);

  Nodo* nodo=(Nodo*)malloc(sizeof(Nodo));
  
  nodo->id=a->id;
  nodo->hash=a->hash;
  nodo->izq=NULL;
  nodo->der=NULL;

  Nodo *DD = desbalanceado(a->der, pult);

  if (UI != NULL) {
    UI->der=nodo;
  }
  nodo->der = DD;
  if (DD == NULL) {
    *pult = nodo;
  }

  if (ID!=NULL){
    return ID;
  }
  else{
    return nodo;
  }
  
}
// Nodo *desbalanceado(Nodo *a, Nodo **pult) {
//   if (a== NULL){
//     *pult=NULL;
//     return NULL;
//   }
//   Nodo *UI = NULL;
//   Nodo *ID = desbalanceado(a->izq, &UI);

//   Nodo* nodo=(Nodo*)malloc(sizeof(Nodo));
  
//   nodo->id=a->id;
//   nodo->hash=a->hash;
//   nodo->izq=NULL;
//   nodo->der=NULL;

//   Nodo *DD = desbalanceado(a->der, pult);

//   if (UI != NULL) {
//     UI->der=nodo;
//   }
//   nodo->der = DD;
//   if (DD == NULL) {
//     *pult = nodo;
//   }

//   if (ID!=NULL){
//     return ID;
//   }
//   else{
//     return nodo;
//   }
  
// }