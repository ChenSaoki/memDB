all: clean server client

server: 
	g++ -W -Wall -o server ./src/memdbServer.cpp -lpthread

client:
	g++ -W -Wall -o client ./src/memdbClient.cpp -lpthread

clean:
	rm -f server
	rm -f client
