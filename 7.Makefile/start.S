.global _start
.global main
_start:
	mov r0,#0x11
	mov r1,#0x22
	add r2,r0,r1
	bl main
loop:
	b loop

	.end
