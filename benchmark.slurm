
!#/bin/bash
#SBATCH --job-name=mergesort_benchmark
#SBATCH --output=benchmark_output.txt
#SBATCH --time=00:30:00
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
g++ -o mergesort mergesort.cpp 

for size in 10 100 1000 10000 100000 1000000 10000000 100000000 1000000000
do
 ./mergesort $size >> results.txt
done
