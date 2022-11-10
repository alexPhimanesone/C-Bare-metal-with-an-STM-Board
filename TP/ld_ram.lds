MEMORY
    {
        flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
        sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
        sram2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
    }

/* commandes pour linker l'image en format binaire */
TARGET(binary)
INPUT(./image.raw)
OUTPUT_FORMAT(default)

SECTIONS
    {
        .text : {
            *(.text)
        } > sram1

        .rodata : {
            image = .;
            ./image.raw
            *(.rodata)
        } > sram1

        .data : {
            *(.data)
        } > sram1

        __bss_start = .;
        .bss : {
            *(.bss) *(COMMON)
        } > sram1
        __bss_end = .;
    }

_stack_start = ORIGIN(sram2) + LENGTH(sram2);

ENTRY(_start)