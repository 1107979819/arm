.text
.global _start
_start:

	LDR R0,=0xE0200280
	LDR R1,=0x00001111
	STR R1,[R0]

	LDR R0,=0xE0200284
	MOV R1,#0;
	STR R1,[R0]
loop:
	B loop
