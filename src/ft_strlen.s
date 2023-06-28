global _ft_strlen

section __DATA,__data
; 	EXIT:	equ 0x2000001
; 	WRITE:	equ 0x2000004
;
; 	STDOUT: equ 1

;	hello_str:	db "Hello"
; 	rdi string to pointer	
; 	rax increament counter 

section __TEXT,__text
_ft_strlen:
	; push rbp			; push rbp (base pointer) so that it can be returned at the end of stack frame (setting up stack frame)
	; mov rbp, rsp		; move rsp to rbp (stack pointer) the current stack position to rbp which is the base of the stack
	; sub rsp, 16			; grows the stack by 16 bytes/hex (not sure which) for any variables being used

	mov rax, 0			; mov 0 to increament counter	

loop_head:
	cmp byte [rdi], 0x0	; cmp char to null
	je return			; jump if equal to null

	inc rdi				; increament string
	inc rax				; increament counter
	jmp loop_head		; jump to loop_start

return:
	; add rsp, 16			; lowers the stack by 16 bytes/hex (not sure which) for any variables that were used
	; pop rbp             ; pop rbp pack so that it is back at the start of the stack frame

	ret					; return to function call
