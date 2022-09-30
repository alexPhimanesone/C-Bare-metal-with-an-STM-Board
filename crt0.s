	.syntax unified
	.global _start
	.thumb

_start:
	ldr sp, =0x10008000
	bl init_bss
	bl main
