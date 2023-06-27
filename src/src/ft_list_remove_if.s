global _ft_list_remove_if

extern _malloc
extern _ft_list_new
extern _free

; extern void *ft_list_remove_if(t_list **begin_list, void *data, int (*cmp)(void*, void*));


; void		ft_remove_if(t_list **begin_list, void *data, int (*cmp)(void*, void*))
; {
; 	t_list		*current;
; 	t_list		*previous;
;
; 	previous = NULL;
; 	current = *begin_list;
; 	while (current)									; loop throught all the content of the list
; 	{
; 		if ((cmp)(current->data, data_ref) == 0)	; if cmp function returns 0
; 		{
; 			if (previous == NULL)					; if previous is NULL
; 				*begin_list = current->next;		; set begin of list to next
; 			else									
; 				previous->next = current->next;		; else set previous next to current next
; 			free(current);							; free current
; 		}
; 		previous = current;							; iter previous to current
; 		current = current->next;					; iter current to current->next
; 	}
; }

; typedef struct	s_list
; {
; 	void			*data;	8 bytes
; 	struct s_list	*next; 	8 bytes
; }					t_list;	16 bytes total

section __DATA,__data
	; rdi pointer to beggining of struct
	; rsi data pointer to compare to
	; rdx cmp function to use

	; r15 current
	; r14 previous

	; r13 store begin of list
	; r12 store data to compare
	; r11 store cmp function

section __TEXT,__text
_ft_list_remove_if:
	push rbp					; push rbp (base pointer) so that it can be returned at the end of stack frame (setting up stack frame)
	mov rbp, rsp				; move rsp to rbp (stack pointer) the current stack position to rbp which is the base of the stack
	sub rsp, 16					; grows the stack by 16 bytes for any variables being used

	mov r14, 0x0				; set previous(r14) to NULL
	mov qword r15, [rdi]		; set current(r15) to start of list
	mov r13, rdi				; store begin of list
	mov r12, rsi				; store data to compare
	mov r11, rdx				; store cmp function

	jmp ft_list_remove_loop

ft_list_remove_loop:
	cmp r15, 0x0				; check if current == NULL
	je return					; jump to return

	mov qword rdi, [r15]		; move current->data into rdi
	mov qword rsi, r12			; move data to comprae to rsi
	push r11
	call r11					; call function to compare
	pop r11
	
	cmp rax, 0					; if cmp function returned true
	je remove_node				; jump to remove node

inc_loop:
	mov r14, r15				; move previous = current
	mov qword r15, [r15 + 8]	; move current = current->next

	jmp ft_list_remove_loop		; jump back to start of loop

remove_node:
	cmp r14, 0x0					; check if previous is NULL
	je remove_first_node			; if previous is NULL jump to first_node

	; else remove node normally
	; previous->next = current->next
	mov r10, [r14 + 8]				; move previous->next to r10 temporarily
	mov qword r10, [r15 + 8]		; move current->next to previous->next
	mov qword [r14 + 8], r10		; set previous->next to r10
	jmp free_data					

remove_first_node:
	; *begin_list(*r13) = current->next(r15 + 8)
	mov r10, [r15 + 8]			; move current->next to r10 temporarily
	mov [r13], r10				; set *begin_list to current->next
	jmp free_data

free_data:
	mov rdi, r15				; move current to rdi
	call _free					; call free
	cmp rax, 0x0				; free returns a pointer to null on error

return:
	add rsp, 16					; lowers the stack by 16 bytes for any variables that were used
	pop rbp						; pop rbp pack so that it is back at the start of the stack frame
	ret							; return to function call


;3cf0
