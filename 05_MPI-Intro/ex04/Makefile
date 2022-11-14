CC=mpicc

target=ex04

%.o: %.c
	$(CC) -c $<

$(target): $(target).o
	$(CC) -o $@ $<

clean:
	$(RM) $(target).o
