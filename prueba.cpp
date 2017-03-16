
#include <stdio.h>
int main()
int texto_a_int(texto_t t) {
  int res;
  for(nat i = 0; i <= (t->longitud); i++) {
      res += t->caracteres[i];
  }
  return res;