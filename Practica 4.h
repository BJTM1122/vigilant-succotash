#define Max 50

void Practica_4(void);

int elemm=0,belem=-1,c=0; 
struct ccircular
{
	char a[Max][50];	
	int f;
	int e;
};

typedef struct ccircular cola;

void cCola(cola *miCola)
{
	miCola->f=0;	
	miCola->e=0;
}

int cVacia(cola *miCola)
{
	if (miCola->e==0)
		return 1;
	return 0;
}

int cLlena(cola *miCola)
{
	if (miCola->e==Max)
		return 1;
	return 0;
}

int cUbicacion(cola *miCola)
{
	return (miCola->f+miCola->e)%Max;	
}

int cFrente(cola *miCola)
{
	return (miCola->f+1)%Max;
}

void push(cola *miCola,char a[])
{
	int ubicacion;
	ubicacion=cUbicacion(miCola);
	strcpy(miCola->a[ubicacion],a);
	miCola->e++;
	
}

char *pop(cola *miCola)
{
	char aux[50];
	
	strcpy(aux,miCola->a[miCola->f]);
	miCola->f=cFrente(miCola);
	miCola->e--;
	printf(" %s \n",aux);
	return aux;
}

void mostrarCola(cola *miCola)
{
	cola cAuxiliar;

	cAuxiliar=*miCola;
	if (cVacia(&cAuxiliar))
	{
		printf("Cola Vacia");
	}
	else
	{
		do
		{
			pop(&cAuxiliar);
		} while(!cVacia(&cAuxiliar));
	}
}

void ordenarCola(cola *miCola)
{
	int cantidad = miCola->e;
	int inicio = miCola->f;
	char temp[50];
	int i, j;
	for (i = inicio; i != (inicio+cantidad - 1); ++i)
	{
		for (j = i + 1; j != inicio+cantidad; ++j)
		{
			if (strcmp(miCola->a[i], miCola->a[j]) > 0)
			{
				strcpy(temp, miCola->a[i]);
				strcpy(miCola->a[i], miCola->a[j]);
				strcpy(miCola->a[j], temp);
			}
		}
	}
}


void Practica_4(void)
{
	cola miCola;
	int ch,x;
	char a[50];
	char *nRegreso;
	cCola(&miCola);
	
	while(1){
		printf("\n.....................\n");
		printf("[1] Insertar\n[2] Retirar\n[3] Mostrar Odenada\n[4] Salir o eligiendo 0 cuando se pida continuar\nOpcion:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			if (cLlena(&miCola))
			{
				printf("Cola llena :(");
			}
			else
			{
				system("cls");
				printf("Digite el nombre: ");
				scanf(" %[^\n]",a);
				push(&miCola,a);
				printf("Se ha insertado %s en la cola\n",a);
			}
			break;
		case 2:
			
			if (cVacia(&miCola))
				printf("Cola Vacia :(");
			else
			{
				system("cls");printf("Se elimino el elemento: ");
				nRegreso=pop(&miCola);
			}
			break;
		case 3:
			system("cls");
			if (cVacia(&miCola))
				printf("Cola Vacia :(");
			else
			{
				printf("Cola ordenada\n");ordenarCola(&miCola);
			    mostrarCola(&miCola);
			}
			break;
		}
		printf("\n Desea Continuar \n [1] SI [0] NO \n");
		scanf("%d",&x);system("cls");
		if(x==0)
			break;
	}
}
