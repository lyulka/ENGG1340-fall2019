census.o:census.cpp BigInteger.h Country.h 
	g++ -c $<
#The above command is the same as g++ -c census.cpp

BigInteger.o:BigInteger.cpp BigInteger.h 
	g++ -c $<
#The above command is the same as g++ -c BigInteger.cpp

Country.o:Country.cpp BigInteger.h Country.h 
	g++ -c $<
#The above command is the same as g++ -c Country.cpp

census:census.o BigInteger.o Country.o 
	g++ $^ -o $@ > output.txt
#The above command is the same as g++ census.o BigInteger.o Country.o -o census

clean:
	rm census census.o BigInteger.o Country.o

tar:
	tar -czvf census.tgz *.cpp *.h

run:
	./census > output.txt
	echo "The following is the output of census."
	cat output.txt

.PHONY: clean tar