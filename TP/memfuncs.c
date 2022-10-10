#include <stdint.h>


/* const uint8_t* : le pointeur varie mais les objets pointes sont constants */

void* memcpy(void* dest, const void* source, unsigned int size)
{
    uint8_t* i = (uint8_t*) dest;
    const uint8_t* j = (uint8_t*) source;
    for (unsigned int k = 0; k < size; k++)
    {
        *i = *j;
        i++;
        j++;
    }
    return dest;
}

/* on regarde la position relative de dest et source
pour savoir par ou commencer a copier source vers dest */
void* memmove(void* dest, const void* source, unsigned int size)
{
    if (dest < source)
    {
        return memcpy(dest, source, size);
    }
    else
    {
        uint8_t* i = (uint8_t*) (dest + size - 1);
        const uint8_t* j = (uint8_t*) (source + size - 1);
        while (size--)
        {
            *i = *j;
            i--;
            j--;
        }
        return dest;
    }
}

void* memset (void* dest, int value, unsigned int size)
{
    uint8_t* i = (uint8_t*) dest;
    while (size--)
    {
        *i = value;
        i++;
    }
    return dest;
}

int memcmp (const void* pointer1, const void* pointer2, unsigned int size)
{
    while (size--)
    {
        uint8_t* i = (uint8_t*) pointer1;
        uint8_t* j = (uint8_t*) pointer2;
        if (*i != *j)
        {
            return *i < *j ? -1 : 1;
        }
        i++;
        j++;
    }
    return 0;
}