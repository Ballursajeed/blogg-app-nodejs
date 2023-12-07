#include <stdio.h>

// Constants for maximum number of cities
#define MAX_CITIES 10

// Global variables
int costMatrix[MAX_CITIES][MAX_CITIES];
int completedCities[MAX_CITIES];
int numCities, totalCost = 0;

// Function prototypes
void takeInput();
void tsp(int city);
void displayCostMatrix();

int main() {
    // Clears the console screen (compiler-specific)


    // Take input from the user
    takeInput();

    // Display the entered cost matrix
    printf("The Cost Matrix is:\n");
    displayCostMatrix();

    // Find and display the minimum cost tour
    printf("\nThe Path is:\n");
    tsp(0);

    // Display the minimum cost
    printf("\nMinimum cost is %d\n", totalCost);

    // Wait for a key press (compiler-specific)


    return 0;
}

// Function to take input from the user
void takeInput() {
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the Cost Matrix:\n");
    for (int i = 0; i < numCities; i++) {
        printf("Enter elements of Row %d:\n", i);
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
        completedCities[i] = 0; // Mark all cities as not visited
    }
}

// Recursive function to find the minimum cost tour
void tsp(int city) {

    // Mark the current city as visited
    completedCities[city] = 1;

    int currentCity = city;
    int nextCity=999, minCost = 999, kmin;

    // Explore unvisited cities
    for (int i = 0; i < numCities; i++) {
        if (costMatrix[currentCity][i] != 0 && completedCities[i] == 0) {
            if (costMatrix[currentCity][i] + costMatrix[i][currentCity] < minCost) {
                minCost = costMatrix[i][currentCity] + costMatrix[currentCity][i];
                kmin = costMatrix[currentCity][i];
                nextCity = i;
            }
        }
    }

    // Update the total cost
    if (minCost != 999) {
        totalCost += kmin;
    }

    // If all cities are visited, return
    if (nextCity == 999) {
        nextCity = 0;
        printf("%d", nextCity);
        totalCost += costMatrix[city][nextCity];
        return;
    }

    // Recursively call tsp for the next city
    tsp(nextCity);
}

// Function to display the entered cost matrix
void displayCostMatrix() {
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            printf("\t%d", costMatrix[i][j]);
        }
        printf("\n");
    }
}
