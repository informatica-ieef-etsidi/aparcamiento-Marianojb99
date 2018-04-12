//Programador: Mariano Jiménez Bohórquez
// Programa para gestionar dos plazas de coches y una de moto si estas registrado

#include <stdio.h>
#include <string.h>
#define NPLAZAS 10 // 5 son de coche y 5 son de moto

struct plaza {
	char tipo; // M - Moto / C - Coche
	int estado; // 0 - Libre / 1 - Ocupada
	char matricula[8]; // Formato de la matrícula: NNNNLLL
};

struct parking { // Estructura del parking para poder registrarse
	char usuario[50];
	char password[50];
};

void main() {
	char usuario1[50] = "mariano", password1[50] = "0000";
	int i = 0; // Numero de intentos
	int j, num = 0; // Variables para los bucles
	int orden, bucle2 = 0;
	int estado;
	char opcion, matricula[8], tipo_vehiculo;
	struct parking cliente[NPLAZAS];
	struct plaza aparcamiento[NPLAZAS] = { 0 };

	do {
		printf("Regristrese antes de entrar al aparcamiento por favor.\n");
		printf("Introduzca su usuario:\n");
		gets(cliente[NPLAZAS].usuario);
		printf("Introduzca su contraseña: \n");
		gets(cliente[NPLAZAS].password);
		system("pause");
		system("cls");
		

		if (strcmp(usuario1, cliente[NPLAZAS].usuario) == 0 && strcmp(password1, cliente[NPLAZAS].password) == 0) {
			while (bucle2 == 0) {
				printf(" Bienvenido, seleccione una de estas opciones: \n");
				printf("\t R - Si quiere reservar una plaza de aparcamiento\n");
				printf("\t A - Si quiere abandonar la plaza de aparcamiento\n");
				printf("\t E - Si quiere mirar como se encuentran las plazas de aparcamiento\n");
				printf("\t B - Si quiere buscar su vehiculo a traves de su matricula\n");
				printf("\t S - Si quiere salir del programa\n");
				scanf_s("%c", &opcion);
				system("cls");

				getchar();
				switch (opcion) {
				case'r':
				case'R':
					getchar();
					for (j = 0; j < NPLAZAS; j++) {
						if (aparcamiento[j].estado == 0) {
							estado = 0;
							break;
						}
						break;
					}
					if (estado == 0) {
						printf("Hay plazas disponibles en el aparcamiento. Seleccione el tipo de vehiculo que posee:\n");
						printf("\t C - coche \n \t M - moto\n");
						scanf_s("%c", &tipo_vehiculo);

						switch (tipo_vehiculo) {
						case'c':
						case'C':
							printf("El vehiculo seleccionado es un coche\n");
							system("pause");
							system("cls");

							for (j = 0; j < NPLAZAS - 5; j++) {
								if (aparcamiento[j].estado == 0) {
									break;
								}
							}
							if (j < NPLAZAS - 5) {
								aparcamiento[j].estado = 1;
								getchar();
								printf("Introduzca su matricula:\n");
								gets(aparcamiento[j].matricula);
								printf("Vehiculo aparcado correctamente en la plaza %d\n", j + 1);
								system("pause");
								system("cls");
							}
							getchar();
							break;
						case'm':
						case'M':
							printf("El vehiculo seleccionado es una moto\n");
							system("pause");
							system("cls");

							for (j = (NPLAZAS - 5); j < NPLAZAS; j++) {
								if (aparcamiento[j].estado == 0) {
									break;
								}
							}
							if (j < NPLAZAS) {
								aparcamiento[j].estado = 1;
								getchar();
								printf("Introduzca su matricula:\n");
								gets(aparcamiento[j].matricula);
								printf("Vehiculo aparcado correctamente en la plaza %d\n", j + 1);
								system("pause");
								system("cls");
							}
							getchar();
							break;
						}
					}
					else {
						printf("Lo siento pero no quedan plazas disponibles, vuelva mas tarde\n");
						system("pause");
						system("cls");
					}
					break;
				case'a':
				case'A':
					printf("Seleccione que plaza va ha abandonar:\n");
					scanf_s("%d", &num);
					getchar();

					if (aparcamiento[num - 1].estado == 1) {
						printf("La plaza %d ha sido abandonada correctamente\n", num);
						aparcamiento[num - 1].estado = 0;
						system("pause");
						system("cls");
					}
					else {
						printf("Lo siento pero en esa plaza ya no hay ningun vehiculo, vuelva a intentarlo\n");
						system("pause");
						system("cls");
					}
					break;
				case 'e':
				case'E':
					printf("Aqui podra comprobar el estado del aparcamiento\n");
					system("pause");
					system("cls");

					for (j = 0; j < NPLAZAS - 5; j++) {
						if (aparcamiento[j].estado == 0) {
							printf("Plaza %d de coche - LIBRE\n", j + 1);
						}
						else if (aparcamiento[j].estado == 1) {
							printf("Plaza %d de coche - OCUPADO por vehiculo con matricula %s \n", j + 1, aparcamiento[j].matricula, 8);
						}
						getchar();
					}
					for (j = (NPLAZAS - 5); j < NPLAZAS; j++) {
						if (aparcamiento[j].estado == 0) {
							printf("Plaza %d de moto - LIBRE\n", j + 1);
						}
						else if (aparcamiento[j].estado == 1) {
							printf("Plaza %d de moto - OCUPADO por vehiculo con matricula %s \n", j + 1, aparcamiento[j].matricula, 8);
						}
						getchar();
					}
					system("pause");
					system("cls");
					break;
				case 'b':
				case 'B':
					printf("Introduzca la matricula de su vehiculo: \n");
					scanf_s("%s", matricula, 8);
					printf("La matricula introducida es: %s\n\n", matricula, 8);

					for (j = 0; j < NPLAZAS; j++) {
						if (strcmp(matricula, aparcamiento[j].matricula) == 0) {
							printf("El vehiculo con matricula %s se encuentra en la plaza %d del aparcamiento \n", aparcamiento[j].matricula, j + 1);
							getchar();
							break;
						}
					}
					if (strcmp(matricula, aparcamiento[j].matricula) != 0) {
						printf("Lo siento, pero la matricula %s no se encuentra en el aparcamiento \n ", matricula, 8);
					}
					system("pause");
					system("cls");
					break;
				case's':
				case'S':
					bucle2 = 1;
					break;
				}

			}
		}
		else {
			if (i == 3) {
				printf("Lo siento pero no quedan mas intentos\n");
				return;
			}
			else {
				printf("Lo siento pero no esta registrado vuelva a intentarlo\n");
				printf("Le quedan %d intentos\n", 3 - i);
				i++;
				system("pause");
				system("cls");
			}
		}
	}
	while (opcion == 's' || opcion == 'S');
	system("pause");
	system("cls");
}
