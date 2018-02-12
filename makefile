
all:
	g++ -o linkedList linkedList.cc

clean:
	rm linkedList

run:
	g++ -o linkedList linkedList.cc
	./linkedList
	rm linkedList	