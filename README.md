# Learning C the Beej Way

{Beejs_Guide}[https://beej.us/guide/bgc/html/split/index.html]

## Small things I should remember

x + y > 10 ? 1 : 0;
will print 1 if the result is bigger than 10, otherwise it'll print 0;

printf("The number %d is %s.\n", x, x % 2 == 0? "even": "odd");

## i++ && ++i

i = 1;
10 + i++ = 11;
10 + ++i = 12; (increment then evaluate)

## sizeof()

printf("%zu\n", sizeof(int)); // print 4;
printf("%zu\n", sizeof(char)); // print 1;

## functions and copies

```
#include <stdio.h>

void increment(int a){
    a++;
}

int main(void){
    int i = 10;
    increment(i);
    printf("i == %d\n", i);  // prints:  ** 10 **
}
```

you can write the prototype of a function, write the main, then the function.
but when you have an empty params list, use void inside the parenthesis of the prototype.

## Pointers

Memory is like a massive array of cells.
each byte of the memory is identified
an int uses 4 cells (4 bytes) "they sit next to eachother"
a char only uses one cell (1 byte)

a pointer is a variable that can hold the address of a cell.
other names include: index to memory, address, location...

& gives you the address of a variable.

```
printf("the address is %p\n", (void *)&x);      /// 0x7ffddf7072a4
```

_okay just found out about the existence of virtual memory... moving on..._

```
int i;      // declares an int
int *p;     // declares a pointer to an int.

p = &i;  // p is assigned the address of i -- p now "points to" i
```

### derefrencing pointers

okay, now we want to use the value that's being pointed at.
that's called derefrencing a pointer.

" \*p is derefrencing p ".
meaning that whatever p points at is being manipulated, in this case its i.

As a general rule, if you want the function to modify the thing that you’re passing in such that you see the result, you’ll have to pass a pointer to that thing.

## Arrays

To get the size of the array: you devide the size of the array (sizeof(arr)) on the size of its type (sizeof(int))

to set an entire array to zeros, there's a small shortcut
int a[100] = {0};

or you can fill a middle part by setting an initializer from a certain index
int a[10] = {0, 11, 22, [5]=55, 66, 77};
[0, 11, 22, 0, 0, 55, 66, 77, 0, 0]

dude I totally forgot about multidimensional arrays;
int a[10];
int b[2][7];
int c[4][5][6];

to make a 3\*3 identity matrix
int a[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
should fill the rest with 0

you can manipulate functions using int \*a in the function params.

void double_array(int \*arr, int len)

## Strings

they're also pointers, like arrays.
char \*s = "Hello Dumbass!"
char s[14] = "Hello Dumbass!"

char \*s = "Hello dumbass" will allocate a chunk of memory, read only, away from your program for safety and performance reasons.
so if you do s[0] = z. you're trying to change an immutable.
bad new: that's undefined behaviour. don't do it.

but if you use s[] = "Hello Dumbass!" ; s[0] = t, this is completely okay.

printf("The string is %zu bytes long.\n", strlen(s));
char \*s = "Hello!"; // Actually "Hello!\0"
this is how the program knows when to end the string.

finding the string length is to count until we hit the /0.

instead of t = s (it just creates an other pointer), use strcpy(t, s);

## struct

we have no objects or classes.
we have structs.

struct car {
char \*name;
float price;
int speed;
}

struct car Ford.

ford.name = "Fiesta".
ford.price = 15000
ford.speed = 170;
or
struct car Ford = {"Fiesta", 15000, 170}
or
struct car Ford = {.speed=15000, .name="Fiesta"}; // doesn't need order.

to pass it to a function, you have two options: - Pass the struct - Pass a pointer to the struct

You'd pass a pointer if - You want to make changes to the struct. - Struct is large and more expensive to copy

void set_price(struct car \*Car, float price){
car->price = price;
}

if you have a struct: use .
if you have a pointer to a struct: use ->

## File Input and Output

FILE\* Data type.
it holds all info needed to communicate with the I/O subsystem.
referred to as Streams.

current streams:
stdin: for the keyboard input
stdout: for the screen

printf("Hello Dumbass!");
fprintf(stdout, "Hello Dumbass!"); same thing.

streams are either "text" or "binary".

general rule: if you are able to edit the file in a text editor, its a text file, otherise its binary

for writing in files you can use
fputs(char \*s, fp);
fprintf(fp, "%d", x);

For Binaries:
Add a b after "w" or "r" to write/read binary files.  
fread() and fwrite() are your functions to operate on bytes.

## Typedef

typedef int antelope
intelop x = 1;

typedef is used in scoping -more on that later-
typedef is used with structs

typedef struct animal {
char \*name;
int speed;
} Animal;

Animal.name = "Sea Horse";

```
typedef struct {
    int x, y;
} point;

point p = {.x=20, .y=40};

printf("%d, %d\n", p.x, p.y);  // 20, 40
```

it also helps if you have to change like a gazillion floats into a double.

Some creates types of pointers. better not, I'd rather see the \*

## Pointer 2 - Arithmetics Time.

when we add 1 to the pointer, it knows to jumb how many bytes (sizeof(whatever)) long. landing it in the next array item.

```
#include <stdio.h>

int my_strlen(char *s)
{
    // Start scanning from the beginning of the string
    char *p = s;

    // Scan until we find the NUL character
    while (*p != '\0')
        p++;

    // Return the difference in pointers
    return p - s;
}

int main(void)
{
    printf("%d\n", my_strlen("Hello, world!"));  // Prints "13"
}
```

### Array Pointer Equivalence

The fundamental Array Pointer Equivalence:
a[b] = _(a + b)
arr[i] = _(arr + i)

the big difference is that you can make the pointer point to a difference address, while the array can't.

also, if you havea function call with a pointer, you can either pass a pointer or an array

```
char s[] = "Antelopes";
char *t = "Wombats";

printf("%d\n", my_strlen(s));  // Works!
printf("%d\n", my_strlen(t));  // Works, too!

```

there are also void\* : void pointers (for when you don't know what kind of data you're gonna get)

like memcpy, we can either use it with chars.

```
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "Goats!";
    char t[100];

    memcpy(t, s, 7);  // Copy 7 bytes--including the NUL terminator!

    printf("%s\n", t);  // "Goats!"
}
```

or ints

```
 can copy some ints:

#include <stdio.h>
#include <string.h>

int main(void)
{
    int a[] = {11, 22, 33};
    int b[3];

    memcpy(b, a, 3 * sizeof(int));  // Copy 3 ints of data

    printf("%d\n", b[1]);  // 22
}
```

## Memory Allocation

Most languages have garbage collectors, reference counting...
C doesn't.

You can tell C to allocate a chunk of bytes from memory.
and they will persist, until you free them
if you don't, that's what we call a **Memory Leak**
meaning the process will continue to allocate that memory until you close the program.

Automatic Local Variables are allocated on "_the stack_",
Manually Allocated Memory is allocated on "_the heap_".

_If you manually allocated it, you have to manually free it when you’re done with it._

### malloc() and free()

_malloc_ accepts a number of bytes to allocate, returns a void pointer to that new block, meaning we can assign it any type we want.

```
int *p = malloc(sizeof(int));

*p = 12;  // Store something there

printf("%d\n", *p);  // Print it: 12

free(p);  // All done with that memory

```

always check if it returns a NULL value

```
int *x = malloc(sizeof(*x));

if(x == NULL){
    printf("Error Allocating an int.\n");
}
```

How to allocate space for an array?
malloc(sizeof(type_of_elements) \* number_of_elements);

difference between malloc and calloc?

```
// Allocate space for 10 ints with calloc(), initialized to 0:
int *p = calloc(10, sizeof(int));

// Allocate space for 10 ints with malloc(), initialized to 0:
int *q = malloc(10 * sizeof(int));
memset(q, 0, 10 * sizeof(int));   // set to 0
```

result is the same, except calloc initializes it with 0.

realloc?
you can reallocate memory using realloc byt giving it the previously allocated memory and the **number of bytes** needed:
realloc(m, sizeof(int) \* number_of_elements)

**Alligned Memory :**

okay, this is a lil too advanced considering we JUST learned how to allocate memory

just remember: _Avoid needing to reallocate custom-aligned data._
and you might need custom-aligned data when you're working with embeded-systems programming.

## Scope

What variables are visible in what context
file scope = global scope??

## Types II : More Types

a signed type is anything that can be either positive or negative.
unsigned: only hold positive numbers

why unsigned? you can get larger numbers.

char is a small int.
char can either be signed or unsigned, you need to be specific about it.
signed char's maximum is 127 and minimum is 128
unsigned's max is 255.

just keep the things in the range of char.

<limits.h> defines the minimum and maximum values of these types.
short int
long int
long long int

Type                Min. Bytes     min             Max
unsigned char   	    1	        0	    255
unsigned short  	    2	        0	    65535
unsigned int    	    2	        0	    65535
unsigned long   	    4	        0	    4294967295
unsigned long long	    8	        0	    18446744073709551615

---

***Intermission - Practicing Pointers***

int *p 
/// declaring a pointer of type int: it will hold an address

int x = 10; p = &x;     
/// we're assigning the pointer to x by giving it its address

printf("%d\n", *p);
/// we're derefrencing a pointer by using the * to access the value inside the address

*p = 20;
/// we're changing the value of x using its pointer

int **pp = &p;
/// this is a pointer that points to a pointer that has the address of x. 

int *arr = (int*)malloc(5 * sizeof(int));
/// we're trying to allocate a int type array of size 5 manually.

*(arr + 2) = 50;
/// arr[2] = 50

void increment(int *n) { (*n)++; }
increment(&x);
/// we're creating a function that takes a pointer to an integer and increments it by 1.

void (*funcPtr)(int*) = increment;
funcPtr(&x);
/// We're basically creating a pointer to a function by defining the type of param and result.
*This can be useful for callbacks or when the function to call is determined at runtime.*

struct Point { int x, y; };
struct Point p1 = {3, 4}, *ptr = &p1;
printf("%d\n", ptr->x);
/// We create a struct, then we create a pointer to that struct, then we use it to access the x value.

---


### Constant Numeric Types

Hexadecimal and Octal:

int a = 0xA12B
printf("%x", a); /// prints "1a2b"

int a = 012;
printf("%o", a)  /// prints 12

there's an unofficial extension in many C compilers that allows you to represent a binary number:

int x = 0b101010;
printf("%d/n", x); // prints 42;

you can add types at the end of numbers to be more precise:
long int x = 122L
long long int x = 125L

unsiffixed floats are actually double.
so impend f at then end if you want it to force it to be a float.
and a double has no suffix
but long double: 
long double x = 1234.564L

you can print scientific notation using %e.


double x = 0xa.1p3;
printf("%a\n", x);  // 0x1.42p+6

this is insanity we'll deal with later when we need to.

## Conversions

