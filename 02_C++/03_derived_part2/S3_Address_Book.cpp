#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

// 1. Function to add a new contact
void addContact(std::vector<Contact>& contacts) {
    Contact newContact;
    std::cout << "Enter name: ";
    std::cin >> newContact.name;
    std::cout << "Enter phone: ";
    std::cin >> newContact.phone;
    std::cout << "Enter email: ";
    std::cin >> newContact.email;
    contacts.push_back(newContact);
    std::cout << "Contact added successfully!" << std::endl;
}

// 2. Function to update an existing contact
void updateContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter the name of the contact to update: ";
    std::cin >> name;

    auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
        return c.name == name;
    });

    if (it != contacts.end()) {
        std::cout << "Enter new phone: ";
        std::cin >> it->phone;
        std::cout << "Enter new email: ";
        std::cin >> it->email;
        std::cout << "Contact updated successfully!" << std::endl;
    } else {
        std::cout << "Contact not found!" << std::endl;
    }
}

// 3. Function to search for a contact
void searchContact(const std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter the name of the contact to search: ";
    std::cin >> name;

    auto it = std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
        return c.name == name;
    });

    if (it != contacts.end()) {
        std::cout << "Name: " << it->name << std::endl;
        std::cout << "Phone: " << it->phone << std::endl;
        std::cout << "Email: " << it->email << std::endl;
    } else {
        std::cout << "Contact not found!" << std::endl;
    }
}

// 4. Function to display all contacts
void displayContacts(const std::vector<Contact>& contacts) {
    std::cout << "Address Book:" << std::endl;
    for (const auto& contact : contacts) {
        std::cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << std::endl;
    }
}

// 5. Function to remove a certain contact
void removeContact(std::vector<Contact>& contacts) {
    std::string name;
    std::cout << "Enter the name of the contact to remove: ";
    std::cin >> name;

    auto it = std::remove_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
        return c.name == name;
    });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "Contact removed successfully!" << std::endl;
    } else {
        std::cout << "Contact not found!" << std::endl;
    }
}

// 6. Function to remove all contacts
void removeAllContacts(std::vector<Contact>& contacts) {
    contacts.clear();
    std::cout << "All contacts removed successfully!" << std::endl;
}

// 7. Function to close the address book
void closeBook() {
    std::cout << "Closing the address book. Goodbye!" << std::endl;
}

int main() {
    std::vector<Contact> contacts;
    int choice;

    while (true) {
        std::cout << "Address Book Menu:" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Update Contact" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Display Contacts" << std::endl;
        std::cout << "5. Remove Contact" << std::endl;
        std::cout << "6. Remove All Contacts" << std::endl;
        std::cout << "7. Close Book" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                updateContact(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                displayContacts(contacts);
                break;
            case 5:
                removeContact(contacts);
                break;
            case 6:
                removeAllContacts(contacts);
                break;
            case 7:
                closeBook();
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
