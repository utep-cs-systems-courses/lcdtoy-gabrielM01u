COMMON_OBJECTS 		=
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all:main.elf

stateMachine.o: stateMachine.h stateMachine.o states.h
main.elf: ${COMMON_OBJECTS} hardware.o main.o stateMachine.o states.o wdt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lp2sw

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf
	rm -rf lib h
