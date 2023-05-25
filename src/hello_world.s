global _main

section __DATA,__data
	str: db "Hello, World"
	;str = name of mem address
	;db = "define bytes"

	.len: equ $ - str
	;.len = name of mem address
	;

section __TEXT,__text
_main:
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, str
	mov rdx, str.len
	syscall

	mov rax, 0x2000001
	xor rdi, rdi
	syscall
