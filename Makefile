CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

all: inverse lostfound traffic

inverse: 01_inverse_sequence.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

lostfound: 02_lost_and_found.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

traffic: 03_strange_traffic_lights.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f inverse lostfound traffic
