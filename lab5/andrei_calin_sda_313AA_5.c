#include<stdio.h>
#define N 10

typedef struct{
char vector[N];
int index_intrare;
int index_iesire;
char stare;
}coada;

void initializare(coada *c)
{
	c->index_intrare = 0;
	c->index_iesire = 0;
	c->stare = 'V';
}

int introducere(coada *c, char element)
{
	if (c->stare == 'P')
		return 0;
	c->vector[c->index_intrare] = element;
	c->index_intrare++;
	if (c->index_intrare == N)
		c->index_intrare = 0;
	if (c->index_iesire == c->index_intrare)
		c->stare = 'P';
	else
		c->stare = 'N';
	return 1;
}

int extragere(coada *c, char *adresa_var)
{
	if (c->stare == 'V')
		return 0;
	*adresa_var = c->vector[c->index_iesire];
	c->index_iesire++;
	if (c->index_iesire == N)
		c->index_iesire = 0;
	if (c->index_iesire == c->index_intrare)
		c->stare = 'V';
	else
		c->stare = 'N';
	return 1;
}

void afisare (coada *c)
{
	int i;
	printf ("Continutul cozii:");
	if (c->index_iesire >= c->index_intrare){
		for (i = c->index_iesire; i < N; i++)
			printf (" %c",c->vector[i]);
		for (i = 0; i < c->index_intrare; i++)
			printf (" %c",c->vector[i]);
	}
	else
		for (i = c->index_iesire; i < c->index_intrare; i++)
			printf (" %c",c->vector[i]);
	puts(" ");
}

int main(void)
{
	coada c;
	char var;
	initializare (&c);
	printf ("%d\n",extragere(&c,&var));
	introducere (&c,'a');
	introducere (&c,'n');
	introducere (&c,'a');
	introducere (&c,'!');
	afisare(&c);
	extragere (&c,&var);
	printf ("Variabila extrasa este: %c\n",var);
	afisare(&c);
	while (introducere(&c,'a') == 1); // Bucla se opreste cand nu se mai poate introduce niciun element in coada deoarece este plina
	printf("Starea cozii este: %c\n",c.stare);
	afisare(&c);
	if(extragere (&c,&var)){
		printf ("Variabila extrasa este: %c\n",var);
		afisare(&c);
	}
	while (extragere(&c,&var) == 1); // Bucla se opreste cand nu se mai poate extrage niciun element din coada deoarece este vida
	printf ("Ultima variabila extrasa este: %c\n",var);
	printf("Starea cozii este: %c\n",c.stare);
	if(extragere (&c,&var)){
		printf ("Variabila extrasa este: %c\n",var);
		afisare(&c);
	}
	scanf("%c",&var);
	return 0;	
}
