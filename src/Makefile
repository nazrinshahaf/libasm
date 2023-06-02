all:
	# nasm -f macho64 hello_world.s -o hello_world.o && arch -x86_64 ld hello_world.o -o hello_world -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _main -arch x86_64
	nasm -f macho64 hello_world.s -o hello_world.o && ld -macosx_version_min 10.7.0 -lSystem -o hello_world hello_world.o -e _main

test:
	# nasm -f macho64 hello_world.s -o hello_world.o && arch -x86_64 ld hello_world.o -o hello_world -l System -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _main -arch x86_64 && ./hello_world
	nasm -f macho64 hello_world.s -o hello_world.o && ld -macosx_version_min 10.7.0 -lSystem -o hello_world hello_world.o -e _main && ./hello_world
