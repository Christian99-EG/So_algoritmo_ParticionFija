#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

struct Particion_fija
{
  int  Capacidad, Loc_inicial, Loc_final, Acceso, Edo, So;
  Particion_fija *sig;
};
Particion_fija *Ptr, *Qrry, *NuevoPtr, *Aux;

void crear_algoritmo(void);
void ejecutar_algoritmo(void);

void main(void)
{
 Ptr = NULL;
 Qrry = NULL;

crear_algoritmo();
ejecutar_algoritmo();
getch();
}

void crear_algoritmo(void)
{
  int Input_particion, memoria = 512,flag, So = 20, Input_bloques;
  int i = 0;
  int loc_inicial;
  int loc_final;


  printf("*********************************** \n");
  printf("*    ALGORITMO DE PARTICION FIJA  * \n");
  printf("*********************************** \n");

  printf("cuantos bloques de memoria necesita: ");
  scanf("\n %d", &Input_bloques);

  do
  {
    if(Ptr == NULL)
    {
      loc_inicial = 0;
      loc_final = 19;
      Ptr = (Particion_fija *)malloc(sizeof(Particion_fija));
      Ptr -> Capacidad = So;
      Ptr -> Loc_inicial = loc_inicial;
      Ptr -> Loc_final = loc_final;
      Ptr -> Acceso = 0;
      Ptr -> Edo = 0;

      Ptr -> sig = NULL;
      Qrry = Ptr;
    }
      else
      {
        NuevoPtr = (Particion_fija *)malloc(sizeof(Particion_fija));
        NuevoPtr -> Capacidad = 1 + rand()%10;
        loc_inicial = 19 + NuevoPtr->Loc_final+1;
        loc_final = (NuevoPtr->Loc_final + NuevoPtr-> Capacidad) - 1;
        NuevoPtr -> Loc_inicial = loc_inicial;
        NuevoPtr -> Loc_final = loc_final;
        NuevoPtr -> Acceso = 0;
        NuevoPtr -> Edo = 0;
        NuevoPtr -> sig = NULL;

        Qrry -> sig = NuevoPtr;
        Qrry = NuevoPtr;

      }
      i++;
  }while(i<=Input_bloques);


}//end function crear_algoritmo

void ejecutar_algoritmo(void)
{
  int i = 0;
  Aux = Ptr;
  printf("\n bloque \t  Capacidad \t  Localidad inicial \t  Localidad final  \t Acceso \t  Estado ");
    while(Aux != NULL)
    {
      i++;
      printf("\n %i   \t \t      %d  \t \t  %d       \t \t  %d      \t   %d      \t    %d ",i, Aux-> Capacidad, Aux->Loc_inicial, Aux->Loc_final, Aux->Acceso, Aux-> Edo);
      Aux = Aux->sig;
    }
}//end function ejecutar algoritmo
