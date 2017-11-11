#include "mural.h"

Mural::Mural() {

}

Mural::~Mural() {

}

void Mural::Initialize(int argc, char **argv) {
    int rc;
#ifdef MURAL_USE_MPI
    mpi_enabled = true;
    rc = MPI_Init(&argc, &argv);
    rc |= MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    rc |= MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);
#else
    mpi_enabled = false;
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
}
