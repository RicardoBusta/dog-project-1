run: spaceShip
	./spaceShip
spaceShip: src
	g++ src/main.cpp src/entities/*.cpp src/base/*.cpp src/gamescenes/*.cpp src/math/*.cpp src/physics/*.cpp src/scenes/*.cpp src/contents/*.cpp src/contents/model/*.cpp -lSDLmain -lSDL_mixer -lSDL_image -lSDL -lGLU -lGL -o spaceShip
clean:
	rm spaceShip
