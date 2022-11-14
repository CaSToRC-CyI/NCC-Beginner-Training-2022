CC=mpicc

target=ex05

%.o: %.c
	$(CC) -c $<

$(target): $(target).o
	$(CC) -o $@ $<

clean:
	$(RM) $(target).o
