CC=mpicc

target=ex01

%.o: %.c
	$(CC) -c $<

$(target): $(target).o
	$(CC) -o $@ $<

clean:
	$(RM) $(target).o
