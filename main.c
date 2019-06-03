/*Una empresa que se dedica a la reubicaci�n de empleados tiene una lista de 500
empleados (como m�ximo) con la siguiente informaci�n.
- Nombre y apellido. Con el formato "Apellidos, Nombres".
- Fecha de nacimiento del empleado.
- sexo (M, F)
- Nacionalidadnacionaliadeslidades pueden ser: Argentina, Uruguaya, Chilena, Peruana, Boliviana,
Paraguaya, Brasit_ea. Un empleado puede tener m�s de una nacionalidad.
Se pide armar las estructuras y el programa que permita:
A. Realizar la carga de datos. Validar todos los datos ingresados.
B- Mostrar un listado teepersonasvtaeidas antes de 2000 ordenado por Fecha de
nacimiento. Mostrar todos los datos de cada empleado.
C- Ingresar un Apellido por teclado y listar todas las mujeres que se apellidan igual y
adem�s nacieron en verano. Mostrar todos los datos de cada empleado.
D- Emitir un informe de empleados uruguayos y argentinos que tengan m�s de una
nacionalidad. Mostrar todos los datos de cada empleado.
E- Indicar el porcentaje de empleados argentinos*/
#include <stdio.h>
#include <string.h>
#include "funciones_PuntoA.h"
#define max_nacionalidades 7
#define max_empleados 500
#define max_string 30

typedef char ts_nacionalidad[12]; 
typedef ts_nacionalidad v_nacionalidades[max_nacionalidades];

//Defino un struct de nacinalidades para poder manejar el maximo logico en cada empleado
typedef struct 
{
	v_nacionalidades nacionalidades;
	int ml_nacionalidades;
} t_nacionalidades;

typedef char t_vector[9];
typedef char t_cadena[max_string];

//Defino un registro de fecha para hacer un manejo mejor de los datos
typedef struct 
{
	int dia;
	int mes;
	int anio;	
} t_fecha;

//Defino el registro que contentra los datos del empleado
typedef struct 
{
	t_cadena nombre;
	t_cadena apellido;
	t_fecha fecha_de_nacimiento;
	char sexo;
	t_nacionalidades nacionalidades;	
} t_empleado;

//Defino el array de Empleados 
typedef t_empleado vt_empleados[max_empleados];

//Valido la fecha de nacimiento, FALTA VALIDAR SI SE INGRESA UN CARACTER EN VEZ DE NUMERO
int validar_fecha(t_fecha fecha)
{
	int fecha_correcta;
	fecha_correcta = 0;
	if(fecha.mes >=1 && fecha.mes <= 12)
	{
		switch(fecha.mes)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(fecha.dia >= 1 && fecha.dia <= 31)
			{
				fecha_correcta = 1;
			}; 
			break;
			case 4: case 6: case 9: case 11: 
			if(fecha.dia >= 1 && fecha.dia <= 30)
			{
				fecha_correcta = 1;
			};
			break;
			case 2 :  
			if( (fecha.anio % 4 == 0)  &&  (fecha.anio % 100 != 0)  ||  (fecha.anio % 400 == 0) || ( fecha.dia >= 1 && fecha.dia <= 29 ) || (fecha.dia >=1 && fecha.dia <= 28))
			{		
				fecha_correcta = 1;
			};break;
		}
	}	
	return fecha_correcta;
};

int validar_genero(char genero)
{
	int es_valido;
	es_valido = 0;
	if((genero == 'F' ) || (genero  =='f')  || (genero == 'M')  || (genero == 'm') ) //Puede ser con strcmp o strchr
	{
		es_valido = 1;
	}
	return es_valido;
};

int validar_nacionalidades(ts_nacionalidad nacionalidad)
{
	int es_valida, result;
	es_valida = 0;
	if((strcmp(nacionalidad, "argentina\n") == 0) || (strcmp(nacionalidad, "Argentina\n") == 0) || (strcmp(nacionalidad, "uruguaya\n") == 0) || (strcmp(nacionalidad, "Uruguaya\n") == 0) || (strcmp(nacionalidad, "chilena\n") == 0) || (strcmp(nacionalidad, "Chilena\n") == 0) || (strcmp(nacionalidad, "peruana\n") == 0) ||(strcmp(nacionalidad, "Peruana\n") == 0) || (strcmp(nacionalidad, "boliviana\n") == 0) || (strcmp(nacionalidad, "Boliviana\n") == 0) || (strcmp(nacionalidad, "brasileña\n") == 0) || (strcmp(nacionalidad, "Brasilenia\n") == 0) || (strcmp(nacionalidad, "brasilenia\n") == 0) || (strcmp(nacionalidad, "Brasile�a\n") == 0) )
	{
		es_valida = 1;
	}
	
	return es_valida;
};

void cargar_nacionalidades(t_nacionalidades nacionalidades)
{
	int i, continuar, es_correcta;
	i = 0;
	continuar = 0;
	nacionalidades.ml_nacionalidades = 0;
	do
	{
		printf("Ingrese la/s nacionalidades:\n");
		fgets(nacionalidades.nacionalidades[i], 12, stdin);
		es_correcta = validar_nacionalidades(nacionalidades.nacionalidades[i]);
		if(es_correcta == 0)
		{
			printf("No existe esa nacionalidad\n");
		}
		else
		{
			nacionalidades.ml_nacionalidades ++;
			printf("Desea continuar cargando nacionalidades? 0 PARA CONTINUAR,\n 1 PARA FINALIZAR: \n");//Mejorar con el SI y el NO
			scanf("%i", &continuar);
			fflush(stdin);
		}
		i++;
	}
	while((nacionalidades.ml_nacionalidades > 5) || continuar != 1 || es_correcta != 1);
	
};

int validar_string(char caracter)
{
	t_vector numeros = {'1','2','3','4','5','6','7','8','9'};
	int i, incorrecto;
	incorrecto = 0;
	i= 0;
	
	for(i = 0; i <= 8; i++)
	{
		if(caracter == numeros[i])
		{
			incorrecto = 1;
			printf("%i", incorrecto);
		}
	}
	return incorrecto;
};
void cargar_nombre_empleado(t_cadena nombre, t_cadena apellido)
{
	int j, nombre_incorrecto, apellido_incorrecto, largo;
	do
	{
		printf("Ingrese el apellido:\n");
		fgets(apellido, 30, stdin);
		apellido_incorrecto = 0;
		j = 0;
		while( (apellido_incorrecto != 1)  &&  (j < strlen(apellido)) )	
		{
			apellido_incorrecto = validar_string(apellido[j]);
			j++;
		} 
		if ( apellido_incorrecto == 1 )
		{
			printf("Ingreso mal el apellido. Solo se permiten letras: %s\n", apellido);
		}
	} while(apellido_incorrecto != 0);
	do
	{
		printf("Ingrese el nombre:\n");
		fgets(nombre, 30, stdin);

		nombre_incorrecto = 0;
		j = 0;
		while(  (nombre_incorrecto != 1)  &&  (j < strlen(nombre)) )	
		{
			nombre_incorrecto = validar_string(nombre[j]);
			j++;
		} 
		if (nombre_incorrecto == 1 )
		{
			printf("Ingreso mal el nombre. Solo se permiten letras: %s\n", nombre);
		}
	}
	while(nombre_incorrecto != 0 );
};

void cargar_fecha_nacimiento(t_fecha fecha_nacimiento)
{
	int es_correcta;
	do
	{
		printf("Ingrese la fecha de nacimiento:\n");
		printf("Dia: ");
		scanf("%i",&fecha_nacimiento.dia);
		fflush(stdin);
		printf("mes: ");
		scanf("%i",&fecha_nacimiento.mes);
		fflush(stdin);
		printf("Año: ");
		scanf("%i",&fecha_nacimiento.anio);
		fflush(stdin);
		es_correcta = validar_fecha(fecha_nacimiento);
		if(es_correcta == 0)
		{
			printf("Ingreso mal la fecha %i/%i/%i\n",fecha_nacimiento.dia, fecha_nacimiento.mes, fecha_nacimiento.anio);
		}
	}
	while(es_correcta != 1);
};

void cargar_genero(char genero)
{
	int es_correcta;
	do
	{
		printf("Ingrese el sexo:\n");
		scanf(" %c",&genero);
		fflush(stdin);
		es_correcta = validar_genero(genero);
		if(es_correcta== 0)
		{
			printf("Ingreso mal el sexo, (F)emenino, (M)asculino");
		}
	}
	while(es_correcta != 1);
}

void cargar_empleado(vt_empleados empleados, int *ml)
{
	int continuar, i, ml_nacionalidad;
	continuar = 0;
	i = 0;
	printf("Ingrese los datos de los empleados:\n");
	do 
	{
		cargar_nombre_empleado(empleados[i].nombre, empleados[i].apellido);
		cargar_fecha_nacimiento(empleados[i].fecha_de_nacimiento);	
		cargar_genero(empleados[i].sexo);
		cargar_nacionalidades(empleados[i].nacionalidades);
		*ml ++;
		printf("Desea continuar cargando empleados? \n 0 PARA CONTINUAR, 1 PARA FINALIZAR: \n"); //Mejorar con el SI y el NO
		scanf("%i", &continuar);
		fflush(stdin);
		i++;
	}while(*ml > max_empleados || continuar != 1);	 	
}
void main() 
{
	vt_empleados empleados;
	int ml;
	cargar_empleado(empleados, &ml);
}
