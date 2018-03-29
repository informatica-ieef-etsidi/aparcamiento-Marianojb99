//Programador: Mariano Jiménez Bohórquez
// Programa para gestionar dos plazas de coches y una de moto si estas registrado

#include <stdio.h>
#include <string.h>

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
	char usuario1[50]= "mariano" , password1[50] = "1234";
	int i = 0; // Numero de intentos
	struct plaza plaza1 = { 'C', 0 }, plaza2 = { 'C', 0 }, plaza3 = { 'M', 0 };
	struct parking cliente[3];
	char opcion;
	int bucle = 0, bucle2 = 0;
	char tipo_vehiculo, plaza, matricula[8];
	int orden;

	while (bucle == 0) {

		printf("Antes de poder entrar al aparcamiento, debe registrarse. Registrese por favor.\n");
		system("pause");
		system("cls");
		printf("Introduzca su usuario: \n");
		gets(cliente[3].usuario);
		printf("Introduzca su contraseña: \n");
		gets(cliente[3].password);
		system("pause");
		system("cls");

		if (strcmp(usuario1, cliente[3].usuario) == 0 && strcmp(password1, cliente[3].password)== 0) {
			while (bucle2 == 0) {
				printf(" Bienvenido, seleccione una de estas opciones: \n");
				printf("\t R - Si quiere reservar una plaza de aparcamiento\n");
				printf("\t A - Si quiere abandonar la plaza de aparcamiento\n");
				printf("\t E - Si quiere mirar como se encuentran las plazas de aparcamiento\n");
				printf("\t B - Si quiere buscar su vehiculo a traves de su matricula\n");
				printf("\t S - Si quiere salir del programa\n");
				scanf_s("%c", &opcion);

				system("cls");
				switch (opcion) {
				case 'r':
				case 'R':
					getchar();
					printf("Antes de reservar plaza indique que tipo de vehiculo posee: \n C -(coche) \n M -(moto) \n");
					scanf_s("%c", &tipo_vehiculo);

					switch (tipo_vehiculo) {
					case'c':
					case'C':
						printf("El vehiculo seleccionado es un coche\n");
						system("pause");
						system("cls");

						if (plaza1.estado == 0 && plaza2.estado == 0) {
							printf("Al estar las dos plazas de coche disponibles, introduzca su matricula: \n");
							scanf_s("%s", plaza1.matricula, 8);
							plaza1.estado = 1;
						}
						else if (plaza1.estado == 1 && plaza2.estado == 0) {
							printf("La plaza 1 de coche esta ocupada pero la plaza 2 de coche no, introduzca su matricula: \n");
							scanf_s("%s", plaza2.matricula, 8);
							plaza2.estado = 1;
						}
						else if (plaza1.estado == 0 && plaza2.estado == 1) {
							printf("La plaza 2 de coche esta ocupada pero la plaza 1 de coche no, introduzca su matricula: \n");
							scanf_s("%s", plaza1.matricula, 8);
							plaza1.estado = 1;
						}
						else {
							printf("Lo siento, el aparcamiento de coche esta completo, vuelva mas tarde\n");
							system("pause");
							system("cls");
						}
						break;

					case'm':
					case'M':
						printf("El vehiculo introducido es una moto\n");
						system("pause");
						system("cls");

						if (plaza3.estado == 0) {
							printf("Al estar la plaza de moto disponible (plaza 3), introduzca su matricula: \n");
							scanf_s("%s", plaza3.matricula, 8);
							plaza3.estado = 1;
						}
						else {
							printf("Lo siento, pero el aparcamiento de motos esta completo, vuelva mas tarde... \n");
							system("pause");
							system("cls");
						}
						break;
					}
					break;
				case 'a':
				case 'A':
					printf("seleccione que plaza va ha abandonar: 1, 2 o 3.\n");
					scanf_s("%d", &plaza);

					if (plaza == 1) {
						printf("El coche con matricula %s ha abandonado la plaza 1, vuelva pronto \n", plaza1.matricula);
						plaza1.estado = 0;
						system("pause");
					}
					else if (plaza == 2) {
						printf("El coche con matricula %s ha abandonado la plaza 2, vuelva pronto \n", plaza2.matricula);
						plaza2.estado = 0;
						system("pause");
					}
					else if (plaza == 3) {
						printf("La moto con matricula %s ha abandonado la plaza 3, vuelva pronto \n", plaza3.matricula);
						plaza3.estado = 0;
						system("pause");
					}
					else {
						printf("Opcion introducida incorrecta, vuelva a intentarlo\n");
						system("pause");
					}
					break;

				case 'e':
				case'E':
					printf("Aqui podra comprobar el estado del aparcamiento\n");
					system("pause");
					system("cls");
					if (plaza1.estado == 0 && plaza2.estado == 0 && plaza3.estado == 0) {
						printf("Plaza 1 (coche): LIBRE\n");
						printf("Plaza 2 (coche): LIBRE\n");
						printf("Plaza 3 (moto): LIBRE\n");
						system("pause");
						system("cls");
					}
					else if (plaza1.estado == 1 && plaza2.estado == 0 && plaza3.estado == 0) {
						printf("Plaza 1 (coche): OCUPADO por vehiculo con matricula %s\n", plaza1.matricula);
						printf("Plaza 2 (coche): LIBRE\n");
						printf("Plaza 3 (moto): LIBRE\n");
						system("pause");
						system("cls");
					}
					else if (plaza1.estado == 0 && plaza2.estado == 1 && plaza3.estado == 0) {
						printf("Plaza 1 (coche): LIBRE\n");
						printf("Plaza 2 (coche): OCUPADO por vehiculo con matricula %s\n", plaza2.matricula);
						printf("Plaza 3 (moto): LIBRE\n");
						system("pause");
						system("cls");
					}
					else if (plaza1.estado == 0 && plaza2.estado == 0 && plaza3.estado == 1) {
						printf("Plaza 1 (coche): LIBRE\n");
						printf("Plaza 2 (coche): LIBRE\n");
						printf("Plaza 3 (moto): OCUPADO por vehiculo con matricula %s\n", plaza3.matricula);
						system("pause");
						system("cls");
					}
					else if (plaza1.estado == 1 && plaza2.estado == 0 && plaza3.estado == 1) {
						printf("Plaza 1 (coche): OCUPADO por vehiculo con matricula %s\n", plaza1.matricula);
						printf("Plaza 2 (coche): LIBRE\n");
						printf("Plaza 3 (moto): OCUPADO por vehiculo con matricula %s\n", plaza3.matricula);
						system("pause");
						system("cls");
					}
					else if (plaza1.estado == 1 && plaza2.estado == 1 && plaza3.estado == 0) {
						printf("Plaza 1 (coche): OCUPADO por vehiculo con matricula %s\n", plaza1.matricula);
						printf("Plaza 2 (coche): OCUPADO por vehiculo con matricula %s\n", plaza2.matricula);
						printf("Plaza 3 (moto): LIBRE\n");
						system("pause");
						system("cls");
					}
					else {
						printf("Plaza 1 (coche): OCUPADO por vehiculo con matricula %s\n", plaza1.matricula);
						printf("Plaza 2 (coche): OCUPADO por vehiculo con matricula %s\n", plaza2.matricula);
						printf("Plaza 3 (moto): OCUPADO por vehiculo con matricula %s\n", plaza3.matricula);
						system("pause");
						system("cls");
					}
					break;
				case 'b':
				case 'B':
					printf("Introduzca la matricula de su vehiculo: \n");
					scanf_s("%s", matricula, 8);
					printf("La matricula introducida es: %s\n\n", matricula, 8);

					if (strcmp(matricula, plaza1.matricula)== 0) {
						printf("El vehiculo con matricula %s se encuentra en la plaza 1 del aparcamiento \n", plaza1.matricula, 8);
						getchar();
					}
					else if (strcmp(matricula, plaza2.matricula)== 0){
						printf("El vehiculo con matricula %s se encuentra en la plaza 2 del aparcamiento \n", plaza2.matricula, 8);
						getchar();
					}
					else if (strcmp(matricula, plaza3.matricula)== 0) {
						printf("El vehiculo con matricula %s se encuentra en la plaza 3 del aparcamiento \n", plaza3.matricula, 8);
						getchar();
					}
					else {
						printf("Lo siento, pero la matricula %s no se encuentra en el aparcamiento \n ", matricula, 8);
					}
					system("pause");
					system("cls");
					break;
				case's':
				case'S':
					getchar();
					bucle = 1;
					bucle2 = 1;
					break;
				}
			}
		}
		else {
			if (i == 3) {
				printf("Lo siento pero no quedan mas intentos\n");
				bucle = 1;
			}
			else {
				printf("Lo siento pero no esta registrado vuelva a intentarlo\n");
				printf("Le quedan %d intentos\n", 3-i);
				i++;
				system("pause");
				system("cls");
			}
		}
	}
	getchar();
}