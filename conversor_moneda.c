#include <stdio.h>

int menu(void);
float conversion (float , float );
float conversionA (float , float );
float conversionB (float , float );
main()
    {
        float cifra, tasa1,tasa2,tasa3, dinero, preciof;
        int opcion;
        printf("cifra que se desea convertir:");
        scanf("%f", &cifra );
        do
        {
            opcion=menu();
            if (opcion==1)
                {

                    tasa1=0.8;
                    preciof= conversion(cifra ,tasa1 );
                    printf("los %f euros son : %f libras esterlinas",cifra, preciof );
                }
            else if (opcion==2)
            {
                 tasa2=1.25;
                    preciof= conversionA(cifra ,tasa2 );
                    printf("los %f euros son : %f dolares",cifra, preciof );
            }
            else if(opcion==3)
            {
                tasa3=145;
                    preciof= conversionB(cifra ,tasa3 );
                    printf("los %f euros son : %f yenes",cifra, preciof );
            }
        }while(cifra<0);

    }
int menu(void)
{
    int op;
            printf("\n a que lo deseas convertir?\n ");
            printf("\n pulse 1 para pasar a libras esterlinas");
            printf("\n pulse 2 para pasar a dolares");
            printf("\n pulse 3 para pasar a yenes\n");
            scanf(" %d",&op);
    return op;
}
float conversion (float dinero, float tasa_conversion)
{
    float conversion1;
    conversion1=tasa_conversion*dinero;
    return (conversion1);
}
float conversionA (float dinero, float tasa_conversion)
{
    float conversion1;
    conversion1=tasa_conversion*dinero;
    return (conversion1);
}
float conversionB (float dinero, float tasa_conversion)
{
    float conversion1;
    conversion1=tasa_conversion*dinero;
    return (conversion1);
}

