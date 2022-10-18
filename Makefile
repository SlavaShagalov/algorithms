.PHONY: check clean

check_run:
	./Linters/run.sh

clean:
	rm *.out *.o
