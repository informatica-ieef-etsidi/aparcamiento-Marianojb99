//Programador: Mariano Jiménez Bohórquez
// programa para gestionar dos plazas de aparcamiento de coche y una de moto

#include<stdio.h>
#include <string.h>


void main() {

	char opcion, matricula1[8], matricula2[8], vehiculo[6], matricula3[8], matricula[8], tipo_vehiculo;
	int plaza_1_coche = 0, plaza_2_coche = 0, plaza, plaza_1_moto = 0;
	int i;
	int orden, orden1, orden2;


	do {

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

				if (plaza_1_coche == 0 && plaza_2_coche == 0) {
					printf("Al estar las dos plazas de coche disponibles, introduzca su matricula: \n");
					scanf_s("%s", matricula1, 8);
					plaza_1_coche = 1;
				}
				else if (plaza_1_coche == 1 && plaza_2_coche == 0) {
					printf("La plaza 1 de coche esta ocupada pero la plaza 2 de coche no, introduzca su matricula: \n");
					scanf_s("%s", matricula2, 8);
					plaza_2_coche = 1;
				}
				else if (plaza_1_coche == 0 && plaza_2_coche == 1) {
					printf("La plaza 2 de coche esta ocupada pero la plaza 1 de coche no, introduzca su matricula: \n");
					scanf_s("%s", matricula1, 8);
					plaza_1_coche = 1;
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

				if (plaza_1_moto == 0) {
					printf("Al estar la plaza de moto disponible, introduzca su matricula: \n");
					scanf_s("%s", matricula3, 8);
					plaza_1_moto = 1;
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
				printf("El coche con matricula %s ha abandonado la plaza 1, vuelva pronto \n", matricula1);
				plaza_1_coche = 0;
				system("pause");
			}
			else if (plaza == 2) {
				printf("El coche con matricula %s ha abandonado la plaza 2, vuelva pronto \n", matricula2);
				plaza_2_coche = 0;
				system("pause");
			}
			else if (plaza == 3) {
				printf("La moto con matricula %s ha abandonado la plaza 1 de moto, vuelva pronto \n", matricula3);
				plaza_1_moto = 0;
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
			if (plaza_1_coche == 0 && plaza_2_coche == 0 && plaza_1_moto == 0) {
				printf("Plaza 1 (coche): LIBRE\n");
				printf("Plaza 2 (coche): LIBRE\n");
				printf("Plaza 3 (moto): LIBRE\n");
				system("pause");
				system("cls");
			}
			else if (plaza_1_coche == 1 && plaza_2_coche == 0 && plaza_1_moto == 0) {
				printf("Plaza 1 (coche): OCUPADO por vehiculo con matricula %s\n", matricula1);
				printf("Plaza 2 (coche): LIBRE\n");
				printf("Plaza 3 (moto): LIBRE\n");
				system("pause");
				system("cls");
			}
			else if (plaza_1_coche == 0 && plaza_2_coche == 1 && plaza_1_moto == 0) {
				printf("Plaza 1 (coche): LIBRE\n");
				printf("Plaza 2 (coche): OCUPADO por vehiculo con matricula %s\n", matricula2);
				printf("Plaza 3 (moto): LIBRE\n");
				system("pause");
				system("cls");
			}
			else if (plaza_1_coche == 0 && plaza_2_coche == 0 && plaza_1_moto == 1) {
				printf("Plaza 1 (coche): LIBRE\n");
				printf("Plaza 2 (coche): LIBRE\n");
				printf("Plaza 3 (moto): OCUPADO por vehiculo con matricula %s\n", matricula3);
				system("pause");
				system("cls");
			}
			else if (plaza_1_coche == 1 && plaza_2_coche == 0 && plaza_1_moto == 1) {
				printf("Plaza 1 (coche): OCUPADO por vehiculo con matricula %s\n", matricula1);
				printf("Plaza 2 (coche): LIBRE\n");
				printf("Plaza 3 (moto): OCUPADO por vehiculo con matricula %s\n", matricula3);
				system("pause");
				system("cls");
			}
			else if (plaza_1_coche == 1 && plaza_2_coche == 1 && plaza_1_moto == 0) {
				printf("Plaza 1 (coche): OCUPADO por vehiculo con matricula %s\n", matricula1);
				printf("Plaza 2 (coche): OCUPADO por vehiculo con matricula %s\n", matricula2);
				printf("Plaza 3 (moto): LIBRE\n");
				system("pause");
				system("cls");
			}
			else {
				printf("Plaza 1 (coche): OCUPADO por vehiculo con matricula %s\n", matricula1);
				printf("Plaza 2 (coche): OCUPADO por vehiculo con matricula %s\n", matricula2);
				printf("Plaza 3 (moto): OCUPADO por vehiculo con matricula %s\n", matricula3);
				system("pause");
				system("cls");
			}
			break;
		case 'b':
		case 'B':
			printf("Introduzca la matricula de su vehiculo: \n");
			scanf_s("%s", matricula, 8);
			printf("La matricula introducida es: %s\n\n", matricula, 8);

			orden = strcmp(matricula, matricula1);

			if (orden == 0) {
				printf("El vehiculo con matricula %s se encuentra en el aparcamiento \n", matricula, 8);
				getchar();
			}
			else if (orden != 0) {

				orden1 = strcmp(matricula, matricula2);

				if (orden1 == 0) {
					printf("El vehiculo con matricula %s se encuentra en el aparcamiento \n", matricula, 8);
					getchar();
				}
				else if (orden1 != 0) {

					orden2 = strcmp(matricula, matricula3);

					if (orden2 == 0) {
						printf("El vehiculo con matricula %s se encuentra en el aparcamiento \n", matricula, 8);
						getchar();
					}
					else {
						printf("Lo siento, pero la matricula %s no se encuentra en el aparcamiento \n ", matricula, 8);
					}
				}
			}
			system("pause");
			system("cls");
			break;
		case's':
		case'S':
			break;
		}

	} while (opcion != 's'&& opcion != 'S');
	return 0;
}