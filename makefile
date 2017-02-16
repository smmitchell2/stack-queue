SLLOBJS = integer.o sll.o test-sll.o
DLLOBJS = integer.o dll.o test-dll.o
STACKOBJS = integer.o dll.o stack.o test-stack.o
QUEUEOBJS = integer.o sll.o queue.o test-queue.o
OOPTS = -Wall -std=c99 -c -g
LOOPTS = -Wall -std=c99 -g

all : test-sll test-dll test-stack test-queue

test-sll : $(SLLOBJS)
	gcc $(LOOPTS) -o test-sll $(SLLOBJS)

test-dll : $(DLLOBJS)
	gcc $(LOOPTS) -o test-dll $(DLLOBJS)

test-stack : $(STACKOBJS)
	gcc $(LOOPTS) -o test-stack $(STACKOBJS)

test-queue : $(QUEUEOBJS)
	gcc $(LOOPTS) -o test-queue $(QUEUEOBJS)

sll.o : sll.c sll.h
	gcc $(OOPTS) sll.c

dll.o : dll.c dll.h
	gcc $(OOPTS) dll.c

stack.o : stack.c stack.h dll.h
	gcc $(OOPTS) stack.c

queue.o : queue.c queue.h sll.h
	gcc $(OOPTS) queue.c

integer.o : integer.c integer.h
	gcc $(OOPTS) integer.c

test-sll.o : test-sll.c integer.h sll.h
	gcc $(OOPTS) test-sll.c

test-dll.o : test-dll.c integer.h dll.h
	gcc $(OOPTS) test-dll.c

test-stack.o : test-stack.c integer.h dll.h stack.h
	gcc $(OOPTS) test-stack.c

test-queue.o : test-queue.c integer.h sll.h queue.h
	gcc $(OOPTS) test-queue.c

test :
	#testing sll#
	test-sll
	@echo
	@echo
	#testing dll#
	test-dll
	@echo
	@echo
	#testing stack#
	test-stack
	@echo
	@echo
	#testing queue#
	test-queue
	@echo

clean   :
	rm -f *.o test-sll test-dll test-stack test-queue
