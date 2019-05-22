/*Una empresa que se dedica a la reubicación de empleados tiene una lista de 500
empleados (como máximo) con la siguiente información.
- Nombre y apellido. Con el formato "Apellidos, Nombres".
- Fecha de nacimiento del empleado.
- Sexo (M, F)
- Nacionalidad
Las nacionalidades pueden ser: Argentina, Uruguaya, Chilena, Peruana, Boliviana,
Paraguaya, Brasileña. Un empleado puede tener más de una nacionalidad.
Se pide armar las estructuras y el programa que permita:
A. Realizar la carga de datos. Validar todos los datos ingresados.
B- Mostrar un listado de personas nacidas antes de 2000 ordenado por Fecha de
nacimiento. Mostrar todos los datos de cada empleado.
C- Ingresar un Apellido por teclado y listar todas las mujeres que se apellidan igual y
además nacieron en verano. Mostrar todos los datos de cada empleado.
D- Emitir un informe de empleados uruguayos y argentinos que tengan más de una
nacionalidad. Mostrar todos los datos de cada empleado.
E- Indicar el porcentaje de empleados argentinos*/
#include <stdio.h>
#include <string.h>
#include "funciones_PuntoA.h"
#define Max_Nacionalidades 7
#define Max_Empleado 500
#define Max_Cadena_Nacionalidad 12 

//Defino una matriz para las nacionalidades
//typedef  char M_Nacionalidades[Max_Cadena_Nacionalidad][Max_Nacionalidades];

 typedef char T_Nacionalidad[12]; 
 typedef T_Nacionalidad V_Nacionalidad[Max_Nacionalidades];

//Defino un registro de fecha para hacer un manejo mejor de los datos
typedef struct 
{
	int Dia;
	int Mes;
	int Anio;	
} T_Fecha;

//Defino el registro que contentra los datos del empleado
typedef struct 
{
	char Apellido_Nombre[60];//Apellido, Nombre
	T_Fecha Fecha_De_Nacimiento;
	char Sexo;
	V_Nacionalidad Nacionalidad;//?		
}T_Empleado;

typedef T_Empleado VT_Empleados[Max_Empleado];


//Puede ser un solo Cargar datos que obtenga un mensaje, y el dato, ya que sino seria muy repetitiva
void Cargar_Empleado(VT_Empleados Empleados, int *ml)
{
	int Continuar, i/*, ml_Nacionalidad*/;
	Continuar = 0;
	i = 0;
	printf("Ingrese los datos de los empleados:\n");
	do 
	{
		printf("Ingrese el Apellido y Nombre:\n");
		fgets(Empleados[i].Apellido_Nombre, 60, stdin);
		
		printf("Ingrese la fecha de nacimiento:\n");
		printf("Dia: ");
		scanf("%i",&Empleados[i].Fecha_De_Nacimiento.Dia);
		fflush(stdin);
		printf("Mes: ");
		scanf("%i",&Empleados[i].Fecha_De_Nacimiento.Mes);
		fflush(stdin);
		printf("Año: ");
		scanf("%i",&Empleados[i].Fecha_De_Nacimiento.Anio);
		fflush(stdin);
		
		printf("Ingrese el Sexo:\n");
		scanf(" %c",&Empleados[i].Sexo);
		fflush(stdin);
		
		//Cargar_Nacionalidades(Empleados[i].Nacionalidad, &ml_Nacionalidad);
		do{
		
		printf("Ingrese la/s nacionalidades:\n");
		fgets(Empleados[i].Nacionalidad[i], 12, stdin);
		printf("Desea continuar cargando nacionalidades? 0 PARA CONTINUAR,\n 1 PARA FINALIZAR: \n");
		scanf("%i", &Continuar);
		fflush(stdin);
		}while(Continuar != 1);
		printf("Desea continuar cargando empleados? 0 PARA CONTINUAR,\n 1 PARA FINALIZAR: \n");
		scanf("%i", &Continuar);
		fflush(stdin);
		i++;
	}
	while(*ml > Max_Empleado || Continuar != 1);	 	
};
void main() 
{
	VT_Empleados Empleados;
	int ml;
	 
	Cargar_Empleado(Empleados, &ml);
	
}
