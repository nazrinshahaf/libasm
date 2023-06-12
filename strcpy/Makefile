alone:
	nasm -f macho64 ft_strcpy.s -o ft_strcpy.o && ld -macosx_version_min 10.15.7 -lSystem -o ft_strcpy ft_strcpy.o -e _ft_strcpy

test:
	nasm -f macho64 ft_strcpy.s -o ft_strcpy.o -F dwarf -g
	clang -o main.o -c main.c
	clang -o ft_strcpy ft_strcpy.o main.o
	./ft_strcpy
