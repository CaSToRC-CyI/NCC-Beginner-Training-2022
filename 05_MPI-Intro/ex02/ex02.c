#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
  /*
   * Get the hostname of the node we are running on
   */
  char hname[256];
  gethostname(hname, 256);
    
  MPI_Init(&argc, &argv);
  
  int nproc, rank;
  /*
   * Call MPI_Comm_size() and MPI_Comm_rank() with the appropriate
   * arguments (copied from ex01)
   */
  MPI_Comm_size(MPI_COMM_WORLD, &nproc);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  /*
   * TODO: add an MPI_Barrier() to ensure the ranks print in-order
   */
  for(int i=0; i<nproc; i++) {
    if(rank == i)
      printf(" This is rank = %d of nproc = %d on node: %s\n", rank, nproc, hname);
  }
  
  MPI_Finalize();
  return 0;
}
