CC:= gcc
DESTDIR:=$$HOME/.local/bin
BIN=fsync

.PHONY: clean

CFALGS+= -Wall -Wextra -Wpedantic

OBJ = fsync.o

DEP = $(OBJ:.o=.d)
-include $(DEP)

all: $(BIN) install

.c.o:
	$(CC) $(CFLAGS) -MD -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

install:
	mv $(BIN) $(DESTDIR)/$(BIN)

clean:
	rm -f $(DESTDIR)/$(BIN) $(DEP) $(OBJ)