CC = gcc
CFLAGS = -Wall -O2
LIBS = -lexif

INSTALL_DIR = /usr/local/bin
SRCS = main.c
TARGET = rexif

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LIBS)

install: $(TARGET)
	cp $(TARGET) $(INSTALL_DIR)

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)

clean:
	rm -f $(TARGET)
