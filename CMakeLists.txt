StudentaiOptimized: main.o deque.o list.o vector.o
    g++ main.o deque.o list.o vector.o -o StudentaiOptimized

main.o: main.cpp
    g++ -c main.cpp

deque.o: deque.cpp
    g++ -c deque.cpp

list.o: list.cpp
    g++ -c list.cpp

vector.o: vector.cpp
    g++ -c vector.cpp

clean:
    rm *.o StudentaiOptimized