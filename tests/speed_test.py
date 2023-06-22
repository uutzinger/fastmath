import time
import random
from fastmath import invSqrt, invSqrt_fast

repeat = 1000000

tic = time.perf_counter()
for i in range(repeat):
    x = random.uniform(4.0, 5.0)
toc = time.perf_counter()
rand_time = toc-tic

tic = time.perf_counter()
for i in range(repeat):
    x = random.uniform(4.0, 5.0)
    tmp = x**-0.5
toc = time.perf_counter()
print(f"x**-0.5 {(toc-tic-rand_time)/repeat*1000000:0.4f} micro seconds")  

tic = time.perf_counter()
for i in range(repeat):
    x = random.uniform(4.0, 5.0)
    tmp = invSqrt(x)
toc = time.perf_counter()
print(f"fastmath.invSqrt {(toc-tic-rand_time)/repeat*1000000:0.4f} micro seconds")  

tic = time.perf_counter()
for i in range(repeat):
    x = random.uniform(4.0, 5.0)
    tmp = invSqrt_fast(x)
toc = time.perf_counter()
print(f"fastmath.invSqrt_fast {(toc-tic-rand_time)/repeat*1000000:0.4f} micro seconds")  
