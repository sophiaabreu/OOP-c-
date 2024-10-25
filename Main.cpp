#include <iostream>  // Include iostream for input/output operations
#include <string>    // Include string for using string variables
using namespace std; // Use the standard namespace

// Base class GameStructure
class GameStructure {
public:
    // Pure virtual function for Help, will be overridden in subclasses
    virtual void Help() = 0;
};

// Character class inherits from GameStructure
class Character : public GameStructure {
public:
    string Name;  // Public property for name of the character

    // Constructor to initialize the name and set initial Health to 100
    Character(string name) : Name(name), Health(100) {}

    // Overloaded Talk method that takes one parameter
    void Talk(string stuffToSay) {
        cout << Name << " says: " << stuffToSay << endl;  // Output name and message
    }

    // Overloaded Talk method that takes two parameters
    void Talk(string name, string stuffToSay) {
        cout << name << " says: " << stuffToSay << endl;  // Output provided name and message
    }

    // Virtual attack method, returns 10 by default, can be overridden by subclasses
    virtual int attack() {
        return 10; // Default attack power for character
    }

    // Getter method for Health property, returns the current health value
    int getHealth() {
        return Health;
    }

    // Setter method for Health property with validation
    void setHealth(int health) {
        if (health < 0) { // Check if health is below zero
            Health = 0;  // Set Health to 0 if health is negative
            cout << "Character has Expired..." << endl;  // Output character expiration message
        } else {
            Health = health; // Otherwise, set Health to provided value
        }
    }

    // Overridden Help method in Character class (does nothing here)
    void Help() override {}

protected:
    int Health;  // Private Health property for character health
};

// Ninja class inherits from Character
class Ninja : public Character {
public:
    // Constructor for Ninja, initializes Name using Character constructor
    Ninja(string name) : Character(name) {}

    // Method for Ninja's special action of throwing stars
    void ThrowStars() {
        cout << "I am throwing stars!" << endl; // Output message for throwing stars
    }

    // Override attack method, specific to Ninja, returns 25
    int attack() override {
        return 25; // Increased attack power for Ninja
    }

    // Override Help method with Ninja-specific message
    void Help() override {
        cout << "Ninjas are really cool, you can use them to throw stars!" << endl; // Output Ninja help message
    }
};

// Pirate class inherits from Character
class Pirate : public Character {
public:
    // Constructor for Pirate, initializes Name using Character constructor
    Pirate(string name) : Character(name) {}

    // Method for Pirate's special action of using a sword
    void UseSword() {
        cout << "I am Swooshing my Sword!" << endl; // Output message for using sword
    }

    // Override attack method, specific to Pirate, returns 25
    int attack() override {
        return 25; // Increased attack power for Pirate
    }

    // Override Help method with Pirate-specific message
    void Help() override {
        cout << "Pirates are fierce, you can use them to slash with swords!" << endl; // Output Pirate help message
    }
};

// Main function
int main() {
    cout << "Welcome to Pirates vs Ninjas!" << endl; // Display game intro
    cout << "Prepare for an epic battle of skills and strength!" << endl; // Display game setup message

    // Game loop, allows user to replay or exit
    char choice; // Variable to store user's choice to play again
    do {
        cout << "\nChoose your character (n for Ninja, p for Pirate): "; // Prompt for character choice
        char characterChoice; // Variable to store character choice
        cin >> characterChoice; // Get user input for character choice

        // Check if user chose Ninja
        if (characterChoice == 'n' || characterChoice == 'N') {
            Ninja ninja("Shadow"); // Create Ninja object with name "Shadow"
            ninja.Talk("Prepare to meet your end!"); // Call Talk method with message
            ninja.ThrowStars(); // Call Ninja's special action method
            cout << "Ninja attack points: " << ninja.attack() << endl; // Display Ninja's attack power
            ninja.Help(); // Call Ninja's Help method

        } 
        // Check if user chose Pirate
        else if (characterChoice == 'p' || characterChoice == 'P') {
            Pirate pirate("Blackbeard"); // Create Pirate object with name "Blackbeard"
            pirate.Talk("You are no match for my sword!"); // Call Talk method with message
            pirate.UseSword(); // Call Pirate's special action method
            cout << "Pirate attack points: " << pirate.attack() << endl; // Display Pirate's attack power
            pirate.Help(); // Call Pirate's Help method
        } 
        // Handle invalid character choice
        else {
            cout << "Invalid choice. Please choose again." << endl; // Error message for invalid input
            continue; // Skip to next iteration to prompt again
        }

        // Option to replay or exit
        cout << "Do you want to play again? (y/n): "; // Prompt for replay
        cin >> choice; // Get user input for replay choice
    } while (choice == 'y' || choice == 'Y'); // Continue loop if user chooses 'y' or 'Y'

    cout << "Thanks for playing Pirates vs Ninjas! Goodbye!" << endl; // Goodbye message on exit
    return 0; // End program
}
