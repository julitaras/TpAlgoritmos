/*Una empresa que se dedica a la reubicaci�n de empleados tiene una lista de 500
empleados (como m�ximo) con la siguiente informaci�n.
- Nombre y apellido. Con el formato "Apellidos, Nombres".
- Fecha de nacimiento del empleado.
- Sexo (M, F)
- Nacionalidad
Las nacionalidades pueden ser: Argentina, Uruguaya, Chilena, Peruana, Boliviana,
Paraguaya, Brasile�a. Un empleado puede tener m�s de una nacionalidad.
Se pide armar las estructuras y el programa que permita:
A. Realizar la carga de datos. Validar todos los datos ingresados.
B- Mostrar un listado de personas nacidas antes de 2000 ordenado por Fecha de
nacimiento. Mostrar todos los datos de cada empleado.
C- Ingresar un Apellido por teclado y listar todas las mujeres que se apellidan igual y
adem�s nacieron en verano. Mostrar todos los datos de cada empleado.
D- Emitir un informe de empleados uruguayos y argentinos que tengan m�s de una
nacionalidad. Mostrar todos los datos de cada empleado.
E- Indicar el porcentaje de empleados argentinos*/
#include <stdio.h>
#include <string.h>
#include "funciones_PuntoA.h"
#define Max_Nacionalidades 7
#define Max_Empleado 500
#define Max_Cadena_Nacionalidad 12 
#define Maximo_String 60

typedef char T_Nacionalidad[12]; 
typedef T_Nacionalidad V_Nacionalidades[Max_Nacionalidades];
typedef char Vector[9];
typedef char Cadena[Maximo_String];
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
	Cadena Apellido_Nombre;//Apellido, Nombre
	T_Fecha Fecha_De_Nacimiento;
	char Sexo;
	V_Nacionalidades Nacionalidad;//?		
} T_Empleado;

//Defino el array de Empleados 
typedef T_Empleado VT_Empleados[Max_Empleado];

//Valido la fecha de nacimiento, FALTA VALIDAR SI SE INGRESA UN CARACTER EN VEZ DE NUMERO
int ValidarFecha(T_Fecha Fecha)
{
	int FechaCorrecta;
	FechaCorrecta = 0;
	if(Fecha.Mes >=1 && Fecha.Mes <= 12)
	{
		switch(Fecha.Mes)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(Fecha.Dia >= 1 && Fecha.Dia <= 31)
			{
				FechaCorrecta = 1;
			}; break;
			case 4: case 6: case 9: case 11: 
			if( Fecha.Dia >= 1 && Fecha.Dia <= 30)
			{
				FechaCorrecta = 1;
			};break;
			case 2 :  
			if( (Fecha.Anio % 4 == 0)   &&   (Fecha.Anio % 100 != 0)   ||   (Fecha.Anio % 400 == 0) )
			{
				if( Fecha.Dia >= 1 && Fecha.Dia <= 29 ) 
				{
					FechaCorrecta = 1;
				}
				else 
				{
					if(Fecha.Dia >=1 && Fecha.Dia <= 28)
					{
						FechaCorrecta = 1;
					}
				}
			}break;
		}
	}	
	return FechaCorrecta;
};
int Validar_Nombre(Cadena Nombre_Completo_Empleado)
{
	const Vector Numeros = {'1','2','3','4','5','6','7','8','9'};
	int i, Correcto;
	Correcto = 0;
	//burcar en nombre algun signo especial o numero
	for(i = 0; i < 8; i++)
	{
		if(strstr(Nombre_Completo_Empleado, Numeros[i]) == NULL)
		{
			Correcto = 1;
		}
	}
	return Correcto;
};

int Validar_Sexo(char Genero)
{
	int Es_Valido;
	Es_Valido = 0;
	if((Genero == 'F' ) || (Genero  =='f')  || (Genero == 'M')  || (Genero == 'm') ) //Puede ser con strcmp o strchr
	{
		Es_Valido = 1;
	}
	return Es_Valido;
};

int Validad_Nacionalidad(T_Nacionalidad Nacionalidad)
{
	int Es_Valida;
	Es_Valida = 0;
	//Agarro el vector lo recorro y comparo si en esa pocisicion es igual a una de las opciones 
		//if(Nacionalidad == "Argentina" || Nacionalidad== "Uruguaya" || Nacionalidad == "Chilena" || Nacionalidad == "Peruana"||Nacionalidad == "Boliviana" || Nacionalidad== "Brasile�a" )
	if((strcmp(Nacionalidad, "Argentina") == 0) || (strcmp(Nacionalidad, "Uruguaya") == 0) || (strcmp(Nacionalidad, "Chilena") == 0) || (strcmp(Nacionalidad, "Peruana") == 0) || (strcmp(Nacionalidad, "Boliviana") == 0) ||(strcmp(Nacionalidad, "Brasile�a") == 0) )
	{
		Es_Valida = 1;
	}
	
	return Es_Valida;
};

void Cargar_Nacionalidades(V_Nacionalidades Nacionalidades, int *ml_Nacionalidad)
{
	int i, Continuar, EsCorrecta;
	i = 0;
	Continuar = 0;
	do
	{
		printf("Ingrese la/s nacionalidades:\n");
		fgets(Nacionalidades[i], 12, stdin);
		EsCorrecta = Validad_Nacionalidad(Nacionalidades[i]);
		if(EsCorrecta == 0)
		{
			printf("No existe esa nacionalidad\n");
		}
		else
		{
			printf("Desea continuar cargando nacionalidades? 0 PARA CONTINUAR,\n 1 PARA FINALIZAR: \n");//Mejorar con el SI y el NO
			scanf("%i", &Continuar);
			fflush(stdin);
		}
		i++;
	}
	while((*ml_Nacionalidad > 5) || Continuar != 1 || EsCorrecta != 1);
	
}
//Cargo los datos del empleado, puedo modulareizarlo mas haciendo diferentes funciones que cargue diferentes daos pq se hace muy largo 
void Cargar_Empleado(VT_Empleados Empleados, int *ml)
{
	int Continuar, i, EsCorrecta, ml_Nacionalidad;
	Continuar = 0;
	i = 0;

	printf("Ingrese los datos de los empleados:\n");
	do 
	{
		do
		{
			//Cargar_Nombre_Completo_Empleado();
			printf("Ingrese el Apellido y Nombre:\n");
			fgets(Empleados[i].Apellido_Nombre, 60, stdin);
			EsCorrecta = Validar_Nombre(Empleados[i].Apellido_Nombre); 
			if (EsCorrecta == 0)
			{
				printf("Hubo algun error");
			}
		}
		while(EsCorrecta != 1);
		//Cargar_Fecha_Nacimiento();
		do
		{
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
			EsCorrecta = ValidarFecha(Empleados[i].Fecha_De_Nacimiento);
			if(EsCorrecta == 0)
			{
			 printf("Ingreso mal la fecha %i/%i/%i\n",Empleados[i].Fecha_De_Nacimiento.Dia, Empleados[i].Fecha_De_Nacimiento.Mes, Empleados[i].Fecha_De_Nacimiento.Anio);
			}
		}
		while(EsCorrecta != 1);
		//Cargar_Genero();
		do{
		printf("Ingrese el Sexo:\n");
		scanf(" %c",&Empleados[i].Sexo);
		fflush(stdin);
		EsCorrecta = Validar_Sexo(Empleados[i].Sexo);
		if(EsCorrecta == 0)
		{
			 printf("Ingreso mal el genero, F o G");
		}
		}while(EsCorrecta != 1);
		Cargar_Nacionalidades(Empleados[i].Nacionalidad, &ml_Nacionalidad);
		
		printf("Desea continuar cargando empleados? 0 PARA CONTINUAR,\n 1 PARA FINALIZAR: \n"); //Mejorar con el SI y el NO
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
