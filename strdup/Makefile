alone:
	nasm -f macho64 ft_strdup.s -o ft_strdup.o && ld -macosx_version_min 10.15.7 -lSystem -o ft_strdup ft_strdup.o -e _ft_strdup

test:
	nasm -f macho64 ft_strdup.s -o ft_strdup.o -F dwarf -g
	clang -o main.o -c main.c
	clang -o ft_strdup ft_strdup.o ft_strlen.o ft_strcpy.o main.o
	./ft_strdup
