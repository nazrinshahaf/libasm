global _ft_read

extern ___error

; extern int ft_read(int filedes, const void *buf, size_t nbyte);

section __DATA,__data
	READ:	equ 0x2000003

	; rax function to call
	; rdi file descriptor
	; rsi buff to fill read with
	; rdx length to read
	; r8 used to store the errno of sys_read

section __TEXT,__text
_ft_read:
	push rbp				; push rbp (base pointer) so that it can be returned at the end of stack frame (setting up stack frame)
	mov rbp, rsp			; move rsp to rbp (stack pointer) the current stack position to rbp which is the base of the stack
	sub rsp, 16				; grows the stack by 16 bytes for any variables being used

	mov rax, READ			; move sys_read to rax register
	syscall					; perform syscall

	jc set_error			; if syscall in MacOS returns an error carry flag is set
	
	add rsp, 16				; lowers the stack by 16 bytes for any variables that were used
	pop rbp             	; pop rbp pack so that it is back at the start of the stack frame
	ret						; return to function call

set_error:
	mov r8, rax				; save the original error value that was returned from read
	call ___error			; call the ___error function which returns a pointer to the position of the errno flag*

	mov [rax], r8			; dereference [errno] and set the return value of read in r8 into the address that errno is stored at

	add rsp, 16				; lowers the stack by 16 bytes for any variables that were used
	pop rbp             	; pop rbp pack so that it is back at the start of the stack frame
	ret						; return to function call


; * In C we use the errno global variable to set the errno of any errors that a function might have.
;	The actuall implementation of ___error and errno_location is hard to find without finding other 42
;	students stackoverflow questions. But the actual implementation looks like this.
;	extern int * __error(void);
;	You can find it if u go into errno.h
;	It returns a pointer the the memory address when errno is at.
