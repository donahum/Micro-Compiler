team: 
	@echo "Team: 6d 69 6b 65 6e 72 65 73 68 61 76\n" 
	@echo "Reshav Abraham\nabe66\n" 
	@echo "Mike Donahue\ndonahum\n"
compiler:
	@flex step1.lex
	@gcc -w lex.yy.c
	@./a.out test.txt
clean:
	@if [ -f lex.yy.c ]; then \
		rm lex.yy.c ;\
	fi

	@if [ -f a.out ]; then\
		rm a.out ;\
	fi
