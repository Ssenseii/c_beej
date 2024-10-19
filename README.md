# Learning C the Beej Way

[Beejs_Guide]{https://beej.us/guide/bgc/html/split/index.html}

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

*okay just found out about the existence of virtual memory... moving on...*

```
int i;      // declares an int
int *p;     // declares a pointer to an int. 

p = &i;  // p is assigned the address of i--p now "points to" i
```

### derefrencing pointers

okay, now we want to use the value that's being pointed at.
that's called derefrencing a pointer.

*p is derefrencing p.
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

to make a 3*3 identity matrix
int a[3][3] = {[0][0]=1, [1][1]=1, [2][2]=1};
should fill the rest with 0

you can manipulate functions using int *a in the function params.

void double_array(int *arr, int len)

## Strings 

they're also pointers, like arrays.
char *s  = "Hello Dumbass!"
char s[14] = "Hello Dumbass!" 

char *s = "Hello dumbass" will allocate a chunk of memory, read only, away from your program for safety and performance reasons.
so if you do s[0] = z. you're trying to change an immutable.
bad new: that's undefined behaviour. don't do it.

but if you use s[] = "Hello Dumbass!" ; s[0] = t, this is completely okay.

printf("The string is %zu bytes long.\n", strlen(s));
char *s = "Hello!";  // Actually "Hello!\0"
this is how the program knows when to end the string.

finding the string length is to count until we hit the /0.

instead of t = s (it just creates an other pointer), use strcpy(t, s);

## struct

we have no objects or classes.
we have structs.

struct car {
    char *name;
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

to pass it to a function, you have two options:
    - Pass the struct
    - Pass a pointer to the struct

You'd pass a pointer if
    - You want to make changes to the struct.
    - Struct is large and more expensive to copy

void set_price(struct car *Car, float price){
    car->price = price;
}

if you have a struct: use .
if you have a pointer to a struct: use ->

## File Input and Output

FILE* Data type.
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
fputs(char *s, fp);
fprintf(fp, "%d", x);


For Binaries:
Add a b after "w" or "r" to write/read binary files.  
fread() and fwrite() are your functions to operate on bytes.
