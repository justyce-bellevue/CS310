#include <iostream>
#include <iomanip>   //Used to set decimal places

using namespace std;

float taxReturnBilling(float income, int consultTime, float hourlyRate) // Has to be float to return floats
{
    float consultCost = 0;
    if (income <= 25000) //Low income case
    {
        if (consultTime <= 30)
        {
            consultCost = 0;
        } else
        {
            consultCost = (hourlyRate * .40) * (consultTime - 30)/60; //Divided by 60 to get hours
        }
    } else //Case for everyone else that is not considered low income
    {
        if (consultTime <= 20)
        {
            consultCost = 0;
        } else
        {
            consultCost = (hourlyRate * .60) * (consultTime - 20)/60; //Divided by 60 to get hours
        }
    }

    return consultCost;
}

int main()
{
    float clientIncome, hourlyRate;
    int consultTime;

    cout << "What is the hourly rate of the consultation? ";
    cin >> hourlyRate;
    cout << "How long, in minutes, was the consultation? ";
    cin >> consultTime;
    cout << "What is the income of the client? ";
    cin >> clientIncome;

    float consultationCost = taxReturnBilling(clientIncome, consultTime, hourlyRate);

    cout << fixed << setprecision(2); //Use this so the output is formatted like money should be
    cout << "The cost of the consultation is $" << consultationCost << "." << endl;

    return 0;
}