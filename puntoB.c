
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrar(VT_Empleados empleado, int ml);
void ordenar(VT_Empleados empleado);
int buscar(VT_Empleados empleado, int buscar);
void cortar(VT_Empleados empleado, VT_Empleados menores_a_2000, int cortar_desde);

int main(){
    int i, cortar_desde;
    VT_Empleados empleado;
    VT_Empleados menores_a_2000;
    
    ordenar(empleado);

    cortar_desde = buscar(empleado, 200);
    if(cortar_desde != -1){
        cortar(empleado, menores_a_2000, cortar_desde);
    }

    mostrar(menores_a_2000, 5);
    
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


