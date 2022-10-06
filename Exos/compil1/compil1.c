#include <stdint.h>

void g() {}

uint32_t a;

__attribute__((naked)) void f()
{
    for (unsigned int i = 0; i <= a; i++)
    {
        g();
    }
}