// 12S22016 - Desri Stevie Natalie Dabukke
// 12S22035 - Brain Wonderson Sitorus

#include <stdio.h>

int main(int _argc, char **_argv)
{
  int bil1,bil2,bil3;

  scanf("%d",&bil1);
  scanf("%d",&bil2);
  scanf("%d",&bil3);

  int hasilOperasi = bil1 << bil2;
  printf("%d\n",hasilOperasi);
  printf("%d\n",hasilOperasi == bil3);

  return 0;
}
