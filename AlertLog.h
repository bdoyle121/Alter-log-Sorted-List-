#ifndef ALERT_LOG_H
#define ALERT_LOG_H

#include <string>

class AlertLog {
    private:
        struct Node {
            std::string threatName;
            std::string severity;
            Node* next;

            Node(const std::string& name, const std:: string& sev)
                : threatName(name), severity(sev), next(nullptr) {}
        };

        Node* head;
    
    public:
        // Constructor and Destructor 
        AlertLog();
        ~AlertLog();
        void addAlert(const std::string& threatName, const std::string& severitiy);
        bool removeAlert(const std::string& threatName);
        std::string findAlert(const std::string& threatName) const;
        void printAlerts() const;
};

#endif