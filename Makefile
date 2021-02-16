CC = g++
CFLAGS = -c -Wall -Werror -std=c++11 -pedantic
OBJS = CircularBuffer.o StringSound.o KSGuitarSim.o
SRCS = CircularBuffer.cpp KSGuitarsim.cpp StringSound.cpp
LDFLAGS = #-L/usr/local/lib -L/usr/lib/x86-64-linux-gnu
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

EXE = KSGuitarSim

#ps3a: lint all

all:  $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(LDFLAGS) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

#lint:
	#python cpplint.py $(SRCS)
clean:
	\rm $(OBJS) $(EXE)
