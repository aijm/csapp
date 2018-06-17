CPP = gcc
CPPFLAGS = 

Lib = -lpthread

target = snooze

$(target) : $(target).o csapp.o
	$(CPP)  -o $(target) $(target).o csapp.o $(Lib)

$(target).o : $(target).c  
	$(CPP) -c $(target).c

csapp.o: csapp.c csapp.h
	$(CPP) -c csapp.c





clean :
	rm $(target) *.o
run : $(target)
	./$(target)