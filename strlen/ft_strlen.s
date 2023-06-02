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
	push rbp			; create stack frame??
	mov rbp, rsp		; setting up stack idk what the fuck this does
	sub rsp, 16			; setting up stack idk what the fuck this does 

	mov rax, 0			; mov 0 to increament counter	

loop_head:
	cmp byte [rdi], 0x0	; cmp char to null
	je return			; jump if equal to null

	inc rdi				; increament string
	inc rax				; increament counter
	jmp loop_head		; jump to loop_start

return:
	add rsp, 16			; clearing up stack idk what the fuck this does
	pop rbp             ; restore the base pointer??

	ret					; return to function call
