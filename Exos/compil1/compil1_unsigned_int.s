	.cpu arm7tdmi
	.arch armv4t
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 4
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"compil1.c"
	.text
	.align	2
	.global	g
	.syntax unified
	.arm
	.type	g, %function
g:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	@ link register save eliminated.
	bx	lr
	.size	g, .-g
	.align	2
	.global	f
	.syntax unified
	.arm
	.type	f, %function
f:
	@ Function supports interworking.
	@ Naked Function: prologue and epilogue provided by programmer.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	ldr	r3, .L5
	ldr	r2, [r3]
	mov	r3, #0
.L3:
	add	r3, r3, #1
	cmp	r3, r2
	bls	.L3
.L6:
	.align	2
.L5:
	.word	.LANCHOR0
	.size	f, .-f
	.global	a
	.bss
	.align	2
	.set	.LANCHOR0,. + 0
	.type	a, %object
	.size	a, 4
a:
	.space	4
	.ident	"GCC: (Arch Repository) 12.2.0"
