global _ft_list_sort

; extern void	ft_list_sort(t_list **begin_list, int (*cmp)())

; void	ft_list_sort(t_list **begin_list, int (*cmp)())
; {
; 	t_list	*a;
; 	t_list	*b;
;
; 	a = *begin_list;
; 	while (a != NULL)
; 	{
; 		b = *begin_list;
; 		while (b->next != NULL)
; 		{
; 			if ((*cmp)(b->data, b->next->data) > 0)
;			{
;				void	*data;
;
;				data = b->data;
; 				b->data = b->next->data;
; 				b->next->data = data;
;			}
; 			b = b->next;
; 		}
; 		a = a->next;
; 	}
; }

; typedef struct	s_list
; {
; 	void			*data;	8 bytes
; 	struct s_list	*next; 	8 bytes
; }					t_list;	16 bytes total

section __DATA,__data
	; rdi **list_begin
	; rsi cmp function

	; r15 store list_begin
	; r14 store cmp function
	; r13 a
	; r12 b

section __TEXT,__text
_ft_list_sort:
	push rbp					; push rbp (base pointer) so that it can be returned at the end of stack frame (setting up stack frame)
	mov rbp, rsp				; move rsp to rbp (stack pointer) the current stack position to rbp which is the base of the stack
	sub rsp, 16					; grows the stack by 16 bytes for any variables being used

	mov r15, rdi				; store begin list in r15
	mov r14, rsi				; store cmp function in r14
	mov r13, [r15]				; set r13 to *begin_list

	jmp ft_list_outer_loop		; jump to ft_list_outer_loop

ft_list_outer_loop:
	cmp r13, 0x0				; check if a is NULL
	je return					; if null then end of list and return

	mov r12, [r15]				; set r12(b) to *begin_list
	jmp ft_list_inner_loop		; jump to inner loop

inc_outer_loop:
	mov qword r13, [r13 + 8]	; set r13(a) to a -> next 
	jmp ft_list_outer_loop		; jump back to start of loop

ft_list_inner_loop:
	cmp qword [r12 +  8], 0x0	; check if b->next is NULL
	je inc_outer_loop			; jump back to outer loop

	mov qword rdi, [r12]		; move b->data to rdi for function call
	mov r11, [r12 + 8]			; temp store b->next->data to r11
	mov rsi, [r11]				; mov b->next->data to rsi 
	call r14					; call cmp function

	cmp rax, 0					; check if return value > 0
	jg swap						; swap elements if return value more than 0

inc_inner_loop:
	mov r12, [r12 + 8]			; set b = b->next
	jmp ft_list_inner_loop		; jump back to inner loop

swap:
	; data = b->data | step 1
	; b->data = b->next->data | step 2
	; b->next->data = data | step 3

	; r12 b
	; rax b->next
	mov r11, [r12]				; store r12(b->data) to r11 | step 1
	mov rax, [r12 + 8]			; move r12(b->next) to rax

	; r10 b->next->data
	; b->data = b->next->data | step 2
	; [r12], r10
	mov r10, [rax]				; move r10(b->next->data) to r10
	mov [r12], r10				; set b->data to b->next->data | step 2

	; rax b->next
	; r11 b->data
	; b->next->data = data | step 3
	; [rax] = r11
	mov rax, [r12 + 8]			; move b->next->data to rax
	mov [rax], r11				; set b->next->data to r11 | step 3

	jmp inc_inner_loop			; jump back to inner loop

return:
	add rsp, 16					; lowers the stack by 16 bytes for any variables that were used
	pop rbp						; pop rbp pack so that it is back at the start of the stack frame
	ret							; return to function call
