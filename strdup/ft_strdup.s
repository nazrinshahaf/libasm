global _ft_strdup

extern ___error
extern _malloc
extern _ft_strlen
extern _ft_strcpy

; extern char *ft_strdup(const char *s1);

section __DATA,__data
	WRITE:	equ 0x2000004

	; rax function to call

	; rdi string to copy

	; r12 string to copy
	; r13 address of malloced data (not used)
	; r14 length of string to copy (not used)

section __TEXT,__text
_ft_strdup:
	push rbp				; push rbp (base pointer) so that it can be returned at the end of stack frame (setting up stack frame)
	mov rbp, rsp			; move rsp to rbp (stack pointer) the current stack position to rbp which is the base of the stack
	sub rsp, 16				; grows the stack by 16 bytes for any variables being used

	mov r12, rdi			; move string to copy to r12 register

	call _ft_strlen			; call to strlen string is already in rdi register
	mov rdi, rax			; move length of string to rdi register
	add rdi, 1				; add 1 to rdi for null terminator length

	call _malloc			; call to malloc length of string already in rdi register
	cmp rax, 0x0			; if malloc returns error it returns pointer to NULL
	je error_return			; if call to malloc returns error jump to errro_return *

	mov rdi, rax			; move address to be written to to rdi
	mov rsi, r12			; move string to copy to rsi
	call _ft_strcpy

	add rsp, 16				; lowers the stack by 16 bytes for any variables that were used
	pop rbp					; pop rbp pack so that it is back at the start of the stack frame
	ret						; return to function call

error_return:
	add rsp, 16				; lowers the stack by 16 bytes for any variables that were used
	pop rbp             	; pop rbp pack so that it is back at the start of the stack frame
	ret						; return to function call

;	* If scenenario where malloc returns error, it will set errno to appropriate error
;	so I dont have to do it. I just have to ensure that I compare rax to NULL and
;	return early
