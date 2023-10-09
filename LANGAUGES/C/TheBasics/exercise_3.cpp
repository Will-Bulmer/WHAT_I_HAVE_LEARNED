/*
PROBLEM: We have sales at $95,000 and need to pay State
Tax at 4%, and County Tax at 2%. Write code to show your
total sales as well as your State Tax, County Tax, and 
total tax you have to pay on this income.
*/

/*
SOLUTION:
- For monitary values, always use a DOUBLE
- Should use constants for tax rates to avoid them being changed
*/

#include <iostream>

void tax_calculator(std::string tax_type, float tax_percent, float total_sales){
    float tax_decimal = tax_percent / 100.0;
    float tax_amount = total_sales * tax_decimal;
    std::cout << tax_type << " = $" << tax_amount << std::endl;
}

int main() {
    float total_sales = 95000.0;
    float stateTaxRate = 4.0;
    float countyTaxRate = 2.0;
    float totalTaxRate = stateTaxRate + countyTaxRate;
    
    std::cout << "Total Sales = $" << total_sales << std::endl;
    tax_calculator("State Tax", stateTaxRate, total_sales);
    tax_calculator("County Tax", countyTaxRate, total_sales);
    tax_calculator("Total Tax", totalTaxRate, total_sales);
    return 0;
}

