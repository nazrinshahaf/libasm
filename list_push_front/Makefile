alone:
	nasm -f macho64 ft_list_push_front.s -o ft_list_push_front.o && ld -macosx_version_min 10.15.7 -lSystem -o ft_list_push_front ft_list_push_front.o -e _ft_list_push_front

test:
	nasm -f macho64 ft_list_push_front.s -o ft_list_push_front.o -F dwarf -g
	nasm -f macho64 ft_list_new.s -o ft_list_new.o -F dwarf -g
	clang -o main.o -c main.c
	clang -o ft_list_push_front ft_list_push_front.o ft_list_new.o main.o
	./ft_list_push_front
