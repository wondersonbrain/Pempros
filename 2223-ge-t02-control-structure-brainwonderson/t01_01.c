// NIM - Name
// NIM - Name

#include <stdio.h>

int main(int _argc, char **_argv) {
  int x;
  scanf("%d", &x);
  switch(x){
    case 1 :
        x=1;
        printf("January\nFebruary\nMarch");
        break;
    case 2 :
        x=2;
        printf("February\nMarch\nApril");
        break;
    case 3 :
        x=3;
        printf("March\nApril\nMay");
        break;
    case 4 :
        x=4;
        printf("April\nMay\nJune");
        break;
    case 5 :
        x=5;
         printf("May\nJune\nJuly");
         break;
    case 6 :
        x=6;
         printf("June\nJuly\nAugust");
         break;
    case 7 :
        x=7;
         printf("July\nAugust\nSeptember");
         break;
    case 8:
        x=8;
         printf("August\nSeptember\nOctober");
         break;
    case 9 :
        x=9;
        printf("September\nOctober\nNovember");
        break;
    case 10 :
        x=10;
         printf("October\nNovember\nDecember");
         break;
    case 11 :
        x=11;
         printf("November\nDecember\nNew year\nJanuary");
         break;
    case 12 :
        x=12;
        printf("December\nNew year\nJanuary\nFebruary");
        break;


  }



  return 0;
}
