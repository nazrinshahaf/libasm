global _main
extern _printf

section __DATA,__data
	EXIT:	equ 0x2000001
	WRITE:	equ 0x2000004

	STDOUT: equ 1

	hello_str:	db "Hello, World",10
	len:	equ $ - hello_str

section __TEXT,__text
_main:
	mov r8, 0				; move exit code to r8
	mov r15, 0			; increament counter
	jmp write_hello		; jump to write_hello tag
	jmp exit				; jump to exit tag

loop:
	cmp r15, 15			; cmp r15 to 15
	je exit				; if previous value is true then execute
	
	jmp	write_num		; jmp to write_num 
	inc r15				; add 1 to r15
	jmp loop			; jump back to loop

write_hello:
	mov rax, WRITE		; syscall for sys_write
	mov rdi, STDOUT		; mov fd 1 to rdi register
	mov rsi, hello_str	; mov hello_str to rsi register 
	mov rdx, len		; mov the strlen to rdx register
	syscall				; execute sys_write syscall

exit:
	mov rax, EXIT		; syscall for sys_exit
	mov rdi, 0			; move exit code to rdi register
	syscall				; execute sys_exit syscall

; TODO
; find some way to pass arguemnts to ft_strlen
; figure out how to do go-to
; find someway to check for null
