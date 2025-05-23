#include "systemlocker.hpp"
#include <iostream>



namespace {
    /**
    * This is a sample function to authenticate a user based on a license key.
    *
    * The code you need to add in your program should look like what is inside mock().
    *
    * This function prompts the user to input their license key and then attempts
    * authentication using `SystemLocker::Authenticate`. The authentication can be
    * configured to lock based on hardware ID (HWID).
    *
    * Flowchart:
    * - Prompts the user to enter a license key.
    * - Attempts to authenticate using `SystemLocker::Authenticate`.
    * - If authentication is successful, outputs a success message.
    * - If authentication fails, outputs a failure message.
    */

    /// <summary>
    /// Prompts the user for their license key, initializes the system locker,
    /// and attempts to authenticate using the provided key. Outputs the 
    /// authentication status.
    /// </summary>
    void mock() {
        std::string userInput{}; // Declare a string to hold the user's input for the license key.

        std::cout << "Please input your license key : "; // Prompt the user to enter their license key.
        std::cin >> userInput; // Read the user input from the console and store it in userInput.

        bool shouldUseHwidLock{ true }; // Flag indicating that HWID locking should be enabled.
        //std::string customHwid{ "custom" }; // Uncomment and pass in the result of your own HWID function to enable. 

        SystemLocker::Initialize(shouldUseHwidLock); // Initialize the system locker with HWID locking enabled.

        auto const authenticated = SystemLocker::Authenticate(userInput); // Authenticate the user with the provided key and store the result.

        if (authenticated) { // Check if authentication was successful.
            std::cout << "Authenticated successfully!\n"; // Notify the user of successful authentication.
        }
        else {
            std::cout << "Failed to authenticate!\n"; // Notify the user of failed authentication.
        }
    }

    void tests() {
        bool shouldUseHwidLock{ true };

        auto constexpr goodKey = "test-system-98GMMZXSLR"; // A valid license key for testing
        auto constexpr badKey = "test-system-jhefksgr";    // An invalid license key for testing

        SystemLocker::test::RunAll(shouldUseHwidLock, goodKey, badKey); // Run all tests with both keys
    }
} // unnamed namespace

int main() {
    
    mock();
    std::cout << "\n\n\n";

    tests();
    std::cout << "\n\n\n";

    std::cin.get();
}




































/*
namespace test {
    /*

    void serversideVariable() {
        std::cout << "Running: " << __FUNCTION__ << "\n";

        nlohmann::json requestData = {
            { fields::key, kKey },
            { fields::system, kSystem },
            { fields::hwid, hwid },
            { fields::version, kVersion },
            { fields::clean, kClean },
            { fields::intent, "variable" },
            { fields::var1, "eeeeeeeeeeeeeeeeee" }
        };

        auto const response = submitRequest(requestData);

        std::cout << formatResponse(response) << "\n";
    }
}
*/