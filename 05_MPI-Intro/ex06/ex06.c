#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

/*
 * Function reads `n' lines from file with name `fname[]` and returns
 * each line as a double precision number in `arr[]'. `arr[]' should
 * have enough space for `n' double precision numbers
 */
void
readlines(int n, double *arr, char fname[])
{
  FILE *fp = fopen(fname, "r");
  double line_val;
  for(int i=0; i<n; i++) {
    fscanf(fp, "%lf", &line_val);
    arr[i] = line_val;
  }
  fclose(fp);
  return;
}

int
main(int argc, char *argv[])
{
  char hname[256];
  gethostname(hname, 256);
    
  MPI_Init(&argc, &argv);
  
  int nproc, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  /*
   * Abort if the number of processes does not divide `nelems' exactly
   */
  int nelems = 2520;
  if(nelems % nproc != 0) {
    fprintf(stderr, " nelems = %d not divisible by nproc = %d\n", nelems, nproc);
    MPI_Abort(MPI_COMM_WORLD, 1);
  }
  
  /*
   * root process: read `nelems' lines of "data.txt" into array `vars[]'
   */
  double vars[nelems];
  if(rank == 0) {
    char fname[] = "data.txt";
    readlines(nelems, vars, fname);
  }

  /*
   * `nelems_loc': local number of elements, i.e. number of elements
   * pre process
   *
   * `vars_loc[]': local array, i.e. array to store elements
   * corresponding to process
   */
  int nelems_loc = nelems/nproc;
  double vars_loc[nelems_loc];
  
  /*
   * TODO: use an MPI_Scatter() to distribute the elements of `vars[]'
   * to each process' `vars_loc[]' array
   */
  MPI_Scatter(/* TODO */);

  /*
   * `sum_loc' holds the sum over each process' local elements
   */
  double sum_loc = 0;
  for(int i=0; i<nelems_loc; i++)
    sum_loc += vars_loc[i];
  
  /*
   * TODO: use an MPI_Reduce() to sum `sum_loc' over all processes and
   * store in `sum' of the root process
   */
  double sum;
  MPI_Reduce(/* TODO */);

  /*
   * root process: print the sum and how many processes were used
   */
  if(rank == 0)
    printf(" Used %d processes, sum = %lf\n", nproc, sum);
  
  MPI_Finalize();
  return 0;
}
