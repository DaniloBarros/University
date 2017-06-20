CC = g++
CFLAGS = -g -pedantic -Wall -Wextra -Wshadow

# connect4

driver.o: driver.cpp connect4.h  
	$(CC) $(CFLAGS) -c driver.cpp

driver: driver.o connect4.o 
	$(CC) $(CFLAGS) -o driver 

tester.o: tester.cpp connect4.h  
	$(CC) $(CFLAGS) -c tester.cpp

tester: tester.o connect4.o 
	$(CC) $(CFLAGS) -o tester 

connect4.o: connect4.cpp connect4.h 
	$(CC) $(CFLAGS) -c connect4.cpp

clean:
	rm -f *.o driver driver tester driver_purify pure

cleanObjects:
	rm -f *.o


what: help
all: help
help:
	@echo ""
	@echo "---------------------------------------------------------------"
	@echo "CS367-4, Program 2 Makefile - John Bent"
	@echo ""
	@echo "  make (driver)       - Create the driver"
	@echo "  make tester         - Create the driver"
	@echo "  make driver_purify  - Check driver with purify"
	@echo "  make clean          - Remove objects and executables"
	@echo "  make cleanObjects   - Remove objects only"
	@echo "  make help           - this screen"
	@echo "  make what           - also this screen"
	@echo "  make all            - also this screen"
	@echo ""
	@echo "---------------------------------------------------------------"
	@echo ""

