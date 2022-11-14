#!/bin/bash
#SBATCH --job-name=07
#SBATCH --nodes=2
#SBATCH --ntasks=8
#SBATCH --output=ex07-output.txt
#SBATCH --time=00:01:00
#SBATCH --reservation=NCC
#SBATCH -A edu17

module load gompi
mpirun ./ex07
