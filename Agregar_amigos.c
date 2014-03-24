#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct usuario{
    char *nombre;
    char *ipa;
    int puerto;
};

int main()
{
	char nombre_usuario[]=" ";
	char ip[]=" ";
	int port;
	printf("Digite el nombre del usuario a agregar\n");
	scanf("%s",nombre_usuario);
	printf("\n");
	printf("Digite el ip del usuario:\n");
	scanf("%s",ip);
	printf("\n");
	printf("Digite el puerto de comunicacion");
	scanf("%d",&port);
	struct usuario temp;
    temp.nombre = nombre_usuario;
    temp.ipa = ip;
    temp.puerto = port;
	printf("\n");
	FILE *pointer;
	pointer = fopen("amigos.txt", "r+");
	fprintf(pointer, "%50s%20s%4d\n", temp.nombre, temp.ipa, temp.puerto);
    //fputs(temp, pointer);
	//fputs("\n",pointer);
	fclose (pointer);
	return 0;
}

