all:
	# nasm -f macho64 ft_strlen.s -o ft_strlen.o && arch -x86_64 ld ft_strlen.o -o ft_strlen -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e ft_strlen -arch x86_64
	nasm -f macho64 ft_strlen.s -o ft_strlen.o -F dwarf -g
	ld -macosx_version_min 10.15.7 -lSystem -o ft_strlen ft_strlen.o -e _ft_strlen

test:
	# nasm -f macho64 ft_strlen.s -o ft_strlen.o && arch -x86_64 ld ft_strlen.o -o ft_strlen -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e ft_strlen -arch x86_64 && ./ft_strlen
	nasm -f macho64 ft_strlen.s -o ft_strlen.o -F dwarf -g
	# ld -macosx_version_min 10.15.7 -lSystem -o ft_strlen ft_strlen.o -e _ft_strlen
	clang -o main.o -c main.c
	clang -o ft_strlen ft_strlen.o main.o
	./ft_strlen
	
debug:
	# nasm -f macho64 ft_strlen.s -o ft_strlen.o && arch -x86_64 ld ft_strlen.o -o ft_strlen -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e ft_strlen -arch x86_64 && ./ft_strlen
	nasm -f macho64 ft_strlen.s -o ft_strlen.o -F dwarf -g
	ld -macosx_version_min 10.15.7 -lSystem -o ft_strlen ft_strlen.o -e _ft_strlen && lldb ./ft_strlen

d:
	# nasm -f macho64 ft_strlen.s -o ft_strlen.o && arch -x86_64 ld ft_strlen.o -o ft_strlen -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e ft_strlen -arch x86_64 && ./ft_strlen
	nasm -f macho64 ft_strlen.s -o ft_strlen.o -F dwarf -g
	ld -macosx_version_min 10.15.7 -lSystem -o ft_strlen ft_strlen.o -e _ft_strlen && lldb ./ft_strlen
