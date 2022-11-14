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
   * Abort if the number of processes is not equal to `nelems'
   */
  int nelems = 8;
  if(nelems != nproc) {
    fprintf(stderr, " nelems (=%d) must be equal to nproc (=%d)\n", nelems, nproc);
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
   * Distribute the elements of `vars[]', one element per process, to
   * variable `var_proc'
   */
  double var_proc;
  MPI_Scatter(vars, 1, MPI_DOUBLE, &var_proc, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  double var_next, var_prev;
  /*
   * TODO: Use `MPI_Sendrecv()' appropriately, so that `var_proc' of
   * each rank is copied into `var_prev' of the next rank. Assume
   * periodicity of ranks, i.e. if the sender is the last process
   * (`rank == nproc - 1') then send to the first process (`rank ==
   * 0')
   */
  MPI_Sendrecv(/* TODO */);
  
  /*
   * TODO: Use `MPI_Sendrecv()' appropriately, so that `var_proc' of
   * each rank is copied into `var_next' of the previous rank. Assume
   * periodicity of ranks, i.e. if the sender is the first process
   * (`rank == 0') then send to the last process (`rank == nproc - 1')
   */
  MPI_Sendrecv(/* TODO */);
  
  /*
   * All processes: print `var_proc', `var_prec', and `var_next'
   */
  printf(" This is rank = %d of nproc = %d on node: %s | var_proc = %lf   var_prev = %lf   var_next = %lf\n",
	 rank, nproc, hname, var_proc, var_prev, var_next);
    
  MPI_Finalize();
  return 0;
}
