
# Demand Forecasting Tool

## Description
The Demand Forecasting Tool is a C++ program designed to predict future demand based on historical data using simple linear regression. This tool reads historical demand data from a CSV file, calculates the linear regression coefficients (slope and intercept), and uses these coefficients to forecast future demand.

## Features
- Reads historical demand data from a CSV file
- Calculates linear regression coefficients (slope and intercept)
- Predicts future demand based on user input
- Outputs the predicted demand for the specified future time period

## Requirements
- C++ Compiler (e.g., GCC)
- CSV file containing historical demand data

## Usage
1. Prepare a CSV file named `demand_data.csv` with historical demand data in the following format:
    ```
    1,100
    2,150
    3,200
    4,250
    5,300
    ```
    Each line represents a data point where the first value is the time period (e.g., month) and the second value is the demand.

2. Compile the program:
    ```
    g++ DemandForecastingTool.cpp -o DemandForecastingTool
    ```

3. Run the program:
    ```
    ./DemandForecastingTool
    ```

4. Enter the future time period (e.g., month) when prompted to get the predicted demand.

## Example
```
Enter the future time period (e.g., month) to predict demand: 6
Predicted demand for period 6 is 350
```

## Project Files
- `DemandForecastingTool.cpp`: Main C++ source code file
- `demand_data.csv`: Sample CSV file with historical demand data (create this file separately)

## Author
- Siddhant Tripathi

## License
This project is licensed under the MIT License.
