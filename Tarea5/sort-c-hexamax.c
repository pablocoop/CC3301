#include <string.h>

void sort(unsigned int *nums, int n) {
  unsigned int *ult= &nums[n-1];
  unsigned int *p= nums;
  while (p<ult) {
    // No modifique nada arriba de esta linea
    // Inicio de la parte que debe cambiar
    int a1 = p[0];   // primer numero
    int a6 = p[1];   // siguiente numero

    int a2 = 0;  // maximo de a1
    int a3 = 0;  // maximo de a6
    
    int a5 = 0;           // contador de bits
    int a7 = 32;          // cantidad de bits
    while(a5<a7){         // recorrer los 32 bits de a1 y a6
      // En primer lugar obtenemos el máximo para el primer número a partir de los 4 bits actuales
      int t2 = (a1 >> a5) & 0x0000000F;   // obtener los 4 bits de a1
      if (t2 > a2){         // si el valor de t2 es mayor que el maximo actual
        a2 = t2;            // actualizar el maximo
      }
      // Continuamos obteniendo el máximo para el segundo número en los 4 bits actuales
      int t3 = (a6 >> a5) & 0x0000000F;   // obtener 4 bits de a6
      if (t3 > a3){         // si el valor de t3 es mayor que el maximo actual
        a3 = t3;            // actualizar el maximo
      }
      a5+=4;                // avanzar 4 bits
    }
    
    // Comparar los maximos, recordando que queremos orden ascendente
    int t1 = a2 >= a3 ? 0 : 1;    // comparar los maximos
    
    // Fin de la parte que debe cambiar
    // No Cambie nada mas a partir de aca
    if (t1 <= 0)
      p++;
    else {
      unsigned int tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= nums;
    }
  }
}
