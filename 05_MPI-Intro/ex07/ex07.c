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
   * variable `var0'
   */
  double var0;
  MPI_Scatter(vars, 1, MPI_DOUBLE, &var0, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  double var1;
  /*
   * TODO: Use `MPI_Send()' and `MPI_Recv()' appropriately, so that
   * `var0' of each even rank is copied into `var1' of the next odd
   * rank
   */
  if(rank % 2 == 0) {
    MPI_Send(/* TODO */);
  } else {
    MPI_Recv(/* TODO */);
  }
  
  /*
   * TODO: Use `MPI_Send()' and `MPI_Recv()' appropriately, so that
   * `var0' of each odd rank is copied into `var1' of the previous
   * even rank
   */
  if(rank % 2 == 1) {
    MPI_Send(/* TODO */);
  } else {
    MPI_Recv(/* TODO */);
  }
  
  /*
   * All processes: print `var0' and `var1'
   */
  printf(" This is rank = %d of nproc = %d on node: %s | var0 = %lf   var1 = %lf\n",
	 rank, nproc, hname, var0, var1);
    
  MPI_Finalize();
  return 0;
}
