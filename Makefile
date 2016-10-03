cc = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Wstrict-prototypes -Wmissing-prototypes -g

SRC = main.c \
      utils.c \

LIBS = -lreadline -lm -lpthread

OBJ = $(SRC:.c=.o)

TARGET = Shell

.PHONE: depend clean

all: $(TARGET)
	@echo "\x1b[37mtarget assembled\x1b[0m"

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

clean:
	rm -f *.o *~ $(TARGET)
