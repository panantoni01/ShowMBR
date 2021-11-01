CC=gcc
CPP=cpp
CFLAGS=-std=c17 -Wall -Wextra -pedantic

SRCDIR=src
BUILDDIR=build
$(shell mkdir -p $(BUILDDIR))

TARGET=showmbr

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
DEP=$(SRC:$(SRCDIR)/%.c=$(BUILDDIR)/%.d)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

-include $(DEP)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -MM $< -MQ $(BUILDDIR)/$*.o -MF $(BUILDDIR)/$*.d
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -rf $(BUILDDIR) $(TARGET)

BINDIR=/usr/local/bin

install: $(TARGET)
	install -m 4755 -o root $(TARGET) $(BINDIR)

uninstall:
	rm $(BINDIR)/$(TARGET)

.PHONY: all clean install uninstall 