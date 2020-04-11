CXX := g++
CXXFLAGS := -std=c++14 -Wall
INCLUDE := -Iinclude/
LDFLAGS := $(shell curl-config --libs)

APP := covid-in
BUILD := ./build
INSTDIR := /usr/local/bin/
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:%.cpp=$(BUILD)/%.o)

all: build $(APP)

build:
	@mkdir -pv $(BUILD)

$(APP): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(APP) $(LDFLAGS)
	@echo "App compiled successfully."

$(BUILD)/%.o: %.cpp
	@mkdir -vp $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "Cleaning...."
	@rm -rvf $(BUILD) 

install: all
	@cp -v $(APP) $(INSTDIR)
	@echo "You can now use covid-in globally"