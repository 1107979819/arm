.text
.global _start
_start:
	BL main
	B loop
loop:
	B loop
