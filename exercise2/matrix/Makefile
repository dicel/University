################################################################
## SIMPLE MAKEFILE TO BUILD WITH MPICH2                       ##
################################################################
# oct-2010 - a.knirsch@fbi.h-da.de                             #
################################################################

CXX	= mpic++
CFLAGS	= -O1
PROGS	= matrix_sequential matrix_parallel matrix_generator
OBJS	= matrix_sequential.o matrix_parallel.o matrix_generator.o CMatrix.o

PLATFORM=$(shell uname)
ifeq ($(PLATFORM), Darwin)
CFLAGS	+= -I/opt/local/include/
LDFLAGS += -L/opt/local/lib/ 
else
LDFLAGS += 
endif

all: $(OBJS)
	$(CXX) $(LDFLAGS) matrix_sequential.o CMatrix.o -o matrix_sequential
	$(CXX) $(LDFLAGS) matrix_parallel.o CMatrix.o -o matrix_parallel
	$(CXX) $(LDFLAGS) matrix_generator.o CMatrix.o -o  matrix_generator
	
%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(PROGS) *~ *.o ._*