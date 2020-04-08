#include <stdio.h>

#define TAMPILA 10

typedef struct pila{
   int dato;
   int anterior;
}Pila;

void push(int);
int pop(void);
void muestraPila(void);

Pila p1[TAMPILA];

int tope = -1;

int main() {

    int opc = 0, val = 0;

    do {
       system("clear");
       printf("\n1. Introducir Elemento.\n");
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
               push(val);
               break;
          case 2:
               system("clear");
               val = pop();
               if(val == -1)
                printf("Pila vacia");
               else
                printf("Se extrajo: %d",val);
               break;
          case 3:
               system("clear");
               printf("El tope es: %d",tope);
               break;
          case 4:
               system("clear");
               muestraPila();
               system("sleep 5");
               break;
          case 5:
               break;
          default:
               system("clear");
               printf("Opcion no valida!");
               break;
       }
    }while(opc != 5);
    return 0;
}

void push(int v) {
   Pila nuevo;
   nuevo.dato = v;

  if(tope == TAMPILA-1) {
      printf("Pila Llena\n");  
      system("sleep 2"); 
    }
  else {
      if(tope == -1) {
         tope = 0;
         nuevo.anterior = -1;
      }
      else {
         nuevo.anterior = tope;
         tope++;
      }
      p1[tope] = nuevo;
  }
}

int pop(void) {
   Pila aux;
   int v;
   if(tope == -1) {
      return -1;
   }
   else {
      aux = p1[tope];
      p1[tope].dato = 0;
      p1[tope].anterior = -1;
      tope--;
      v = aux.dato;
      return v;
   }
}

void muestraPila(void) {
  int i=0;
   for(i = tope;i>=0;i--) 
         printf("%d\n",p1[i].dato);
}
