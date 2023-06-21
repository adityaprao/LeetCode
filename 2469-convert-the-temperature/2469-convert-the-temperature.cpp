class Solution {
public:
    vector<double> convertTemperature(double c) {
        double k = c + 273.15;
        double f = c * 1.8 + (double)32;
        return {k, f};
        
    }
};