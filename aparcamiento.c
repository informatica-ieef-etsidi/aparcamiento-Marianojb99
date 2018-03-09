//Programador: Mariano Jiménez Bohórquez
// programa para gestionar dos plazas de aparcamiento

#include<stdio.h>


void main() {
	char opcion, matricula1[8], matricula2[8];
	int plaza_1 = 0, plaza_2 = 0, plaza;

	
	while (1) {

		printf("Bienvenido, seleccione una de estas opciones: \n");
		printf("R - Si quiere reservar una plaza de aparcamiento\n");
		printf("A - Si quiere abandonar la plaza de aparcamiento\n");
		printf("E - Si quiere mirar como se encuentran las plazas de aparcamiento\n");
		scanf_s("%c", &opcion);

		system("cls");

		switch (opcion) {
		case 'r':
		case 'R':
			if (plaza_1 == 0 && plaza_2 == 0) {
				printf("Al estar las dos plazas disponibles, introduzca su matricula: \n");
				scanf_s("%s", matricula1, 8);
				plaza_1 = 1;
			}
			else if (plaza_1 == 1 && plaza_2 == 0) {
				printf("La plaza 1 esta ocupada pero la plaza 2 no, introduzca su matricula: \n");
				scanf_s("%s", matricula2, 8);
				plaza_2 = 1;
			}
			else if (plaza_1 == 0 && plaza_2 == 1) {
				printf("La plaza 2 esta ocupada pero la plaza 1 no, introduzca su matricula: \n");
				scanf_s("%s", matricula1, 8);
				plaza_1 = 1;
			}
			else {
				printf("Lo siento, el aparcamiento esta completo, vuelva mas tarde\n");
				system("pause");
			}
			break;

		case 'a':
		case 'A':
		    printf("seleccione que plaza va ha abandonar: 1 o 2\n");
			scanf_s("%d", &plaza);

			if (plaza == 1) {
				printf("El vehiculo con matricula %s ha abandonado la plaza 1, vuelva pronto \n", matricula1);
				plaza_1 = 0;
				system("pause");
			}
			else if (plaza == 2) {
				printf("El vehiculo con matricula %s ha abandonado la plaza 2, vuelva pronto \n", matricula2);
				plaza_2 = 0;
				system("pause");
			}
			break;

		case 'e':
		case'E':
			printf("Aqui podra comprobar el estado del aparcamiento\n");
			system("pause");
			system("cls");
			if (plaza_1 == 0 && plaza_2 == 0) {
				printf("Plaza 1: LIBRE\n");
				printf("Plaza 2: LIBRE\n");
				system("pause");
				system("cls");
			}
			else if (plaza_1 == 1 && plaza_2 == 0) {
				printf("Plaza 1: OCUPADO por vehiculo con matricula %s\n", matricula1);
				printf("Plaza 2: LIBRE\n");
				system("pause");
				system("cls");
			}
			else if (plaza_1 == 0 && plaza_2 == 1) {
				printf("Plaza 1: LIBRE\n");
				printf("Plaza 2: OCUPADO por vehiculo con matricula %s\n", matricula2);
				system("pause");
				system("cls");
			}
			else {
				printf("Plaza 1: OCUPADO por vehiculo con matricula %s\n", matricula1);
				printf("Plaza 2: OCUPADO por vehiculo con matricula %s\n", matricula2);
				system("pause");
				system("cls");
			}
			break;
		}

	}
	system("pause");

}