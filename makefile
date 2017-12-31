CC = g++ -g -pthread
VERSION = -std=c++98
CLIENT_CPP_FILES = ./src/client/*.cpp
CLIENT_H_FILES = ./src/client/*.h
PAIR_H = ./src/client/Pair.h
PAIR_C = ./src/client/Pair.cpp
SERVER_H_FILES = ./src/server/*.h
SERVER_CPP_FILES = ./src/server/*.cpp
CLIENT_O_FILES = ./obj/client_obj/*
SERVER_O_FILES = ./obj/server_obj/*

create_all: obj server_exe client_exe clean

client_exe: $(CLIENT_CPP_FILES) $(CLIENT_H_FILES)
	$(CC) $(VERSION) -c $(CLIENT_CPP_FILES)
	mv *.o obj/client_obj
	$(CC) $(VERSION) $(CLIENT_O_FILES) -o exe/client_exe

server_exe: $(SERVER_CPP_FILES) $(SERVER_H_FILES) $(PAIR_C) $(PAIR_H)
	$(CC) $(VERSION) -c $(SERVER_CPP_FILES) -c $(PAIR_C)
	mv *.o obj/server_obj
	$(CC) $(VERSION) $(SERVER_O_FILES) -o exe/server_exe

obj:
	mkdir obj
	mkdir obj/client_obj
	mkdir obj/server_obj

clean:	
	rm -rf obj/
