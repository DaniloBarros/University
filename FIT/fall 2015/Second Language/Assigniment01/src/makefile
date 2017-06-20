#
# Source: http://cs.millersville.edu/~katz/linuxHelp/Makefile.txt
#
# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

Objects = sum_of_two_numbers.o annual_pay.o sales_prediction.o restaurant_bill.o average_of_values.o

# This is a simple makefile that compiles multiple C++ source files

# set the names here to be the names of your source files with the
# .cxx or .cpp replaced by .o
# Be *** SURE *** to put the .o files here rather than the source files

proj1 = sum_of_two_numbers.o
proj2 = sales_prediction.o
proj3 = annual_pay.o
proj4 = restaurant_bill.o
proj5 = average_of_values.o

#------------ no need to change between these lines -------------------
CFLAGS = -g -pedantic -Wall -Wextra -Wshadow
.SUFFIXES: .cxx .cpp .c

.cxx.o:
	g++ $(CFLAGS) -c $<

.cpp.o:
	g++ $(CFLAGS) -c $<

.c.o:
	g++ $(CFLAGS) -c $<


#------------ no need to change between these lines -------------------


#------------ targets --------------------------------------------
# describe how to create the targets - often there will be only one target
# For CSE2050 class executable names *must* be the same as source file name but without the .cpp extension

all: sum_of_two_numbers sales_prediction annual_pay restaurant_bill average_of_values

sum_of_two_numbers: $(proj1)
	g++ $(CFLAGS) $(proj1) -o sum_of_two_numbers

sales_prediction: $(proj2)
	g++ $(CFLAGS) $(proj2) -o sales_prediction

annual_pay: $(proj3)
	g++ $(CFLAGS) $(proj3) -o annual_pay

restaurant_bill: $(proj4)
	g++ $(CFLAGS) $(proj4) -o restaurant_bill

average_of_values: $(proj5)
	g++ $(CFLAGS) $(proj5) -o average_of_values

clean:
	rm -f $(Objects) sum_of_two_numbers sales_prediction annual_pay restaurant_bill average_of_values
#------------ dependencies --------------------------------------------
# put the .o that depends on a .h, then colon, then TAB, then the .h

#class1.o:	class1.h
#class2.o:	class2.h
#theProject.o:	class1.h class2.h

sum_of_two_numbers.o:	dummy_driver.h
sales_prediction.o:	dummy_driver.h
annual_pay.o:	dummy_driver.h
restaurant_bill.o:	dummy_driver.h
average_of_values.o:	dummy_driver.h

