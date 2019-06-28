///////////////////////////////////////////
///Ultima actualizacion→ ya funciona/////
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
#include <ctype.h>
#define max_nacionalidades 7
#define max_empleados 500
#define max_string 30
#define NO "1\n"
typedef char nombre_nacionalidad[max_string]; 
typedef nombre_nacionalidad vec_nacionalidades[max_nacionalidades];

//Defino un struct de nacinalidades para poder manejar el maximo logico en cada empleado
typedef struct{
	vec_nacionalidades nacionalidades;
	int ml_nacionalidades;
} t_nacionalidades;

typedef char t_vector[26];
typedef char t_cadena[max_string];

//Defino un registro de fecha para hacer un manejo mejor de los datos
typedef struct{
	int dia;
	int mes;
	int anio;
} t_fecha;

//Defino el registro que contentra los datos del empleado
typedef struct{
	t_cadena nombre;
	t_cadena apellido;
	t_fecha fecha_nacimiento;
    char sexo;
	t_nacionalidades nacionalidades;	
} t_empleado;

//Defino el array de Empleados 
typedef t_empleado vt_empleados[max_empleados];

//Valido la fecha de nacimiento
int validar_fecha(t_fecha fecha){
	int fecha_correcta;
	fecha_correcta = 0;
	if( (fecha.mes >=1) && (fecha.mes <= 12) ){
		switch(fecha.mes){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(fecha.dia >= 1 && fecha.dia <= 31){
				fecha_correcta = 1;
			}; 
			break;
			case 4: case 6: case 9: case 11: 
			if(fecha.dia >= 1 && fecha.dia <= 30){
				fecha_correcta = 1;
			};
			break;
			case 2 :  
			if( (fecha.anio % 4 == 0)  &&  (fecha.anio % 100 != 0)  ||  (fecha.anio % 400 == 0) || ( fecha.dia >= 1 && fecha.dia <= 29 ) || (fecha.dia >=1 && fecha.dia <= 28)){		
				fecha_correcta = 1;
			};break;
		}
	}
	return fecha_correcta;
};

//Validación del género por caracter
int validar_genero(char genero){
	int es_valido;
	es_valido = 0;
	if((genero == 'F' ) || (genero  =='f')  || (genero == 'M')  || (genero == 'm') ){
		es_valido = 1;
	}
	return es_valido;
};

//Validación de la nacionalidad por mínusculas o mayúsculas
int validar_nacionalidades(nombre_nacionalidad nacionalidad){
	int es_valida, result, i;
	es_valida = 0;
	vec_nacionalidades const_nacionalidades = {"argentina\n", "uruguaya\n", "chilena\n", "peruana\n", "boliviana\n", "brasileña\n", "paraguaya\n"};
	for(i = 0; i <= 7; i++)
	{
		if((strcmp(nacionalidad, const_nacionalidades[i]) == 0) || (strcmp(nacionalidad, strupr(const_nacionalidades[i])) == 0) )
		{
			es_valida = 1;
		}
	}
	return es_valida;
};

//Módulo de carga de nacionalidades
void cargar_nacionalidades(t_nacionalidades *nacionalidades){
    int i = 0, es_correcta;
    nacionalidades->ml_nacionalidades = 0;
    printf("\t\t\t\tIngrese la/s nacionalidades. Presione (1) para SALIR de la carga de nacionalidades\n");
	printf("\t\t\t\t\t\t- ");
    fgets(nacionalidades->nacionalidades[i], 30, stdin); 
    while(strcmp(NO, nacionalidades->nacionalidades[i]) != 0){
        es_correcta = validar_nacionalidades(nacionalidades->nacionalidades[i]);
        if(es_correcta == 0){
            printf("\t\t\t\t ¡ERROR! No existe esa nacionalidad.\n");
    	}
        else{
            printf("\n\t\t\t\t¡CARGA REALIZADA CON ÉXITO!\n");
            nacionalidades->ml_nacionalidades ++;
            fflush(stdin);
    	}
        i++;
		printf("\t\t\t\t\t\t- ");
        fgets(nacionalidades->nacionalidades[i], 30, stdin);
	}	
}

//
int validar_string(char caracter)
{
	int incorrecto;
	incorrecto = 0;
	if(isdigit(caracter) != 0)
	{
		incorrecto = 1;
	}
	return incorrecto;
};

//Módulo de carga de nombre
void cargar_nombre(t_cadena nombre ){
	int j, nombre_incorrecto, largo;
	do{
		printf("\t\t\t\tIngrese el nombre.\n");
		printf("\t\t\t\t\t\t- ");
		fgets(nombre, 30, stdin);

		nombre_incorrecto = 0;
		j = 0;
		while((nombre_incorrecto != 1)  &&  (j < strlen(nombre))){
			nombre_incorrecto = validar_string(nombre[j]);
			j++;
		} 
		if (nombre_incorrecto == 1 ){
			printf("\t\t\t\tIngreso mal el nombre. Solo se permiten letras: %s\n", nombre);
		}
	}
	while(nombre_incorrecto != 0 );
};

//Módulo de carga de aoellido
void cargar_apellido(t_cadena apellido){
	int j, apellido_incorrecto, largo;
	do{
		printf("\t\t\t\tIngrese el apellido.\n");
		printf("\t\t\t\t\t\t- ");
		fgets(apellido, 30, stdin);
		apellido_incorrecto = 0;
		j = 0;
		while((apellido_incorrecto != 1)  &&  (j < strlen(apellido))){
			apellido_incorrecto = validar_string(apellido[j]);
			j++;
		} 
		if ( apellido_incorrecto == 1 ){
			printf("\t\t\t\tIngreso mal el apellido. Solo se permiten letras: %s\n", apellido);
		}
	} while(apellido_incorrecto != 0);
};

//Módulo de carga de fecha de nacimiento, formato: ddmmaa
void cargar_fecha_nacimiento(t_fecha *fecha_nacimiento){
	int es_correcta;
	do{
		printf("\t\t\t\tIngrese la fecha de nacimiento.\n");
		printf("\t\t\t\t\t\tDia: \n");
		printf("\t\t\t\t\t\t- ");
		scanf("%i",&fecha_nacimiento->dia);
		fflush(stdin);
		printf("\t\t\t\t\t\tMes: \n");
		printf("\t\t\t\t\t\t- ");
		scanf("%i",&fecha_nacimiento->mes);
		fflush(stdin);
		printf("\t\t\t\t\t\tAnio: \n");
		printf("\t\t\t\t\t\t- ");
		scanf("%i",&fecha_nacimiento->anio);
		fflush(stdin);
		es_correcta = validar_fecha(*fecha_nacimiento);
		if(es_correcta == 0){
			printf("\t\t\t\tIngreso mal la fecha %i/%i/%i\n",fecha_nacimiento->dia, fecha_nacimiento->mes, fecha_nacimiento->anio);
		}
	}
	while(es_correcta != 1);
};

//Módulo de carga de género por caracter
void cargar_genero(char *genero){
	int es_correcta;
	do{
		printf("\t\t\t\t\t\tIngrese el sexo.\n");
		printf("\t\t\t\t\t\t- ");
		scanf(" %c",genero);
		fflush(stdin);
		es_correcta = validar_genero(*genero);
		if(es_correcta== 0){
			printf("\t\t\t\tIngreso mal el sexo, (F)emenino, (M)asculino.");
		}
	}
	while(es_correcta != 1);
}

//Módulo de carga de los datos del empleado
void cargar_empleado(vt_empleados empleados, int *ml){
	int continuar, i, ml_nacionalidad;
	continuar = 0;
	i = 0;
	printf("\t\tIngrese los datos de los empleados:\n");
	do{
		cargar_apellido(empleados[i].apellido);
		cargar_nombre(empleados[i].nombre);
		cargar_fecha_nacimiento(&empleados[i].fecha_nacimiento);	
		cargar_genero(&empleados[i].sexo);
		cargar_nacionalidades(&empleados[i].nacionalidades);
		*ml = *ml + 1;
		printf("\t\t\t\t¿Desea continuar cargando empleados? (0)Si o (1)No.\n"); 
		printf("\t\t\t\t\t\t- ");
		scanf("%i", &continuar);
		fflush(stdin);
		i++;
	}
	while(*ml > max_empleados || continuar != 1);	 	
};

//Intercambia el contenido entre las posiciones
void intercambiar(vt_empleados empleado, t_empleado aux, int j){
    aux = empleado[j];
    empleado[j] = empleado[j+1];
    empleado[j+1] = aux;
}

//Ordena de manera ascendente por año, mes y día
void ordenar(vt_empleados empleado, int ml){
    int i, j;
    t_empleado aux;
    for (i=1; i < ml; i++){
        for(j=0 ; j < ml - i; j++){
            int fecha1 = (empleado[j].fecha_nacimiento.anio * 1000) + (empleado[j].fecha_nacimiento.mes * 100) + (empleado[j].fecha_nacimiento.dia);
            int fecha2 = (empleado[j+1].fecha_nacimiento.anio * 1000) + (empleado[j+1].fecha_nacimiento.mes * 100) + (empleado[j+1].fecha_nacimiento.dia);
            if (fecha1 > fecha2){
                intercambiar(empleado, aux, j);
}}}} 

//Busca linealmente al primer empleado nacido a partir del año 2000.      
int buscar(vt_empleados empleado, int ml){
    int i;
    for(i=0; i < ml;i++){
        if(empleado[i].fecha_nacimiento.anio >= 2000){
            return i;
        }
}}

//Muestra todos los datos de los empleados.      
void mostrar(vt_empleados empleado, int limite){
    int i, j;
    char cadena[100];
    for(i = 0; i < limite; i++){
        strcat(cadena, empleado[i].nombre);
        strcat(cadena, empleado[i].apellido);
		printf("%s", cadena);
        printf("\n\t\t\t\tEL EMPLEADO:\n %s", cadena);
        printf("\n\t\t\t\t\t\t Nació el: %i - %i - %i", empleado[i].fecha_nacimiento.dia,
                                            empleado[i].fecha_nacimiento.mes,
                                            empleado[i].fecha_nacimiento.anio);
        printf("\n\t\t\t\t\t\t Sexo: %c", empleado[i].sexo);
        printf("\n\t\t\t\t\t\t De nacionalidad(es): \n");
        for(j=0; j < empleado[i].nacionalidades.ml_nacionalidades; j++){
            printf("\t\t\t\t\t\t\t* %s.\n", empleado[i].nacionalidades.nacionalidades[j]);
		}
   	 	strcpy(cadena, "");
}}



//Se encarga de mostrar solamente a los empleados nacidos antes del año 2000.      
void mostrar_nacidos_antes_2000(vt_empleados empleado, int ml){
    int i, cortar_desde;
    vt_empleados menores_a_2000;
    for(i = 0; i < ml; i++){
        menores_a_2000[i] = empleado[i];
    }    
    ordenar(menores_a_2000, ml);
    cortar_desde = buscar(menores_a_2000, ml);
    mostrar(menores_a_2000, cortar_desde);
}


void doble_nacionalidad(vt_empleados empleados, int ml){
    int d, i, posicion_inicial = 0;
    vt_empleados empleados_arg_uru;
    for(i = 0; i < ml; i++){
        if(empleados[i].nacionalidades.ml_nacionalidades > 1){
			for(d = 0; d < empleados[i].nacionalidades.ml_nacionalidades; d++){
				if((strcmp(empleados[i].nacionalidades.nacionalidades[d],"Argentina\n") == 0) || (strcmp(empleados[i].nacionalidades.nacionalidades[d], "argentina\n") == 0) || (strcmp(empleados[i].nacionalidades.nacionalidades[d], "Uruguaya\n") == 0) || (strcmp(empleados[i].nacionalidades.nacionalidades[d], "uruguaya\n") == 0)){
					empleados_arg_uru[posicion_inicial] = empleados[i];
					posicion_inicial ++;
				}
			}
        }
    }
    mostrar(empleados_arg_uru, posicion_inicial);
}

int buscar_argentinos(vt_empleados empleados, int ml)
{
    int i, contador_argentinos, j;
    contador_argentinos = 0;
    for(i = 0; i < ml; i++){
        for(j = 0; j < empleados[i].nacionalidades.ml_nacionalidades; j ++){
            if( (strcmp(empleados[i].nacionalidades.nacionalidades[j], "argentina\n") == 0) || (strcmp(empleados[i].nacionalidades.nacionalidades[j], "Argentina\n") == 0 ) ){
                contador_argentinos ++;
            }
        }
    }
    return contador_argentinos;
}
void porcentaje_argentinos(vt_empleados empleados, int ml){
    int contador_argentinos, porcentaje;
    contador_argentinos = buscar_argentinos(empleados, ml);
    porcentaje = ((contador_argentinos * 100)/ml );
    printf("\t\t\t\tEl porcentaje de empleados argentinos es de: %i.\n", porcentaje);
}
void buscar_empleado_punto_c (vt_empleados empleados, int ml)
{
	int i, j, aux, posicion;
	t_cadena palabra;
	aux = 0;
    vt_empleados mujeres_verano;
	posicion = 0;	

	printf ("Ingresar apellido a buscar: \n");
	printf ("Solo se mostraran a las mujeres nacidas en verano\n");
	fgets (palabra, 30, stdin);
	
	for (i = 0; i < ml && aux == 0; i++)
    {
		j = strcmp (palabra, empleados[i].apellido);
		if (j == 0 && (empleados[i].sexo == 'f' || empleados[i].sexo == 'F') && ((empleados[i].fecha_nacimiento.mes == 12 && empleados[i].fecha_nacimiento.dia >= 21) || empleados[i].fecha_nacimiento.mes < 3 || (empleados[i].fecha_nacimiento.mes == 3 && empleados[i].fecha_nacimiento.dia < 21)))
		{
            mujeres_verano[posicion] = empleados[i];
            posicion ++;
            mostrar(mujeres_verano, posicion);
		}		
		 else 
		{
			printf ("\t\t\t\tNo se encontro empleado\n");
			aux = 1;
		}	
	}
}


void main(){
	vt_empleados empleados;
	int ml, opcion, continuar;
	cargar_empleado(empleados, &ml);
	do{ 
		printf ("\t\t\t\tElegir opcion a realizar:\n");
		printf ("\t\t\t\t(1) Punto B:\n");
		printf ("\t\t\t\t(2) Punto C:\n");
		printf ("\t\t\t\t(3) Punto D:\n");
		printf ("\t\t\t\t(4) Punto E:\n");
		printf("\t\t\t\t- ");
		scanf ("%i", &opcion);
		fflush (stdin);
		switch(opcion){
			case 1: mostrar_nacidos_antes_2000(empleados, ml);
					break;
			case 2: buscar_empleado_punto_c(empleados, ml);
					break;
			case 3: doble_nacionalidad(empleados, ml);
					break;
			case 4: porcentaje_argentinos(empleados, ml);
					 break;
		}
		printf ("\t\t\t\t ¿Desea realizar otra operacion? (0)Si o (1)No: \n");
		printf("\t\t\t\t\t\t- ");
		scanf ("%i", &continuar);
		fflush(stdin);
	}while( continuar != 1);
}
