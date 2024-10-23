#include <stdio.h>

int main(void)
{
    FILE *fp;
    unsigned char bytes[6] = {5, 7, 0, 8, 124, 21};
    unsigned char c;

    fp = fopen("output.bin", "wb");

    fwrite(bytes, sizeof(char), 6, fp);

    fclose(fp);

    fopen("output.bin", "rb");

    while (fread(&c, sizeof(char), 1, fp) > 0){
        printf("%d\n", c);
    }

    fclose(fp);
}