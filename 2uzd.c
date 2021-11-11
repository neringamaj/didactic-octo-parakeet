#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//user interface:
#define program "In this program user enters an integer N,\
 that then will allow user to enter a table of N*N integers.\n\
The program will find the smallest number in each row, and\
 then from those numbers find the biggest one and give it's coordinates. \n"
#define start "Enter an integer: \n"
#define zero "Table can not be 0*0, try again\n"
#define table "Enter a %d*%d table of integers: \n"
#define end "Coordinates of the number: (%d, %d) \nThe number: %d \n"
#define goodbye "\nEnd of program, goodbye! \n"
//
int validation();
int* maximum(int n, int Min[], int Coord[n][2], int *ma);
int main(){
    printf(program);
    printf(start);

    int n = 0;
    while (n == 0){
        n = validation();
        n = abs(n);
        if (n == 0)
            printf (zero);
    }

    int Min[n], max, sk, min, Coord[n][2];

    printf(table,n,n);

    for (int i = 0; i < n; i++){
        min = INT_MAX;
        for (int j = 0; j < n; j++){
            sk = validation();
            if (sk < min){
                min = sk;
                Min[i] = sk;
                Coord[i][1] = j;
                Coord[i][0] = i;
            }
        }
    }
    max = Min[0];
    int *Max_coord = maximum(n,Min,Coord,&max);

    printf(end,Max_coord[0],Max_coord[1], max);
    printf(goodbye);
    return 0;
}
int* maximum(int n, int Min[], int Coord[n][2], int *ma){
    int M[2];
    for (int i = 0; i < n; i++)
        if (Min[i] >= *ma){
            *ma = Min[i];
            M[0] = Coord[i][0];
            M[1] = Coord[i][1];
        }
    return M;
}
int validation(){

    int x;
    char symb;
    bool legal = false;

    while (legal != true)
    {
        scanf ("%d", &x);
        symb = getchar();
        if(x%1 != 0 || symb != '\n' && symb != ' ')
            while (symb != '\n' && symb != ' ')
                symb = getchar();
        else
            legal = true;
    }

    return x;
}
