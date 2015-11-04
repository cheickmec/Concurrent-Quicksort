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
be 6000 after running some tests. The results were remarkably better for big containers.

List Size                Sequential Time (s)                          Concurrent Time (s)
                     min            max        average            min            max        average
---------           -----          -----       -------           -----          -----       -------
10                4.29e-05       5.59e-05     4.982e-05         4.34e-05       5.6e-05      5.024e-05 
100               0.0012326      0.0120211    0.00345726        0.0012577      0.0014084    0.0013462  
1000              0.0162889      0.0449601    0.0308797         0.0166794      0.0262041    0.0219854  
10000             0.17815        0.222454     0.206616          0.110755       0.151423     0.133348   
100000            2.14821        2.38503      2.2054            1.0419         1.11963      1.06739    
1000000           25.6446        27.6376      26.4366           12.126         12.8952      12.4336