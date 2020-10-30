#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m;
    printf("Introduceti numarul de linii n si coloane m: ");
    scanf("%d%d",&n,&m);
    int *a;
//varianta 1
    a = calloc(n*m , sizeof(int) );
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            *(a+i*m+j)=i*m+j;
        }

    }
/*verificare continut
   printf("\n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            printf("%d ",*(a+i*m+j));
        }
        printf("\n");
    }
*/
//varianta 2

    int **b;
    b = calloc( n , sizeof(int*) );
    for (int i=0;i<n;i++)
    {
        *(b+i) = calloc ( m , sizeof(int) );
        for (int j=0;j<m;j++)
        {
            *(*(b+i)+j) = i*m+j;
        }
    }
/*verificare continut
    printf("\n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            printf("%d",*(*(b+i)+j));
        }
        printf("\n");
    }
*/

//test final

    int x,y;
    printf("Introduceti coordonatele x si y: ");
    scanf("%d%d",&x,&y);
    printf("Rezultatul dat de matricea A este: %d\n",*(a+(x-1)*m+y-1));
    printf("Rezultatul dat de matricea B este: %d",*(*(b+x-1)+y-1));

    return 0;

}
