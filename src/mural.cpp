#include "config.h"

#include <iostream>
#ifdef MURAL_USE_MPI
#include <mpi.h>
#endif

int main(int argc, char** argv)
{
    int rc, rank, num_ranks;
#ifdef MURAL_USE_MPI
    rc = MPI_Init(&argc, &argv);
    rc |= MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    rc |= MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);
#else
    rc = 0;
    rank = 0;
    num_ranks = 1;
#endif
    if (rc != 0) {
        fprintf(stderr, "Error initializing MPI and obtaining task ID information\n");
    }

#ifdef MURAL_USE_MPI
    std::cout << "MPI Enabled" << std::endl;
#else
    std::cout << "No MPI" << std::endl;
#endif
    std::cout << "Number of Ranks: " << num_ranks << ", Rank: " << rank << std::endl;

    return 0;
}