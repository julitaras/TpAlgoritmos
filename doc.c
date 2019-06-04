Una empresa que se dedica a la reubicación de empleados tiene una lista de 500 empleados (como máximo) con la siguiente información. - Nombre y apellido. Con el formato "Apellidos, Nombres". - Fecha de nacimiento del empleado. - Sexo (M, F) - Nacionalidad Las nacionalidades pueden ser: Argentina, Uruguaya, Chilena, Peruana, Boliviana, Paraguaya, Brasileña. Un empleado puede tener más de una nacionalidad. Se pide armar las estructuras y el programa que permita:
 
A. Realizar la carga de datos. Validar todos los datos ingresados.

 B- Mostrar un listado de personas nacidas antes de 2000 ordenado por Fecha de nacimiento. Mostrar todos los datos de cada empleado. 

C- Ingresar un Apellido por teclado y listar todas las mujeres que se apellidan igual y además nacieron en verano. Mostrar todos los datos de cada empleado.

 D- Emitir un informe de empleados uruguayos y argentinos que tengan más de una nacionalidad. Mostrar todos los datos de cada empleado. 

E- Indicar el porcentaje de empleados argentinos



Código:

////////PUNTO A y D//////////////////
#include <stdio.h>
#include <string.h>
#define max_nacionalidades 7
#define max_empleados 500
#define max_string 60

typedef char t_nacionalidad[12];
typedef t_nacionalidad v_nacionalidades[max_nacionalidades];
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
    t_cadena apellido_nombre;//Apellido, Nombre //Separar nombre de apellido x punto C
    t_fecha fecha_de_nacimiento;
    char sexo;
    v_nacionalidades nacionalidades;//?
} t_empleado;

//Defino el array de Empleados
typedef t_empleado vt_empleados[max_empleados];

//Valido la fecha de nacimiento
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
int validar_nombre(char caracter_nombre)
{
    t_vector numeros = {'1','2','3','4','5','6','7','8','9'};
    int i, incorrecto;
    incorrecto = 0;
    i= 0;
    //burcar en nombre algun signo especial o numero
    for(i = 0; i <= 8; i++)
    {
        if(caracter_nombre == numeros[i])
        {
            incorrecto = 1;
        }
    }
    return incorrecto;
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

int validar_nacionalidades(t_nacionalidad nacionalidad)
{
    int es_valida;
    es_valida = 0;
    if((strcmp(nacionalidad, "argentina\n") == 0) || (strcmp(nacionalidad, "Argentina\n") == 0) || (strcmp(nacionalidad, "uruguaya\n") == 0) || (strcmp(nacionalidad, "Uruguaya\n") == 0) || (strcmp(nacionalidad, "chilena\n") == 0) || (strcmp(nacionalidad, "Chilena\n") == 0) || (strcmp(nacionalidad, "peruana\n") == 0) ||(strcmp(nacionalidad, "Peruana\n") == 0) || (strcmp(nacionalidad, "boliviana\n") == 0) || (strcmp(nacionalidad, "Boliviana\n") == 0) || (strcmp(nacionalidad, "brasileña\n") == 0) || (strcmp(nacionalidad, "Brasilenia\n") == 0) || (strcmp(nacionalidad, "brasilenia\n") == 0) || (strcmp(nacionalidad, "Brasileña\n") == 0) )
    {
        es_valida = 1;
    }

    return es_valida;
};

void cargar_nacionalidades(v_nacionalidades nacionalidades, int *ml_nacionalidad)
{
    int i, continuar, es_correcta,d;
    i = 0;
    d=0;
    continuar = 0;
    do
    {
        printf("Ingrese la/s nacionalidades:\n");
        fgets(nacionalidades[i], 12, stdin);
        es_correcta = validar_nacionalidades(nacionalidades[i]);
        if(es_correcta == 0)
        {
            printf("No existe esa nacionalidad\n");
        }
        else
        {
            printf("Desea continuar cargando nacionalidades? 0 PARA CONTINUAR,\n 1 PARA FINALIZAR: \n");//Mejorar con el SI y el NO
            scanf("%i", &continuar);
            fflush(stdin);
        }
        i++;
        *ml_nacionalidad=*ml_nacionalidad+1;
    }
    while((*ml_nacionalidad > 5) || continuar != 1 || es_correcta != 1);

    }
int doble_nacionalidad(t_nacionalidades nacionalidades)
{
    int d,valor_que_devuelve;
    valor_que_devuelve=0;
    d = 0;
    if(nacionalidades.ml_nacionalidades > 1)
    {
        while(d < )
        {
            if((strcmp(nacionalidades.nacionalidades[d],"Argentina\n") == 0)||((strcmp(nacionalidades.nacionalidades[d], "argentina\n")) == 0)||((strcmp(nacionalidades.nacionalidades[d], "Uruguaya\n") == 0))||((strcmp(nacionalidades.nacionalidades[d], "uruguaya\n")) == 0)){
                valor_que_devuelve=1;

        return valor_que_devuelve;
                }
    }
    }
}

void cargar_nombre_empleado(t_cadena nombre_completo)
{
    int j, es_incorrecta, largo;
    do
    {
        printf("Ingrese el Apellido y Nombre:\n");
        fgets(nombre_completo, 60, stdin);
        es_incorrecta = 0;
        while((j < strlen(nombre_completo)) && es_incorrecta != 1)
        {
            es_incorrecta = validar_nombre(nombre_completo[j]);
            j++;
        }
        if (es_incorrecta == 1)
        {
            printf("Hubo algun error");
        }
    }
    while(es_incorrecta != 0);
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
    int continuar, i, ml_nacionalidad,d;
    continuar = 0;
    d=0;
    i = 0;
    printf("Ingrese los datos de los empleados:\n");
    do
    {
        cargar_nombre_empleado(empleados[i].apellido_nombre);
        cargar_fecha_nacimiento(empleados[i].fecha_de_nacimiento);
        cargar_genero(empleados[i].sexo);
        cargar_nacionalidades(empleados[i].nacionalidades, &ml_nacionalidad);
        *ml=*ml+1;
        printf("Desea continuar cargando empleados? \n 0 PARA CONTINUAR, 1 PARA FINALIZAR: \n"); //Mejorar con el SI y el NO
        scanf("%i", &continuar);
        fflush(stdin);
        i++;
    }while(*ml > max_empleados || continuar != 1);
    for(d=0;d<*ml;d++){
        if(doble_nacionalidad(empleados[d].nacionalidades,ml_nacionalidad)==1)
            printf("El empleado %s de sexo %c tiene mas de una nacionalidad y una de ellas es la Argentina o la uruguaya\n",empleados[d].apellido_nombre,empleados[d].sexo);
        if(doble_nacionalidad(empleados[d].nacionalidades,ml_nacionalidad)==0)
            printf("El empleado %s de sexo %c no tiene mas de una nacionalidad, o una de ellas no es la Argentina o la uruguaya",empleados[d].apellido_nombre,empleados[d].sexo);//Falta mostrar la fecha y el genero del empleado
    }
}
void main()
{
    vt_empleados empleados;
    int ml;
    cargar_empleado(empleados, &ml);
}




//////////////////////PUNTO B//////////////////

void mostrar(VT_Empleados empleado, int ml);
void ordenar(VT_Empleados empleado);
int buscar(VT_Empleados empleado, int buscar);
void cortar(VT_Empleados empleado, VT_Empleados menores_a_2000, int cortar_desde);

int main(){
   int i, cortar_desde;
   VT_Empleados empleado;
   VT_Empleados menores_a_2000;
  
   ordenar(empleado);

   cortar_desde = buscar(empleado, 2000);
   if(cortar_desde != -1){
       cortar(empleado, menores_a_2000, cortar_desde);
   }

   mostrar(menores_a_2000, ml);
  
   return 0;
}
void ordenar(VT_Empleados empleado){
   int i, j;
   T_Empleado aux;
    for (i=1; i < TAM; i++){
       for(j=0 ; j < TAM - i; j++){
           if (empleado[j].anio > empleado[j+1].anio){
               aux = empleado[j];
               empleado[j] = empleado[j+1];
               empleado[j+1] = aux;   
             }
         }
    }
}
int buscar(VT_Empleados empleado, int buscar){
   int medio, inicio, final;
   inicio = 0;
   final = TAM;
    while(inicio <= final){
       medio = (inicio + final)/2;
       if(empleado[medio].anio == buscar){
            return medio;
       }
        if(empleado[medio].anio < buscar){
            inicio = medio+1;
        }
        else{
            final = medio-1;
        }
    }
    return -1;  
}
void cortar(VT_Empleados empleado, VT_Empleados menores_a_2000, int cortar_desde){
   int i, j;
   T_Empleado copia;
   for(i = 0; i < cortar_desde; i++){
       copia.dia = empleado[i].dia;
       copia.mes = empleado[i].mes;
       copia.anio = empleado[i].anio;
       menores_a_2000[i] = copia;
   }
}

void mostrar(VT_Empleados empleado, int ml, int ml_nacionalidad){
   int i, j;
   for(i = 0; i < ml; i++){
       printf("EL EMPLEADO: %i", empleado[i].Apellido_Nombre);
       printf("\n\t\t Nació el: %i %i %i", empleado[i].Fecha_De_Nacimiento.dia,
                                           empleado[i].Fecha_De_Nacimiento.mes,
                                           empleado[i].Fecha_De_Nacimiento.anio);
       printf("\n\t\t Sexo: %c\n", empleado[i].Fecha_De_Nacimiento.sexo);
       for(j=0; j < ml_nacionalidad; j++){
           printf("\n\t\t De nacionalidad(es): %s\n", empleado[i].Nacionalidad[0]);
       }
   }   
}

void mostrar_punto_D(int ml, vt_empleados empleados)
{
	int i;
    for(i=0;i<ml;i++)
	{
        if(doble_nacionalidad(empleados[i].nacionalidades)==1)
		{
            printf("El empleado %s %s tiene mas de una nacionalidad y una de ellas es la Argentina o la uruguaya\n",empleados[i].apellido,empleados[i].nombre,empleados[i].sexo);
		}
		if(doble_nacionalidad(empleados[i].nacionalidades)==0)
		{
            printf("El empleado %s %s no tiene mas de una nacionalidad, o una de ellas no es la Argentina o la uruguaya",empleados[i].apellido,empleados[i].nombre,empleados[i].sexo);//Falta mostrar la fecha y el genero del empleado
		}
	}
}




//////////////////////////////PUNTO C//////////////////////////////

int main (){
	int opcion, continuar;
	
	do{
		do{ 
			printf ("Elegir opcion a realizar:\n");
			printf ("(1) Ingresar Empleado:\n");
			printf ("(2) Buscar Empleado:\n");
			scanf ("%i", &opcion);
			fflush (stdin);
		} while (opcion < 1 || opcion > 2);
		
		switch (opcion){
			case 1: cargar_apellido (opcion);
					cargar_nombre (opcion);
					cargar_nacimiento (empleado[MAX].fecha_nacimiento);
					cargar_sexo (opcion);
					cargar_nacionalidad (opcion);
					break; 
			case 2: buscar_empleado (opcion);
					break;
		}
	printf ("Desea realizar otra operacion? S/N: ");
	scanf (" %c", &continuar);
	} while (continuar == 'S' || continuar == 's');


return 0;
}

int doble_nacionalidad(t_nacionalidades nacionalidades){
      int d,valor_que_devuelve;
      d=0;
      valor_que_devuelve=0;
      if(nacionalidades.ml_nacionalidades > 1){
        for(d=0;d<nacionalidades.ml_nacionalidades;d++){
            if((strcmp(nacionalidades.nacionalidades[d],"Argentina\n") == 0)||((strcmp(nacionalidades.nacionalidades[d], "argentina\n")) == 0)||((strcmp(nacionalidades.nacionalidades[d], "Uruguaya\n") == 0))||((strcmp(nacionalidades.nacionalidades[d], "uruguaya\n")) == 0)){
                valor_que_devuelve=1;

        return valor_que_devuelve;
                }
}
}
}

void mostrar_punto_D(int ml,vt_empleados empleados){
    int i;
    for(i=0;i<ml;i++){
        if(doble_nacionalidad(empleados[i].nacionalidades)==1)
            printf("El empleado %s %s tiene mas de una nacionalidad y una de ellas es la Argentina o la uruguaya\n",empleados[i].apellido,empleados[i].nombre,empleados[i].sexo);
        if(doble_nacionalidad(empleados[i].nacionalidades)==0)
            printf("El empleado %s %s no tiene mas de una nacionalidad, o una de ellas no es la Argentina o la uruguaya",empleados[i].apellido,empleados[i].nombre,empleados[i].sexo);//Falta mostrar la fecha y el genero del empleado
    }
    }
    
void mostrar_nacidos_antes_2000(vt_empleados empleado);
void ordenar_por_anio(vt_empleados empleado, int ml);
void ordenar_por_dia(vt_empleados empleado, int ml);
int buscar(vt_empleados empleado, int buscar, int ml);
void cortar(vt_empleados empleado, vt_empleados menores_a_2000, int cortar_desde);
void mostrar(vt_empleados empleado, int cortar_desde, int ml_nacionalidad);

void mostrar_nacidos_antes_2000(vt_empleados empleado){
   int i, cortar_desde;
  
   ordenar_por_anio(empleado);
   ordenar_por_dia(empleado);

   cortar_desde = buscar(empleado, 2000);
   if(cortar_desde != -1){
       cortar(empleado, menores_a_2000, cortar_desde);
   }

   mostrar(menores_a_2000, cortar_desde);
}

void ordenar_por_anio(vt_empleados empleado, int ml){
   int i, j;
   t_empleado aux;
    for (i=1; i < ml; i++){
       for(j=0 ; j < ml - i; j++){
           if (empleado[j].anio > empleado[j+1].anio){
               aux = empleado[j];
               empleado[j] = empleado[j+1];
               empleado[j+1] = aux;   
             }
         }
    }
}

void ordenar_por_dia(vt_empleados empleado, int ml){
   int i, j;
   t_fecha aux;
    for (i=1; i < ml; i++){
       for(j=0 ; j < ml - i; j++){
           if((empleado[j].anio == empleado[j+1].anio) && (empleado[j].mes == empleado[j+1].mes)){
               if (empleado[j].dia > empleado[j+1].dia){
                   aux = empleado[j];
                   empleado[j] = empleado[j+1];
                   empleado[j+1] = aux;   
                 }               
           }
         }
    }
}

int buscar(vt_empleados empleado, int buscar, int ml){
   int medio, inicio, final;
   inicio = 0;
   final = ml;
    while(inicio <= final){
       medio = (inicio + final)/2;
       if(empleado[medio].anio == buscar){
            return medio;
       }
        if(empleado[medio].anio < buscar){
            inicio = medio+1;
        }
        else{
            final = medio-1;
        }
    }
    return -1;  
}
void cortar(vt_empleados empleado, vt_empleados menores_a_2000, int cortar_desde){
   int i, j;
   t_empleado copia;
   for(i = 0; i < cortar_desde; i++){
       copia.dia = empleado[i].dia;
       copia.mes = empleado[i].mes;
       copia.anio = empleado[i].anio;
       menores_a_2000[i] = copia;
   }  
}

void mostrar(vt_empleados empleado, int cortar_desde, int ml_nacionalidad){
   int i, j;
   for(i = 0; i < cortar_desde; i++){
       printf("EL EMPLEADO: %s %s", empleado[i].nombre,
                                    empleado[i].apellido);
       printf("\n\t\t Nació el: %i %i %i", empleado[i].fecha_de_nacimiento.dia,
                                           empleado[i].fecha_de_nacimiento.mes,
                                           empleado[i].fecha_de_nacimiento.anio);
       printf("\n\t\t Sexo: %c\n", empleado[i].fecha_de_nacimiento.sexo);
       printf("\n\t\t De nacionalidad(es): \n");
       for(j=0; j < empleado.nacionalidades.ml_nacionalidad; j++){
           printf("\n\t\t\t %s\n", empleado[i].nacionalidades.nacionalidades);
       }
   }   
}
