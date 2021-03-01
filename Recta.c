/*Este programa crea una recta a partir de dos puntos y saca valores de la recta dependiendo de X
 *Autores: 	Alejandro Montilla
 *		Esneider Silva
 *		Jefferson Espitia
 *Versión: 1.0.0
 * */

//Definiendo paquetes
#include <stdio.h>

// Definiendo Estructura de un punto
struct punto 
{
        float x,y;
};

// Definiendo Funciones

// Pide los puntos de la recta
void PedirPuntos(struct punto *P1 , struct punto *P2);

// Calcula una pendiente con dos puntos
float CalcularPendiente(struct punto P1, struct punto P2);

// Calcula el punto de corte con dos puntos
float CalcularCorte(struct punto P1, struct punto P2);

// Calcula el producto Y en un punto X de una funcion definida por dos puntos  
float Funcion(float x, struct punto P1, struct punto P2);

void main()
{
	struct punto P1;
	struct punto P2;		  

	PedirPuntos(&P1,&P2);

	char Seleccion = 'y';

	// Proceso para elegir, si continuar hallando puntos de la recta o salir del programa
	do
	{
		printf("-|------------------------------------------------|-\n");
		printf("¿Continua hallando puntos de la recta? [Y/N]\n");
		scanf(" %1c",&Seleccion);
		printf("selecciono: %c\n", Seleccion);
		
		//Muestra los datos para ayudar al usuario
		printf("-|------------------------------------------------|-\n");
		printf("Los puntos son:\n");
	        printf("P1: ( %.3f , %.3f )\n", P1.x, P1.y);
        	printf("P2: ( %.3f , %.3f )\n", P2.x, P2.y);
		printf("Ecuacion de la recta:\n Y = %.3f * X + %.3f  \n", CalcularPendiente(P1, P2), CalcularCorte(P1, P2));
		switch(Seleccion)
		{
			// Hallando puntos de la recta
			case 'y':
			case 'Y':
				printf("Escoja un X:\n");
				float x;
				scanf(" %3f", &x);

				printf("Resultado: \nY = %.3f * %.3f + %.3f = %.3f \n",CalcularPendiente(P1, P2), x, CalcularCorte(P1, P2), Funcion(x, P1, P2));
				break;
		}
	}while(Seleccion != 'n' && Seleccion != 'N');
	
	// Finalizando Ejecución
	printf("Saliendo...");

}

void PedirPuntos( struct punto *P1 , struct punto *P2 )
{
	// Ingreso del primer punto
        printf("-|------------------------------------------------|-\n");
        printf("Ingrese primer punto\n");
        printf("Ingrse X: \n");
        scanf(" %3f",&(*P1).x);

        printf("Ingrese primer punto\n");
        printf("Ingrse Y: \n");
        scanf(" %3f",&(*P1).y);

        // Ingreso del primer punto

        printf("-|------------------------------------------------|-\n");
        printf("Ingrese segundo punto\n");
        printf("Ingrse X: \n");
        scanf(" %3f",&(*P2).x);

        printf("Ingrese segundo punto\n");
        printf("Ingrse Y: \n");
        scanf(" %3f",&(*P2).y);

}

float CalcularPendiente(struct punto P1, struct punto P2)
{
	return (P2.y - P1.y) / (P2.x - P1.x);
}

float CalcularCorte(struct punto P1, struct punto P2)
{
	return (-CalcularPendiente(P1,P2) * P1.x + P1.y);
}

float Funcion(float x, struct punto P1, struct punto P2)
{
	return (CalcularPendiente(P1, P2) * x + CalcularCorte(P1, P2));
}
