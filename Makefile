# AAFR, 17 de noviembre de 2013
#
#

CC= gcc -c

CLINKER= gcc -o

CFLAGS= -O3 -Wall

LIBS= -lm -lgsl -lgslcblas 


OBJ= main.o \
     dproductos.o \

	
DIR_SRC= ./src/
DIR_BIN= ./bin/
DIR_OBJ= ./obj/

all: clean $(OBJ)
	$(CLINKER) $(DIR_BIN)cbp.exe $(OBJ) $(LIBS) $(CFLAGS)

%.o: $(DIR_SRC)%.c
	$(CC) $(CFLAGS)  $<	
	
clean:
	@rm -rfv *.o
	

