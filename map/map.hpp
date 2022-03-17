#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <vector>

using namespace std;

class Map {
    public:
        Map(int height, int width);
        void displayMap();
    private:
        vector<vector<int>> map;
        vector<vector<int>> createMap(int height, int width);
        int half_width;
        int half_height;
};

#endif // MAP_HPP