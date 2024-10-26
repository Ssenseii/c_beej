[samwho-memory-allocation](https://samwho.dev/memory-allocation/)

# Memory Allocation

What the majority of programs do is:
    - Load Values from memory
    - Computer
    - Store back to memory

allocators exist because we have to use the memory efficiently.

---

## Malloc and Free

```
int main() {
  void *ptr = malloc(4);
  free(ptr);
  return 0;
}
```

it's pretty simple.

## Memory

smallest unit in memory that allocaters work with is a **Byte**
a **Byte** can hold any number from 0 to 255

malloc(4) allocated 4 bytes of memory: 4 * 8 = 32 bits.
malloc returns a pointer to the memory allocated
in a form called hexadecimal
31 = 0x1f

Here's a guide:
0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F


## coalescing

It's when you free memory and if there's free memory next to it, you combine them.
