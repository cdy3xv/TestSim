IDIR=../include
ODIR=obj
LDIR=../lib

CC=gcc
CFLAGS=-I$(IDIR)

LIBS=
SENS_LIBS=-lpthread

APPS=supervisor sensor actuator dut

_SUP_OBJ= supervisor.o testsim.o sample_sup.o
SUP_OBJ=$(patsubst %,$(ODIR)/%,$(_SUP_OBJ))

_SENS_OBJ= sensor.o testsim.o sample_sensors.o sample_gauge.o sample_feedback.o
SENS_OBJ=$(patsubst %,$(ODIR)/%,$(_SENS_OBJ))

_ACT_OBJ= actuator.o testsim.o sampleHPU.o
ACT_OBJ=$(patsubst %,$(ODIR)/%,$(_ACT_OBJ))

_DUT_OBJ= dut.o testsim.o steel_1x1_compress.o
DUT_OBJ=$(patsubst %,$(ODIR)/%,$(_DUT_OBJ))

$(ODIR)/%.o: %.c %.h testsim.h
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(APPS)
PHONY: all

supervisor: $(SUP_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

sensor: $(SENS_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(SENS_LIBS)

actuator: $(ACT_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

dut: $(DUT_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(APPS)

