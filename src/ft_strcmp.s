global _ft_strcmp

; extern int ft_strcmp(const char *s1, const char *s2);

section __DATA,__data
;	rdi s1
;	rsi s2

;	r9b s1 char
;	r10b s2 char

section __TEXT,__text
_ft_strcmp:

loop:
	cmp byte [rdi], 0x0			; cmp char to null
	je end_of_str				; jump if equal to null

	movzx r9d, byte [rdi]		; mov rdi char to r9b
	movzx r10d, byte [rsi]		; mov rsi char to r10b
	cmp byte r9b, byte r10b		; compare if s1_char and s2_char is diffrent
	jne char_diff

	inc rdi						; increament dst 
	inc rsi						; increament src
	jmp loop					; jump to loop_start

char_diff:
	sub r9, r10					; sub s2[] - s1[]
	mov rax, r9					; move result of subtraction to rax

	ret							; return to function call

end_of_str:
	movzx r9d, byte [rdi]		; mov rdi char to r9b
	movzx r10d, byte [rsi]		; mov rsi char to r10b

	cmp byte [rsi], 0x0			; cmp byte of s2 to null (if not equal that means the strings arent the same)
	jne char_diff				; jump, to char_diff

	mov rax, 0					; set return value to 0
	ret							; return to function call

; * since I want to store a 8byte char in to a register i have to used the appropriate size
; originally I was using r8 which led to it storing what i assume is the byte of the address of the
; first char or something
