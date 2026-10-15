CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic
TARGET = solucion
SOURCES = solucion.c funciones.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

solucion.o: solucion.c funciones.h

funciones.o: funciones.c funciones.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
