mean_sd.o:mean_sd.cpp mean_sd.h
	g++ -c $<

mean_sd:mean_sd.o 
	g++ -o mean_sd $<
# This is very redundant, I know.

clean:
	rm mean_sd mean_sd.o

.PHONY: clean
