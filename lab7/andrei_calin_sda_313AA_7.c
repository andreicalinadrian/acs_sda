#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int info;
    int urmator;
} LISTA;

#define DIM 20

void afis1(int cap,LISTA *vector)
{
    if(cap==-1)
    {
        printf("Nu exista nici un element!");
        return ;
    }
    else
    {
        int t;
        t=cap;
        while(t!=-1)
        {
            // printf("<%d>",vector[t].urmator);
            printf("<%d>",vector[t].info);
            t=vector[t].urmator;
        }
    }
}
void afis2(int cap,LISTA *vector)
{
    if(cap==-1)
    {
        printf("Nu exista nici un element!");
        return ;
    }
    else
    {
        int t;
        t=cap;
        while(t!=-1)
        {
            // printf("<%d>",vector[t].urmator);
            printf("<%d>",vector[t].urmator);
            t=vector[t].urmator;
        }
    }
}
void adaugare(int *lista,int *lista_el_libere,LISTA *vector,int x)
{
    int z,t;
    z=*lista_el_libere;
    t=*lista;
    if(*lista_el_libere==-1)
    {
        printf("Lista este plina!");
        return;
    }

    if(*lista_el_libere==0)
    {
        (*lista_el_libere)=vector[*lista_el_libere].urmator;
        vector[0].info=x;
        vector[0].urmator=(*lista);
        (*lista)=z;
    }
    else
    {
        while(t!=-1)
        {
            t=vector[t].urmator;
        }
        (*lista_el_libere)=vector[*lista_el_libere].urmator;
        vector[z].info=x;
        vector[z].urmator=(*lista);
        (*lista)=z;
    }

}

void stergere(int *lista,int *lista_el_libere,LISTA *vector)
{
    int z,t;
    z=*lista_el_libere;
    t=*lista;
    if(t==-1)
    {
        printf("Lista este goala!");
        return;
    }
    if(z==-1)
    {
        while(vector[vector[t].urmator].urmator!=-1)
        {
            t=vector[t].urmator;
        }
        *lista_el_libere=vector[t].urmator;
                vector[t].urmator=-1;
    }
   else if(z==vector[0].urmator)
    {
        int t;
        *lista=vector[t].urmator;
        vector[t].urmator=*lista_el_libere;
        *lista_el_libere=t;
    }
    else
    {
        while(vector[vector[t].urmator].urmator!=-1)
        {
            t=vector[t].urmator;
        }
        vector[t].urmator=z;
        *lista_el_libere=vector[t].urmator;
        vector[t].urmator=-1;
    }

}
int main()
{

    LISTA vector[DIM];
    int lista;
    int lista_el_libere;
    int k,x,l;
    lista=-1;
    lista_el_libere=0;
    for(k=0; k<DIM-1; k++)
    {
        vector[k].urmator=k+1;
    }
    vector[DIM-1].urmator=-1;
    printf("Cate elemente doriti sa adaugati(Maxim %d)",DIM);
    scanf("%d",&l);
    for(int i=0; i<l; i++)
    {
        printf("Elementul pe care doriti sa il adaugati este:");
        scanf("%d",&x);
        //ADAUGAREA UNUI ELEMENT LA SFARSITUL LISTEI PRINCIPALE
        adaugare(&lista,&lista_el_libere,vector,x);
    }
    //AFISAERE ELEMENTE LISTA LIBERA
    afis2(lista_el_libere,vector);
    printf("\n");
   //AFISARE LISTEI PRINCIPALE DUPA ADAUGARE
    afis1(lista,vector);
    printf("\n");
   //STERGEREA ULTIMULUI ELEMENT DIN LISTA PRINCIPALA
    stergere(&lista,&lista_el_libere,vector);
    //AFISARE LISTEI PRINCIPALE DUPA STERGEREA ULTIMULUI ELEMENT
    afis1(lista,vector);

    return 0;
}
