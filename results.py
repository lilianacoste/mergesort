
import matplotlib.pyplot as plt
sizes =[]
times=[]
with open("results.txt","r") as file:
    for line in file:
        parts= line.split(",")
        size=int(parts[0].split(":")[1].strip())
        time = float(parts[1].split(":")[1].strip().split()[0])
plt.figure(figsize=(8,6))
plt.plot(sizes,times,marker="o",linestyle="-")
plt.xlabel("Input Size(log scale)")
plt.ylabel("Execution Time(ms,log scale)")
plt.legend()
plt.grid(True)
plt.savefig("benchmark_plot.png")
plt.show()

