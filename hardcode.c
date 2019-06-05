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
	void ordenar_por_anio(vt_empleados menores_a_2000, int ml);
	void ordenar_por_dia(vt_empleados menores_a_2000, int ml);
	int buscar(vt_empleados menores_a_2000, int buscar, int ml);
	void cortar(vt_empleados menores_a_2000, int cortar_desde);
	void mostrar(vt_empleados menores_a_2000, int cortar_desde);
    
	int main(){
   	int i, cortar_desde, ml = 7;
   	vt_empleados menores_a_2000;
    
   	vt_empleados empleado;
   	t_empleado vector1;
   	t_empleado vector2;
   	t_empleado vector3;
   	t_empleado vector4;
   	t_empleado vector5;
   	empleado[0] = vector1;
   	empleado[1] = vector2;
   	empleado[2] = vector3;
   	empleado[3] = vector4;
   	empleado[4] = vector5;
  	 
    
   	strcpy(empleado[0].nombre, "Sergio");
   	strcpy(empleado[0].apellido, "Koschel");
   	empleado[0].fecha_de_nacimiento.dia = 11;
   	empleado[0].fecha_de_nacimiento.mes = 5;
   	empleado[0].fecha_de_nacimiento.anio = 1996;
   	strcpy(empleado[0].nacionalidades.nacionalidades[0], "argentina");
   	empleado[0].nacionalidades.ml_nacionalidades = 1;
   	empleado[0].sexo = 'M';
    
   	strcpy(empleado[1].nombre, "Julieta");
   	strcpy(empleado[1].apellido, "Fernández");
   	empleado[1].fecha_de_nacimiento.dia = 16;
   	empleado[1].fecha_de_nacimiento.mes = 2;
   	empleado[1].fecha_de_nacimiento.anio = 1998;
   	strcpy(empleado[1].nacionalidades.nacionalidades[0], "argentina");
   	empleado[1].nacionalidades.ml_nacionalidades = 1;
   	empleado[1].sexo = 'F';
    
   	strcpy(empleado[2].nacionalidades.nacionalidades[0], "argentina");
   	strcpy(empleado[2].nombre, "Nicole");
   	strcpy(empleado[2].apellido, "Raveszani");
   	empleado[2].fecha_de_nacimiento.dia = 6;
   	empleado[2].fecha_de_nacimiento.mes = 7;
   	empleado[2].fecha_de_nacimiento.anio = 1996;
   	strcpy(empleado[2].nacionalidades.nacionalidades[0], "argentina");
   	empleado[2].nacionalidades.ml_nacionalidades = 1;
   	empleado[2].sexo = 'F';
    
   	strcpy(empleado[3].nombre, "Iván");
   	strcpy(empleado[3].apellido, "Ayala");
   	empleado[3].fecha_de_nacimiento.dia = 17;
   	empleado[3].fecha_de_nacimiento.mes = 2;
   	empleado[3].fecha_de_nacimiento.anio = 1996;
   	strcpy(empleado[3].nacionalidades.nacionalidades[0], "argentina");
   	empleado[3].nacionalidades.ml_nacionalidades = 1;
   	empleado[3].sexo = 'M';
    
   	strcpy(empleado[4].nombre, "Arianna");
   	strcpy(empleado[4].apellido, "Millán");
   	empleado[4].fecha_de_nacimiento.dia = 10;
   	empleado[4].fecha_de_nacimiento.mes = 25;
   	empleado[4].fecha_de_nacimiento.anio = 2000;
   	strcpy(empleado[4].nacionalidades.nacionalidades[0], "argentina");
   	empleado[4].nacionalidades.ml_nacionalidades = 1;
    	empleado[4].sexo = 'F';
    
   	strcpy(empleado[5].nombre, "Matías");
   	strcpy(empleado[5].apellido, "Gorgellón");
   	empleado[5].fecha_de_nacimiento.dia = 7;
   	empleado[5].fecha_de_nacimiento.mes = 2;
   	empleado[5].fecha_de_nacimiento.anio = 1996;
   	strcpy(empleado[5].nacionalidades.nacionalidades[0], "argentina");
   	empleado[5].nacionalidades.ml_nacionalidades = 1;
   	empleado[5].sexo = 'M';
    
   	strcpy(empleado[6].nombre, "Nicolás");
   	strcpy(empleado[6].apellido, "Díaz");
   	empleado[6].fecha_de_nacimiento.dia = 11;
   	empleado[6].fecha_de_nacimiento.mes = 8;
   	empleado[6].fecha_de_nacimiento.anio = 1994;
   	strcpy(empleado[6].nacionalidades.nacionalidades[0], "argentina");
   	empleado[6].nacionalidades.ml_nacionalidades = 1;
   	empleado[6].sexo = 'M';
 	 
    	for(i = 0; i < ml; i++){
       	menores_a_2000[i] = empleado[i];
    	}    
    	printf("LISTA DESORDENADA:\n\n");
    	for(i = 0; i < ml; i++){
       	printf("%s %s: %i\n", menores_a_2000[i].nombre, menores_a_2000[i].apellido, menores_a_2000[i].fecha_de_nacimiento.anio);
    	}    
    
    	ordenar_por_anio(menores_a_2000, ml);
   	 
    	ordenar_por_dia(menores_a_2000, ml);
   	 
    	cortar_desde = buscar(menores_a_2000, 2000, ml);
    	if(cortar_desde != -1){
       	cortar(menores_a_2000, cortar_desde);
    	}
    	mostrar(menores_a_2000, cortar_desde);
   	 
   	return 0;
	}
   	/*
    
   	return 0;*/
    
    
    
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
    	}}}
    
    
	}
    
    
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
	}
    
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
   	}  
  	 
    
	}
    
	void mostrar(vt_empleados menores_a_2000, int cortar_desde)
	{
   	int i, j;
   	for(i = 0; i < cortar_desde; i++)
	   {
       	printf("EL EMPLEADO: %s %s", menores_a_2000[i].nombre,
                                    	menores_a_2000[i].apellido);
       	printf("\n\t\t Nació el: %i %i %i", menores_a_2000[i].fecha_de_nacimiento.dia,
                                           	menores_a_2000[i].fecha_de_nacimiento.mes,
                                           	menores_a_2000[i].fecha_de_nacimiento.anio);
       	printf("\n\t\t Sexo: %c\n", menores_a_2000[i].sexo);
       	printf("\t\t De nacionalidad(es): \n");
       	for(j=0; j < menores_a_2000->nacionalidades.ml_nacionalidades; j++)
		   {
           	printf("\n\t\t\t %s\n", menores_a_2000[i].nacionalidades.nacionalidades[j]);
       		}
		}  
	   }

