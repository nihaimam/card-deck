CFLAGS=-Wall -g

make:
	gcc -g -o project2_int_nimam_206 project2_int_nimam_206.c
	gcc -g -o project2_deck_nimam_206 project2_deck_nimam_206.c
clean:
	rm -f project2_int_nimam_206 project2_deck_nimam_206
