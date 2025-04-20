#include <vector>
using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Replace -1 with a large value for unreachable nodes
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1) {
                    matrix[i][j] = 1e9;
                }
                if(i == j) matrix[i][j] = 0;
            }
        }
        
        // Floyd Warshall algorithm
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], 
                                      matrix[i][k] + matrix[k][j]);
                }
            }
        }
        
        // Replace unreachable nodes with -1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};