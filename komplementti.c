#include <stdio.h>
#include <math.h>
#include <string.h>
/*
  === komplementti.c ===

  Toteuta ohjelma, joka olettaa saavansa komentoriviparametrina argv[1] numeromerkeist� '0' ja '1'
  koostuvan merkkijonon ja joka tulostaa ruudulle, mit� 10-lukuj�rjestelm�n lukua kyseisen
  merkkijonon kuvaama bittijono vastaisi, jos se tulkittaisiin 2:n komplementtiesitykseksi
  (eli bittijonoksi, jonka ensimm�inen bitti on etumerkkibitti ja loput bitit ovat arvobittej�).
  Huomaa, ettei t�ss� teht�v�ss� oleteta ennalta kiinnitetty� "bittileveytt�": merkkijonon argv[1]
  ensimm�inen merkki tulkitaan aina etumerkkibitiksi riippumatta siit�,
  kuinka pitk� kyseinen komentoriviparametri on.

  Toteutuksessa ei tarvitse varautua virhetilanteisiin: voit olettaa, ett� parametri argv[1]
  todellakin sis�lt�� ainoastaan numeromerkkej� '0' ja '1'
  ja ett� sen 2:n komplementtiesityksen� kuvaama lukuarvo mahtuu int-tyyppiseen muuttujaan

  ---
  Esim: 100101011 --> -213

*/



int main(int argc, char *argv[]) {

  int ci = strlen(argv[1]); /* ci = char index */
  int tot = 0;
  int m = 1; /* multiplier */

  for(ci;ci>=0; --ci) {
    char c = argv[1][ci];
    /*printf("%c \n", c);
*/
    m = 1; /* back to 1 */

    /*
      if last is 1, number is -(2^i) + ...
      multiplier m* is set to -1, by default 1
    */
    if(ci==0 && argv[1][ci]=='1') {
      m = -1;
    }

    if(argv[1][ci] == '1') {
      int bit_i = strlen(argv[1])-ci-1;
      /*printf("  %d^%d \n", 2, bit_i);*/
      tot += m*pow(2, bit_i); /* !! */
    }
  }

  printf("%d\n", tot);


  return 0;
}
