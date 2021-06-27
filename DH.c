#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265
#define N 4

int elos;
int i, j, k;
float DH[4][4], current[4][4], next[4][4], current2[4][4];
float toDegree = PI/180; // to convert radian to degree
float res[4][4];
float matAtual[4][4];


void multiply(float mat1[][N][N], float res[][N], float matAtual[][N], int elos){ //mat1 its our vector of matrices

    int i, j, k, x;

    for(x = 0; x < elos; x++) {

        if(x == 0){ // if x = 0, matAtual its the indentity matrix
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++){
                    if(j == k)
                        matAtual[j][k] = 1;
                    else
                        matAtual[j][k] = 0;   
                }
            }
        }

        for (i = 0; i < 4; i++) { //multiplying matrices  matAutal x mat1 (the x matrix)
            for (j = 0; j < 4; j++) {
                res[i][j] = 0;
                for (k = 0; k < 4; k++)
                    res[i][j] += matAtual[i][k] * mat1[x][k][j];
            }
        }
        
        for (j = 0; j < 4; j++) {  // matAtual is now the new current multiplied matrix
            for (k = 0; k < 4; k++){
                matAtual[j][k] = res[j][k];
            }    
        }
   
    }


    for(i = 0; i < 4; i++){ // printing the final matAtual, wich is the final result
        printf("                     ");
        for(j = 0; j < 4; j++){
            if(matAtual[i][j] >= 0)
                printf("   %.3f", matAtual[i][j]);

            else if(matAtual[i][j] < 0)
                printf("  %.3f", matAtual[i][j]);

        }
        printf("\n\n");    
    }        

}


void pInitialData(int elos, int table[][4]){ 

    printf("<----------------------------INITIAL-DATA------------------------------->\n\n\n");

    for(i = 0; i < 4; i++){
        if(i == 0)
            printf("                            Teta: ");

        else if(i == 1)
            printf("                            Alfa: ");

        else if(i == 2)
            printf("\n                            D:    ");

        else if(i == 3)
            printf("                            A:    ");        

        for(j = 0; j < elos; j++){
            printf(" %d", table[j][i]);
        }
        printf("\n");
    }

    printf("\n\n");
}



int main(){
    printf("\n\nDigite o numero de elos: ");
    scanf("%d", &elos);

    int table[elos][4];

    float answer[elos][4][4];

    int teta[elos], alfa[elos], D[elos], A[elos];

    printf("\n");

    for(i = 0; i <elos; i++){
        printf("Teta %d: ", i+1);
        scanf("%d", &table[i][0]);
        teta[i] = table[i][0];
    }

    printf("\n");

    for(i = 0; i <elos; i++){
        printf("Alfa %d: ", i+1);
        scanf("%d", &table[i][1]);
        alfa[i] = table[i][1];
    }

    printf("\n");

    for(i = 0; i <elos; i++){
        printf("D %d: ", i+1);
        scanf("%d", &table[i][2]);
        D[i] = table[i][2];
    }

    printf("\n");

    for(i = 0; i <elos; i++){
        printf("A %d: ", i+1);
        scanf("%d", &table[i][3]);
        A[i] = table[i][3];
    }

    printf("\n\n\n");

    pInitialData(elos, table);

    printf("<-------------------------MATRIX-DH-FORMAT-iN-DEGRES--------------------->\n\n\n");

    for(i = 0; i < elos; i++){ //------------------MAKING THE DH MATRICES------------------

        DH[0][0] = cos(teta[i]*toDegree);
        DH[0][1] = -sin(teta[i]*toDegree)*cos(alfa[i]*toDegree);
        DH[0][2] = sin(teta[i]*toDegree)*sin(alfa[i]*toDegree);
        DH[0][3] = A[i]*cos(teta[i]*toDegree);

        DH[1][0] = sin(teta[i]*toDegree);
        DH[1][1] = cos(teta[i]*toDegree)*cos(alfa[i]*toDegree);
        DH[1][2] = -cos(teta[i]*toDegree)*sin(alfa[i]*toDegree);
        DH[1][3] = A[i]*sin(teta[i]*toDegree);

        DH[2][0] = 0;
        DH[2][1] = sin(alfa[i]*toDegree);
        DH[2][2] = cos(alfa[i]*toDegree);
        DH[2][3] = D[i];

        DH[3][0] = 0;
        DH[3][1] = 0;
        DH[3][2] = 0;
        DH[3][3] = 1;

        for(j = 0; j < 4; j++){
                printf("                      ");

            for(k = 0; k < 4; k++){
                answer[i][j][k] = DH[j][k];

                if(answer[i][j][k] >= 0)
                    printf("   %.3f", answer[i][j][k]);  //printing the matrices

                else if(answer[i][j][k] < 0)
                    printf("  %.3f", answer[i][j][k]);  //printing the matrices with one less space (just for esthetic)

            }
            printf("\n\n");
        }

        printf("\n\n");
    }

    printf("<--------------------PRODUCT-OF-MATRIX-DH-FORMAT-IN-DEGRES---------------->\n\n\n\n");



    multiply(answer, res, matAtual, elos);


    printf("\n\n\n<-------------------------------------------------------------------------->\n\n\n");
        

    return 0;
}

//made by Luis Octavio GS, with care :)