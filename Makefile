.PHONY: check clean

check_run:
	./run_linters.sh

clean:
	rm *.out *.o
