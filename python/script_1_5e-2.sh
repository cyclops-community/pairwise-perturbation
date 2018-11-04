#!/bin/bash
#----------------------------------------------------
#SBATCH -J ctf_pp
#SBATCH -o pp.bench.N1.n8.5e-2.o%j.out
#SBATCH -e pp.bench.N1.n8.5e-2.o%j.err
#SBATCH -p normal
#SBATCH -N 1
#SBATCH -n 8
#SBATCH -t 02:00:00
#SBATCH --mail-user=solomon2@illinois.edu
#SBATCH --mail-type=all    # Send email at begin and end of job

module list
pwd
date

export CTF_PPN=8
export OMP_NUM_THREADS=6

ibrun ./test_ALS -model CP -tensor r -pp 0 -dim 6 -size 30 -rank 5 -maxiter 250 -filename CP_r_nodes=1_pp=0_dim=6_size=30_rank=5_restol=0.05.csv -pp_res_tol 0.05 -resprint 10
ibrun ./test_ALS -model CP -tensor r -pp 1 -dim 6 -size 30 -rank 5 -maxiter 250 -filename CP_r_nodes=1_pp=1_dim=6_size=30_rank=5_restol=0.05.csv -pp_res_tol 0.05 -resprint 10
ibrun ./test_ALS -model CP -tensor c -pp 0 -dim 6 -size 30 -rank 5 -maxiter 250 -filename CP_c_nodes=1_pp=0_dim=6_size=30_rank=5_restol=0.05.csv -pp_res_tol 0.05 -resprint 10
ibrun ./test_ALS -model CP -tensor c -pp 1 -dim 6 -size 30 -rank 5 -maxiter 250 -filename CP_c_nodes=1_pp=1_dim=6_size=30_rank=5_restol=0.05.csv -pp_res_tol 0.05 -resprint 10




