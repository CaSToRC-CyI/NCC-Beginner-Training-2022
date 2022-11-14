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
   * root process: read `n' lines of "data.txt" into array `vars[]'
   */
  int nelems = 8;
  double vars[nelems];
  if(rank == 0) {
    char fname[] = "data.txt";
    readlines(nelems, vars, fname);
  }

  double var;
  /*
   * TODO: use an MPI_Scatter() to distribute the elements of `vars[]'
   * to the processes, one element for each process. Assume the number
   * of processes is the same as the number of elements. Same as in
   * exercise ex04.
   */
  MPI_Scatter(/* TODO */);

  /*
   * Divide by two on each rank
   */
  var = var*0.5;

  /*
   * TODO: use an MPI_Gather() to collect `var' from each rank to the
   * array `vars[]' on the root process
   */  
  MPI_Gather(/* TODO */);

  /*
   * root process: print the elements of `vars[]' obtained via the
   * `MPI_Gather()'
   */
  if(rank == 0)
    for(int i=0; i<nelems; i++)
      printf(" vars[%d] = %lf\n", i, vars[i]);
  
  MPI_Finalize();
  return 0;
}
