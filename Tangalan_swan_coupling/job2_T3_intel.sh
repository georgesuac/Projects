#!/bin/sh
## Run in current working directory
#$ -cwd
## Resource type F: qty 2
#$ -l f_node=1
## maximum run time
#$ -l h_rt=24:00:00
#$ -N COAWST_TANGALAN
## Initialize module command
. /etc/profile.d/modules.sh

module load cuda intel
module load openmpi
module load hdf5-parallel
module load netcdf-parallel
## 28 process per node, all MPI process is 28
mpirun -x LD_LIBRARY_PATH -npernode 28 -n 28 ./coawstM coupling_tangalan_T3.in
