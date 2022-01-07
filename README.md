# Algorithms 

Contents 
- Recursive and iterative algorithms and their T(n)
- Search and sort algorithms and their T(n) 
- Divide and conquer algorithms 
- Brute Force algorithms ( TSP)
- Trees (BT, BST , Heap , priority queues)
- Graphs ( direcetd, undirected , BFS , DFS , topological sort)
- Greedy algorithms 
- Dynamic programing
- Scheduling algorithms 

More details at https://programmingaltanai.wordpress.com/ 

## Time efficiency

Time efficiency is analyzed by determining the number of repetitions of the “basic operation”. It almost always depends on the size of the
input
-  “Basic operation”: the operation that contributes most towards the running time of the algorithm

If T(n) is the run time , Cop is the cost of basic operation and C(n) is the number of time the basic operation is excuted

    T(n) ≈ Cop ⨉ C(n)

### Prereq
Check if gdb is installed and updated
    
    sudo apt-get install build-essential gdb

    build-essential is already the newest version (12.4ubuntu1).
    gdb is already the newest version (8.1.1-0ubuntu1).

check if gcc is updated too

    gcc -v

    Using built-in specs.
    COLLECT_GCC=gcc
    COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/7/lto-wrapper
    OFFLOAD_TARGET_NAMES=nvptx-none
    OFFLOAD_TARGET_DEFAULT=1
    Target: x86_64-linux-gnu
    Configured with: ../src/configure -v --with-pkgversion='Ubuntu 7.5.0-3ubuntu1~18.04' --with-bugurl=file:///usr/share/doc/gcc-7/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++ --prefix=/usr --with-gcc-major-version-only --program-suffix=-7 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
    Thread model: posix
    gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04) 

### Compiling a C program 
The phases  of gcc Compiler converts a C program into an executable. 
1. Pre-processing
    This can be further broken down into 
    - Removal of Comments
    - Expansion of Macros
    - Expansion of the included files.
    - Conditional compilation

2. Compilation , is converting to assembly language for assembler

    gcc -Wall -save-temps ll.c -o ll.out 

3. Assembly

4. Linking - linking function call with defs and adding aextra ocee for setting up env



## Help/Hints 

1. Corrupt memeory errors **segmentation fault (core dumped) **

Core Dump/Segmentation fault is caused by accessing memory that “does not belong to you.” 
When a piece of code tries to do read and write operation in a read only location in memory or freed block of memory, it is known as core dump.


### Note 

There is a .githook file to remove binaries ( .out) before pushing to git. I suggest anyone using this repo to add the same process as well.



**References**

Sites 
- Standford University course on Algorithm Design and Analysis by Tim Tim Roughgarden 
- CS 161 https://web.stanford.edu/class/archive/cs/cs161/cs161.1138/
- Git https://github.com/TheAlgorithms/C-Plus-Plus 
- Github.io pages - https://walkccc.github.io/CLRS/
- MIT openCourseware - Introduction to Algorithms https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/lecture-videos/ 
- Video Lectures http://videolectures.net/mit6046jf05_introduction_algorithms/

Books 
- Introduction to Algorithms by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein( CLRS )
    - MIT press - Introduction to Algorithms, Third Edition https://mitpress.mit.edu/books/introduction-algorithms-third-edition
- https://code.visualstudio.com/docs/cpp/config-linux 
