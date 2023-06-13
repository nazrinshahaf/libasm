global _ft_write

; extern int ft_write(int filedes, const void *buf, size_t nbyte);

section __DATA,__data
	WRITE:	equ 0x2000004

	; rax funciton to call
	; rdi file descriptor
	; rsi string to write
	; rdx length of string

section __TEXT,__text
_ft_write:
	mov rax, WRITE	; move sys_write to rax register
	syscall			; perform syscall
	ret				; return to function call
