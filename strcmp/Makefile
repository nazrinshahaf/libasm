alone:
	nasm -f macho64 ft_strcmp.s -o ft_strcmp.o && ld -macosx_version_min 10.15.7 -lSystem -o ft_strcmp ft_strcmp.o -e _ft_strcmp

test:
	nasm -f macho64 ft_strcmp.s -o ft_strcmp.o -F dwarf -g
	clang -o main.o -c main.c
	clang -o ft_strcmp ft_strcmp.o main.o
	./ft_strcmp
