global _ft_list_new

extern _malloc

; extern void *ft_list_new(void *data);

; t_list	*ft_create_elem(void *data)
; {
; 	t_list	*list;
;
; 	list = NULL;
; 	list = malloc(sizeof(t_list));		; malloc
; 	if (list)							; check if malloc returns anything
; 	{
; 		list->data = data;				; assign data
; 		list->next = NULL;				; assign next
; 	}
; 	return (list);						; return list
; }

; typedef struct	s_list
; {
; 	void			*data;	8 bytes
; 	struct s_list	*next; 	8 bytes
; }					t_list;	16 bytes total

section __DATA,__data
	; WRITE:	equ 0x2000004

	; rax function to call
	; rdi data to assign

section __TEXT,__text
_ft_list_new:
	push rbp				; push rbp (base pointer) so that it can be returned at the end of stack frame (setting up stack frame)
	mov rbp, rsp			; move rsp to rbp (stack pointer) the current stack position to rbp which is the base of the stack
	sub rsp, 16				; grows the stack by 16 bytes for any variables being used

	mov r15, rdi			; save data to assign in r15

	mov rdi, 16				; move size of t_list node to rdi;
	call _malloc			; call malloc
	cmp rax, 0x0			; check if malloc returns 0
	je malloc_error			; jump if malloc error and early return

	mov [rax], r15			; move r15 to the memory address of rax
	mov byte [rax + 8], 0x0		; point next to NULL

	add rsp, 16				; lowers the stack by 16 bytes for any variables that were used
	pop rbp					; pop rbp pack so that it is back at the start of the stack frame
	ret						; return to function call

malloc_error:
	add rsp, 16				; lowers the stack by 16 bytes for any variables that were used
	pop rbp					; pop rbp pack so that it is back at the start of the stack frame
	ret						; return to function call
