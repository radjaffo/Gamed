all:
	g++ game.cpp ./core/*.cpp ./core/character/*.cpp -o game

run: 
	./game


test:
	g++ -I./tests/gtest ./tests/*.cpp ./core/character/*.cpp ./tests/gtest/*.a -o test_runner

clean:
	rm -rf ./game
	rm -rf ./test_runner
