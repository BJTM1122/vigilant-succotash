#include <stdio.h>

typedef struct pila {
   int dato;
   struct pila *ant;
} Pila;

void push(int,Pila **);
int pop(Pila **);
int muestraTope(Pila **);
void muestraPila(Pila **);

Pila *tope = NULL;
Pila *tope2 = NULL;

int main() {
    Pila *p1 = NULL, *p2 = NULL;
    int opc = 0, val = 0;

    do {
       system("clear");
       printf("1. Introducir Elemento.\n");
       printf("2. Sacar elemento.\n");
       printf("3. Mostrar tope.\n");
       printf("4. Mostrar pila.\n");
       printf("5. Salir\n");
       printf("Opcion:\t");
       scanf("%d",&opc);
       switch(opc) {
          case 1:
               system("clear");
               printf("Valor a introducir:");
               scanf("%d",&val);
               push(val,&p1);
               break;
          case 2:
               system("clear");
               val = pop(&p1);
               if(val>0) printf("Se extrajo: %d",val);
               system("sleep 5");
               break;
          case 3:
               system("clear");
               printf("El tope es: %d",muestraTope(&p1));
               system("sleep 5");
               break;
          case 4:
               system("clear");
               muestraPila(&p1);
               system("sleep 5");
               break;
          case 5:
               break;
          default:
               system("clear");
               printf("Opcion no valida!");
               system("sleep 5");
               break;
       }
    }while(opc != 5);
    return 0;
}

void push(int v, Pila *p) {
   Pila *nuevo;
   nuevo = (Pila*)malloc(sizeof(Pila));

   if(*p == NULL) {
      nuevo->dato = v;
      nuevo->ant = NULL;
      *p = nuevo;
      tope = *p;
   }
   else {
      nuevo->ant = *p;
      nuevo->dato = v;
      *p = nuevo;
      tope = *p;
   }
}

int pop(Pila **p) {
   Pila *tmp;
   int v;
   
   if(*p == NULL) {
      printf("Pila vacia.\n");
      return -1;
   }
   else {
      tmp = *p;
      v = tmp->dato;
      *p = tmp->ant;
      tope = *p;
      free(tmp);
      return v;
   }
}

int muestraTope(Pila **p) {
   return tope->dato;
}

void muestraPila(Pila **p) {
   Pila *tmp;
   tmp = *p;
   while(tmp != NULL) {
      printf("%d\n",tmp->dato);
      tmp = tmp->ant;
   }
}
