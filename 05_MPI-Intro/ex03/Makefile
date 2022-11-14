CC=mpicc

target=ex03

%.o: %.c
	$(CC) -c $<

$(target): $(target).o
	$(CC) -o $@ $<

clean:
	$(RM) $(target).o
