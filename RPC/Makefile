CC=cc
CFLAGS=-std=c99 -lnsl
LIBS=

PROGRAMA = client
EXEC = agenda_svc.c agenda_xdr.c agenda_clnt.c 

all: clean rpc client server

rpc: 
	rpcgen agenda.x

client:  
	cc client.c agenda_clnt.c agenda_xdr.c -o client $(CFLAGS)

server: 
	cc server.c agenda_svc.c agenda_xdr.c -o server $(CFLAGS)


clean:
	rm -f client
	rm -f server
	rm -f agenda.h
	rm -f agenda_clnt.c
	rm -f agenda_svc.c
	rm -f agenda_xdr.c



