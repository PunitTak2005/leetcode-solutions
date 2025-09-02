class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int count = 0;
        
       
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
               
                if (i == j) {
                    continue;
                }
                
                int x_A = points[i][0];
                int y_A = points[i][1];
                int x_B = points[j][0];
                int y_B = points[j][1];
                
                
                if (x_A <= x_B && y_A >= y_B) {
                    bool is_empty_rectangle = true;
                    
                   
                    for (int k = 0; k < n; ++k) {
                        if (k == i || k == j) {
                            continue;
                        }
                        
                        int x_C = points[k][0];
                        int y_C = points[k][1];
                        
                        
                        if ((x_A <= x_C && x_C <= x_B) && (y_B <= y_C && y_C <= y_A)) {
                            is_empty_rectangle = false;
                            break; 
                        }
                    }
                    
                    if (is_empty_rectangle) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
