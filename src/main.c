#include <stdio.h>
#include "emu_assert.h"

int main()
{
    printf("Hello Emu8051\n");
    EMU_ASSERT(1==2);
    return 0;
}
