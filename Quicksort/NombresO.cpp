/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 6396                                                       *
* AUTOR: Chicaiza Jaya Cristopher Jennsy                          *
* VERSION DEL PROGRAMA: 1.0                                       *
******************************************************************/
#include <stdio.h>
#include <string.h>
//void quicksort(char ,int , int );

void quicksort(char nombre[15][15],int izquierda,int derecha)
{
 int i,j;
 char y[15],*x;

 i=izquierda;
 j=derecha;
 x=nombre[(izquierda+derecha)/2];
 do{
 while((strcmp(nombre[i],x)<0) && (i<derecha)) i++; 
 while((strcmp(nombre[j],x)>0) && (j>izquierda)) j--;
 if(i<=j)
{
 strcpy(y,nombre[i]);
 strcpy(nombre[i],nombre[j]);
 strcpy(nombre[j],y);
 i++;
 j--;
 }
 }while(i<=j);

 if(izquierda<j) quicksort(nombre,izquierda,j);
 if(i<derecha) quicksort(nombre,i,derecha);
}

int main()
{
 char nombre[15][15];
 int n,i,izquierda,derecha,respuesta;

 do{
 printf("Introduce el numero de nombres que desea ordenar alfabeticamente:\n ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("Introduzca el nombre de la persona %d: ",i+1);
 scanf("%s",nombre[i]);
 }
 izquierda=0;
 derecha=n-1;
 quicksort(nombre,izquierda,derecha);
 printf("Los nombres en orden alfabetico:\n");
 for(i=0;i<n;i++)
 printf("\n %d.-%s",i+1,nombre[i]);


 printf("\n�Desea volver a ordenar otros nombres alfabeticamente?(si-pulse 1, no-pulse otra tecla)\n");
 scanf("%d",&respuesta);
 }while(respuesta==1);

 return 0;
}
