#include<iostream>
#include<string>
#include "AlertLog.h"

int main() {
    AlertLog securityAlerts;

    // Add alerts (they will be inserted in sorted order)
    securityAlerts.addAlert("ZeroDay Exploit", "High");
    securityAlerts.addAlert("SQL Injection", "Medium");
    securityAlerts.addAlert("Phishing Attempt", "High");

    // Print current alert log
    std::cout << "Security Alert Log:\n";
    securityAlerts.printAlerts();

    // Search for an alert
    std::string searchThreat = "SQL Injection";
    std::string severity = securityAlerts.findAlert(searchThreat);

    if (!severity.empty()) {
        std::cout << "\nFound alert '" << searchThreat << "' with severity: " << severity << "\n";
    } else {
        std::cout << "\nAlert '" << searchThreat << "' not found in the log.\n";
    }

    // Remove an alert
    std::cout << "\nRemoving 'Phishing Attempt'...\n";
    bool removed = securityAlerts.removeAlert("Phishing Attempt");
    std::cout << (removed ? "Success" : "Not Found") << "\n";

    // Print updated alert log
    std::cout << "\nUpdated Security Alert Log:\n";
    securityAlerts.printAlerts();

    return 0;
}