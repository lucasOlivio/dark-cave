#include <iostream>
#include <vector>

using namespace std;


class Map {
    public:
        Map(int height, int width);
        bool resetMap();
        void displayMap();
    private:
        vector<vector<int>> map;
        vector<vector<int>> createMap(int height, int width);

    /**
     * @brief Construct a new Map:: Map object
     * 
     * @param height Map X size
     * @param width Map Y size
     */
    Map::Map(int height, int width) {
        map = createMap(height, width);
    }

    /**
     * @brief Create a new map randomizing the tiles 
     * to create enemies and set the player position
     * 
     * @param height Map X size
     * @param width Map Y size
     * 
     * @return vector<vector<int>> Map
     */
     vector<vector<int>> createMap(int height, int width) {
        vector<vector<int>> map(height, vector<int>(width));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                map[i][j] = 0;
            }
        }
        return map;
    }

    /**
     * @brief Reset map to initial values
     * 
     * @return true Map reset successfully
     * @return false Map reset failed
     */
    bool resetMap() {
        return true;
    }
};