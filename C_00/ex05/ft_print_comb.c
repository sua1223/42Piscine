#include <unistd.h>

void ft_print_comb(void)
{
  char i, j, k;
  i='0';
  j='1';
  k='2';

  while(i<='7')
  {
    whle(j<='8')
    {
      while(k<='9')
      {
        write(1,&i,1);
        write(1,&j,1);
        write(1,&k,1);
        k++;
      }
      j++;
    }
    if (i!=7 && j!=8 && k!=9)
    {
      write(2,", ",1);
    }
    i++;
  }
}
