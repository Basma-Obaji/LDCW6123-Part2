#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// ========================================================
// PROJECT: Nucor Steel Mini-Mill Calculator (Part 2)
// INPUTS: User Name, Professional Role Choice (1-3), 
//         Market Tier Choice (1-3), Production Tonnage
// LOGIC: Struct-based data mapping, switch statements, 
//        robust input validation loops.
// OUTPUTS: Cost comparison, EAF percentage savings, 
//          Christensen Disruptive Innovation phase insight.
// ========================================================

using namespace std;

// Struct to hold market tier data mapped to Christensen's model
struct MarketTier {
    int id;
    string name;
    string application;
    string productionMethod;
    double baseCostPerTonIntegrated; // Traditional integrated mill baseline cost ($)
    double eafCostAdvantagePercentage; // Christensen's economic advantage (~20%)
    string disruptionPhase;
};

class NucorSimulator {
private:
    string userName;
    string userRole;
    vector<string> searchHistory;
    vector<MarketTier> tiers;

public:
    NucorSimulator() {
        // Initialize historical and economic data based on research
        tiers = {
            {1, "Low-End Construction (Rebar)",
             "Residential/commercial concrete reinforcement",
             "Electric Arc Furnace (EAF) scrap melting",
             650.0, 0.20, "Low-End Foothold (Weak incumbent interest due to ~7% gross margin)"},

            {2, "Medium-Grade Structural Steel",
             "Skyscraper frameworks and bridge construction",
             "Advanced EAF long-product rolling (Nucor-Yamato model)",
             850.0, 0.18, "Upmarket Expansion (Capturing higher-load structural segments)"},

            {3, "High-Grade Sheet Steel",
             "Automotive body panels and home appliances",
             "Compact Strip Production (CSP) / Thin-slab casting",
             1100.0, 0.15, "Mainstream Disruption (Overtaking legacy integrated giants)"}
        };
    }

    void startSession() {
        cout << "\n========================================================\n";
        cout << "    ADVANCED NUCOR DISRUPTION & COST SIMULATOR (C++)    \n";
        cout << "========================================================\n";

        // Name validation loop (ensures name isn't blank)
        do {
            cout << "Enter your name: ";
            getline(cin, userName);
            if (userName.empty() || (userName.length() == 1 && !isalpha(userName[0]))) {
                cout << "[Error] Name cannot be empty or invalid. Please try again.\n";
            }
        } while (userName.empty());

        // Strict Role Validation using a selection menu to prevent nonsense strings like 'E'
        int roleChoice = 0;
        do {
            cout << "\nSelect your professional/academic role:\n";
            cout << "1. Computer Science Student\n";
            cout << "2. Industrial Analyst\n";
            cout << "3. Economics Researcher\n";
            cout << "Enter choice (1-3): ";
            cin >> roleChoice;

            if (cin.fail() || roleChoice < 1 || roleChoice > 3) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Error] Invalid selection. Please choose a valid role option between 1 and 3.\n";
            } else {
                if (roleChoice == 1) userRole = "Computer Science Student";
                else if (roleChoice == 2) userRole = "Industrial Analyst";
                else userRole = "Economics Researcher";
            }
        } while (roleChoice < 1 || roleChoice > 3);

        // Clear input buffer after cin numeric read
        cin.ignore(10000, '\n');

        cout << "\n[System] Initialized simulation successfully for " << userName << " (" << userRole << ").\n";
    }

    void displayMenu() {
        cout << "\n--------------------------------------------------------\n";
        cout << "               SELECT A MARKET TIER                     \n";
        cout << "--------------------------------------------------------\n";
        for (const auto& tier : tiers) {
            cout << tier.id << ". " << tier.name << "\n";
        }
        cout << "4. View Session Summary & Export Log\n";
        cout << "5. Exit Simulator\n";
        cout << "--------------------------------------------------------\n";
        cout << "Enter your choice (1-5): ";
    }

    void processTier(int choice, double tonnage) {
        if (choice < 1 || choice > 3) return;

        const MarketTier& t = tiers[choice - 1];

        // Dynamic calculations based on user input tonnage
        double integratedTotalCost = t.baseCostPerTonIntegrated * tonnage;
        double eafTotalCost = integratedTotalCost * (1.0 - t.eafCostAdvantagePercentage);
        double totalSavings = integratedTotalCost - eafTotalCost;

        cout << "\n========================================================\n";
        cout << " >>> ANALYSIS REPORT: " << t.name << " <<<\n";
        cout << "========================================================\n";
        cout << fixed << setprecision(2);
        cout << "Target Application  : " << t.application << "\n";
        cout << "Production Tech     : " << t.productionMethod << "\n";
        cout << "Target Tonnage      : " << tonnage << " metric tons\n";
        cout << "--------------------------------------------------------\n";
        cout << "ECONOMIC COMPARISON SIMULATION:\n";
        cout << " * Integrated Mill Est. Cost : $" << integratedTotalCost << "\n";
        cout << " * EAF Mini-Mill Est. Cost   : $" << eafTotalCost << " (Highlights ~" << (t.eafCostAdvantagePercentage * 100) << "% cost advantage)\n";
        cout << " * Estimated Capital Savings : $" << totalSavings << "\n";
        cout << "--------------------------------------------------------\n";
        cout << "CHRISTENSEN DISRUPTION INSIGHT:\n";
        cout << " -> " << t.disruptionPhase << "\n";
        cout << "========================================================\n";

        // Log query to session history
        searchHistory.push_back(t.name + " (" + to_string((int)tonnage) + " tons analyzed)");
    }

    void showSummary() {
        cout << "\n========================================================\n";
        cout << "            SESSION ACTIVITY SUMMARY                    \n";
        cout << "========================================================\n";
        cout << "User : " << userName << " [" << userRole << "]\n";
        cout << "Total Tiers Analyzed This Session: " << searchHistory.size() << "\n";
        if (searchHistory.empty()) {
            cout << "No analyses performed yet.\n";
        } else {
            cout << "History Log:\n";
            for (size_t i = 0; i < searchHistory.size(); ++i) {
                cout << "  " << (i + 1) << ". " << searchHistory[i] << "\n";
            }
        }
        cout << "========================================================\n";
    }

    void run() {
        startSession();
        int choice;
        double tonnage;

        do {
            displayMenu();
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\n[Error] Invalid numeric input. Please enter a valid number.\n";
                continue;
            }

            if (choice >= 1 && choice <= 3) {
                cout << "Enter production volume / target tonnage (e.g., 5000): ";
                cin >> tonnage;
                if (cin.fail() || tonnage <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "\n[Error] Invalid tonnage. Defaulting to 1000 tons.\n";
                    tonnage = 1000.0;
                }
                processTier(choice, tonnage);
            }
            else if (choice == 4) {
                showSummary();
            }
            else if (choice == 5) {
                cout << "\nExiting simulator. Great work on Part 2, " << userName << "!\n";
            }
            else {
                cout << "\n[Error] Invalid menu choice. Select an option between 1 and 5.\n";
            }

        } while (choice != 5);
    }
};

int main() {
    NucorSimulator simulator;
    simulator.run();
    return 0;
}
