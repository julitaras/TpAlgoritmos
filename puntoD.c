int doble_nacionalidad(t_nacionalidades nacionalidades)
{
      int d,valor_que_devuelve;
      
      valor_que_devuelve = 0;
      if(nacionalidades.ml_nacionalidades > 1)
      {
        for(d = 0; d < nacionalidades.ml_nacionalidades; d++)
        {
            if((strcmp(nacionalidades.nacionalidades[d],"Argentina\n") == 0) || (strcmp(nacionalidades.nacionalidades[d], "argentina\n") == 0) || (strcmp(nacionalidades.nacionalidades[d], "Uruguaya\n") == 0) || (strcmp(nacionalidades.nacionalidades[d], "uruguaya\n") == 0) )
            {
                valor_que_devuelve = 1;
            }
        }
        }
        return valor_que_devuelve;
}

void mostrar_punto_D(int ml,vt_empleados empleados)
{
    int i;
    for(i=0;i<ml;i++)
    {
        if(doble_nacionalidad(empleados[i].nacionalidades) == 1)
        {
            printf("El empleado %s %s tiene mas de una nacionalidad y una de ellas es la Argentina o la uruguaya\n",empleados[i].apellido,empleados[i].nombre,empleados[i].sexo);
        }
        if(doble_nacionalidad(empleados[i].nacionalidades)==0)
         {
            printf("El empleado %s %s no tiene mas de una nacionalidad, o una de ellas no es la Argentina o la uruguaya",empleados[i].apellido,empleados[i].nombre,empleados[i].sexo);//Falta mostrar la fecha y el genero del empleado
         }
    }
    }
