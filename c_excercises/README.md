# C  

Basics of using C programming language 

## storage classes 

**auto** accessed within the block/function they have been declared / inscope.
- assigned a garbage value by default whenever they are declared

**static** allocated memory in data segment, not stack segment.It remains in memory while the program is running

    static int i = 50;

- In C, static variables can only be initialized using constant literals

-  Static variables (like global variables) are initialized as 0 if not initialized explicitly.

**register** Registers are faster than memory to access so frequently used variables can be put in a register to hint compiker to optimize and put these caribles in registger.

    register int a = 10;

- Do not use & operator in register : variable is a register, it may be stored in a register instead of memory and accessing address of a register is invalid

- do not use static and register together since Register is a storage class and static is also a storage class . Both cannot be used together.,.

- Register can only be used within a block (local), it can not be used in the global scope  

**extern**  extends the variable/functions visibility to the whole program

    extern int var=10

## Memory

**Memeory Layout**

    > size ./a.out
    text    data     bss     dec     hex filename
    2115     624       8    2747     abb ./a.out

***malloc()** allocates memory block of given size (in bytes) and returns a pointer to the beginning of the block
- allocate memory at run time.  
- on being called ,  functions they take memory from and release the meory whever not required

    p = (datatype *)malloc(size);

- malloc() returns a void pointer to the first allocated byte of memory. 
- Before you can use the pointer you must cast it to appropriate type

    int *p; // p is pointer to int or (int*)
    p = (int*)malloc(20); // allocate 20 bytes contiguous of memory from the heap  

- Memory allocated contains garbage so do not try to dereference it before assigning proper values


**calloc()** contiguous allocation. allocates the memory and also initializes the allocated memory block to zero

    int *p;
    p = (int*)calloc(5, sizeof(int));

**realloc()** function is used to resize allocated memory without losing old data.

-  increase the size of the allocated memory to store 6 more integers. 
    - If sufficient memory is available following already used bytes then realloc() function allocates only allocates extra bytes next to already used bytes. I
    - If insufficient memeory exists , then it reallocates bytes of memory somewhere else in the heap and copies the content from the old memory block to the new memory block. 

## Data types 

**int** : 32-bit int data type can hold integer values in the range of −2,147,483,648 to 2,147,483,647.

**unsigned int** : 32-bit unsigned int data type can hold integer values in the range of 0 to 4,294,967,295


## Data Structures in C 

**string**  one-dimensional array of characters with a null character (escape sequence) ('\0') as it's the last element.

    char name[10] = {'s', 't', 'r', 'i', 'n', 'g' ,'\0'};


**structs** block of memory that stores several data objects, where those objects don't overlap


    struct student {
        char name[80];
        int age;
        float percentage;
    };
    emp = (struct student*) malloc(sizeof(struct student));


**Union** is a block of memory that stores several data objects, but has only storage for the largest of these, and thus can only store one of the data objects at any one time

    emp = (union student*) malloc(sizeof(union student));


**Arrow operator** in C/C++ allows to access elements in Structures and Unions. 

    emp->age = 18;




## Pointers 

We cannot have pointers to bit field members as they may not start at a byte boundary. 

**pointer-to-a-pointer** are used to reference a pointer.
If a pointer is passed in function , then any modification inside the function will be in local scope, not value change refelcted in original location.
By passing a pointer to pointer we can modify the original values.


**Dereferencing** is used to access or manipulate data contained in memory location pointed to by a pointer. *(asterisk) is used with pointer variable

    int *p; // Un-initialized Pointer
    p = &a; // Stores address of a in ptr
    b = *p; // Put Value at ptr in b


Whenever a pointer to an array is dereferenced we get the address (or base address) of the array to which it points.


------------------------------------------