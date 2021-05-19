#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <math.h>
#define MAX 50

void bubble_sort(int array[],int size){
    int i,j;

    for(i=0;i<size;i++){
        for(j=1;j<size-i;j++){
            if(array[j-1]>array[j]){
                int temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
            }
        }
    }
}


bool kaprekar(int n)
    {
        if (n == 1)
           return true;
        int karesi = n * n;
        int rakamSay = 0;
        while (karesi != 0)
        {
            rakamSay++;
            karesi /= 10;
        }
        karesi = n*n;
        for (int basamak=1; basamak<rakamSay; basamak++)
        {
             int parca = (int) pow(10, basamak);
            if (parca == n)
                continue;
             int sum = karesi/parca + karesi % parca;
             if (sum == n)
               return true;

        }
        return false;
    }


int main()
{
    srand(time(NULL));
    int **matris;
   int i,j, satir, sutun;
    int **matrisG;
  printf("Satir Sayisisni Giriniz=");
    scanf("%d",&satir);
    printf("Sutun Sayisini Giriniz=");
    scanf("%d",&sutun);

    matris = (int **)malloc( satir*100 * sizeof(int) );
    if( matris == NULL )
        printf( "Yetersiz bellek!" );

    for( i = 0; i <satir; i++ ) {
            matris[i] =(int *) malloc(sutun*100 * sizeof(int) );
    if( matris[i] == NULL )
        printf( "Yetersiz bellek!" );
    }

    matrisG = (int **)malloc(satir*100 * sizeof(int) );
    if( matrisG == NULL )
        printf( "Yetersiz bellek!" );

    for( i = 0; i < satir; i++ ) {
            matrisG[i] =(int *) malloc( sutun*100 * sizeof(int) );
    if( matrisG[i] == NULL )
        printf( "Yetersiz bellek!" );
    }


    for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {

            matris[i][j]=rand()%40000-5;
        }
    }
      printf("\n%d Satir ve %d Sutundan olusan = matris[%d][%d] cok boyutlu dizisini olusturdunuz:\n\n",satir,sutun,i,j);
    printf("\nmatris[%d][%d] Icin Gelen Degerler\n\n",i,j);

    for(i=0;i<satir;i++){
        for(j=0;j<sutun;j++){
            printf("%2d\t",matris[i][j]);
   }
     printf("\n\n");
  }

  int elemansayisi=(satir*sutun);
  int *mat;
  int a,b,k=0;
  mat=(int *)malloc(elemansayisi*100 * sizeof(matris[0]));
  if(mat==NULL){
		printf("Yer ayrilamadi.");
	}


for(a=0;a<satir;a++)
    {
        for(b=0;b<sutun;b++)
        {
            mat[k] = matris[a][b];
            k++;
        }
    }
    printf("****************************************\n\n");
    printf("Bubble Sort Siralama:\n\n");
    bubble_sort(mat,elemansayisi);
{


    for(int c=0;c<elemansayisi;c++){
        printf("%d ",mat[c]);
    }

    int geridonus = 1;

  k=0;

  for(b=0;b<satir;b++)
    {
        if(geridonus==1)
          {
            for(a=0;a<sutun;a++)
            {
              matrisG[a][b] = mat[k];
              k++;
            }
            geridonus = 0;
          }
        else
          {
             for(a=satir-1;a>=0;a--)
            {
                matrisG[a][b] = mat[k];
                k++;
            }
            geridonus = 1;

          }
    }
    }

    printf("\n\n****************************************\n");
    printf("\n\nBubble Sort Matris Siralama\n\n");

   for(i=0;i<satir;i++)
    {
        for(j=0;j<sutun;j++)
        {
            printf("%d\t",matrisG[i][j]);

        }
        printf("\n");
    }

    printf("\n\n****************************************\n");

    printf("\n\nBubble Sort Matris Transpoze Siralama\n\n");

    int **matrisT;

    matrisT = (int **)malloc( satir*100 * sizeof(int) );
    if( matrisT == NULL )
        printf( "Yetersiz bellek!" );

    for( i = 0; i <satir; i++ ) {
            matrisT[i] =(int *) malloc(sutun*100 * sizeof(int) );
    if( matrisT[i] == NULL )
        printf( "Yetersiz bellek!" );
    }

     for(i=0; i<a; i++){
        for(j=0; j<b; j++){
            matrisT[j][i] = matrisG[i][j];
        }
    }

    for(i=0; i<b; i++){
        for(j=0; j<a; j++){
            printf("%d ", matrisT[i][j]);
        }
        printf("\n");
    }


    printf("\n");
    printf("Dosyaya Yazdirma Islemi Baslatiliyor!!\n");


FILE *fp;
fp=fopen("transpoze.txt","w");
for(i=0;i<sutun;i++){
    for(j=0;j<satir;j++){
        fprintf(fp,"%d\t\n",matris[j][i]);
    }
    fprintf(fp,"*********\n");
printf("\n");

}

fprintf(fp,"Transpozesi:\n");
for(i=0;i<satir;i++){
    for(j=0;j<sutun;j++){
        fprintf(fp,"%d\t\n",matrisT[j][i]);
    }
    fprintf(fp,"********\n");
printf("\n");
}
fprintf(fp,"Yazdirma Islemi Tamanlandi\n");
if(fp!=NULL){
    printf("Yazdirma Islemi Tamanlandi");
}
fclose(fp);
printf("\n\n");

printf("**************************\n");
printf("Kaprekar Sayilar\n");

FILE *fpkaprekar;
fpkaprekar=fopen("kaprekar.txt","w");
int yazici;
for (int v=0; v<satir; v++) {
        for(int c=0;c<sutun;c++){
            if(kaprekar(matrisT[v][c])==true){
                printf("%d Sayisi Kaprekar\n",matrisT[v][c]);
                fprintf(fpkaprekar,"%d\n",matrisT[v][c]);
            }
            else
                printf("%d Sayisi Kaprekar Degil\n",matrisT[v][c]);

}
}

fclose(fpkaprekar);


for( i = 0; i < satir; i++ ) {
        free( matris[i] );
}

free(matris);

for( i = 0; i < satir
; i++ ) {
        free( matrisG[i] );
}



for( i = 0; i < satir; i++ ) {
        free( matrisT[i] );
}
free(matrisG);
free(matrisT);
free(mat);

   getch();
}









/*
    matris=(int **)malloc(satir * sizeof(int *));

    matrisG=(int **)malloc(satir * sizeof(int *));*/












