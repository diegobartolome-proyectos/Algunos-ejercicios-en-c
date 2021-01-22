#include <stdio.h>
#define NUM_MAX_ALUMNOS 1000
typedef struct Alumno
{
 char NIF[10];
 int edad;
}ALUMNO;
int Pedir_Valor(int valor_max);
void Solicitar_Datos_Todos(ALUMNO[],int);
double Calcular_Edad_Media(ALUMNO[],int);
main()
{
 int num_alumnos;
 double edad_media;
 num_alumnos=Pedir_Valor(NUM_MAX_ALUMNOS);
 if(num_alumnos)
 {
 ALUMNO vector_alumnos[num_alumnos];
 Solicitar_Datos_Todos (vector_alumnos,num_alumnos);
 edad_media=Calcular_Edad_Media(vector_alumnos,num_alumnos);
 printf("La edad media es %lf\n",edad_media);
 }
}
int Pedir_Valor(int valor_max)
{
 int valor;
 do
 {
 printf("Introduzca valor (<=%d):",valor_max);
 scanf("%d",&valor);
 if(valor<0 || valor>valor_max)
 printf("El valor introducido no es válido\n");
 }while(valor<0 || valor>valor_max);
 return(valor);
}

void Solicitar_Datos_Todos(ALUMNO vector_alumnos[],int num)
{
 int i;
 for(i=0;i<num;i++)
 {
 printf("Introduzca NIF alumno %d: ",i+1);
 scanf("%s",vector_alumnos[i].NIF);
 printf("Introduzca edad alumno %d: ",i+1);
 scanf("%d",&vector_alumnos[i].edad);
 }
}

double Calcular_Edad_Media(ALUMNO vector_alumnos[],int num)
{
 int i;
 double edad_media=0.;
 for(i=0;i<num;i++)
 {
 edad_media+=vector_alumnos[i].edad;
 }
 return edad_media/num;
}
