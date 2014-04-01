//
//  cargar.c
//
// Created by Luis Gabelo
//
//

#include <stdio.h>
#include <stdlib.h>


void cargar(void)
{
    
    char cadena[80]; //tamaño máximo de la línea
    char nombre[10], ipa[16], puerto[8];
    FILE *puntero;
    
    puntero = fopen("amigos.txt", "r"); //abre el archivo de los contactos
    

    printf("Nombre\t\tIP\tpuerto\n"); //imprime una línea de informacion

    
    do{
      
        fscanf(puntero, "%s %s %s", nombre, ipa, puerto);
    
        printf("%s\t%s\t%s\n", nombre, ipa, puerto);
    
    } while (fgets(cadena, 100, puntero) != NULL);
    
    fclose(puntero);
    
    
}
