#include<stdio.h>
#include<stdlib.h>
#define max 100
#include<Windows.h>

int elem=0,belem=-1,c=0; 
struct ccircular{
	int a;
};

void push(struct ccircular *aux,int x,int num)
{
	if(c==num)
	{
		printf("COLA LLENA jajaja XD\n"); return;
	}
	belem++; 
	belem=belem%num;
	if(c!=num)
		c++;
	(aux+belem)->a=x;
}

int pop(struct ccircular *aux,int num)
{
	if(c==0)
	{
		printf("COLA LLENA jajaja XD\n"); return 0;
	}
	c--; 
	elem=elem%num;
	int x=(aux+elem)->a;
	printf("\nElemento eliminado: [%d]\n",x);elem++;
}

void muestracolajeje(struct ccircular *aux,int num)
{	
	if(c==0)
	{
	printf("La cola esta Vacia\n"); return; 
	}
	int i=elem,j=0;
	if(elem>belem)
	for(i=elem; i<num; i++)
	{
		printf("[%d]",(aux+i)->a); j++;
		
	}
	else
		for(i=elem; i<=belem; i++)
		{
		printf("[%d]",(aux+i)->a); j++;
		}
		if(j!=c)
			{
				for(i=0; i<c-j; i++)
				{
					printf("[%d]",(aux+i)->a);
				}
			}
		printf("\n");
}

void eliminarcola(struct ccircular *aux,int num)
{	
	if(c==0)
	{
	printf("La cola esta Vacia\n"); return; 
	}
	int i=elem,j=0;
	if(elem>belem)
	for(i=elem; i<num; i++)
	{
		pop(aux,num);
	}
	else
		for(i=elem; i<=belem; i++)
		{
		}
		if(j!=c)
			{
				for(i=0; i<c-j; i++)
				{	
				pop(aux,num);	
				}
			}
}


int main()
{
	struct ccircular *aux;
	int x,num,p,ch;
	printf("De que tamaño quiere la cola\n");
	scanf("%d",&num);system("cls");
	aux=(struct ccircular *)malloc(num*(sizeof(struct ccircular)));
	while (1)
	{
		printf("MENU\n 1.-Insertar \n 2.-Eliminar \n 3.-Mostrar \n 4.-Eliminar toda la cola \n 5.-Salir \n");
		scanf("%d",&ch);system("cls");
	switch(ch)
	{
	case 1:
		printf("Ingrese elemento\n");
		scanf("%d",&x);
		push(aux,x,num);
		printf("Regresando en un segundo\n");Sleep(1000);
		break;
	case 2: 
		pop(aux,num);
		printf("Regresando en 2 segundos\n");Sleep(2000);
		break;
	case 3:
		muestracolajeje(aux,num);
		printf("Regresando en un segundo\n");Sleep(1000);
		break;
	case 4:
		while(c!=0){
			eliminarcola(aux,num);	
		}
		break;
	case 5:
		break;
	}
	printf("\n Desea Continuar \n [1] SI [0] NO \n");
	scanf("%d",&x);system("cls");
	if(x==0)
		break;
	}
}
