.PHONY: check clean

check:
	./Linters/run.sh

build:
	echo "Building..."

test:
	echo "Testing..."

clean:
	rm *.out *.o
