#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_RUNNERS = 50;
const int NUM_DAYS = 7;

struct Runner
{
    string name;
    double miles[NUM_DAYS];
    double total;
    double average;
};

int readRunnerData(Runner runners[], int maxRunners);
void calculateTotalsAndAverages(Runner runners[], int runnerCount);
void displayResults(const Runner runners[], int runnerCount);

int main()
{
    Runner runners[MAX_RUNNERS];
    int runnerCount = 0;

    runnerCount = readRunnerData(runners, MAX_RUNNERS);

    calculateTotalsAndAverages(runners, runnerCount);

    displayResults(runners, runnerCount);

    return 0;
}