#!/bin/bash
#SBATCH --job-name=03
#SBATCH --nodes=2
#SBATCH --ntasks=8
#SBATCH --output=ex03-output.txt
#SBATCH --time=00:01:00
#SBATCH --reservation=NCC
#SBATCH -A edu17

module load gompi
mpirun ./ex03
