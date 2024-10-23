# Codewars

## 8 KYU

Get character from ascii value.

```
#include <stdio.h>

char char_of_code (unsigned charcode)
{
  int res = charcode;
  return res;
}
```

---

String Concatenation in C

```
char* are_you_playing_banjo(const char* n) {
  char *r = (char*)calloc(strlen(n) + 20, 1);
  strcpy(r, n);
  strcat(r, (n[0] == 'R' || n[0] == 'r') ? " plays banjo" : " does not play banjo");
  return r;
}
```

---

Hex to Decimal

```
int hex_to_dec(const char *source) {
  return (int)strtol(source, NULL, 16);
}
```