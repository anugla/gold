SRCS := $(shell find . -name *.c)
OBJS := $(SRCS:%=%.o)

%.c.o: %.c
	$(CC) -fpic -c $< -o $@

gold.so: $(OBJS)
	$(CC) $(OBJS) -shared -o gold.so
