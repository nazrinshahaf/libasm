alone:
	nasm -f macho64 ft_list_size.s -o ft_list_size.o && ld -macosx_version_min 10.15.7 -lSystem -o ft_list_size ft_list_size.o -e _ft_list_size

test:
	nasm -f macho64 ft_list_size.s -o ft_list_size.o -F dwarf -g
	nasm -f macho64 ft_list_new.s -o ft_list_new.o -F dwarf -g
	clang -o main.o -c main.c
	clang -o ft_list_size ft_list_size.o ft_list_push_front.o ft_list_new.o main.o
	./ft_list_size
