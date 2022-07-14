
a.out: y.tab.o lex.yy.o ass6_19CS30016_translator.o ass6_19CS30016_target_translator.o 
	g++ lex.yy.o y.tab.o ass6_19CS30016_target_translator.o ass6_19CS30016_translator.o -lfl
	./a.out < testFiles/ass6_19CS30016_test1.c
	./a.out < testFiles/ass6_19CS30016_test2.c 
	./a.out < testFiles/ass6_19CS30016_test3.c
	./a.out < testFiles/ass6_19CS30016_test4.c
	./a.out < testFiles/ass6_19CS30016_test5.c
	@echo " use command (make run) to create the test run files"

ass6_19CS30016_translator.o: ass6_19CS30016_translator.cxx ass6_19CS30016_translator.h
	g++ -c ass6_19CS30016_translator.h
	g++ -c ass6_19CS30016_translator.cxx

ass6_19CS30016_target_translator.o: ass6_19CS30016_translator.cxx ass6_19CS30016_translator.h
	g++ -c ass6_19CS30016_target_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass6_19CS30016.l y.tab.h ass6_19CS30016_translator.h
	flex ass6_19CS30016.l

y.tab.c: ass6_19CS30016.y
	yacc -dtv ass6_19CS30016.y -W

libass6_19CS30016.a:ass6_19CS30016.o
	ar -rcs libass6_19CS30016.a ass6_19CS30016.o

ass6_19CS30016.o:ass6_19CS30016.c myl.h
	gcc -Wall -c ass6_19CS30016.c

#output: output.o
output: output.o libass6_19CS30016.a
	gcc -g  output.o -o output -L. -lass6_19CS30016
output.o: output.s myl.h
	gcc -g -Wall -c output.s


runtest1: ass6_19CS30016_test1.o libass6_19CS30016.a
	gcc -g ass6_19CS30016_test1.o -o runtest1 -L. -lass6_19CS30016
ass6_19CS30016_test1.o: ass6_19CS30016_test1.s myl.h
	gcc -g -Wall  -c ass6_19CS30016_test1.s

runtest2: ass6_19CS30016_test2.o libass6_19CS30016.a
	gcc -g  ass6_19CS30016_test2.o -o runtest2 -L. -lass6_19CS30016
ass6_19CS30016_test2.o: ass6_19CS30016_test2.s myl.h
	gcc -g -Wall -c ass6_19CS30016_test2.s

runtest3: ass6_19CS30016_test3.o libass6_19CS30016.a
	gcc -g  ass6_19CS30016_test3.o -o runtest3 -L. -lass6_19CS30016
ass6_19CS30016_test3.o: ass6_19CS30016_test3.s myl.h
	gcc -g -Wall  -c ass6_19CS30016_test3.s

runtest4: ass6_19CS30016_test4.o libass6_19CS30016.a
	gcc -g  ass6_19CS30016_test4.o -o runtest4 -L. -lass6_19CS30016
ass6_19CS30016_test4.o: ass6_19CS30016_test4.s myl.h
	gcc -g -Wall  -c ass6_19CS30016_test4.s

runtest5: ass6_19CS30016_test5.o libass6_19CS30016.a
	gcc -g  ass6_19CS30016_test5.o -o runtest5 -L. -lass6_19CS30016
ass6_19CS30016_test5.o: ass6_19CS30016_test5.s myl.h
	gcc -g -Wall -c ass6_19CS30016_test5.s


run: 
		
	./a.out <  testFiles/ass6_19CS30016_test1.c > 3-address_outputFiles/ass6_19CS30016_quads1.out
	
	@mv output.s ass6_19CS30016_test1.s
	
	@make runtest1
	
	./a.out <  testFiles/ass6_19CS30016_test2.c > 3-address_outputFiles/ass6_19CS30016_quads2.out

	@mv output.s ass6_19CS30016_test2.s
	
	@make runtest2

	./a.out <  testFiles/ass6_19CS30016_test3.c > 3-address_outputFiles/ass6_19CS30016_quads3.out

	@mv output.s ass6_19CS30016_test3.s

	@make runtest3

	./a.out <  testFiles/ass6_19CS30016_test4.c > 3-address_outputFiles/ass6_19CS30016_quads4.out
	
	@mv output.s ass6_19CS30016_test4.s

	@make runtest4

	./a.out <  testFiles/ass6_19CS30016_test5.c > 3-address_outputFiles/ass6_19CS30016_quads5.out
	
	@mv output.s ass6_19CS30016_test5.s

	@make runtest5

	@echo ""
	@echo "COMMANDS FOR THE TEST CASES"
	@echo "1 : Calculate factorial of a number                             										  : ./runtest1"
	@echo "2 : Program that printStr factors of a number    	           										  : ./runtest2"
	@echo "3 : Program that finds number of trailing zeros in n factorial  										  : ./runtest3"
	@echo "4 : program to find whether a subset of an array has sum equal to the given target sum                 : ./runtest4"
	@echo "5 : Program to find and print the reverse of a number								                  : ./runtest5"


clean:
	@rm ass6_19CS30016_test1.s ass6_19CS30016_test2.s ass6_19CS30016_test3.s ass6_19CS30016_test4.s ass6_19CS30016_test5.s runtest1 runtest2 runtest3 runtest4 runtest5 lex.yy.c y.tab.h y.output y.tab.c lex.yy.o y.tab.o ass6_19CS30016_translator.o ass6_19CS30016_target_translator.o ass6_19CS30016_test1.o ass6_19CS30016_test2.o ass6_19CS30016_test3.o ass6_19CS30016_test4.o ass6_19CS30016_test5.o libass6_19CS30016.a ass6_19CS30016.o ass6_19CS30016_translator.h.gch a.out
