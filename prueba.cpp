
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
  char aux = hola ;
  prueba->caracteres[0] = aux;
  prueba->longitud = strlen(prueba->caracteres);

  int texto_a_int(texto_t t) {
    int res;
    for(nat i = 0; i <= (t->longitud); i++) {
        res += t->caracteres[i];
    }
    return res;
  }

  int res = texto_a_int(prueba);
  printf("%d", res);
}