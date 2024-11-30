#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define TAM_MAX 255

typedef struct {
    int izq, der;
    uint16_t tam_llave, tam_valor;
} NodoArch;


int agregar(FILE *dicc, char *llave, char *valor){
    fseek(dicc, 0, SEEK_END);
    int pos = ftell(dicc);
    uint16_t tam_llave = strlen(llave);
    uint16_t tam_valor = strlen(valor);
    NodoArch nodo = {-1, -1, tam_llave, tam_valor};
    fwrite(&nodo, sizeof(NodoArch), 1, dicc);
    fwrite(llave, tam_llave, 1, dicc);
    fwrite(valor, tam_valor, 1, dicc);
    return pos;
}

int main(int argc, char *argv[]) {
    // Verificar que se reciban los parámetros correctos
    if (argc != 4) {    // Los parámetros son el nombre del archivo, la llave y el valor
        // Error de uso (mal ingreso de parámetros)
        fprintf(stderr, "uso: ./definir <archivo> <llave> <definicion>\n");
        exit(1);
    }

    // Abrir el archivo en modo r+ (leer y escribir)
    char *nom = argv[1];
    FILE *dicc = fopen(nom, "r+");
    if (dicc == NULL) { // Si no se puede abrir el archivo
        perror(nom);
        exit(1);
    }

    // Obtener la llave y el valor desde los parámetros de la línea de comandos
    char *llave = argv[2];
    char *valor = argv[3];

    int pos = 0;
    fseek(dicc, 0, SEEK_SET); // Volver al inicio del archivo después de la verificación

    if (ftell(dicc)==0){ //tamaño del archivo es 0
        agregar(dicc, llave, valor);
    } else {
        while (1) { //while(true)
            NodoArch nodo;
            fseek(dicc, pos, SEEK_SET); // Desde el inicio se posiciona en el nodo que quiero leer
            fread(&nodo, sizeof(NodoArch), 1, dicc); // Lee el nodo
            char llavenodo[nodo.tam_llave+1]; // Crea un arreglo de tamaño de la llave
            fread(llavenodo, nodo.tam_llave, 1, dicc); // Lee la llave
            llavenodo[nodo.tam_llave] = '\0'; // Agrega un caracter nulo al final
            int cmp = strcmp(llavenodo, llave); // Compara la llave que quiero agregar con la llave que estoy leyendo
            if(cmp==0){
                exit(1);
            } else {
                int n_pos = nodo.izq;
                int es_izq = 1;
                if (cmp < 0) {
                    n_pos = nodo.der;
                    es_izq = 0;
                }
                if (n_pos != -1) {
                    pos = n_pos;
                } else {
                    n_pos = agregar(dicc, llave, valor);
                    if(es_izq){
                        nodo.izq = n_pos;
                    } else {
                        nodo.der = n_pos;
                    }
                    fseek(dicc, pos, SEEK_SET);
                    fwrite(&nodo, sizeof(NodoArch), 1, dicc);
                    break;
                } //else
            
            

            } //else
            

            
        } //for
        fclose(dicc);
        

        
    }
    
    return 0;
}

    