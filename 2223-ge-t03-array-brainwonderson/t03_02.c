
// 12S22016 - Desri Stevie Natalie Dabukke
// 12S22035 - Brain Wonderson

#include <stdio.h>

int main()
{
    int baris;
    int i, j;
    int nilai, nilaiRendah = 0, nilaiTinggi = 0;
    float avg, avgRendah = 0, avgTertinggi = 0;
    
    scanf("%d", &baris);
    
    int nilaiBaris[baris];

    for(i = 0; i < baris; i++){
        scanf("%d", &nilai);
        nilaiBaris[i] = nilai;
        
        if(i==0){
            nilaiTinggi = nilai;
            nilaiRendah = nilai;
        } else{
            if(nilai > nilaiTinggi){
                nilaiTinggi = nilai;
            }
            
            if (nilai < nilaiRendah){
                nilaiRendah = nilai;
            }   
        }
    }
    
    for(j=0; j < baris; j++){
        if(j + 1 < baris){
            avg = (float)( nilaiBaris[j] + nilaiBaris[j+1] ) / 2;
            
            if(j==0){
                avgRendah = avg;
                avgTertinggi = avg;
            }
            
            if(avg < avgRendah){
                avgRendah = avg;
            }
            
            if(avg > avgTertinggi){
                avgTertinggi = avg;
            }
        }
    }
    
    printf("%d\n", nilaiRendah);
    printf("%d\n", nilaiTinggi);
    printf("%.2f\n", avgRendah);


    return 0;
}
