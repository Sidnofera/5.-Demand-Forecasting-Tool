
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

struct DataPoint {
    double x; // time period (e.g., month)
    double y; // demand
};

// Function to read CSV file and load data into a vector of DataPoints
vector<DataPoint> readCSV(const string& filename) {
    vector<DataPoint> data;
    ifstream file(filename);
    string line, word;
    while (getline(file, line)) {
        stringstream s(line);
        DataPoint point;
        getline(s, word, ',');
        point.x = stod(word);
        getline(s, word, ',');
        point.y = stod(word);
        data.push_back(point);
    }
    return data;
}

// Function to calculate linear regression coefficients
void calculateLinearRegression(const vector<DataPoint>& data, double& slope, double& intercept) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    int n = data.size();

    for (const auto& point : data) {
        sumX += point.x;
        sumY += point.y;
        sumXY += point.x * point.y;
        sumX2 += point.x * point.x;
    }

    slope = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    intercept = (sumY - slope * sumX) / n;
}

// Function to predict future demand
double predictDemand(double slope, double intercept, double futureX) {
    return slope * futureX + intercept;
}

int main() {
    string filename = "demand_data.csv"; // Replace with your CSV file path
    vector<DataPoint> data = readCSV(filename);

    double slope, intercept;
    calculateLinearRegression(data, slope, intercept);

    double futureX;
    cout << "Enter the future time period (e.g., month) to predict demand: ";
    cin >> futureX;

    double predictedDemand = predictDemand(slope, intercept, futureX);
    cout << "Predicted demand for period " << futureX << " is " << predictedDemand << endl;

    return 0;
}
