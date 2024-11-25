compile:
	@gcc -Wall -o fork fork.c
run:
	@./fork
clean:
	@rm -f @.o fork;
