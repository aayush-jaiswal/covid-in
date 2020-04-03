CXX := g++
CXXFLAGS := -std=c++14 -Wall 
INCLUDE := -Iinclude/
LDFLAGS := -lcurl

APP := covid-in
BUILD := ./build
INSTDIR := /usr/local/bin/
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:%.cpp=$(BUILD)/%.o)

all: build $(APP)

build:
	@mkdir -pv $(BUILD)

$(APP): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $(APP) 
	@echo "App compiled successfully."

$(BUILD)/%.o: %.cpp
	@mkdir -vp $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "Cleaning...."
	@rm -rvf $(BUILD) 

install:
	@cp -v $(APP) $(INSTDIR)
	@echo $(APP) is installed at $(INSTDIR)