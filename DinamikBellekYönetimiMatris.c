#include <stdio.h>
#include <stdlib.h>
# include <stdbool.h>
# include <math.h>
int **matris_normal;
int **transpozeli_matris;
int satir_sayisi;
int sutun_sayisi;
int i;
int j;

void matris_fonk();


void rastegle_sayilar_matris();


void bubble_sort_matris(int ** dizi, int satir_sayisi, int sutun_sayisi);


void matrisin_transpozesi(int **dizi,int satir_sayisi,int sutun_sayisi);


void matris_tranpoze_bblSort_yazirma(int **transpozeli_matris,int **dizi,int satir_sayisi,int sutun_sayisi);


bool kaprekar_sayisi(int n);


void transpozeKaprekar(int **dizi, int satir_sayisi, int sutun_sayisi);

int main()
{
srand(time(NULL));


matris_fonk();


rastegle_sayilar_matris();


bubble_sort_matris(matris_normal, satir_sayisi,sutun_sayisi);


matrisin_transpozesi(matris_normal, satir_sayisi,sutun_sayisi);


matris_tranpoze_bblSort_yazirma(transpozeli_matris,matris_normal,satir_sayisi,sutun_sayisi);

printf("\n\nyazdirma islemi tamam!");


transpozeKaprekar(matris_normal,satir_sayisi,sutun_sayisi);


return 0;
}
void matris_fonk(){

printf("Satir :");
scanf("%d",&satir_sayisi);


printf("Sutun :");
scanf("%d",&sutun_sayisi);


matris_normal = malloc(satir_sayisi*sizeof(int*));


for(i=0;i<satir_sayisi;i++){
matris_normal[i]= malloc(sutun_sayisi*sizeof(int));
    }
}

void rastegle_sayilar_matris(){
for(i=0;i<satir_sayisi;i++){
    for(j=0;j<sutun_sayisi;j++){
        matris_normal[i][j]= (rand()%40000)+5 ;
        }
    }
}

void bubble_sort_matris(int ** dizi, int satir_sayisi, int sutun_sayisi){

   int matris_1D[satir_sayisi*sutun_sayisi];
   int k=0;

   for(i=0;i<satir_sayisi;i++){
    for(j=0;j<sutun_sayisi;j++){
        matris_1D[k] = dizi[i][j];
        k++;

    }
   }


    for(i=0;i<satir_sayisi*sutun_sayisi-1;i++){
        for(j=0;j<satir_sayisi*sutun_sayisi-1-i;j++){
        if(matris_1D[j] > matris_1D[j+1]){
            int temp = matris_1D[j];
            matris_1D[j]=matris_1D[j+1];
            matris_1D[j+1]= temp;
            }
        }
    }


    for(i=0;i<satir_sayisi*sutun_sayisi;i++){


    }



    k=0;
    for(i=0;i<satir_sayisi;i++){
        for(j=0;j<sutun_sayisi;j++){
            dizi[i][j]=matris_1D[k];
            k++;
        }

    }
}

void matrisin_transpozesi(int **dizi,int satir_sayisi,int sutun_sayisi){




if(satir_sayisi>sutun_sayisi){
    transpozeli_matris = malloc(satir_sayisi*sizeof(int*));

for(i=0;i<satir_sayisi;i++){
transpozeli_matris[i]= malloc(sutun_sayisi*sizeof(int));
    }
}



else{
    transpozeli_matris = malloc(sutun_sayisi*sizeof(int*));

for(i=0;i<sutun_sayisi;i++){
transpozeli_matris[i]= malloc(satir_sayisi*sizeof(int));
    }
}
    for(i=0;i<satir_sayisi;i++){
    for(j=0;j<sutun_sayisi;j++){
        transpozeli_matris[j][i]=dizi[i][j];
        }
    }
}


void matris_tranpoze_bblSort_yazirma(int **transpozeli_matris,int **dizi,int satir_sayisi,int sutun_sayisi){

    FILE *fT;
    fT = fopen("matris_transpoze_bbl_sort.txt", "w");
    if(fT == NULL){
        printf("Error !");
        exit(1);
    }
    fprintf(fT,"Transpoze Olmadan Matris... (Bubble Sorted):\n");
    for(i=0;i<satir_sayisi;i++){
        for(j=0;j<sutun_sayisi;j++){
            fprintf(fT,"[%d][%d]:%d\t",i,j,dizi[i][j]);
        }
        fprintf(fT,"\n");
    }
    fclose(fT);


 FILE *fA;
    fA = fopen("matris_transpoze_bbl_sort.txt", "a");
    if(fA == NULL){
        printf("Error !");
        exit(1);
    }

    fprintf(fA,"\nMatris Transpozesi... :\n");


    for(i=0;i<sutun_sayisi;i++){
        for(j=0;j<satir_sayisi;j++){
            fprintf(fA,"[%d][%d]:%d\t",i,j,transpozeli_matris[i][j]);
        }
        fprintf(fA,"\n");
    }
    fclose(fA);
}

bool kaprekar_sayisi(int n){
        if (n == 1)
        return true;
        int sayi_karesi = n * n;
        int sayac_kaprekar = 0;
        while (sayi_karesi != 0)
        {
            sayac_kaprekar++;
            sayi_karesi /= 10;
        }

        sayi_karesi = n*n;

        for (int rakamlar_sayaci=1; rakamlar_sayaci<sayac_kaprekar; rakamlar_sayaci++)
        {
             int sayilar = (int) pow(10, rakamlar_sayaci);
            if (sayilar == n)
                continue;
             int toplam = sayi_karesi/sayilar + sayi_karesi % sayilar;
             if (toplam == n)
               return true;
        }

        return false;
    }

    void transpozeKaprekar(int **dizi, int satir_sayisi, int sutun_sayisi){

    FILE *fK;
    fK = fopen("kaprekar_sayisi.txt", "w");
    if(fK == NULL){
        printf("Error !");
        exit(1);
    }
    for(i=0;i<sutun_sayisi;i++){
        for(j=0;j<satir_sayisi;j++){
            if(kaprekar_sayisi(transpozeli_matris[i][j])){
                fprintf(fK,"Kaprekar Sayi : [%d][%d], \t",i,j);
            }
        }
    }


int size;

   fseek (fK, 0, SEEK_END);
    size = ftell(fK);

    if (0 == size) {
        printf("\nKaprekar Yok\n");
    }

    fclose(fK);
}
