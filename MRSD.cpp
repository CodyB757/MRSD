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

int readRunnerData(Runner runners[], int maxRunners)
{
    ifstream inputFile("runners.txt");

    if (!inputFile)
    {
        cout << "Error opening file." << endl;
        return 0;
    }

    int runnerCount = 0;

    while (runnerCount < maxRunners)
    {
        if (!(inputFile >> runners[runnerCount].name))
        {
            break;
        }

        for (int day = 0; day < NUM_DAYS; day++)
        {
            inputFile >> runners[runnerCount].miles[day];
        }

        runnerCount++;
    }

    inputFile.close();

    return runnerCount;
}

void calculateTotalsAndAverages(Runner runners[], int runnerCount)
{
    for (int i = 0; i < runnerCount; i++)
    {
        runners[i].total = 0;

        for (int day = 0; day < NUM_DAYS; day++)
        {
            runners[i].total += runners[i].miles[day];
        }

        runners[i].average = runners[i].total / NUM_DAYS;
    }
}

void displayResults(const Runner runners[], int runnerCount)
{
    cout << left << setw(12) << "Runner";

    for (int day = 1; day <= NUM_DAYS; day++)
    {
        cout << setw(8) << ("Day" + to_string(day));
    }

    cout << setw(10) << "Total"
        << setw(10) << "Average"
        << endl;

    cout << fixed << setprecision(2);

    for (int i = 0; i < runnerCount; i++)
    {
        cout << left << setw(12) << runners[i].name;

        for (int day = 0; day < NUM_DAYS; day++)
        {
            cout << setw(8) << runners[i].miles[day];
        }

        cout << setw(10) << runners[i].total
            << setw(10) << runners[i].average
            << endl;
    }
}
``