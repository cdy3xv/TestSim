IDIR=../include
ODIR=obj
LDIR=../lib

CC=gcc
CFLAGS=-I$(IDIR)

LIBS=

_SUP_OBJ= supervisor.o testsim.o
SUP_OBJ=$(patsubst %,$(ODIR)/%,$(_SUP_OBJ))

_SENS_OBJ= sensor.o testsim.o
SENS_OBJ=$(patsubst %,$(ODIR)/%,$(_SENS_OBJ))

$(ODIR)/%.o: %.c %.h testsim.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: supervisor sensor
PHONY: all

supervisor: $(SUP_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

sensor: $(SENS_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ supervisor sensor

