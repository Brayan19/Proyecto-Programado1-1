#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "servidor.h"

void Mensaje_Error (const char *mensaje)
{
    perror (mensaje);
    exit(1);
}

int main(int argc, char *argv[])
{

	int sockfeed, newsockfeed, portnumber;
    socklen_t cliente;
	char buffer[256];

	struct sockaddr_in direccionservidor,direccioncliente;

	sockfeed = socket (AF_INET, SOCK_STREAM,0);
	if (sockfeed <0)
		Mensaje_Error("Error creando socket\n");
 
	bzero((char*)&direccionservidor,sizeof(direccionservidor));
	
	portnumber = atoi(argv[1]);
	
    direccionservidor.sin_family = AF_INET; //codigo de familia de direcciones
					//se usa AF_INET por recomendacion

	direccionservidor.sin_port = htons (portnumber); //asignacion de numero de puerto
	
	direccionservidor.sin_addr.s_addr = INADDR_ANY;

	if (bind(sockfeed, (struct sockaddr*)&direccionservidor,sizeof(direccionservidor)) <0)
        Mensaje_Error("Error en la conexion\n");
	
	listen(sockfeed,5); //cantidad maxima de conexiones

	cliente = sizeof(direccioncliente);
	newsockfeed = accept (sockfeed, (struct sockaddr*)&direccioncliente,&cliente);
	if (newsockfeed <0)
		Mensaje_Error ("Error en aceptar");

	bzero (buffer,256); //limpieza del buffer
	newsockfeed = read(newsockfeed,buffer,255);
	if (newsockfeed <0)
		Mensaje_Error("Error al leer del socket\n");
	printf ("Aquí está el mensaje: %s ",buffer);

	char prueba[]= "Hola";
	newsockfeed = write(newsockfeed,prueba,18);
	if (newsockfeed <0)
		Mensaje_Error("Error al escribir en el socket");
	

return 0;
}
