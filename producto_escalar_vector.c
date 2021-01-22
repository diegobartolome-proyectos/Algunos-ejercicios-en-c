#include <stdio.h>
#include <math.h>
#define GRADO_MAX 20
int Pedir_Valor( int * ,int );
float Calcula_Vector_X(int  ,float v[]);
float Producto_Escalar(int, float v1[] ,float v2[] );


main()
{
 int seguir,i,tam;
 float resultado,x;
    do
         {
             if(Pedir_Valor(&tam,GRADO_MAX))
             {

             float v1[tam],v[tam], v2[tam];
                    for(i=0;i<tam;i++)
                        {

                            printf("Introduzca los coeficientes del primer polinomio c%d:\n",i);
                            scanf("%f",&v1[i]);
                        }

             x=Calcula_Vector_X(tam, &v);

             for(i=0;i<tam;i++)
                    {
                        v2[i]=pow(v[i],i);

                        //printf("%f\n",v2[i]);
                    }
                    resultado= Producto_Escalar(tam,v1,v2);

             printf("El valor del polinomio en  es: %f\n", resultado);
             }
         else
         printf("El tama�o del vector no es v�lido\n");
         printf("Si desea continuar pulse 1:");
         scanf("%d",&seguir);
         }
    while(seguir==1);
}
int Pedir_Valor( int *tam,int max)
{
    int i;
    printf("introducir grado de los vectores:");
    scanf("%d",&*tam);
    if(tam>max)
    {
        i=1;

    }
    else
    {
        i=0;

    }
    return i;
}
float Calcula_Vector_X(int tam,float v[])
{
  int i;
 float v2[tam],x;
    printf("Introduzca el valor  de x:\n");
    scanf("%f",&x);
        for(i=0;i<tam;i++)
        {
                v[i]=x;

                v2[i]=pow(v[i],i);

        }
   return x ;

}
float Producto_Escalar(int tam,float v1[],float v2[])
{
    int i;
    float suma=0;
    for (i=0;i<tam;i++)
    {
        suma=suma+v1[i]*v2[i];
    }
    return (suma);

}

