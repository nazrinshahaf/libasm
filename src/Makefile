all:
	nasm -f macho64 hello_world.s -o hello_world.o && arch -x86_64 ld hello_world.o -o hello_world -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _main -arch x86_64

test:
	nasm -f macho64 hello_world.s -o hello_world.o && arch -x86_64 ld hello_world.o -o hello_world -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _main -arch x86_64 && ./hello_world
