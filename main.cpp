#include <iostream>
#include <string>
using namespace std;

// Function to display Nucor / Christensen Disruptive Model info
void displayModelInfo() {
    cout << "===================================================\n";
    cout << "   NUCOR STEEL MINI-MILL: DISRUPTIVE INNOVATION    \n";
    cout << "       (Clayton Christensen's Model)               \n";
    cout << "===================================================\n";
    cout << "Mini-mills utilized Electric Arc Furnaces (EAF) to\n";
    cout << "melt scrap steel, achieving ~20% cost advantages\n";
    cout << "and disrupting traditional capital-intensive mills.\n";
    cout << "---------------------------------------------------\n";
}

int main() {
    displayModelInfo();

    int choice;
    double tonnage;
    const double traditionalCostPerTon = 800.0; // Baseline cost for integrated mills

    cout << "\nSelect Nucor Steel Product Category:\n";
    cout << "1. Rebar (Low-End Entry - ~7% margin for incumbents)\n";
    cout << "2. Structural Steel (Mid-Tier Expansion - Wide-flange beams)\n";
    cout << "3. Sheet Steel (Upmarket Movement - Thin-slab casting)\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 3) {
        cout << "Invalid selection. Please restart the program and choose between 1 and 3.\n";
        return 1;
    }

    cout << "Enter required steel quantity in tons: ";
    cin >> tonnage;

    if (tonnage <= 0) {
        cout << "Invalid tonnage entered.\n";
        return 1;
    }

    string category = "";
    double eafCostPerTon = 0.0;
    string marketImpact = "";

    // Using switch statement to process user choices based on Christensen's model tiers
    switch (choice) {
        case 1:
            category = "Rebar (Reinforcing Bars)";
            eafCostPerTon = traditionalCostPerTon * 0.80; // ~20% cost reduction
            marketImpact = "Low-end foothold: Incumbents ignored this low-margin segment, allowing Nucor to enter safely.";
            break;
        case 2:
            category = "Structural Steel (Beams)";
            eafCostPerTon = traditionalCostPerTon * 0.82; 
            marketImpact = "Upmarket expansion: Nucor scaled operations through joint ventures like Nucor-Yamato.";
            break;
        case 3:
            category = "Flat-Rolled Sheet Steel";
            eafCostPerTon = traditionalCostPerTon * 0.85; 
            marketImpact = "Full disruption: Pioneered thin-slab casting technology, overtaking legacy integrated giants.";
            break;
    }

    double totalTraditionalCost = tonnage * traditionalCostPerTon;
    double totalEafCost = tonnage * eafCostPerTon;
    double totalSavings = totalTraditionalCost - totalEafCost;

    // Output results
    cout << "\n===================================================\n";
    cout << "              PRODUCTION COST ANALYSIS             \n";
    cout << "===================================================\n";
    cout << "Product Category : " << category << "\n";
    cout << "Quantity         : " << tonnage << " tons\n";
    cout << "Traditional Cost : $" << totalTraditionalCost << " (Integrated Mill)\n";
    cout << "Nucor EAF Cost   : $" << totalEafCost << " (Mini-Mill Model)\n";
    cout << "Estimated Savings: $" << totalSavings << " (~20% EAF Advantage)\n";
    cout << "---------------------------------------------------\n";
    cout << "Disruption Stage : " << marketImpact << "\n";
    cout << "===================================================\n";

    return 0;
}