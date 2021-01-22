#include	<stdio.h>
#define	TAM_MAX	100
int	Pedir_Valor(int	*,	int	*,int);
void	pedir_datos(int	t,float	v[]);
int	lee_fichero(int	t1,	int	t2,	float	u[],float	v[]);
void	sumapoli(int	t1,	int	t2,	float	u[],	float	v[],	float	s[]);
void	menu(int	*	op);
main()
{
				int	tam1,tam2,tamsum;
				int	f,	opcion,i;
				if(Pedir_Valor(&tam1,&tam2,TAM_MAX))
				{
												float	u[tam1],v[tam2];//Se	reserva	en	ejecución
												if	(tam1>tam2)
																tamsum=tam1;
												else
																tamsum=tam2;
												float	polisum[tamsum];
												menu(&opcion);
												if(opcion==1	||	opcion==2)
												{
																if	(opcion==1)
																{
																				printf("Introduzca	los	valores	del	primer	polinomio.\n");
																				pedir_datos(tam1,u);
																				printf("Introduzca	los	valores	del	segundo	polinomio.\n");
																				pedir_datos(tam2,v);
																				f=1;
																}
																else
																{
																				f=lee_fichero(tam1,tam2,u,v);
																}
																if	(f!=0)
																{
																				sumapoli(tam1,tam2,u,v,polisum);
																				printf("El	vector	suma	es:	\n");
																				for	(i=tamsum-1;i>=0;i--)
																				{



																								printf("%1.1f	",polisum[i]);
																				}
																				printf("\n");
																}
																else
																				printf("Error	al	acceder	al	fichero.\n");
												}
												else	if	(opcion!=3)
																printf("Opcion	no	válida.\n");
				}
				else
								printf("Grado	de	algun	polinomio	no	valido.\n");
}
int	Pedir_Valor(int	*t1,	int	*t2,	int	max)
{
				printf("Grado	del	primer	polinomio	(<	%d):	",max);
				scanf("%d",t1);
				*t1=*t1+1;
				printf("Grado	del	primer	polinomio	(<	%d):	",max);
				scanf("%d",t2);
				*t2=*t2+1;
				if	(*t1>max	||	*t1<0	||	*t2>max	||	*t2<0)
								return	0;
				else
								return	1;
}
void	pedir_datos(int	t,float	v[])
{
				int	i;
				for	(i=0;i<t;i++)
				{
								printf("Elemento	de	grado	%d	del	polinomio:",i);
								scanf("%f",&v[i]);
				}
}
int	lee_fichero(int	t1,	int	t2,	float	u[],float	v[])
{
				FILE	*fp;
				int	i;
				fp=fopen("datos.txt","r");


				if	(fp==NULL)
				{
								fclose(fp);
								return	0;
				}
				else
				{
								for	(i=0;i<t1;i++)
								{
												fscanf(fp,"%f",&u[i]);
								}
								for	(i=0;i<t2;i++)
								{
												fscanf(fp,"%f",&v[i]);
								}
								fclose(fp);
								return	1;
				}
}
void	sumapoli(int	t1,	int	t2,	float	u[],	float	v[],	float	s[])
{
				int	i;
				if	(t1<t2)
				{
								for(i=0;i<t1;i++)
								{
												s[i]=u[i]+v[i];
								}
								for(i=t1;i<t2;i++)
								{
												s[i]=v[i];
								}
				}
				else
				{
								for(i=0;i<t2;i++)
								{
												s[i]=u[i]+v[i];
								}
								for(i=t2;i<t1;i++)
								{
												s[i]=u[i];
								}
				}



}
void	menu(int	*	op)
{
				printf("Elija	una	opcion:\n");
				printf("1.- Leer	datos	por	teclado.\n");
				printf("2.- Leer	datos	de	fichero	datos.txt	.\n");
				printf("3.- Salir\n");
				scanf("%d",op);
}
