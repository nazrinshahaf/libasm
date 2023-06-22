global _ft_list_push_front

extern _malloc
extern _ft_list_new

; extern void *ft_list_push_front(t_list **begin_list, void *data);

; void	ft_list_push_front(t_list **begin_list, void *data)
; {
; 	t_list	*list;
;	if (*begin_list == NULL)					// if list is empty
; 		*begin_list = ft_create_elem(data);		// set start of list to new list
;	else										// else create new element and push back
; 	{
; 		list = ft_create_elem(data);			// create new element
; 		list->next = *begin_list;				// set new element next to previous begin
; 		*begin_list = list;						// set begin_list to list
; 	}
; }

; typedef struct	s_list
; {
; 	void			*data;	8 bytes
; 	struct s_list	*next; 	8 bytes
; }					t_list;	16 bytes total

section __DATA,__data
	; WRITE:	equ 0x2000004

	; rax function to call

	; rdi pointer to beggining of struct
	; rsi void pointer of element to put in

	; r13 pointer to beggining of struct (dont touch)
	; r14 data to put into struct

section __TEXT,__text
_ft_list_push_front:
	push rbp					; push rbp (base pointer) so that it can be returned at the end of stack frame (setting up stack frame)
	mov rbp, rsp				; move rsp to rbp (stack pointer) the current stack position to rbp which is the base of the stack
	sub rsp, 16					; grows the stack by 16 bytes for any variables being used

	mov r13, rdi				; move the start of the list to r13
	mov r14, rsi				; move the data pointer to r14

	cmp qword [r13], 0x0		; check if list_begin points to NULL 
	je empty_list				; jump if list_begin points to NULL

	mov rdi, r14				; mov r14 to rdi for ft_list_new(void *data)
	call _ft_list_new			; call ft_list_new
	cmp rax, 0x0				; check if ft_list_new returns malloc error
	je return					; jump to return if ft_list_new returns NULL

	mov r12, [r13]				; move *list_start to r12
	mov qword [rax + 8], r12	; set new_list->next to *list_start
	mov qword [r13], rax		; set *list_begin = new_list

	jmp return					; jump to return

empty_list:
	mov rdi, r14				; mov r14 to rdi for ft_list_new(void *data)
	call _ft_list_new			; call ft_list_new
	cmp rax, 0x0				; check if ft_list_new returns malloc error
	je return					; jump to return if ft_list_new returns NULL

	mov [r13], rax				; set *list_begin = new_list

	jmp return					; jump to return

return:
	add rsp, 16					; lowers the stack by 16 bytes for any variables that were used
	pop rbp						; pop rbp pack so that it is back at the start of the stack frame
	ret							; return to function call
