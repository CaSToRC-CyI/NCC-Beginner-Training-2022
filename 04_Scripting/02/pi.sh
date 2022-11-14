#!/bin/bash
#SBATCH -J pi
#SBATCH -o pi.txt
#SBATCH -e pi.err
#SBATCH -p cpu
#SBATCH -A edu17
#SBATCH --reservation=NCC
#SBATCH -t 00:02:00
#SBATCH -n 80
#SBATCH -N 2

