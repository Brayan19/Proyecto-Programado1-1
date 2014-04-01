//
//  server.c
//
//
//  Created by Luis Gabelo & Brayan Blanco.
//
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


void charge(int, char*);

void serv(struct amigo base){
    
    char *no,*ip,*pu; // creación de variables de tipo char pointer para
                      // asignar el contenido del struct

    // Asignación de datos del struct
     no= base.name;
     ip= base.ip;
     pu= base.port;
    
    
    // Creación de variables necesarias para el socket
    int sock, newsock, portnumber, tene;
    socklen_t cli;
    char buffer[256];

    
    
    struct sockaddr_in servidor, cliente; //servidor y cliente del tipo socaddr_in
    int var_cont;
    
    sock = socket(AF_INET, SOCK_STREAM, 0); // creación del socket
    if (sock < 0)
        printf("Error en la apertura del socket");
    
    bzero((char *) &servidor, sizeof(servidor));
    
    portnumber = atoi(pu);
    
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = INADDR_ANY;
    servidor.sin_port = htons(portnumber);
    
    if (bind(sock, (struct sockaddr *) &servidor, sizeof(servidor)) <0)
        printf("Error en la conexión");
    
    listen(sock, 5);
    cli = sizeof(cliente);
    
    while (1)
    {
            newsock = accept(sock, (struct sockaddr *) &cliente,&cli); //aceptar la conexion
            if (newsock <0)
                printf("Error en aceptar");
        
        tene = fork();  //realiza un fork que le permite
                        //seguir recibiendo mensajes
        
        if(tene <0)
            printf("Error en el fork");
        
        if (tene ==0)
        {
            
            close(sock);
            charge(newsock, no);
            exit(0);
        }
        else
            close(newsock);
    }
    close(sock);

    }

    void charge (int s, char *nombre) //metodo para recibir y enviar los mensajes
{
    
    int n;
    
    char buffer[256];
    
    bzero(buffer,256);

    n = read(s, buffer, 255);
    
    if (n <0)
        printf("Error al leer en el socket");
    
            printf("El mensaje de %s es:\n%s\n",nombre, buffer);
    
    
    
        n = write (s, "Mensaje recibido\n", 16);
    
    

    if (n<0)
        printf("Error escribir en socket\n");

}
