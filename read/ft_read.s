global _ft_read

; extern int ft_read(int filedes, const void *buf, size_t nbyte);

section __DATA,__data
	READ:	equ 0x2000003

	; rax function to call
	; rdi file descriptor
	; rsi buff to fill read with
	; rdx length to read

section __TEXT,__text
_ft_read:
	mov rax, READ	; move sys_read to rax register
	syscall			; perform syscall
	ret				; return to function call
