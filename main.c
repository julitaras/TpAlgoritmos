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
#Define Max_Nacionalidades 7
#Define Max_Empleado 500
//Defino un array o un enum con las nacionalidades 
//typedef enum {Argentina, Uruguaya, Chilena, Peruana, Boliviana, Paraguaya, Brasile�a} T_Nacionalidades;
typedef V_Nacionalidades[Max_Nacionalidades]
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
	V_Nacionalidades Nacionalidad;//?		
}T_Empleado;

typedef VT_Empleado[Max_Empleado];

void main() {
	
}
