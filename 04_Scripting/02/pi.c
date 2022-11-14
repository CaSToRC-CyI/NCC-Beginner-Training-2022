#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int
main(int argc, char *argv[])
{
  unsigned long int N = 10000;
  unsigned long int nhit = 0;
  for(int i=0; i<N; i++) {
    double x = drand48();
    double y = drand48();
    if((x*x + y*y) < 1)
      nhit++;
  }
  double pi = 4.0 * (double)nhit/(double)N;
  printf(" N = %16d   pi = %lf\n", N, pi);
  return 0;
}
