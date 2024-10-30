.PHONY:all
all:server client

server:server.cc
	g++ -o $@ $^ -std=c++11 -g
client:client.cc
	g++ -o $@ $^ -std=c++11 -g

.PHONY:clean
clean:
	rm -f server client