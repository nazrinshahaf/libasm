alone:
	nasm -f macho64 ft_read.s -o ft_read.o && ld -macosx_version_min 10.15.7 -lSystem -o ft_read ft_read.o -e _ft_read

test:
	nasm -f macho64 ft_read.s -o ft_read.o -F dwarf -g
	clang -o main.o -c main.c
	clang -o ft_read ft_read.o main.o
	./ft_read
