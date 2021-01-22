#include <stdio.h>
#define TAM_MAX 100
int Pedir_Fil_Col(int *,int *,int);
void Pedir_Datos_Matriz(int,int,float m1[*][*]);
void Pedir_Datos_Vector(int ,float vector[]);
void Producto_Matriz_Vector(int , int , float m1[*][*],float v[],float res[]);
void Guarda_Vector(char nombre[80] ,int ,float v[]);


void Muestra_Matriz(int,float []);
main()
{
 int fil,col,dim,seguir;
 do
 {
 if(Pedir_Fil_Col(&fil,&col,TAM_MAX))
 {
     dim=col;
 float m1[fil][col],vector[dim], res[dim];
  Pedir_Datos_Matriz( fil ,col,m1 );
  Pedir_Datos_Vector(dim, vector);
 Producto_Matriz_Vector(fil,col, m1,vector,res);
 Guarda_Vector("vector.txt",dim, res);


  Muestra_Matriz(dim,res);


 }
 else
 printf("Las dimensiones de la matriz no son validas\n");
 printf("Si desea continuar pulse 1:");
 scanf("%d",&seguir);
 }
 while(seguir==1);
}
int Pedir_Fil_Col(int *fil,int *col,int valor_max)
{
    int i=1;
    printf("introducir tamaño de las filas: ");
    scanf("%d",*&fil);
    printf("introducir tamaño de las columnas: ");
    scanf("%d",*&col);
    if(fil<valor_max)
    {
        i=0;
        if(col<valor_max)
            {
                i=0;
            }
    }

    return i;


}

void Pedir_Datos_Matriz( int fil, int col, float m1[fil][col])
{
    printf("introduce los valores de la primera matriz:\n");
      int i,j;
         for (i=0;i<fil;i++)
         {
                 for (j=0;j<col;j++)
                 {
                     printf("Fila:%d Columna:%d valor: ", i + 1, j + 1);
                     scanf("%f",&m1[i][j]);
                 }
         }
}
void Pedir_Datos_Vector(int dim,float vector[])
{
    printf("introducir vector:\n");
    int i;
    for(i=0;i<dim;i++)
    {
        printf("Fila:%d  valor: ", i + 1);
        scanf("%f",&vector[i] );
    }
}
void Producto_Matriz_Vector(int fil, int col, float m1[fil][col], float vector[col],float res[col])
{
    int i,j;
    for(i=0;i<fil;i++)
    {
        res[i]=0;
    }
    for(j=0;j<col;j++)
    {
        for(i=0;i<fil;i++)
        {
            res[j]+=vector[i]*m1[i][j];
        }
    }
}


void Muestra_Matriz(int dim ,float res[dim])
{
    int i;
 for(i=0;i<dim;i++)
 {

 printf("%f ",res[i]);

 }

}
void Guarda_Vector(char nombre[80],int dim,float res[dim])
{
    FILE *fp;
    fp=fopen("vector.txt", "w");
    if(fp==NULL)
    {
        return 1;
    }
    int i;
    fprintf(fp,"el vector resultado es: ");
    for(i=0;i<dim;i++)
    {
        fprintf(fp,"%f",res[i]);
    }
}


