####################################################
#Author:kevinfu1985@gmail.com
#File:Makefile
#Description:This Makefile was used to generate the \
#dynamic library forthis multiplatrom os api and the\
#Unit test for this library
#Date:2014-05-10
####################################################
INCLUDE_DIR = ./include
SOURCES_DIR = ./src
OBJECT_DIR = ./obj
OUTPUT_DIR = ./lib
BIN_DIR = ./bin
CC = g++
CFLAGS = -g -fPIC -shared -Wall -I$(INCLUDE_DIR) -lrt -lpthread

SOURCE = $(wildcard $(SOURCES_DIR)/*.cpp)
SRC = $(notdir $(SOURCE))
OBJ = $(patsubst %.cpp, $(OBJECT_DIR)/%.o, $(SRC))

TARGET_NAME = libMultiPlatformOsApi.so
TARGET = $(OUTPUT_DIR)/$(TARGET_NAME)
BIN_TARGET = OSAPI_Test
$(BIN_TARGET):main.cpp $(TARGET)
	g++ main.cpp -I./include -L./lib -lMultiPlatformOsApi -lpthread -lrt -o $(BIN_TARGET) 



$(TARGET):$(OBJ)
	@echo $(SOURCES_DIR)
	@echo $(OBJECT_DIR)
	@echo $(BIN_DIR)
	@echo $(SRC)
	@echo $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) 
	cp $(TARGET) /usr/lib


$(OBJECT_DIR)/%.o:$(SOURCES_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean

clean:
	@rm -rf *.o $(BIN_TARGET)
