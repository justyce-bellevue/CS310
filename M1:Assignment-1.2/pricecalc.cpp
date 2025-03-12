#include <iostream>

using namespace std;

int main()
{
    // Declare variables
    double originalPrice, markupPercentage, salesTaxRate;

    // Collect user input
    cout << "Enter the original price of the item: $";
    cin >> originalPrice;

    cout << "Enter the markup percentage for the item, example if 10% enter 10: ";
    cin >> markupPercentage;

    cout << "Enter the sales tax rate, example if 6% enter 6: ";
    cin >> salesTaxRate;

    // Calculate selling price of item
    double markupAmount = (markupPercentage / 100) * originalPrice;
    double sellingPrice = markupAmount + originalPrice;

    // Calculate sales tax and final sale price
    double salesTax = (salesTaxRate / 100) * sellingPrice;
    double finalPrice = sellingPrice + salesTax;

    // Display results
    cout << "\nOriginal Price: $" << originalPrice << endl;
    cout << "Markup Percentage: " << markupPercentage << "%" << endl;
    cout << "Selling Price: $" << sellingPrice << endl;
    cout << "Sales Tax Rate: " << salesTaxRate << "%" << endl;
    cout << "Sales Tax: $" << salesTax << endl;
    cout << "Final Price: $" << finalPrice << endl;

    return 0;
}
