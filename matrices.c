#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//#include <omp.h>

#define MAX_MATRICES 6
#define EPS 1e-9

typedef struct {
    int rows;
    int columns;
    int** data;
}Matrix;

Matrix* new_matrix(int rows, int columns){

    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    if (!matrix){
        printf("Blad przy alokacji pamieci. Koniec programu");
        exit(1);
    }

    matrix->rows = rows;
    matrix->columns = columns;

     //alokacja miejsca na wiersze
    matrix->data = malloc(rows * sizeof(int*));
    if (!matrix->data){
        printf("Blad w alokacji pamieci dla wskaznikow wierszy. Koniec programu");
        free(matrix);
        exit(1);
    }
    //alokacja miejsca na kolumny
    for (int i = 0; i < rows; i++){
        matrix->data[i] = malloc(columns * sizeof(int));
        if(!matrix->data[i]){
            printf("Blad w alokacji pamieci dla kolumn. Koniec programu");
            for(int j = 0; j < i; j++){
            free(matrix->data[j]);
            }
            free(matrix->data);
            free(matrix);
            exit(1);
        }
    }


return matrix;
}

void rand_matrix(Matrix* M){
    srand(time(NULL));
    for(int i = 0; i < M->rows; i++){
        for(int j = 0; j < M->columns; j++){
            M->data[i][j] = rand() % 9 + 1;
        }
    }
}

void fill_matrix(Matrix* M){
    int x = 0;
    printf("Podaj elementy dla macierzy A\n");
    for (int i = 0; i < M->rows; i++){
        for (int j = 0; j < M->columns; j++){
            printf("a%d%d: ", i + 1, j + 1);
            scanf("%d",&x);
            M->data[i][j] = x;
        }
    }
}

void print_matrix(Matrix* M){
    for (int i = 0; i < M->rows; i++){
        for (int j = 0; j < M->columns; j++){
            printf("%d ", M->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* addition(Matrix* tab[],int ind_1, int ind_2){

    if(tab[ind_1]->rows != tab[ind_1]->rows || tab[ind_2]->columns != tab[ind_2]->columns){
        printf("Macierze maja rozne rozmiary. Koniec programu.");
        return NULL;
    }

    Matrix* sum = new_matrix(tab[ind_1]->rows, tab[ind_2]->columns);

    for (int i = 0; i < tab[ind_1]->rows; i++){
            for (int j = 0; j < tab[ind_1]->columns; j++){
                sum->data[i][j] = tab[ind_1]->data[i][j] + tab[ind_2]->data[i][j];
            }
        }

    return sum;
}


Matrix* multiplication(Matrix* tab[], int ind_1, int ind_2){

    if(tab[ind_1]->rows != tab[ind_2]->columns){
        printf("Macierze nie spelniaja warunkow mnozenia macierzy. Koniec programu");
        return NULL;
    }
    Matrix* product = new_matrix(tab[ind_1]->rows, tab[ind_2]->columns);
    if (!product){
        printf("Blad w alokacji pamieci. Koniec programu");
        exit(1);
    }

    //n- liczba mnozen dla poszczegolnego elementu, rowna liczbie kolumn pierwszej macierzy lub liczbie wierszy drugiej macierzy
    int n = tab[ind_1]->columns;

    //#pragma omp parallel for num_threads(16)

    for(int i = 0; i < tab[ind_1]->rows; i++){
        for(int j = 0; j < tab[ind_2]->columns; j++){
            product->data[i][j] = 0;
            for(int k = 0; k < n; k++){
            product->data[i][j] += (tab[ind_1]->data[i][k]) * (tab[ind_2]->data[k][j]);
            }
        }
    }

    return product;
}



void free_matrix(Matrix* M) {
    if (M) {
        for (int i = 0; i < M->rows; i++) {
            free(M->data[i]);
        }
        free(M->data);
        free(M);
    }
}

void rows_columns(int*,int*);

void identity_matrix(Matrix* M){

    int choice, s;

     if(M->rows != M->columns){
        printf("Macierz nie jest kwadratowa. Koniec programu");
        exit(1);
    }

    printf("Macierz jednostkowa - 1, wielokrotnosc macierzy jednostkowej - 2\n");
    scanf("%d", &choice);

    switch(choice){
        case (1):{
            s = 1;
            break;
        };
        case (2):{
            printf("Podaj skalar: ");
            scanf("%d",&s);
            break;
        };
        default:{
            printf("Nie poprawny wybor. Koniec programu");
            exit(1);
        };
    }


    for(int i = 0; i < M->rows; i++){
        for(int j = 0; j < M->columns; j++){
            M->data[i][j] = 0;
            if(i == j) M->data[i][j] = s;
        }
    }
}

void Gaussian_elimination(Matrix* M){

}
int main()
{
    Matrix* tab[MAX_MATRICES];
    int rows = 24;
    int columns =24;
    int* p_rows = &rows;
    int* p_columns = &columns;

    rows_columns(p_rows, p_columns);
    tab[0] = new_matrix(rows, columns);
    //fill_matrix(tab[1]);
    rand_matrix(tab[0]);
    print_matrix(tab[0]);
    printf("\n");
    printf("\n");

    tab[1] = new_matrix(columns, rows);
    rand_matrix(tab[1]);
    print_matrix(tab[1]);
    printf("\n");
    printf("\n");

    tab[2] = multiplication(tab, 0, 1);
    print_matrix(tab[2]);
    printf("\n");

    /*
    rows_columns(p_rows, p_columns);
    tab[3] = new_matrix(rows, columns);
    fill_matrix(tab[3]);
    print_matrix(tab[3]);
    printf("\n");

    tab[4] =  addition(tab, 2, 3);

    print_matrix(tab[4]);
    printf("\n");





    free(tab[0]);
    free(tab[1]);
    free(tab[2]);
    free(tab[3]);
    free(tab[4]);
/*
    rows_columns(&rows,&columns);
    tab[1] = new_matrix(rows,columns);
    fill_matrix(tab[1]);
    print_matrix(tab[1]);

    rows_columns(&rows,&columns);
    tab[2] = new_matrix(rows, columns);
    fill_matrix(tab[2]);
    print_matrix(tab[2]);

    tab[3] = multiplication(tab,1,2);
    print_matrix(tab[3]);

    free_matrix(tab[1]);
    free_matrix(tab[2]);
    free_matrix(tab[3]);
    */
    /*
    rows_columns(p_rows, p_columns);
    tab[4] = new_matrix(rows, columns);
    identity_matrix(tab[4]);
    print_matrix(tab[4]);


    int ind_1, ind_2;
    printf("Podaj numer macierzy:\n");
    scanf("%d %d", &ind_1, &ind_2);

    tab[1] = new_matrix(tab[4]->rows, tab[4]->columns);
    fill_matrix(tab[1]);
    tab[2] = addition(tab, ind_1, ind_2);
    print_matrix(tab[2]);
    free_matrix(tab[2]);
    free_matrix(tab[1]);
    free_matrix(tab[4]);
    */
/*
    int n = -1;

    rows_columns(p_rows, p_columns);
    tab[0] = new_matrix(rows,columns);
    fill_matrix(tab[0]);

    rows_columns(p_rows, p_columns);
    tab[1] = new_matrix(rows,columns);
    fill_matrix(tab[1]);

    print_matrix(tab[0]);
    printf("\n");
    print_matrix(tab[1]);
    printf("\n");

    if(addition(tab) == NULL){
        exit(1);
    }
    else {
    tab[2] = addition(tab);

    print_matrix(tab[2]);
    printf("\n");
    free_matrix(tab[2]);
    }



    free_matrix(tab[0]);
    free_matrix(tab[1]);
*/


    return 0;
}

//= ((tab[ind_1]->data[i][n-2]) * (tab[ind_2]->data[n-2][j])) + ((tab[ind_1]->data[i][n-1]) * (tab[ind_2]->data[n-1][j])) + ((tab[ind_1]->data[i][n]) * (tab[ind_2]->data[n][j]))

void rows_columns(int* p_rows, int* p_columns){
    printf("Podaj ilosc wierszy i kolumn dla macierzy:\n");
    scanf("%d %d", p_rows, p_columns);
}
