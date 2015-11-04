# Concurrent-Quicksort
=====================================================================================|
My system info																		 |
====|Processor: Intel(R) Core(TM) i5-5200U CPU @ 2.20Ghz 2.20 GHz					 |
====|RAM: 8.00 GB																	 |
====|OS: 64-bit Windows 10, x64-based processor										 |
=====================================================================================|
The program was initialy tested for the maximum threads allocated by the OS. 
A couple of runs revealed that number to be between 675 and 700 threads. At such
values, however, the performance dropped by 30% when the list was 1 million elements
long. This drop is most likely due to the overhead time for thread creation which 
would significantly increase with big list sizes.

The above issue required a restriction on the maximum number of threads that could 
be created in order to avoid excessive additional time in the vicinity of 1 million
threads. A few tests with changing values of the maximum threads an interesting 
behaviour with the multithreated approach having much lower minimum times and greater 
maximum times so the multithreaded version had better best case scenario and 
indesirable worst case scenarios.

Given the advantages and disadvantages of the best case and worst case scenarios 
respectively, the average case was the dividing factor. In that case, the allowable 
number of threads was fixed at 650 because it yielded better results overall.

Next, the container size requiring thread creation was to be adjusted to avoid 
unecessary thread creation for small container sizes. A desirable value happened to
be 610 after running some tests. The results were remarkably better for big containers.

List Size                Sequential Time (s)                          Concurrent Time (s)
                     min            max        average            min            max        average
---------           -----          -----       -------           -----          -----       -------
10                5.46e-05       0.0001638    8.995e-05         4.81e-05       0.0001801    8.425e-05
100               0.0008127      0.001554     0.00108769        0.0008155      0.0015549    0.0010712
1000              0.0099408      0.0133651    0.0106994         0.006516       0.0138103    0.00892692
10000             0.132187       0.178236     0.147821          0.0719737      0.100348     0.0806966
100000            1.67756        1.74689      1.7188            0.876486       1.14038      0.928192