#include "libc.h"
#include <stdio.h>

int main()
{
    char buf[1024] = {0};

    read_data(buf, 1024);
    printf("%s\n", buf);
    return 0;
}