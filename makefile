CC=gcc

TARGET=new_c_program

CFLAGS=-Wall -g

SRCS=new_c_program.c 

OBJS=$(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
    rm -f $(TARGET) $(OBJS)