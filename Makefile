# Makefile for NS_web_server (C++)
CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -O2
LDFLAGS = 
INCLUDES = -Iinclude
SRC_DIR = src

SRCS = \
	$(SRC_DIR)/main.cc \
	$(SRC_DIR)/server/server.cc \
	$(SRC_DIR)/server/accept_loop.cc \
	$(SRC_DIR)/server/conn_manager.cc \
	$(SRC_DIR)/server/worker_thread.cc \
	$(SRC_DIR)/http/request.cc \
	$(SRC_DIR)/http/response.cc \
	$(SRC_DIR)/http/pipeline_queue.cc \
	$(SRC_DIR)/http/mime_map.cc \
	$(SRC_DIR)/util/strutil.cc \
	$(SRC_DIR)/util/log.cc \
	$(SRC_DIR)/util/timer.cc

OBJS = $(SRCS:.cc=.o)

TARGET = server

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(SRC_DIR)/*/*.o $(TARGET)

.PHONY: all clean
