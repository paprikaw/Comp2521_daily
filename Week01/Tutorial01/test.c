#include<stdio.h>
int myFunction(int n);

int main (void) {
    int i = myFunction(100);
    printf("%d", i);
    return 0;
}

int myFunction(int n)
{
   int i = 0;
   while (n > 0) {
      i++;
      n = n/2;
   }
   return i;
}