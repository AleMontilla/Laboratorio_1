/* Primer Punto */
/* Se incluye la libreria de funciones matematicas para el ejercicio */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>  // estas son las unicas librerias permitidas para el desarrollo del ejercicio

#define macro 30
#define tam 5  //como una de las buenas prácticas lo sugiere, se definen constantes para los tamaños de los arreglos


void ingrdata();
void hamaxmin();
double desestand();
void mosmenu();
void convt();
float prom(); //acá se realiza el prototipado de las funciones 

void main()
{
	mosmenu();
}

/* Definicion de la funcion que pinta el menu y ejerce el control del resto de las funciones segun la seleccion*/

void mosmenu()
{

/* Se inicializan las variables para control y calculos*/

	short int Selc = 0;
	short int Control = 0 ;

	int Max=0; 
	int Min=0;

	int VALORES[tam];

	short int  END = 1;

	char DATA[macro];


        do{
		//este es el menú que sera presentado al usuario
		Selc = 0;
		printf(" Acontinuacion se le enseñara el Menu de la aplicacion\n ");
		printf(" -----------------------------------------------------------------------------------------\n ");
		printf(" -----------------------------------------------------------------------------------------\n ");
       	        printf(" 1. Ingresar Datos\n ");
		printf(" 2. Mostrar Promedio\n ");
		printf(" 3. Mostrar Desviacion Estandar\n ");
		printf(" 4. Mostrar Valores Maximos y Minimos\n ");
		printf(" 5. Mostrar Toda La Informacion\n " );
		printf(" 6. Salir de la aplicacion\n ");
		printf(" -----------------------------------------------------------------------------------------\n ");
                printf(" -----------------------------------------------------------------------------------------\n ");
		printf(" Seleccion: ");
		scanf("%hd", &Selc); 

/*Se usa el switch para seleccionar los casos de seleccion del menu por parte del usuario*/

		switch( Selc ){
				
			//a partir de acá es el sistema de detección y acción, que actua basado en  la elección del usuario
			case 1:
				{
					for (int i = 0; i<tam ; i++)
					{
						VALORES[i] = 0;
					}

					for (int i = 0; i<macro ; i++)
					{
						DATA[i] = 0;
					}

					printf(" HA SELECCIONADO LA OPCION 1.\n\n");
	
					printf("Usuario; porfavor escriba su numero entero entre punto y coma;cantidad maxima de valores igual a [%d] \n\n",tam);
					printf("Escriba sus valores: ");
					scanf(" %s",DATA);

	                                Control = 1;
	
					convt(DATA,VALORES);

		
					break;
				}
			case 2:
				printf(" HA SELECCIONADO LA OPCION 2.\n\n");
			        if ( Control == 1  )
				{
					printf("El promedio de los valores ingresados es: %.3f",prom(VALORES));
	
				}	
				else
				{
					printf("Aun no ha ingresado valores\n\n");
				}
	
				break;
			case 3:
				printf(" HA SELECCIONADO LA OPCION 3.\n\n");
			  	if ( Control == 1 )
	                        {
	                                printf("La desviación estándar de los valores ingresados es: %.3lf",desestand(VALORES));
	
	                        }
	                        else
	                        {
        	                        printf("Aun no ha ingresado valores\n\n");
                	        }
	
				break;
			case 4:
				printf(" HA SELECCIONADO LA OPCION 4.\n\n");
				if ( Control == 1 )
	       	                {
					hamaxmin(VALORES,&Max,&Min);
	                                printf("Los valores Max y Min son.... Min: %d y Max: %d \n\n ",Min,Max);
	
	                        }
	                        else
	                        {
	                                printf("Aun no ha ingresado valores\n\n");
	                        }

				break;
			case 5:
				printf(" HA SELECCIONADO LA OPCION 5.\n\n");
				if ( Control == 1 )
       		                {
					hamaxmin(VALORES,&Max,&Min);
	                                printf("Los valores Max y Min son.... Min: %d y Max: %d\n ",Min,Max);
					printf("La desviación estándar de los valores ingresados es: %.3f\n",desestand(VALORES));
	       	                        printf("El promedio de los valores ingresados es: %.3f\n",prom(VALORES));
	                        }
	                        else
	                        {
	                                printf("Aun no ha ingresado valores\n\n");
	                        }
	
				break;
			case 6:
				printf(" HA SELECCIONADO LA OPCION 6.\n\n");
				printf("SALIENDO DEL PROGRAMA\n");
				printf(".\n");
				printf(".\n");
				printf(".\n");

				END = 0;
	
				break;
		}

	}while(END!=0);
}

/* Funcion encargada de organizar/transformar los valores del estring a un vector de enteros*/
void convt(char data[macro],int *valores)
{

	char *secc = strtok(data,";"); //se usa strtok, esta funcion separa un string en varios strings comprendidos entre un identificador 

	for(int i=0; secc!= NULL && i<tam ; i++)
	{
		if ( secc == NULL && i<tam ) // por si el tamaño de datos ingresados es menor al tamaño previsto para el vector 
		{
			valores[i] = 0;
		}
		else
		{
			valores[i] = atoi(secc); //se convierten los datos de cada string hecho con secc en un numero operable 
               	        secc = strtok(NULL,";");
		}

	}
}

/* Funcion que calcula el promedio de los valores ingresados*/
float prom(int valores[tam])
{
	float Promedio = 0.0;

	for(int i=0; i < tam ; i++)
	{
		Promedio += valores[i];	//se suman todos los valores contenido en el vector que se creó en la función convt
	}
	Promedio = Promedio / tam ;

	return Promedio;
}

/* Funcion que calcula la desviacion estandar de los valores ingresados*/
double desestand (int valores[tam])
{
	double Radicando = 0;
	float Promedio = prom(valores);

	for ( int i = 0; i < tam ; i++ )
	{
		Radicando += (valores[i]-Promedio)*(valores[i]-Promedio);
	}

	Radicando = Radicando/(tam-1); //se divide sobre n-1 por el concepto de muestra sesgada 
        double Raiz = sqrt(Radicando);

	return Raiz; //retorna la dirección del valor numérico para que pueda ser impreso

}

/* Funcion que reorganiza el vector de valores de menor a mayor y extrae las cantidades minimas y maximas */
void hamaxmin(int valores[tam],int *max,int *min)
{
	int Reserva = 0;

	for(int i = 0; i < tam-1 ; i++ ) // este es un ciclo de reorganizamiento de números 
	{
		for(int j = 1+i; j < tam; j++)
		{
			if(valores[i]>valores[j])
			{
				Reserva = valores[i];
				valores[i] = valores[j];
				valores[j] = Reserva;
			}
		}
	}
        
	*min = valores[0]; //dirección donde quedó el dato más pequeño 
	*max = valores[4]; //dirección donde quedó el dato mayor


}


