TARGET=test
CC = g++

ANSITERM_INSTALL_DIR = ../src
ANSITERM_HEADER_FILES = $(addprefix $(ANSITERM_INSTALL_DIR)/ansiterm/,ansiterm.hpp $(addprefix bits/ansiterm_,control.hpp sgr.hpp))

$(TARGET): main.cpp $(ANSITERM_HEADER_FILES)
	$(CC) -Wall -Wextra -o $@ -I$(ANSITERM_INSTALL_DIR) $< 

.PHONY:clean
clean:
	rm -rf $(TARGET)
