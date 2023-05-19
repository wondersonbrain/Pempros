// NIM - Name
// NIM - Name

#include <stdio.h>
#include <stdbool.h>

int main(int _argc, char **_argv)
{
 int numerik;
 char ASCII;
 int bulan;
 unsigned short int numerik_2;
 float fraction;
 scanf("%d\n", &numerik);
 scanf("%c\n", &ASCII);
 scanf("%d\n", &bulan);
 scanf("%hu\n", &numerik_2);
 scanf("%f", &fraction);

printf("%d\n", numerik);
printf("%c\n", ASCII);
printf("%d\n", bulan);
printf("%hu\n", numerik_2);
printf("%.4f\n", fraction);

  return 0;
}
