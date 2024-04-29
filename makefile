all: build

build: *.cpp
	g++ *.cpp -o testped

run: build
	./testped

clean:
	rm -f testped