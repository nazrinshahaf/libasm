global _ft_strcpy

; extern char *ft_strcpy(const char *dst, const char *src);

section __DATA,__data
;	rdi destination dst
;	rsi source src
;	r8 dst original store
;	r9b registor or character store

section __TEXT,__text
_ft_strcpy:
	mov r8, rdi					; store the initial position of the dst
								; (as Im increamenting the pointer of rdi below)
								; and i want to return the initial position of dst

ft_strcpy_loop:
	cmp byte [rsi], 0x0			; cmp char to null
	je return					; jump if equal to null

	mov byte r9b, byte [rsi]	; move char to r8 register (the size of the registers have to match*)
	mov byte [rdi], byte r9b	; set char at dst[] to src[]
	inc rdi						; increament dst 
	inc rsi						; increament src
	jmp ft_strcpy_loop			; jump to loop_start

return:
	mov byte [r8], 0x0			; set src termination character to null
	mov rax, r8					; set r8 (originally stores dst) to the return value of function call

	ret							; return to function call

; * since I want to store a 8byte char in to a register i have to used the appropriate size
; originally I was using r8 which led to it storing what i assume is the byte of the address of the
; first char or something
