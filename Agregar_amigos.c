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
	char nombre_usuario[30];
	char ip[20];
	int port;
	printf("Digite el nombre del usuario a agregar\n");
	scanf("%s",nombre_usuario);
	printf("\n");
    printf("%s\n", nombre_usuario);
	printf("Digite el ip del usuario:\n");
	scanf("%s",ip);
    printf("%s\n",nombre_usuario);
	printf("%s\n", ip);
	printf("Digite el puerto de comunicacion");
	scanf("%d",&port);
    printf("%s, %s, %d\n", nombre_usuario, ip, port);
	struct usuario temp;
    temp.nombre = nombre_usuario;
    temp.ipa = ip;
    temp.puerto = port;
	printf("\n");
	FILE *pointer;
	pointer = fopen("amigos.txt", "a");
	fprintf(pointer, "%30s%30s%4d\n", temp.nombre, temp.ipa, temp.puerto);
	fclose (pointer);
	return 0;
}

