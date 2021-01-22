#include <stdio.h>
#define TAM_MAX 100
int Pedir_Fil_Col(int *, int *, int);
void Pedir_Datos_Matriz(int, int, float m1[*][*]);
void Suma(int, int, float m1[*][*], float m2[*][*], float suma[*][*]);
void Muestra_Matriz(int, int, float[*][*]);
main()
{
    int fil, col, seguir;
    do
    {
        if (Pedir_Fil_Col(&fil, &col, TAM_MAX))
        {
            float m1[fil][col], m2[fil][col], suma[fil][col];
            Pedir_Datos_Matriz(fil, col, m1);
            Suma(fil, col, m1, m2, suma);
            Muestra_Matriz(fil, col, suma);
        }
        else
            printf("Las dimensiones de la matriz no son v�lidas\n");
        printf("Si desea continuar pulse 1:");
        scanf("%d", &seguir);
    } while (seguir == 1);
}
int Pedir_Fil_Col(int *fil, int *col, int valor_max)
{
    int i = 1;
    printf("introducir tamaño de las filas :");
    scanf("%d", *&fil);
    printf("introducir tamaño de las columnas :");
    scanf("%d", *&col);
    if (fil < valor_max)
    {
        i = 0;
        if (col < valor_max)
        {
            i = 0;
        }
    }

    return i;
}

void Pedir_Datos_Matriz(int fil, int col, float m1[fil][col])
{
    printf("introduce los valores de la primera matriz:\n");
    int i, j;
    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Fila:%d Columna:%d valor: ", i + 1, j + 1);
            scanf("%f", &m1[i][j]);
        }
    }
}

void Suma(int fil, int col, float m1[fil][col], float m2[fil][col], float suma[fil][col])
{
    printf("introduce los valores de la segunda matriz:\n");
    int i, j;
    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Fila:%d Columna:%d valor: ", i + 1, j + 1);
            scanf("%f", &m2[i][j]);
        }
    }
    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
        {

            suma[i][j] = 0;
        }
    }
    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
        {

            suma[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void Muestra_Matriz(int fil, int col, float suma[fil][col])
{
    int i, j;
    for (i = 0; i < fil; i++)
    {
        for (j = 0; j < col; j++)
            printf("%f ", suma[i][j]);
        printf("\n");
    }
}