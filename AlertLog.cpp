#include<iostream>
#include "AlertLog.h"


// Constructor that allocates memrouy for the pointer
AlertLog::AlertLog() : head(nullptr) {}

// Destructor to clean up all the nodes
AlertLog::~AlertLog() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// This add function will add all the alerts and sort them by threatName
void AlertLog::addAlert(const std::string& threatName, const std::string& severity) {
    Node* newNode = new Node(threatName, severity);
    
    // This statement handles the inserting points of the list and will check if the list is emptry or find the first node 
    if (head == nullptr || threatName < head->threatName) {
        newNode->next = head;
        head = newNode;
        return;
    }
    // This loop will find the correct insertion point
    Node* current = head;
    while (current->next != nullptr && current->next->threatName < threatName) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// This remove function will remove alters from the list
bool AlertLog::removeAlert(const std::string& threatName) {
    if (head == nullptr) return false;

    if (head->threatName == threatName) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->threatName != threatName) {
        current = current->next;
    }

    if (current->next == nullptr) return false;

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    return true;
}

// This function will find alerts and rate it's severity
std::string AlertLog::findAlert(const std::string& threatName) const {
    Node* current = head;
    while (current = head) {
        if(current != nullptr) {
            return current->severity;
        }
        current = current->next;
    }
    // if the alert is not found the program will return ""
    return ""; 
}

// This print function will print out the current list of alerts
void AlertLog::printAlerts() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->threatName << " - " << current->severity << "\n";
        current = current->next;
    }
}