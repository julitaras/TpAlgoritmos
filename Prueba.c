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

// ASUMO QUE HAY AL MENOS UN EMPLEADO NACIDO ANTES DE LOS AÑOS 2000
void ordenar_por_anio(vt_empleados empleado, int ml);
void ordenar_por_dia(vt_empleados empleado, int ml);
int buscar(vt_empleados empleado, int buscar, int ml);
void cortar(vt_empleados empleado, vt_empleados menores_a_2000, int cortar_desde);
void mostrar(vt_empleados empleado, int cortar_desde);

int main(){
   int i, cortar_desde;
   vt_empleados menores_a_2000;
   int ml = 4;
   vt_empleados empleado;
   t_empleado vector1;
   t_empleado vector2;
   t_empleado vector3;
   t_empleado vector4;
   empleado[0] = vector1;
   empleado[1] = vector2;
   empleado[2] = vector3;
   empleado[3] = vector4;
   
   strcpy(empleado[0].nombre, "Ivan");
   strcpy(empleado[0].apellido, "Ayala");
   empleado[0].fecha_de_nacimiento.dia = 17;
   empleado[0].fecha_de_nacimiento.mes = 2;
   empleado[0].fecha_de_nacimiento.anio = 1996;
   strcpy(empleado[0].nacionalidades.nacionalidades[0], "argentina");
   
    strcpy(empleado[0].nombre, "Juli");
   strcpy(empleado[0].apellido, "Fernandez");
   empleado[0].fecha_de_nacimiento.dia = 16;
   empleado[0].fecha_de_nacimiento.mes = 2;
   empleado[0].fecha_de_nacimiento.anio = 1996;
   strcpy(empleado[0].nacionalidades.nacionalidades[0], "argentina");

    strcpy(empleado[0].nombre, "Mati");
   strcpy(empleado[0].apellido, "Gorge");
   empleado[0].fecha_de_nacimiento.dia = 7;
   empleado[0].fecha_de_nacimiento.mes = 2;
   empleado[0].fecha_de_nacimiento.anio = 1996;
   strcpy(empleado[0].nacionalidades.nacionalidades[0], "argentina");

   strcpy(empleado[0].nombre, "Essa");
   strcpy(empleado[0].apellido, "eeaaa");
   empleado[0].fecha_de_nacimiento.dia = 17;
   empleado[0].fecha_de_nacimiento.mes = 2;
   empleado[0].fecha_de_nacimiento.anio = 2000;
   strcpy(empleado[0].nacionalidades.nacionalidades[0], "argentina");
   for( i = 0; i < ml; i++){
       printf("EL EMPLEADO: %s \n", empleado[i]);
       /*printf("EL EMPLEADO: %s %s", empleado[i].nombre,
                                    empleado[i].apellido);
       printf("\n\t\t Nació el: %i %i %i", empleado[i].fecha_de_nacimiento.dia,
                                           empleado[i].fecha_de_nacimiento.mes,
                                           empleado[i].fecha_de_nacimiento.anio);
       printf("\n\t\t Sexo: %c\n", empleado[i].sexo);
       printf("\n\t\t De nacionalidad(es): \n");
       for(int j=0; j < empleado->nacionalidades.ml_nacionalidades; j++){
           printf("\n\t\t\t %s\n", empleado[i].nacionalidades.nacionalidades[j]);
       }*/
   }   

   ordenar_por_anio(empleado, ml);
   ordenar_por_dia(empleado, ml);

   cortar_desde = buscar(empleado, 2000, ml);
   if(cortar_desde != -1){
       cortar(empleado, menores_a_2000, cortar_desde);
   }
   mostrar(menores_a_2000, cortar_desde);
   return 0;
}


void ordenar_por_anio(vt_empleados empleado, int ml){
    int i, j;
    t_empleado aux;
     for (i=1; i < ml; i++){
        for(j=0 ; j < ml - i; j++){
            if (empleado[j].fecha_de_nacimiento.anio > empleado[j+1].fecha_de_nacimiento.anio){
                  strcpy(aux.nombre, empleado[j].nombre);
                   strcpy(aux.apellido, empleado[j].apellido);
                   aux.fecha_de_nacimiento.dia = empleado[j].fecha_de_nacimiento.dia;
                   aux.fecha_de_nacimiento.mes = empleado[j].fecha_de_nacimiento.mes;
                   aux.fecha_de_nacimiento.anio = empleado[j].fecha_de_nacimiento.anio;
                   aux.nacionalidades = empleado[j].nacionalidades;
                   strcpy(empleado[j].nombre, empleado[j+1].nombre);
                   strcpy(empleado[j].apellido, empleado[j+1].apellido);
                   empleado[j].fecha_de_nacimiento.dia = empleado[j+1].fecha_de_nacimiento.dia;
                   empleado[j].fecha_de_nacimiento.mes = empleado[j+1].fecha_de_nacimiento.mes;
                   empleado[j].fecha_de_nacimiento.anio = empleado[j+1].fecha_de_nacimiento.anio;
                   empleado[j].nacionalidades = empleado[j+1].nacionalidades;
                   strcpy(empleado[j+1].nombre, aux.nombre);
                   strcpy(empleado[j+1].apellido, aux.nombre);
                   empleado[j+1].fecha_de_nacimiento.dia = aux.fecha_de_nacimiento.dia;
                   empleado[j+1].fecha_de_nacimiento.mes = aux.fecha_de_nacimiento.mes;
                   empleado[j+1].fecha_de_nacimiento.anio = aux.fecha_de_nacimiento.anio;
                   empleado[j+1].nacionalidades = aux.nacionalidades;              }
          }
     }
}

    t_cadena nombre;
    t_cadena apellido;
    t_fecha fecha_de_nacimiento;
    char sexo;
    t_nacionalidades nacionalidades;    

void ordenar_por_dia(vt_empleados empleado, int ml){
   int i, j;
   t_empleado aux;
    for (i=1; i < ml; i++){
       for(j=0 ; j < ml - i; j++){
           if((empleado[j].fecha_de_nacimiento.anio == empleado[j+1].fecha_de_nacimiento.anio) && (empleado[j].fecha_de_nacimiento.mes == empleado[j+1].fecha_de_nacimiento.mes)){
               if (empleado[j].fecha_de_nacimiento.dia > empleado[j+1].fecha_de_nacimiento.dia){
                   strcpy(aux.nombre, empleado[j].nombre);
                   strcpy(aux.apellido, empleado[j].apellido);
                   aux.fecha_de_nacimiento.dia = empleado[j].fecha_de_nacimiento.dia;
                   aux.fecha_de_nacimiento.mes = empleado[j].fecha_de_nacimiento.mes;
                   aux.fecha_de_nacimiento.anio = empleado[j].fecha_de_nacimiento.anio;
                   aux.nacionalidades = empleado[j].nacionalidades;
                   strcpy(empleado[j].nombre, empleado[j+1].nombre);
                   strcpy(empleado[j].apellido, empleado[j+1].apellido);
                   empleado[j].fecha_de_nacimiento.dia = empleado[j+1].fecha_de_nacimiento.dia;
                   empleado[j].fecha_de_nacimiento.mes = empleado[j+1].fecha_de_nacimiento.mes;
                   empleado[j].fecha_de_nacimiento.anio = empleado[j+1].fecha_de_nacimiento.anio;
                   empleado[j].nacionalidades = empleado[j+1].nacionalidades;
                   strcpy(empleado[j+1].nombre, aux.nombre);
                   strcpy(empleado[j+1].apellido, aux.nombre);
                   empleado[j+1].fecha_de_nacimiento.dia = aux.fecha_de_nacimiento.dia;
                   empleado[j+1].fecha_de_nacimiento.mes = aux.fecha_de_nacimiento.mes;
                   empleado[j+1].fecha_de_nacimiento.anio = aux.fecha_de_nacimiento.anio;
                   empleado[j+1].nacionalidades = aux.nacionalidades;
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
       if(empleado[medio].fecha_de_nacimiento.anio == buscar){
            return medio;
       }
        if(empleado[medio].fecha_de_nacimiento.anio < buscar){
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
   t_empleado copia_empleado;
   for(i = 0; i < cortar_desde; i++){
       copia_empleado.fecha_de_nacimiento.dia = empleado[i].fecha_de_nacimiento.dia;
       copia_empleado.fecha_de_nacimiento.mes = empleado[i].fecha_de_nacimiento.mes;
       copia_empleado.fecha_de_nacimiento.anio = empleado[i].fecha_de_nacimiento.anio;
       menores_a_2000[i] = copia_empleado;
   }  
}

void mostrar(vt_empleados empleado, int cortar_desde){
   int i, j;
   for(i = 0; i < cortar_desde; i++){
       printf("EL EMPLEADO: %s %s", empleado[i].nombre,
                                    empleado[i].apellido);
       printf("\n\t\t Nació el: %i %i %i", empleado[i].fecha_de_nacimiento.dia,
                                           empleado[i].fecha_de_nacimiento.mes,
                                           empleado[i].fecha_de_nacimiento.anio);
       printf("\n\t\t Sexo: %c\n", empleado[i].sexo);
       printf("\n\t\t De nacionalidad(es): \n");
       for(j=0; j < empleado->nacionalidades.ml_nacionalidades; j++){
           printf("\n\t\t\t %s\n", empleado[i].nacionalidades.nacionalidades[j]);
       }
   }   
}
