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
	; mov r14, rdi			; move length of string to r14 (malloc touches a lot of registers idk why) (not used)
	add rdi, 1				; add 1 to rdi for null terminator length

	call _malloc			; call to malloc length of string already in rdi register
	jc set_error			; if call to malloc returns error jump to
	; check err here

	; mov r13, rax			; move the address that was malloced to r13 (not used)

	mov rdi, rax			; move address to be written to to rdi
	mov rsi, r12			; move string to copy to rsi
	call _ft_strcpy

	add rsp, 16				; lowers the stack by 16 bytes for any variables that were used
	pop rbp					; pop rbp pack so that it is back at the start of the stack frame
	ret						; return to function call

set_error:
	mov r8, rax				; save the original error value that was returned from malloc
	call ___error			; call the ___error function which returns a pointer to the position of the errno flag*

	mov [rax], r8			; dereference [errno] and set the return value of malloc in r8 into the address that errno is stored at
	mov rax, -1				; set return value of ft_strdup to -1

	add rsp, 16				; lowers the stack by 16 bytes for any variables that were used
	pop rbp             	; pop rbp pack so that it is back at the start of the stack frame
	ret						; return to function call

; * In C we use the errno global variable to set the errno of any errors that a function might have.
;	The actuall implementation of ___error and errno_location is hard to find without finding other 42
;	students stackoverflow questions. But the actual implementation looks like this.
;	extern int * __error(void);
;	You can find it if u go into errno.h
;	It returns a pointer the the memory address when errno is at.
