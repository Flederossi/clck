build:
	gcc src/main.c -o bin/clck -I src/include/

run: build
	./bin/clck

clean:
	rm bin/clck
