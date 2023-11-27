CC = gcc
CFLAGS = -Wall -O2 -I/usr/include/libexif
LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lexif

INSTALL_DIR = /usr/local/bin
SRCS = main.c
TARGET = rexif

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

install: $(TARGET)
	install -m 755 $(TARGET) $(INSTALL_DIR)

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)

clean:
	rm -f $(TARGET)

