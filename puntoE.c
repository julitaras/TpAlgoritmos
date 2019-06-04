#include <stdio.h>
#include <string.h>
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

typedef char t_vector[26];
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

int buscar_argentinos(vt_empleados empleados, int ml)
{
    int i, contador_argentinos;
    contador_argentinos = 0;
    for(i = 0; i < ml; i++)
    {
        for(j = 0; j < empleados[i].nacionalidades.ml_nacionalidades; j ++)
        {
            if(strcmp(empleados[i].nacionalidades.nacionalidades[i], "argentina") || strcmp(empleados[i].nacionalidades.nacionalidades[i], "Argentina") )
            {
                contador_argentinos ++;
            }
        }
    }
    return contador_argentinos;
}
void porcentaje_argentinos(vt_empleados empleados, int ml)
{
    int i, contador_argentinos, porcentaje;
    contador_argentinos = buscar_argentinos(empleados, ml);
    porcentaje = ((contador_argentinos / ml) * 100);
    printf("El porcentaje de empleados argentinos es de: %i ", porcentaje);
}