//
//  Escoger_amigo.c
//  
//
//  Created by Luis Gabelo on 25/03/14.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    char otro[] = "P";
    char cadena[80]; //tamaño máximo de la línea
    char nombre[10], ipa[16];
    int puerto, var_control =0, i;

    
    // Struct para almacenar el amigo a conectar
    struct amigo {
        char *name;
        char *ip;
        int port;
    }; //end struct
    
    struct amigo chat;
    
    
    FILE *puntero;
    
    puntero = fopen("amigos.txt", "r"); //abre el archivo de los contactos
    
    //fscanf(puntero, "%s %s %d", nombre, ipa, &puerto);
    
    do{
        fscanf(puntero, "%s %s %d", nombre, ipa, &puerto);
        //printf("%s\t%s\t%d\n", nombre, ipa, puerto);
        i = (strcmp(otro, nombre));
        if (i==0){
            chat.name = nombre;
            chat.ip = ipa;
            chat.port = puerto;
            printf("%s\t%s\t%d\n", chat.name, chat.ip, chat.port);
            var_control =1;
        } //end if
        else
            var_control =2;
    }while ((fgets(cadena, 100, puntero) != NULL)&&(var_control !=1));
    
   /* do{
        
        fscanf(puntero, "%s %s %s", nombre, ipa, puerto);
        
        i = strcmp(otro_nombre, nombre);
        
        if (i==0) {
            var_control = 1;
            printf("%s %s %s", nombre, ipa, puerto);
    //        chat.name = nombre;
    //        chat.ip = ipa;
    //        chat.port = puerto;
            } // si encuentra al usuario lo guarda en un struct
        
        else
        {
            var_control =2;
        } //end else
    } while (fgets(cadena, 100, puntero) != NULL);//&&(var_control !=1)); */
    
    fclose(puntero); //cierra el archivo
    
  //  printf("%s\t%s\t%s\n", chat.name, chat.ip, chat.port);
    return 0;
}

