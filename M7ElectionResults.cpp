//*********************************************************************
// Author: Justyce Bonczynski
// Course: CS310-T301 Programming with C++
// Title: Election Results
//
// Approach: Use a for loop to collect user data while keeping
// total votes and a winner. Then format data into columns to display.
//*********************************************************************

#include <iostream> //Used to output text
#include <string> // Needed to use string data type
#include <iomanip> // Needed for use of setw(), right, left

using namespace std; // Avoid using std::

int main()
{
    // Declare arrays to store user input in
    int votesReceived[5];
    string candidates[5];

    // Total votes to later use in percentage of votes
    int totalVotes = 0; 

    // Used to figure out who has won the election
    int highestVotes = 0;
    string winner;

    // Loop through 0-4 to collect user input and add to arrays
    for (int i = 0; i < 5; i++) 
    {
        cout << "Enter the candidates last name: ";
        cin >> candidates[i];

        cout << "Enter how many votes they received: ";
        cin >> votesReceived[i];

        totalVotes += votesReceived[i]; // Keep running total of votes to avoid do it later
        if (votesReceived[i] > highestVotes) // Find winner now to avoid doing it later
        {
            winner = candidates[i];
            highestVotes = votesReceived[i];
        }
    }

    float votePercentages[5]; // Array to store vote percentages
    for (int i = 0; i < 5; i++)
    {
        votePercentages[i] = (static_cast<float>(votesReceived[i]) / totalVotes) * 100; // Have to cast to float otherwise int / int so it would always be 0
    }

    // Create Header for data
    cout << endl;
    cout << left << setw(15) << "Candidate" << right << setw(15) << "Votes Received" << setw(20) << "% Total of Votes" << endl;

    for (int i = 0; i < 5; i++)
    {
        // Output correctly formatted data
        cout << left << setw(15) << candidates[i] << right << setw(15) << votesReceived[i] << setw(20) << fixed << setprecision(2) << votePercentages[i] << endl; 
    }
    
    cout << left << setw(15) << "Total" << right << setw(15) << totalVotes << endl; // Formatted output of total votes

    cout << "The winner of the election is " << winner; // Output winner

    return 0;
}

