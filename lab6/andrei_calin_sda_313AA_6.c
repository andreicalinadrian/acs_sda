#include <stdio.h>
#include <stdlib.h>

typedef struct str_element
{
    int info;
    struct str_element *urmator;
} element;
element *lista;

void afisare_lista()
{
    element *p;
    if(lista==NULL)
    {
        printf("Lista este vida\n");
        return;
    }
    printf("Lista: ");
    p=lista;
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->urmator;
    }
}

void adauga_in_ordine(int x)
{
    element *p, *q;
    p=lista;
    if (lista == NULL)
    {
        lista=(element*)malloc(sizeof(element));
        lista->info = x;
        lista->urmator = NULL;
        return;
    }

    if(p->info >= x)
    {
        q=(element*)malloc(sizeof(element));
        q->urmator=p;
        q->info=x;
        lista=q;
        return;
    }

    while(p->urmator!=NULL)
    {
        if(p->urmator->info >= x)
        {
            q=(element*)malloc(sizeof(element));
            q->urmator=p->urmator;
            q->info=x;
            p->urmator=q;
            return;
        }
        p=p->urmator;
    }

    q=(element*)malloc(sizeof(element));
        if(p->info >= x)
        {
            q->urmator=p->urmator;
            q->info=x;
            p->urmator=q;
        }
        else
        {
            p->urmator=q;
            q->info=x;
            q->urmator=NULL;
        }
}

void main()
{
    int i,n,x;
    printf("Introduceti numarul de elem: ");
    scanf("%d",&n);
    for ( i=0;i<n;i++)
    {
        printf("\tValoare element %2d: ",i);
        scanf("%d",&x);
        adauga_in_ordine(x);
        afisare_lista();
    }
}
