//
//  Principal_cliente.c
//  Archivo principal del messenger
//  Creado por Brayan Blanco y Gabelo Ureña
//  Interfaz para el cliente
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agregar_amigos.c"
#include "cargar.c"
#include "escoger3.c"
#include "client.c"


int main(void)
{
    
    char *o;
    int opcion, respuesta =0;
    
    while ((opcion!=4)||(respuesta!=1)){ //Muestra menú
        
        printf("Bienvenido al programa de chat\n");
        printf("Por favor elija una de las siguientes opciones:\n");
        printf("\n 1. Agregar amigos");
        printf("\n 2. Ver amigos en lista");
        printf("\n 3. Enviar un mensaje");
        printf("\n 4. Salir");
        printf("\n");
        printf("Por favor, seleccione una de las opciones anteriores: \n");
        scanf("%d",&opcion);
        
        switch (opcion) {
            case 1:
                system("clear");
                agregar();
                system("clear");
                break;
                
            case 2:
                system("clear");
                cargar();
                printf("\n");
                break;
                
            case 3:
                system("clear");
                printf("Digite el usuario a chatear\n");
                scanf("%s",o);
                cli((escojo(o).name), (escojo(o).ip), (escojo(o).port));
                break;
                
                
            case 4:
                system("clear");
                printf("Está seguro? 1 Sí, 2 No\n");
                scanf("%d",&respuesta);
                system("clear");
                break;
                
            default:
                printf("Error");
                break;
        }
    }
    
    
}
