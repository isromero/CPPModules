#include <iostream>
#include <string>
#include <iomanip>

class Contact {
  public:
    Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}
    Contact(const std::string& first, const std::string& last, const std::string& nick,
            const std::string& phone, const std::string& secret)
        : firstName(first), lastName(last), nickname(nick), phoneNumber(phone), darkestSecret(secret) {}
    
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }

  private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

class PhoneBook {
  public:
    PhoneBook() : currentContactIndex(0) {}
    void addContact(const Contact& contact) {
      if (currentContactIndex < maxContacts) {
        contacts[currentContactIndex] = contact;
        currentContactIndex++;
      } else {
        contacts[0] = contact;
      }
    }

    void printContacts() {
      int index = 0;
      for (const auto& contact : contacts) {
        std::cout << std::setw (10) << "index" " | ";
        std::cout << std::setw (10) << "first name" " | ";
        std::cout << std::setw (10) << "last name" " | ";
        std::cout << std::setw (10) << "last name";
        std::cout << std::endl;

        std::cout << index;
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        
        index++;
      }
    }

    void printSpecificContact(int i) {
      const auto& contact = contacts[i];
      if (i >= 0 && i <= currentContactIndex) {
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
      } else {
        std::cout << "The index of the Contact doesn't exist" << std::endl;
      }
    }

  private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int currentContactIndex;
};

int main() {
  PhoneBook myPhoneBook;

  std::string input;
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
  int index;

  while(input != "EXIT") {
    std::cout << "You have 3 options in your agenda: ADD, SEARCH or EXIT. Use them all!" << std::endl;
    std::getline(std::cin,input);
    
    if (input == "ADD") {
      std::cout << "You are going to add a contact to the agenda, fill this fields:" << std::endl;
      std::cout << "First Name: ";
      std::getline(std::cin, firstName);
      std::cout << "Last Name: ";
      std::getline(std::cin, lastName);
      std::cout << "Nickname: ";
      std::getline(std::cin, nickname);
      std::cout << "Phone Number: ";
      std::getline(std::cin, phoneNumber);
      std::cout << "Darkest Secret: ";
      std::getline(std::cin, darkestSecret);
      Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
      myPhoneBook.addContact(contact);
    } else if (input == "SEARCH") {
        std::cout << "You are going to search a specific contact" << std::endl;
        std::cout << "This is your agenda right now:" << std::endl;
        myPhoneBook.printContacts();
        std::cout << "Insert the index of the contact that you want to search: ";
        std::cin >> index;
        std::cout << std::endl;
        myPhoneBook.printSpecificContact(index);
    }
  }
  return 0;
}
