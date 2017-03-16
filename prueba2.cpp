
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  struct rep_texto {
    char caracteres[TXT_MAX_LNG + 1];
    nat longitud;
  }

  typedef rep_texto *texto_t;

  texto_t prueba = new rep_texto;
  int prueba = 1234 ;

  texto_t int_a_texto(int i) {
    texto_t res = new rep_texto;
    res->longitud = sprintf(res->caracteres, "%d", i);
    for(nat j = 0; j <= (res->longitud); j++) {
	  char aux = (char) (res->caracteres[j] + 48);
	  res->caracteres[j] = aux;
    }
    res->caracteres[res->longitud] = '\0';
    assert((res->longitud > 0) && (res->longitud < TXT_MAX_LNG));
    assert(res->caracteres[res->longitud] == '\0');
    return res;
  }

  texto_t lul = texto_a_int(prueba);
  printf("%c", lul->caracteres);
}