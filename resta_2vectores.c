
#include <stdio.h>
#define TAM_MAX 100
int Pedir_Valor(int *,int);
void Resta_Vectores(int tam,float v1[],float v2[],float resta[] );
void Pedir_Datos(int tam ,float v[]);
void Imprime_Vector(int tam,float v[]);

main()
{
    int tam,seguir;
    int i;
    do
    {
        if(Pedir_Valor(&tam,TAM_MAX))
        {
            float v1[tam],v2[tam],resta[tam];//Se reservan en ejecución
            printf("Introduzca los elementos del primer vector\n");
            Pedir_Datos(tam, v1);

            printf("Introduzca los elementos del segundo vector\n");
            Pedir_Datos(tam, v2);

            printf("La resta de los vectores es: \n");


            Resta_Vectores(tam,v1,v2,resta);
            Imprime_Vector(tam,resta);
        }
        else
            printf("El tamanho del vector no es valido\n");
        printf("Si desea continuar pulse 1:");
        scanf("%d",&seguir);
    }
    while(seguir==1);
}
int Pedir_Valor(int *tamanho,int valor_max)
{
    int exito=0;
    printf("Valor(positivo e inferior a %d): ",valor_max);
    scanf("%d",tamanho);
    if(*tamanho>0 && *tamanho<valor_max)
    {
        exito=1;
    }
    return exito;

}

void Resta_Vectores(int tam,float v1[],float v2[],float resta[])
{
    int i;
    for(i=0; i<tam; i++)
    {
        resta[i]=v1[i]-v2[i];


    }

}
void Pedir_Datos(int tam ,float v[])
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("v[%d]",i+1);
        scanf("%f", &v[i]);

    }

}
void Imprime_Vector(int tam,float v[])
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%f\n", v[i]);

    }
    printf("\n");

}

