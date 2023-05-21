CC=g++ -pthread
CFLAGS=-std=c++11 -c -Wall -I.
LDFLAGS=

# Sources for client
CLIENT_SOURCES=$(wildcard app/*.cpp app/*/*.cpp app/*/*/*.cpp client/*.cpp client/*/*.cpp client/*/*/*.cpp client/*/*/*/*.cpp)
CLIENT_OBJECTS=$(addprefix obj/, $(CLIENT_SOURCES:.cpp=.o))
CLIENT_EXECUTABLE=client.out

# Sources for server
SERVER_SOURCES=$(wildcard app/*.cpp app/*/*.cpp app/*/*/*.cpp server/*.cpp server/*/*.cpp server/*/*/*.cpp server/*/*/*/*.cpp)
SERVER_OBJECTS=$(addprefix obj/, $(SERVER_SOURCES:.cpp=.o))
SERVER_EXECUTABLE=server.out

all: $(CLIENT_EXECUTABLE) $(SERVER_EXECUTABLE)
	@echo -e "\033[1;32m[✔]\033[0m\
	\033[0;35mAll executables created successfully!\033[0m\
	\033[1;32m[✔]\033[0m"
	@echo -e "\033[1;31m--------------------------------------------------\033[0m"
	@echo -e "\033[0;32mRun\033[0m\
	\033[1;31m./client.out [ip] [port]\033[0m\
	\033[0;32mto start the client\033[0m"
	@echo -e "\033[0;32mRun\033[0m\
	\033[1;31m./server.out [port]\033[0m\
	\033[0;32mto start the server\033[0m"
	@echo -e "\033[1;31m--------------------------------------------------\033[0m"

$(CLIENT_EXECUTABLE): $(CLIENT_OBJECTS)
	@$(CC) $(LDFLAGS) $(CLIENT_OBJECTS) -o $@ # if want to show remove @ from the beginning of the line
	@echo -e "\033[1;32m[✔]\033[0m\
	\033[0;93mClient executable created successfully!\033[0m\
	\033[1;32m[✔]\033[0m"

$(SERVER_EXECUTABLE): $(SERVER_OBJECTS)
	@$(CC) $(LDFLAGS) $(SERVER_OBJECTS) -o $@
	@echo -e "\033[1;32m[✔]\033[0m\
	\033[0;93mServer executable created successfully!\033[0m\
	\033[1;32m[✔]\033[0m"

SOURCES:=$(CLIENT_SOURCES) $(SERVER_SOURCES)
file_count = $(words $(SOURCES))
current_file = 0

define increment_current_file
$(eval current_file=$(shell echo $$(($(current_file)+1))))
endef

obj/%.o: %.cpp
	@mkdir -p $(@D)
	@$(call increment_current_file)
	@echo -e "\033[1;33m[$(shell echo "scale=2; $(current_file) / $(file_count) * 100" | bc)%]\033[0m\t \
	\033[0;36mCompiling $< \033[0m\t \
	\033[0;35m[$(current_file)/$(file_count)]\033[0m"
	@$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(CLIENT_EXECUTABLE) $(SERVER_EXECUTABLE)
