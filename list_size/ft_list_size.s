global _ft_list_size

; extern int ft_list_size(t_list *list);

; int ft_lstsize(t_list *lst)
; {
; 	size_t	i;
;
; 	i = 0;						; initialize length of counter to 0
; 	while (lst)					; while list is not null
; 	{
; 		lst = lst->next;
; 		i++;
; 	}
; 	return (i);
; }

; typedef struct	s_list
; {
; 	void			*data;	8 bytes
; 	struct s_list	*next; 	8 bytes
; }					t_list;	16 bytes total

section __DATA,__data
	; rax int to return
	; rdi the beginning of the list
	; r14 counter for list len

	; r15 pointer to beggining of struct (dont touch)
	; r14 next item in the list

section __TEXT,__text
_ft_list_size:
	mov r14, 0					; initialize length of counter to 0
	mov r15, rdi				; move the start of the list to r15

list_size_loop:
	cmp qword r15, 0x0			; cmp (list) to see if list is null
	je return					; jump to return if list is null
	
	mov qword r15, [r15 + 8]	; move next to r15
	inc r14						; inc length of list
	jmp list_size_loop					; jump back to list_size_loop

return:
 	mov r14, rax				; move r14 to rax for return value
	ret							; return to function call
