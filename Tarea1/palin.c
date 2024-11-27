#include <stdio.h>
#include <stdint.h>

#include "palin.h"

int palindrome(uint32_t x) {
  // En primer lugar asignamos las máscaras
  unsigned m1 = -1;
  unsigned mask1 = ~(m1 << 4);

  unsigned m2 = -1;
  unsigned mask2 = ~(m2 >> 4);
  // Estas corresponden a 4 1's puestos en cada extremo
  // Según el extremo del uint32 que analicemos, usaremos una mask u otra

  for (unsigned int i = 0; i < 4; i++){
    //En primer lugar realizamos 4 iteraciones
    if ( (( x & mask1 ) << ((7-(i+i)) + (7-(i+i)) + (7-(i+i)) + (7-(i+i)))) ==  (x & mask2 ) ){ //Tenemos que comparar la misma cadena de bits
      //Por lo que es necesario desplazar una de las 2 cadenas de bits para realizar una correcta comparación
      //Notemos que este desplazamiento dependerá de cada iteración
      mask1 <<= 4;
      mask2 >>= 4;
      //Luego, en caso de que ambos extremos sean idénticos, shifteamos ambos extremos de las máscaras
      // Y continuamos con la siguiente iteración
    } else { //En caso de que algún extremo no sea igual
      return 0; //Retornamos 0
    }
  }
  return 1; //En caso de que ningún extremo sea distinto, retornamos 1
}
