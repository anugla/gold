gcc -c -Wall -Werror -fpic gold.c
gcc -shared -o gold.so gold.o
