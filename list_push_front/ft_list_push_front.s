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
; 		*begin_list = list;
; 	}
; }

; typedef struct	s_list
; {
; 	void			*data;
; 	struct s_list	*next;
; }				t_list;

section __DATA,__data
	; WRITE:	equ 0x2000004

	; rax function to call

	; rdi pointer to beggining of struct
	; rsi void pointer of element to put in

	; r15 pointer to beggining of struct (dont touch)
	; r14 data to put into struct
	; r14 new list_begin

section __TEXT,__text
_ft_list_push_front:
	push rbp					; push rbp (base pointer) so that it can be returned at the end of stack frame (setting up stack frame)
	mov rbp, rsp				; move rsp to rbp (stack pointer) the current stack position to rbp which is the base of the stack
	sub rsp, 16					; grows the stack by 16 bytes for any variables being used

	mov r15, rdi				; move the start of the list to r15
	mov r14, rsi				; move the data pointer to r14

	cmp qword [r15], 0x0		; check if list_begin points to NULL 
	je empty_list				; jump if list_begin points to NULL

	mov rdi, r14				; mov r14 to rdi for ft_list_new(void *data)
	push r15					; push r15 off the stack to preserve value
	call _ft_list_new			; call ft_list_new
	cmp rax, 0x0				; check if ft_list_new returns malloc error
	je return					; jump to return

	pop r15						; pop r15(pointer to **list_start) off the stack to regain the value
	mov qword [rax + 8], r15	; list->next = list_begin
	mov qword [r15], rax		; *list_begin = list

	jmp return

empty_list:
	mov rdi, r14				; mov r14 to rdi for ft_list_new(void *data)
	push r15
	call _ft_list_new			; call ft_list_new
	cmp rax, 0x0				; check if ft_list_new returns malloc error

	pop r15
	mov [r15], rax				; set the beggining of the list to the newly malloced data
	mov rax , r15

return:
	add rsp, 16					; lowers the stack by 16 bytes for any variables that were used
	pop rbp						; pop rbp pack so that it is back at the start of the stack frame
	ret							; return to function call


; r15 = **list_begin
; rax = *list_new
; r13 = *list_begin
; mv [rax + 8], r13
