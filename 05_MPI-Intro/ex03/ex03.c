#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

/*
 * Function reads the first line of a file and returns it as a double
 * precision number
 */
double
readline(char fname[])
{
  FILE *fp = fopen(fname, "r");
  double line_val;
  fscanf(fp, "%lf", &line_val);
  fclose(fp);
  return line_val;
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
   * root process: read the first line of "data.txt"
   */
  double val;
  if(rank == 0) {
    char fname[] = "data.txt";
    val = readline(fname);
  }

  /*
   * TODO: add an MPI_Bcast() with the appropriate arguments to
   * broadcast variable `val' from the root process to all processes
   */  
  MPI_Bcast(/* TODO */);

  /*
   * All processes: print `val'
   */
  printf(" This is rank = %d of nproc = %d on node: %s | Got from root var = %lf\n", rank, nproc, hname, val);
  
  MPI_Finalize();
  return 0;
}
