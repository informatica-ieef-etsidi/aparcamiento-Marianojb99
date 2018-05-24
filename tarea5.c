//Programador: Mariano Jiménez Bohórquez

#include <stdio.h>
#include <string.h>
#define NPLAZAS 10 // 5 son de coche y 5 son de moto


struct usuario {
	char username[50];
	char password[50];
};

struct plaza {
	char tipo; // M - Moto / C - Coche
	int estado; // 0 - Libre / 1 - Ocupada
	char matricula[8]; // Formato de la matrícula: NNNNLLL
};

char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int existeUsuario(struct usuario miusuario, char username[], char password[]);

void main() {
	struct plaza aparcamiento[NPLAZAS] = { 0 };// Para tener todas las plazas libres al principio
	struct usuario miusuario = { "mariano", "0000" };
	int sesion = 0, estado;
	char tipo_vehiculo, matricula[8], usuario[20], contrasena[20], matricula2[8];
	int j, num = 0;// Variables para los bucles
	int aux;
	

	while (sesion == 0) {
		printf("Bienvenido al aparcamiento. Antes de empezar registrese por favor:\n");
		printf("Introduzca su usuario:\n");
		gets(usuario);
		printf("Introduzca su contrasena: \n");
		gets(contrasena);
		if (existeUsuario(miusuario,usuario,contrasena) == 1) {
			sesion = 1;
		}
		else {
			sesion = 0;
		}
		system("pause");
		system("cls");
	}
	while (sesion == 1) {
		switch (menu()) {
		case'r':
		case'R':
			for (j = 0; j < NPLAZAS; j++) {
				if (aparcamiento[j].estado == 0) {
					estado = 0;
				}
			}
			getchar();
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
					getchar();
					if (j < NPLAZAS - 5) {
						printf("Introduzca su matricula:\n");
						gets(aparcamiento[j].matricula);
						aux = esMatriculaValida(aparcamiento[j].matricula);
						if (aux == 1) {
							aparcamiento[j].estado = 1;
							printf("Vehiculo aparcado correctamente en la plaza %d\n", j + 1);
						}
						system("pause");
						system("cls");
					}
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
					getchar();
					if (j < NPLAZAS) {
						printf("Introduzca su matricula:\n");
						gets(aparcamiento[j].matricula);
						aux = esMatriculaValida(aparcamiento[j].matricula);
						if (aux == 1) {
							aparcamiento[j].estado = 1;
							printf("Vehiculo aparcado correctamente en la plaza %d\n", j + 1);
						}
						system("pause");
						system("cls");
					}
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

			for (j = 0; j < NPLAZAS - 5; j++) {
				if (aparcamiento[j].estado == 0) {
					printf("Plaza %d de coche - LIBRE\n", j + 1);
				}
				else if (aparcamiento[j].estado == 1) {
					printf("Plaza %d de coche - OCUPADO por vehiculo con matricula %s \n", j + 1, aparcamiento[j].matricula, 8);
				}
			}
			for (j = (NPLAZAS - 5); j < NPLAZAS; j++) {
				if (aparcamiento[j].estado == 0) {
					printf("Plaza %d de moto - LIBRE\n", j + 1);
				}
				else if (aparcamiento[j].estado == 1) {
					printf("Plaza %d de moto - OCUPADO por vehiculo con matricula %s \n", j + 1, aparcamiento[j].matricula, 8);
				}
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
			sesion = 2;
			break;
		}
		system("cls");
	}
}
char menu() {
	char opcion;

	printf(" Bienvenido, seleccione una de estas opciones: \n");
	printf("\t R - Si quiere reservar una plaza de aparcamiento\n");
	printf("\t A - Si quiere abandonar la plaza de aparcamiento\n");
	printf("\t E - Si quiere mirar como se encuentran las plazas de aparcamiento\n");
	printf("\t B - Si quiere buscar su vehiculo a traves de su matricula\n");
	printf("\t S - Si quiere salir del programa\n");
	scanf_s("%c", &opcion);
	return opcion;
}

int existeUsuario(struct usuario miusuario, char username[], char password[]) {
	int n = 0;
	if (strcmp(username, miusuario.username) == 0 && strcmp(password, miusuario.password) == 0) {
		return 1;
	}
	else {
		if (n == 3) {
			printf("Lo siento pero no quedan mas intentos\n");
			return;
		}
		else {
			printf("Lo siento pero no esta registrado vuelva a intentarlo\n");
			printf("Le quedan %d intentos\n", 3 - n);
			n++;
			system("pause");
			system("cls");
		}
		return 0;
	}
}

int esDigitoValido(char caracter) {
	if (caracter >= '0' && caracter <= '9') {
		return 1;
	}
	else {
		return 0;
	}
}

int esLetraValida(char caracter) {
	if (caracter >= 'a' && caracter <= 'z') {
		caracter = caracter - 32;
	}
	if (caracter > 'A' && caracter <= 'Z' && caracter != 'E' && caracter != 'I' && caracter != 'O' && caracter != 'U') {
		return 1;
	}
	else {
		return 0;
	}
}

int esMatriculaValida(char matricula[]) {
	int i, cierto, numero, letra;

	for (i = 0; i <= 4; i++) {
		numero = esDigitoValido(matricula[i]);
		if (numero == 1) {
			cierto = 1;
		}
	}
	for (i = 4; i <= 7; i++) {
		letra = esLetraValida(matricula[i]);
		if (letra == 1) {
			cierto = 1;
		}
	}
	return cierto;
}