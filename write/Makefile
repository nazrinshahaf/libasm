alone:
	nasm -f macho64 ft_write.s -o ft_write.o && ld -macosx_version_min 10.15.7 -lSystem -o ft_write ft_write.o -e _ft_write

test:
	nasm -f macho64 ft_write.s -o ft_write.o -F dwarf -g
	clang -o main.o -c main.c
	clang -o ft_write ft_write.o main.o
	./ft_write
