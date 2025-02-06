# mergesort benchmark
compile using command: g++ -o mergesort mergesort.cpp

./mergesort<size>

#Benchmarking Centaurus 
1.ssh into centaurus and compile the code
2.slurm job with the benchmark.slurm 
sbatch bench.slurm

##
result
Benchmark results are saved in the results.txt file
##plotting
plot the results by using 
python3 results.py
