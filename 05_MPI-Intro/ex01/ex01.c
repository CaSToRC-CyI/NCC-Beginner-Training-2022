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
   * TODO: call `MPI_Comm_size()' and `MPI_Comm_rank()' with the
   * appropriate arguments
   */
  MPI_Comm_size(/* TODO */);
  MPI_Comm_rank(/* TODO */);

  /*
   * All processes: print `rank', `nproc', and `hname'
   */
  printf(" This is rank = %d of nproc = %d on node: %s\n", rank, nproc, hname);
  
  MPI_Finalize();
  return 0;
}
