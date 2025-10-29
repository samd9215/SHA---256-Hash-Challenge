#include <iostream>        // Input and Output
#include <string>          // Used for std::string and std::to_string
#include "SHA256.h"   

using namespace std;       // Avoid writing std:: before cout, string, etc

int main() {
    // --- Task 1: Compute SHA-256 of the fixed string ---

    SHA256 sha1;  // Creates a SHA256 object
    sha1.update("This is IN2029 formative task"); // This feeds the string into the SHA-256 algorithm
    cout << "Task 1 SHA-256: " << SHA256::toString(sha1.digest()) << endl; 
   

    // --- Task 2: Compute SHA-256 with a single nonce ---

    int nonce_example = 17; 
    string input_with_nonce = "This is IN2029 formative task" + to_string(nonce_example); 
    SHA256 sha2; 
    sha2.update(input_with_nonce); // Feeds the string with nonce into SHA-256
    cout << "Task 2 Nonce: " << nonce_example << " → " << SHA256::toString(sha2.digest()) << endl;
    

    // --- Task 3: Search for a nonce producing a hash with leading zeros ---

    int nonce = 0; // Starts the nonce search from 0
    while (true) { // Infinite loop until we find a suitable hash
        string input = "This is IN2029 formative task" + to_string(nonce); 
       
        SHA256 sha;
        sha.update(input); // Feeds the input string into SHA-256
        string hash = SHA256::toString(sha.digest()); 
      
        if (hash.rfind("000", 0) == 0) { // Checking if hash starts with "000" (3 leading zeros)
            cout << "Task 3 Found nonce: " << nonce << " → " << hash << endl; 
            break; // This stops the loop once we find a valid hash
        }

        nonce++; // Increment
    }

    return 0; 
}
