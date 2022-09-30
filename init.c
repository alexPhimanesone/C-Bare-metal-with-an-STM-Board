void init_bss()
{
    extern int __bss_start, __bss_end;
    int* start_adress = &__bss_start;
    int* end_adress = &__bss_end;

    for (int* i = start_adress; i < end_adress; i++)
    {
        *i = 0;
    }
}