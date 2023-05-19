// 12S22016 - Desri Stevie Natalie Dabukke
// 12S22035 - Brain Wonderson Sitorus

#include <stdio.h>

int main(int _argc, char **_argv)
{
  float a;
  float b;
  float c;
  float d;
  float e;
  float results;
  float median;

  scanf("%f", &a);
  scanf("%f", &b);
  scanf("%f", &c);
  scanf("%f", &d);
  scanf("%f", &e);

  results =a + b + c + d + e;
  median =results / 5;

  printf("%.4f\n", results);
  printf ("%.4f\n", median);

  return 0;
}
