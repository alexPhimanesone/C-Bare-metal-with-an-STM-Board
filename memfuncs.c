/* const void* : le pointeur varie mais les objets pointes sont constants */

void* memcpy(void* dest, const void* source, size_t size)
{
    void* i = dest;
    const void* j = source;
    for (size_t k = 0; k < size; k++)
    {
        *i = *j;
        i++;
        j++;
    }
    return dest;
}

/* on regarde la position relative de dest et source
pour savoir par ou commencer a copier source vers dest */
void* memmove(void* dest, const void* source, size_t size)
{
    if (dest < source)
    {
        memcpy(dest, source, size)
    }
    else
    {
        void* i = dest + size - 1;
        const void* j = source + size - 1;
        while (size--)
        {
            *i = *j;
            i--;
            j--;
        }
        return dest;
    }
}

void* memset (void* dest, int value, size_t size)
{
    void* i = dest;
    while (size--)
    {
        *i = value;
        i++
    }
    return dest;
}

int memcmp (const void* pointer1, const void* pointer2, size_t size)
{
    while (size--)
    {
        if (*pointer1 != *pointer2)
        {
            return *pointer1 < *pointer2 ? -1 : 1;
        }
        pointer1++;
        pointer2++;
    }
    return 0;
}