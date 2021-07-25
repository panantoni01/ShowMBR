CC = gcc
CFLAGS = -std=c17 -Wall -Wextra
TARGET = showmbr

$(TARGET): main.o mbr.o parttypes_map.o wrappers.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c

mbr.o: mbr.c mbr.h

parttypes_map.o: parttypes_map.c parttypes_map.h

wrappers.o: wrappers.c wrappers.h

clean:
	rm -f *.o

distclean:
	rm -f *.o $(TARGET)