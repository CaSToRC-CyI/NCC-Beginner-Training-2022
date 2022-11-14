CC=mpicc

target=ex06

%.o: %.c
	$(CC) -c $<

$(target): $(target).o
	$(CC) -o $@ $<

clean:
	$(RM) $(target).o
