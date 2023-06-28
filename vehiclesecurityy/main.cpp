#include <iostream>
#include <string>

class Vehicle;

class Hacker {
public:
    std::string manipulate(const std::string& message) {
        std::string new_message = message;
        for (char& c : new_message) {
            if (c >= 'a' && c <= 'z') {
                c = 'a' + (c - 'a' + 1) % 26;
            } else if (c >= 'A' && c <= 'Z') {
                c = 'A' + (c - 'A' + 1) % 26;
            }
        }
        return new_message;
    }
};

class Vehicle {
public:
    void send(Vehicle& other, const std::string& message) {
        std::string encrypted_message = encrypt(message);
        encrypted_message = hacker.manipulate(encrypted_message);
        other.receive(encrypted_message);
    }

    void receive(const std::string& message) {
        std::string decrypted_message = decrypt(message);
        std::cout << "Received: " << decrypted_message << std::endl;
    }

private:
    Hacker hacker;

    std::string encrypt(const std::string& message) {
        std::string encrypted_message = message;

        for (char& c : encrypted_message) {
            if (c >= 'a' && c <= 'z') {
                c = 'a' + (c - 'a' + 1) % 26;
            } else if (c >= 'A' && c <= 'Z') {
                c = 'A' + (c - 'A' + 1) % 26;
            }
        }

        return encrypted_message;
    }

    std::string decrypt(const std::string& message) {
        std::string decrypted_message = message;

        for (char& c : decrypted_message) {
            if (c >= 'a' && c <= 'z') {
                c = 'a' + (c - 'a' + 25) % 26;
            } else if (c >= 'A' && c <= 'Z') {
                c = 'A' + (c - 'A' + 25) % 26;
            }
        }

        return decrypted_message;
    }
};

int main() {
    Vehicle vehicle1;
    Vehicle vehicle2;

    vehicle1.send(vehicle2, "Hello from vehicle 1!");
    vehicle2.send(vehicle1, "Hello from vehicle 2!");

    return 0;
}
