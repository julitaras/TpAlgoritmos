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

int validar_numero(int numero)
{
	t_vector letras = {'a', 'b', 'c', 'd', 'e' ,'f', 'g', 'h', 'i' ,'j','k', 'l', 'm', 'n' ,'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int i, incorrecto;
	incorrecto = 0;
	i= 0;
	
	for(i = 0; i <= 26; i++)
	{
		if(numero == letras[i])
		{
			incorrecto = 1;
			printf("%i", incorrecto);
		}
	}
	return incorrecto;
};
//Valido la fecha de nacimiento, FALTA VALIDAR SI SE INGRESA UN CARACTER EN VEZ DE NUMERO
int validar_fecha(t_fecha fecha)
{
	int fecha_correcta;
	fecha_correcta = 0;
	if( (validar_numero(fecha.dia) == 0) || (validar_numero(fecha.mes) == 0) || (validar_numero(fecha.anio) == 0) )
	{
		fecha_correcta = 1;
	}
	if( (fecha.mes >=1) && (fecha.mes <= 12) )
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
	if((strcmp(nacionalidad, "argentina\n") == 0) || (strcmp(nacionalidad, "Argentina\n") == 0) || (strcmp(nacionalidad, "uruguaya\n") == 0) || (strcmp(nacionalidad, "Uruguaya\n") == 0) || (strcmp(nacionalidad, "chilena\n") == 0) || (strcmp(nacionalidad, "Chilena\n") == 0) || (strcmp(nacionalidad, "peruana\n") == 0) ||(strcmp(nacionalidad, "Peruana\n") == 0) || (strcmp(nacionalidad, "boliviana\n") == 0) || (strcmp(nacionalidad, "Boliviana\n") == 0) || (strcmp(nacionalidad, "brasileña\n") == 0) || (strcmp(nacionalidad, "Brasilenia\n") == 0) || (strcmp(nacionalidad, "brasilenia\n") == 0) || (strcmp(nacionalidad, "Brasile�a\n") == 0) || (strcmp(nacionalidad, "paraguaya\n") == 0) || (strcmp(nacionalidad, "Paraguaya\n") == 0) )
	{
		es_valida = 1;
	}
	
	return es_valida;
};

void cargar_nacionalidades(t_nacionalidades *nacionalidades)
{
	int i, continuar, es_correcta;
	i = 0;
	continuar = 0;
	nacionalidades->ml_nacionalidades = 0;
	do
	{
		printf("Ingrese la/s nacionalidades:\n");
		fgets(nacionalidades->nacionalidades[i], 12, stdin);
		es_correcta = validar_nacionalidades(nacionalidades->nacionalidades[i]);
		if(es_correcta == 0)
		{
			printf("No existe esa nacionalidad\n");
		}
		else
		{
			nacionalidades->ml_nacionalidades ++;
			printf("Desea continuar cargando nacionalidades? (0)Si o (1)No: \n");//Mejorar con el SI y el NO
			scanf("%i", &continuar);
			fflush(stdin);
		}
		i++;
		
	}
	while((nacionalidades->ml_nacionalidades > 5) || continuar != 1 || es_correcta != 1);
	
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
void cargar_nombre(t_cadena nombre )
{
	int j, nombre_incorrecto, largo;
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

void cargar_apellido(t_cadena apellido)
{
	int j, apellido_incorrecto, largo;
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
};

void cargar_fecha_nacimiento(t_fecha *fecha_nacimiento)
{
	int es_correcta;
	do
	{
		printf("Ingrese la fecha de nacimiento:\n");
		printf("Dia: ");
		scanf("%i",&fecha_nacimiento->dia);
		fflush(stdin);
		printf("mes: ");
		scanf("%i",&fecha_nacimiento->mes);
		fflush(stdin);
		printf("Año: ");
		scanf("%i",&fecha_nacimiento->anio);
		fflush(stdin);
		es_correcta = validar_fecha(*fecha_nacimiento);
		if(es_correcta == 0)
		{
			printf("Ingreso mal la fecha %i/%i/%i\n",fecha_nacimiento->dia, fecha_nacimiento->mes, fecha_nacimiento->anio);
		}
	}
	while(es_correcta != 1);
};

void cargar_genero(char *genero)
{
	int es_correcta;
	do
	{
		printf("Ingrese el sexo:\n");
		scanf(" %c",genero);
		fflush(stdin);
		es_correcta = validar_genero(*genero);
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
		cargar_apellido(empleados[i].apellido);
		cargar_nombre(empleados[i].nombre);
		cargar_fecha_nacimiento(&empleados[i].fecha_de_nacimiento);	
		cargar_genero(&empleados[i].sexo);
		cargar_nacionalidades(&empleados[i].nacionalidades);
		*ml = *ml + 1;
		printf("Desea coninuar cargando empleados? (0)Si o (1)No:  \n"); 
		scanf("%i", &continuar);
		fflush(stdin);
		i++;
	}
	while(*ml > max_empleados || continuar != 1);	 	
};

void ordenar_por_anio(vt_empleados menores_a_2000, int ml){
    int i, j;
    t_empleado aux;
    for (i=1; i < ml; i++){
        for(j=0 ; j < ml - i; j++){
            if (menores_a_2000[j].fecha_de_nacimiento.anio > menores_a_2000[j+1].fecha_de_nacimiento.anio){
                    strcpy(aux.nombre, menores_a_2000[j].nombre);
                    strcpy(aux.apellido, menores_a_2000[j].apellido);
                    aux.fecha_de_nacimiento.dia = menores_a_2000[j].fecha_de_nacimiento.dia;
                    aux.fecha_de_nacimiento.mes = menores_a_2000[j].fecha_de_nacimiento.mes;
                    aux.fecha_de_nacimiento.anio = menores_a_2000[j].fecha_de_nacimiento.anio;
                    aux.nacionalidades = menores_a_2000[j].nacionalidades;
                    strcpy(menores_a_2000[j].nombre, menores_a_2000[j+1].nombre);
                    strcpy(menores_a_2000[j].apellido, menores_a_2000[j+1].apellido);
                    menores_a_2000[j].fecha_de_nacimiento.dia = menores_a_2000[j+1].fecha_de_nacimiento.dia;
                    menores_a_2000[j].fecha_de_nacimiento.mes = menores_a_2000[j+1].fecha_de_nacimiento.mes;
                    menores_a_2000[j].fecha_de_nacimiento.anio = menores_a_2000[j+1].fecha_de_nacimiento.anio;
                    menores_a_2000[j].nacionalidades = menores_a_2000[j+1].nacionalidades;
                    strcpy(menores_a_2000[j+1].nombre, aux.nombre);
                    strcpy(menores_a_2000[j+1].apellido, aux.apellido);
                    menores_a_2000[j+1].fecha_de_nacimiento.dia = aux.fecha_de_nacimiento.dia;
                    menores_a_2000[j+1].fecha_de_nacimiento.mes = aux.fecha_de_nacimiento.mes;
                    menores_a_2000[j+1].fecha_de_nacimiento.anio = aux.fecha_de_nacimiento.anio;
                    menores_a_2000[j+1].nacionalidades = aux.nacionalidades;  
}}}}
    
void ordenar_por_dia(vt_empleados menores_a_2000, int ml){
    int i, j;
    t_empleado aux;
    for (i=1; i < ml; i++){
        for(j=0 ; j < ml - i; j++){
            if((menores_a_2000[j].fecha_de_nacimiento.anio == menores_a_2000[j+1].fecha_de_nacimiento.anio) && (menores_a_2000[j].fecha_de_nacimiento.mes == menores_a_2000[j+1].fecha_de_nacimiento.mes)){
            if (menores_a_2000[j].fecha_de_nacimiento.dia > menores_a_2000[j+1].fecha_de_nacimiento.dia){
                    strcpy(aux.nombre, menores_a_2000[j].nombre);
                    strcpy(aux.apellido, menores_a_2000[j].apellido);
                    aux.fecha_de_nacimiento.dia = menores_a_2000[j].fecha_de_nacimiento.dia;
                    aux.fecha_de_nacimiento.mes = menores_a_2000[j].fecha_de_nacimiento.mes;
                    aux.fecha_de_nacimiento.anio = menores_a_2000[j].fecha_de_nacimiento.anio;
                    aux.sexo = menores_a_2000[j].sexo;
                    aux.nacionalidades = menores_a_2000[j].nacionalidades;
                    strcpy(menores_a_2000[j].nombre, menores_a_2000[j+1].nombre);
                    strcpy(menores_a_2000[j].apellido, menores_a_2000[j+1].apellido);
                    menores_a_2000[j].fecha_de_nacimiento.dia = menores_a_2000[j+1].fecha_de_nacimiento.dia;
                    menores_a_2000[j].fecha_de_nacimiento.mes = menores_a_2000[j+1].fecha_de_nacimiento.mes;
                    menores_a_2000[j].fecha_de_nacimiento.anio = menores_a_2000[j+1].fecha_de_nacimiento.anio;
                    menores_a_2000[j].nacionalidades = menores_a_2000[j+1].nacionalidades;
                    menores_a_2000[j].sexo = menores_a_2000[j+1].sexo;
                    strcpy(menores_a_2000[j+1].nombre, aux.nombre);
                    strcpy(menores_a_2000[j+1].apellido, aux.apellido);
                    menores_a_2000[j+1].fecha_de_nacimiento.dia = aux.fecha_de_nacimiento.dia;
                    menores_a_2000[j+1].fecha_de_nacimiento.mes = aux.fecha_de_nacimiento.mes;
                    menores_a_2000[j+1].fecha_de_nacimiento.anio = aux.fecha_de_nacimiento.anio;
                    menores_a_2000[j+1].nacionalidades = aux.nacionalidades;  
                    menores_a_2000[j+1].sexo = aux.sexo;  
}}}}}
    
int buscar(vt_empleados menores_a_2000, int buscar, int ml){
    int medio, inicio, final;
    inicio = 0;
    final = ml;
    while(inicio <= final){
        medio = (inicio + final)/2;
        if(menores_a_2000[medio].fecha_de_nacimiento.anio == buscar){
            return medio;
        }
        if(menores_a_2000[medio].fecha_de_nacimiento.anio < buscar){
            inicio = medio+1;
        }
       else{
            final = medio-1;
        }
    }
    return -1;  
}
void cortar(vt_empleados menores_a_2000, int cortar_desde){
    int i, j;
    t_empleado copia_empleado;
    for(i = 0; i < cortar_desde; i++){
        strcpy(copia_empleado.nombre, menores_a_2000[i].nombre);
        strcpy(copia_empleado.apellido, menores_a_2000[i].apellido);
        copia_empleado.fecha_de_nacimiento.dia = menores_a_2000[i].fecha_de_nacimiento.dia;
        copia_empleado.fecha_de_nacimiento.mes = menores_a_2000[i].fecha_de_nacimiento.mes;
        copia_empleado.fecha_de_nacimiento.anio = menores_a_2000[i].fecha_de_nacimiento.anio;
        copia_empleado.sexo = menores_a_2000[i].sexo;
        for(j = 0; j < menores_a_2000[i].nacionalidades.ml_nacionalidades; j++){
            strcpy(copia_empleado.nacionalidades.nacionalidades[j], menores_a_2000[i].nacionalidades.nacionalidades[j]);
        }
        menores_a_2000[i] = copia_empleado;
}}
    
void mostrar(vt_empleados menores_a_2000, int cortar_desde){
    int i, j;
    for(i = 0; i < cortar_desde; i++){
        printf("EL EMPLEADO: %s %s", menores_a_2000[i].nombre,
                                    menores_a_2000[i].apellido);
        printf("\n\t\t Nació el: %i %i %i", menores_a_2000[i].fecha_de_nacimiento.dia,
                                            menores_a_2000[i].fecha_de_nacimiento.mes,
                                            menores_a_2000[i].fecha_de_nacimiento.anio);
        printf("\n\t\t Sexo: %c\n", menores_a_2000[i].sexo);
        printf("\t\t De nacionalidad(es): \n");
        for(j=0; j < menores_a_2000[i].nacionalidades.ml_nacionalidades; j++){
            printf("\n\t\t\t %s\n", menores_a_2000[i].nacionalidades.nacionalidades[j]);
}}}


int es_mayor_a_2000(vt_empleados menores_a_2000, int ml){
    int i;
    for(i=0;i<ml;i++){
        if(menores_a_2000[i].fecha_de_nacimiento.anio >= 2000){
            return i;
        }
    }

}
void mostrar_nacidos_antes_2000(vt_empleados empleado, int ml){
       int i, cortar_desde;
       vt_empleados menores_a_2000;
       for(i = 0; i < ml; i++){
           menores_a_2000[i] = empleado[i];
        }    
    
        ordenar_por_anio(menores_a_2000, ml);
        ordenar_por_dia(menores_a_2000, ml);
        cortar_desde = buscar(menores_a_2000, 2000, ml);
        if(cortar_desde != -1){
           cortar(menores_a_2000, cortar_desde);
        }
        else{
            cortar_desde = es_mayor_a_2000(menores_a_2000, ml);
            cortar(menores_a_2000, cortar_desde);
        }
        printf("SE CORTA ACA: %i", cortar_desde);
        mostrar(menores_a_2000, cortar_desde);
}


void doble_nacionalidad(vt_empleados empleados, int ml)
{
      int d, i, posicion_inicial = 0;
      vt_empleados empleados_arg_uru;

	  for(i = 0; i < ml; i++)
	  {
		  if(empleados[i].nacionalidades.ml_nacionalidades > 1)
		  {
        	for(d = 0; d < empleados[i].nacionalidades.ml_nacionalidades; d++)
        	{
            	if((strcmp(empleados[i].nacionalidades.nacionalidades[d],"Argentina\n") == 0) || (strcmp(empleados[i].nacionalidades.nacionalidades[d], "argentina\n") == 0) || (strcmp(empleados[i].nacionalidades.nacionalidades[d], "Uruguaya\n") == 0) || (strcmp(empleados[i].nacionalidades.nacionalidades[d], "uruguaya\n") == 0) )
            	{
					
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
    for(i = 0; i < ml; i++)
    {
        for(j = 0; j < empleados[i].nacionalidades.ml_nacionalidades; j ++)
        {
            if( (strcmp(empleados[i].nacionalidades.nacionalidades[j], "argentina\n") == 0) || (strcmp(empleados[i].nacionalidades.nacionalidades[j], "Argentina\n") == 0 ) )
            {
                contador_argentinos ++;
            }
        }
    }
    return contador_argentinos;
}
void porcentaje_argentinos(vt_empleados empleados, int ml)
{
    int contador_argentinos, porcentaje;
    contador_argentinos = buscar_argentinos(empleados, ml);
    porcentaje = ((contador_argentinos / ml) * 100);
    printf("El porcentaje de empleados argentinos es de: %i ", porcentaje);
}
void main() 
{
	vt_empleados empleados;
	int ml, opcion, continuar;
	cargar_empleado(empleados, &ml);
	do
	{ 
		printf ("Elegir opcion a realizar:\n");
		printf ("(1) Punto B:\n");
		//printf ("(2) Punto C:\n");
		printf ("(3) Punto D:\n");
		printf ("(4) Punto E:\n");
		scanf ("%i", &opcion);
		fflush (stdin);
		switch(opcion)
		{
			case 1: mostrar_nacidos_antes_2000(empleados, ml);
					break;
		//	case 2: buscar_empleado_punto_c(empleados, ml);
		//			break;
			case 3: doble_nacionalidad(empleados, ml);
					break;
			case 4: porcentaje_argentinos(empleados, ml);
					 break;
		}
		printf ("Desea realizar otra operacion? (0)Si o (1)No: ");
		scanf ("%i", &continuar);
		fflush(stdin);
	}
	while/*(*/( continuar != 1);
}
