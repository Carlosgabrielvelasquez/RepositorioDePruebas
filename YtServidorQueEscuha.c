/*
 * main.c
 *
 *  Created on: 19 abr. 2018
 *      Author: utnso
 */
#include <stdio.h> // Por dependencia de readline en algunas distros de linux :)
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
	printf("hola");

	struct sockaddr_in direccionServidor;
	direccionServidor.sin_family= AF_INET;
	direccionServidor.sin_addr.s_addr = INADDR_ANY;
	direccionServidor.sin_port = htons(8080); //all this - es  Burocracia, menos el puerto

	int servidor = socket(AF_INET, SOCK_STREAM, 0);
	if (bind(servidor/*Socket */,
			(void*/* porque usamos addr_in y no addr ()evita el warning*/) &direccionServidor/*puntero a direccion del servidor*/,
			sizeof(direccionServidor)/*tamaño de la direccion */) != 0) {

		perror("fallo el bind");
		return 1;
	}

	printf("Estoy escuchando\n");
	listen(servidor, 100);
	for (;;)
		;


	return 0;


}





