#To use this make file, navigate to the directory containing the makefile and type "make"
#		

all: main

main: main.o GameManager.o GameObject.o Character.o SDLManager.o Rect.o Player.o Enemy.o Coin.o EvilCoin.o Border.o BigEnemy.o
	g++ -std=c++11 main.o GameManager.o GameObject.o Character.o Rect.o SDLManager.o Player.o Enemy.o BigEnemy.o Coin.o EvilCoin.o Border.o -o main.exe -w -lSDL2

main.o: main.cpp GameManager.h GameObject.h Rect.h Character.h SDLManager.h Player.h Enemy.h BigEnemy.h Coin.h EvilCoin.h Border.h
	g++ -c -std=c++11 main.cpp -w -lSDL2
	
GameManager.o: GameManager.cpp
	g++ -std=c++11 -c GameManager.cpp -w -lSDL2
	
SDLManager.o: SDLManager.cpp
	g++ -std=c++11 -c SDLManager.cpp -w -lSDL2
	
GameObject.o: GameObject.cpp
	g++ -std=c++11 -c GameObject.cpp -w -lSDL2
	
Character.o: GameObject.h Character.cpp
	g++ -std=c++11 -c Character.cpp -w -lSDL2
	
Player.o: Character.h Player.cpp
	g++ -std=c++11 -c Player.cpp -w -lSDL2
	
Enemy.o: Character.h Enemy.cpp
	g++ -std=c++11 -c Enemy.cpp -w -lSDL2
	
Coin.o: GameObject.h Coin.cpp
	g++ -std=c++11 -c Coin.cpp -w -lSDL2
	
EvilCoin.o: Coin.h EvilCoin.cpp
	g++ -std=c++11 -c EvilCoin.cpp -w -lSDL2
	
Border.o: GameObject.h Border.cpp
	g++ -std=c++11 -c Border.cpp -w -lSDL2
	
BigEnemy.o: Enemy.h BigEnemy.cpp
	g++ -std=c++11 -c BigEnemy.cpp -w -lSDL2
	
rect.o: Rect.cpp Rect.h
	g++ -std=c++11 -c Rect.cpp -w -lSDL2
	
clean:
	rm *.o *.exe



