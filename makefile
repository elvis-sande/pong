compile:
	clang++ -o gen/pong src/**.cpp -lSDL2
run:
	gen/pong