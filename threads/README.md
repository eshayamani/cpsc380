CPSC 380
Assignment 5: Thread Synchronization


Esha Yamani 2337310
Sophia Guarnotta 2369941


Files Created:
checksum.h
checksum.cpp
producer.h
producer.cpp
consumer.h
consumer.cpp
prodcon.cpp


To run program:
g++ -o prodcon prodcon.cpp
./prodcon <num_items>


Errors:
1. Checksums don't ever mathch, we tried fixing it but we can't figure out the issue
2. If num_items goes over 10, then we get a shared memory issue that we also don't know how to fix
3. It might not really work that well but we tried :)

References:
geeks for geeks for implementation parts
lucas and arman helped with errors and certain parts of the implementation