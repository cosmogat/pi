/* 11-09-2015 */
/* billy */
/* pi_gmp.c */
/* compilar amb: gcc -lgmp -W -Wall -Wextra -ansi -pedantic -std=c11 pi_gmp.c -o pi */
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <unistd.h>
#include <sys/times.h>
#define C_LN2  0.6931471805599453094172321214581766L
#define C_LN10 2.3025850929940456840179914546843642L
#define XIF 10000

double temps();

int main (int num_arg, char * vec_arg[]) {
  unsigned int k, a = 545140134, b = 13591409, c = 640320, xifres, max_iter;
  long long int sis = 0, tres = 0;
  int i;
  double t_aux = 0.0, t_tmp = 0.0, t = 0.0;
  char * pi_cad;
  mpf_t A, B, C, D, E, F, G, sum, fact1, fact2, fact3, pi;
  mp_exp_t exp;
  FILE * fitxer;
  if (num_arg != 2) {
    printf("Utilitzeu:\n%s xifres\n", vec_arg[0]);
    return -1;
  }
  xifres = atoi(vec_arg[1]);
  mpf_set_default_prec((int) (xifres * (C_LN10 / C_LN2)));
  mpf_init(A);
  mpf_init(B);
  mpf_init(C);
  mpf_init(D);
  mpf_init(E);
  mpf_init(F);
  mpf_init(G);
  mpf_init(sum);
  mpf_init(fact1);
  mpf_init(fact2);
  mpf_init(fact3);
  mpf_init(pi);
  
  mpf_add_ui(fact1, fact1, 1);
  mpf_add_ui(fact2, fact2, 1);
  mpf_add_ui(fact3, fact3, 1);
  mpf_add_ui(sum, sum, b);
  mpf_add_ui(F, F, 1);
  if (xifres >= XIF)
    t_aux = temps();
  mpf_sqrt_ui(pi, 10005);
  if (xifres >= XIF) {
    t = t_tmp = temps() - t_aux;
    if (t_tmp > 0.5)
      printf("Arrel: %f s.\n", t_tmp);
    t_aux = temps();
  }
  mpf_mul_ui(pi, pi, 426880);
  if (xifres >= XIF) {
    t_tmp = temps() - t_aux;
    t += t_tmp;
    if (t_tmp > 0.5)
      printf("Multiplicació: %f s.\n", t_tmp);
    t_aux = temps();
  }
  max_iter = ((int) (xifres / 14)) + 1;
  for (k = 1; k <= max_iter; k++) {
    mpf_add_ui(A, A, a);
    mpf_add_ui(B, A, b);

    for (i = 0; i < 3; i++) {
      tres++;
      mpf_mul_ui(fact2, fact2, tres);
    }
    for (i = 0; i < 6; i++) {
      sis++;
      mpf_mul_ui(fact3, fact3, sis);
    }
    
    mpf_mul_ui(fact1, fact1, k);
    mpf_mul(E, fact1, fact1);
    mpf_mul(E, E, fact1);

    mpf_mul_ui(F, F, c);
    mpf_mul_ui(F, F, c);
    mpf_mul_ui(F, F, c);
    mpf_neg(F, F);

    mpf_mul(C, fact3, B);
    mpf_mul(D, fact2, E);
    mpf_mul(D, D, F);

    mpf_div(G, C, D);
    
    mpf_add(sum, sum, G);
    if (xifres >= XIF)
      printf("\r%.2f%%", 100 * ((float) k) / max_iter);
  }
  if (xifres >= XIF) {
    printf("\n");
    t_tmp = temps() - t_aux;
    t += t_tmp;
    if (t_tmp > 0.5)
      printf("Sèrie: %f s.\n", t_tmp);
    t_aux = temps();
  }
  mpf_div(pi, pi, sum);
  if (xifres >= XIF) {
    t_tmp = temps() - t_aux;
    t += t_tmp;
    if (t_tmp > 0.5)
      printf("Divisió: %f s.\n", t_tmp);
    t_aux = temps();

    fitxer = fopen("pi.txt", "w");
    pi_cad = mpf_get_str(NULL, &exp, 10, xifres, pi);
    fwrite(pi_cad, sizeof(char), 1, fitxer);
    fputc('.', fitxer);
    fwrite(pi_cad + 1, sizeof(char), xifres - 1, fitxer);
    fputc('\n', fitxer);
    fclose(fitxer);
    t_tmp = temps() - t_aux;
    t += t_tmp;
    if (t_tmp > 0.5)
      printf("Escriptura: %f s.\n", t_tmp);

    printf("Temps total: %f s.\n", t);
    printf("%d xifres de pi desades en 'pi.txt'\n", xifres);
  }
  else
    gmp_printf ("%.*Ff\n", xifres - 1, pi);
  mpf_clear(A);
  mpf_clear(B);
  mpf_clear(C);
  mpf_clear(D);
  mpf_clear(E);
  mpf_clear(F);
  mpf_clear(G);
  mpf_clear(sum);
  mpf_clear(fact1);
  mpf_clear(fact2);
  mpf_clear(fact3);
  mpf_clear(pi);

  return 0;
}

double temps() {
  clock_t ct;
  struct tms t;
  
  ct = times(&t);
  if ( ct == (clock_t) - 1 )
    return 0.0; 
  else
    return (((double) t.tms_utime ) / ((double) sysconf(_SC_CLK_TCK)));
}
