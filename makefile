





udpserver:udpsever.c


	gcc -o $@ $<
	

.PHONY:clean
clean:
	-rm -i udpserver
