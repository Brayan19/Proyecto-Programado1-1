//
//  client.c
//  
//
//  Created by Luis Gabelo y Brayan Blanco
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void cli(char *nomb, char *intp, char *purt)
{

int sock, puerto, var_control;
struct sockaddr_in servidor;
struct hostent *server;

char buffer[256];

puerto = atoi(purt);

    sock = socket(AF_INET, SOCK_STREAM, 0); //creación del socket
    
    if (sock<0)
        printf("Error creando el socket");
    
    server = gethostbyname(intp);
    if (server==NULL)
    {
        printf("IP no encontrada");
        exit(0); //se sale del programa
    }
    
    bzero((char *) &servidor, sizeof(servidor));
    
    servidor.sin_family = AF_INET;
    
    bcopy((char *) server->h_addr, (char *) &servidor.sin_addr.s_addr,server->h_length);
    
    servidor.sin_port = htons(puerto);
    
    if (connect(sock, (struct sockaddr *)&servidor,sizeof(servidor)) <0)
        printf("Error de conexión");
    
    printf("Introduzca su mensaje:\n"); //mensaje a enviar 
    scanf("%s",buffer);
    var_control = write (sock, buffer, strlen(buffer));
    
    if (var_control <0)
        printf("Error al escribir en el socket");
    
    bzero(buffer,256);
    var_control = read(sock,buffer,255);
    
    if (var_control <0)
        printf("Error leyendo del socket");
    
    printf("Mensaje de servidor:\n%s\n",nomb, buffer);
    close(sock);
    

}
