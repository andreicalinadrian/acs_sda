#include <stdio.h>
#include<stdlib.h>


#define N 3

int m[N][N];
int M[N][N];
int nr_apeluri;
int nr_solutii;
int nr_apeluri_opt;
int nr_solutii_opt;
FILE* f;
FILE* g;

void completeaza(int i, int j)
{
    int x, y, z, ii, jj;

    nr_apeluri++;

    // Testeaza daca s-a completat matricea
    if (i == N) {
        // Testeaza daca s-a obtinut o solutie corecta

        // Test pe linii
        for (y = 0; y < N; y++)
            for (x = 0; x < N - 1; x++)
                for (z = x + 1; z < N; z++)
                    if (m[y][x] == m[y][z])
                        return;

        // Test pe coloane
        for (x = 0; x < N; x++)
            for (y = 0; y < N - 1; y++)
                for (z = y + 1; z < N; z++)
                    if (m[y][x] == m[z][x])
                        return;

        // Solutie este corecta - scrie in fisier
        fprintf(f, "Solutia %d\n", ++nr_solutii);
        for (y = 0; y < N; y++) {
            fprintf(f, "\t");
            for (x = 0; x < N; x++)
                fprintf(f, "%3d", m[y][x]);
            fprintf(f, "\n");
        }
        fprintf(f, "\n");
        return;
    }

    // Determina elementul urmator in matrice
    jj = j + 1;
    if (jj == N) {
        jj = 0;
        ii = i + 1;
    }
    else
        ii = i;

    // Completeaza elementul curent cu toate valorile posibile si
        // apeleaza recursiv procedura de completare pentru finalizarea matricii
        for (z = 0; z < N; z++) {
            m[i][j] = z;
            completeaza(ii, jj);
        }
}

void completeaza_opt(int i, int j)
{
    int x, y, z, ii, jj;

    nr_apeluri_opt++;

    // Testeaza daca s-a completat matricea
    if (i == N)
    {
        // Solutie este corecta - scrie in fisier
        fprintf(g, "Solutia %d\n", ++nr_solutii_opt);
        for (y = 0; y < N; y++) {
            fprintf(g, "\t");
            for (x = 0; x < N; x++)
                fprintf(g, "%3d", M[y][x]);
            fprintf(g, "\n");
        }
        fprintf(g, "\n");
        return;
    }

    // Determina elementul urmator in matrice
    jj = j + 1;
    if (jj == N) {
        jj = 0;
        ii = i + 1;
    }
    else
        ii = i;

    //Face un vector de frecventa:
    // daca pe pozitia i este 0, inseamna ca numarul i poate fi folosit in casuta curenta a matricii;
    // daca pe pozitia i este 1, inseamna ca numarul i nu poate fi folosit in casuta curenta a matricii;
    int* vectorFrecv = calloc(N, sizeof(int));

    //Verifica linia
    for (x = 0; x < j; x++)
        vectorFrecv[M[i][x]] = 1;

    //Verifica coloana
    for (y = 0; y < i; y++)
        vectorFrecv[M[y][j]] = 1;

    //Parcurge vectorul de frecventa si pune elementul in casuta (si apeleaza recursiv functia) doar daca,
    // in vectorul de frecventa, pe pozitia elementului, se afla valoarea 0
    for (z = 0; z < N; z++)
    {
        if (vectorFrecv[z] == 0)
        {
            M[i][j] = z;
            completeaza_opt(ii, jj);
        }
    }

    free(vectorFrecv);
}

void main(void)
{
    f = fopen("solutii.txt", "w");
    g = fopen("solutii_opt.txt", "w");

    nr_apeluri = 0;
    nr_solutii = 0;

    completeaza(0, 0);
    completeaza_opt(0, 0);

    printf("Numar de solutii gasite pentru versiunea neoptimizata: %d\n", nr_solutii);
    printf("Numar de apeluri recursive pentru versiunea neoptimizata: %d\n", nr_apeluri);
    printf("Numar de solutii gasite pentru versiunea optimizata: %d\n", nr_solutii_opt);
    printf("Numar de apeluri recursive pentru versiunea optimizata: %d\n", nr_apeluri_opt);

    fclose(f);
    fclose(g);

    //Numarul de apelari este mult mai mic la versiunea optimizata a algoritmului decat la cea neoptimizata.

    //Fisierul de iesire la versiunea optimizata a algoritmului este identic cu fisierul de iesire al algoritmului neoptimizat.
}
