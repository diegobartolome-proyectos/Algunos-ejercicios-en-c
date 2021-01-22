#include <stdio.h>
#include <math.h>

typedef struct
{
  float real;
  float imag;
} COMPLEJO;

void muestra_complejo(COMPLEJO);
COMPLEJO pide_complejo(void);
COMPLEJO suma_complejo(COMPLEJO, COMPLEJO, COMPLEJO);
COMPLEJO suma_vector_complejo(COMPLEJO [],int);
void multiplica_complejo(COMPLEJO, COMPLEJO, COMPLEJO *);
float modulo_complejo(COMPLEJO);
float argumento_complejo(COMPLEJO);

main()
{
  COMPLEJO uno, dos, tres, suma, multiplica, v[3];
  float modulo, argumento;

  printf("Dame 3 numeros complejos: \n\n");
  printf("Numero complejo uno: \n");
  uno=pide_complejo();
  printf("Numero complejo dos: \n");
  dos=pide_complejo();
  printf("Numero complejo tres: \n");
  tres=pide_complejo();

  suma=suma_complejo(uno, dos, tres);
  printf("\nLa suma de los tres numeros complejos es: ");
  muestra_complejo(suma);

  v[0]=uno; // Puedo copiar toda la variable en otra, directamente
  v[1]=dos;
  v[2]=tres;

  suma=suma_vector_complejo(v,3);
  printf("La suma de los tres numeros complejos como vector es: ");
  muestra_complejo(suma);

  multiplica_complejo(uno, dos, &multiplica);
  printf("La multiplicacion de los dos primeros numeros complejos es: ");
  muestra_complejo(multiplica);

  modulo=modulo_complejo(uno);
  argumento=argumento_complejo(uno);
  printf("El modulo del primer numero complejo es %g.\n", modulo);
  printf("El argumento del primer numero complejo es %g.\n", argumento);
}

void muestra_complejo(COMPLEJO complejo)
{
  printf("%g %+g i\n", complejo.real,complejo.imag); // %+g indica que siempre se muestra el signo (+ o -)
}

COMPLEJO pide_complejo(void)
{
  COMPLEJO aux;

  printf("Parte real: ");
  scanf("%f", &aux.real);
  printf("Parte imaginaria: ");
  scanf("%f", &aux.imag);

  return aux;
}

COMPLEJO suma_complejo(COMPLEJO uno, COMPLEJO dos, COMPLEJO tres) // Devuelvo un complejo
{
    COMPLEJO suma;
  suma.real=uno.real+dos.real+tres.real; // Debo operar campo a campo, ya que el ordenador no sabe sumar dos complejos
  suma.imag=uno.imag+dos.imag+tres.imag; // uno + dos estaría mal
  return suma;

}

COMPLEJO suma_vector_complejo(COMPLEJO v[], int n) // Devuelvo un complejo
{
    COMPLEJO suma={0,0}; // Inicializo los dos campos a 0, para ir acumulando la suma
    int i;
    for (i=0;i<n;i++)
        {suma.real += v[i].real; // Hago un sumatorio para la parte real y otro
        suma.imag += v[i].imag;} // para la parte imaginaria
  return suma;

}

void multiplica_complejo(COMPLEJO uno, COMPLEJO dos, COMPLEJO *p_multiplica) // Modifico un complejo accediendo al puntero
{
  (*p_multiplica).real=uno.real*dos.real-uno.imag*dos.imag;
  p_multiplica->imag=uno.real*dos.imag+dos.real*uno.imag; // De otra forma, con el operador ->

}

float modulo_complejo(COMPLEJO complejo)
{
  float modulo;
  modulo=sqrt(complejo.real*complejo.real+complejo.imag*complejo.imag);

  return(modulo);
}

float argumento_complejo(COMPLEJO complejo)
{
  float argumento, modulo;
  modulo = modulo_complejo(complejo); // Necesito el modulo, que me lo calcula la otra funcion
  argumento=acos(complejo.real/modulo);

  return (argumento);
}

