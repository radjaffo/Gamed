all:
	g++ game.cpp ./core/*.cpp -o game

test:
	g++ -I./tests/gtest ./tests/*.cpp ./tests/gtest/*.a -o test_runner

clean:
	rm -rf ./game
	rm -rf ./test_runner