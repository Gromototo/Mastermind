
OBJ1 = fon.o client.o mastermind.o
OBJ2 = fon.o serveur.o mastermind.o
OBJ3 = fon.o run.o 

OPTIONS	=
# Adaptation a Darwin / MacOS X avec fink
# Du fait de l'absence de libtermcap on se fait pas mal
# cracher dessus mais ca marche...
ifeq ($(shell uname), Darwin)
LFLAGS	+= -L /opt/X11/lib
CFLAGS	+= -I /opt/X11/include
endif
#Changer si necessaire le chemin d'acces aux librairies

# Adaptation a Linux
ifeq ($(shell uname), Linux)
OPTIONS	+= -ltermcap
endif

# Adaptation a FreeBSD
# Attention : il faut utiliser gmake...
ifeq ($(shell uname),FreeBSD)
OPTIONS	+= -ltermcap
endif

# Adaptation a Solaris

ifeq ($(shell uname),SunOS)
OPTIONS	+= -ltermcap  -lsocket -lnsl
CFLAGS	+= -I..
endif

EXEC = ${OBJ1} client ${OBJ2} serveur ${OBJ3} run
all: ${EXEC} 	


fon.o :  fon.h fon.c #-DDEBUG
	gcc  -c fon.c	

client.o : fon.h	client.c 
	gcc  $(CFLAGS) -c  client.c	

serveur.o : 	serveur.c  #fon.h
	gcc  $(CFLAGS) -c  serveur.c	

mastermind.o : 	mastermind.c  #fon.h
	gcc  $(CFLAGS) -c  mastermind.c


client : ${OBJ1}	
	gcc $(LFLAGS) ${OBJ1} -g -o client -lcurses   $(OPTIONS)

serveur : ${OBJ2}	
	gcc $(LFLAGS) ${OBJ2} -g -o serveur -lcurses   $(OPTIONS)


run.o : 	run.c  #fon.h
	gcc  $(CFLAGS) -c  run.c	

run : ${OBJ3}	
	gcc $(LFLAGS) ${OBJ3} -g -o run -lcurses   $(OPTIONS)



clean : 
	rm -f ${EXEC} core

