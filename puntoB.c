void mostrar_nacidos_antes_2000(vt_empleados empleado, int ml);
void ordenar_por_dia(vt_empleados menores_a_2000, int ml);
int buscar(vt_empleados menores_a_2000, int buscar, int ml);
void cortar(vt_empleados menores_a_2000, int cortar_desde);
void mostrar(vt_empleados menores_a_2000, int cortar_desde);
  
void mostrar_nacidos_antes_2000(vt_empleados empleado, int ml){
       int i, cortar_desde;
       vt_empleados menores_a_2000;
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
        for(j=0; j < menores_a_2000->nacionalidades.ml_nacionalidades; j++){
            printf("\n\t\t\t %s\n", menores_a_2000[i].nacionalidades.nacionalidades[j]);
}}}


