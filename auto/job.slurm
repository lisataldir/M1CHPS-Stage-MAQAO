#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --time=00:05:00


# APPLICATION SETTINGS
module purge
module load binutils/11.2.0
module load gnu/11.2.0
module load openmpi/gnu/4.1.4-gpu

# RUN THE APPLICATION
<mpi_command> <run_command>

