#include <iostream>
#include "first.h"
#include <string> // allows use of std::string
#include <limits> // for: std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



int main()
{
    /*----------------
    std::string
    -----------------*/

    //Just like normal variables, you can initialize or assign values to strings as you would expect:

    std::string empty {}; // empty string 
    std::string myName { "sloiczek" } ;
    myName = "Ania"; // assign variable myName the string literal "Ania"

    //Note that strings can hold numbers as well:

    std::string myID{ "77" }; // "77" is not the same as integer 77!

    /*----------------------
    String input and output
    -----------------------*/


    std::cout << "my name is: " << myName << '\n'; //Strings can be output as expected using std::cout.

    std::cout << "Enter your full name (without getline() ): ";
    std::string name{};
    std::cin >> name; // this won't work as expected since std::cin breaks on whitespace
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Remove the extraneous newline character so getline() doesn't think we entered an empty string
 
    std::cout << "Enter your age (without getline() ): ";
    std::string age{};
    std::cin >> age;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Remove the extraneous newline character so getline() doesn't think we entered an empty string
 
    std::cout << "Your name is " << name << " and your age is " << age << '\n';


    /*
    Hmmm, that isn’t right! What happened? It turns out that when using 
    operator>> to extract a string from cin, operator>> only returns characters up 
    to the first whitespace it encounters. Any other characters are left inside cin, waiting for
    the next extraction.
    So when we used operator>> to extract a string into variable name, only “John” was extracted, 
    leaving “Doe” inside std::cin, waiting for the next extraction. When we then used operator>> to 
    get variable age, it extracted “Doe” instead of waiting for us to input an age. We are never given 
    a chance to enter an age.
    */

    /*------------------------------
    Use std::getline() to input text
    ------------------------------*/

    /*
    To read a full line of input into a string, you’re better off using 
    the std::getline() function instead. std::getline() takes two parameters: 
    the first is std::cin, and the second is your string variable.

    Here’s the same program as above using std::getline():
    */

    std::cout << "Enter your full name (with getline() ): ";
    std::string name1{};
    std::getline( std::cin, name1 ); // read a full line of text into name1 string.
 
    std::cout << "Enter your age (with getline() ): ";
    std::string age1{};
    std::getline( std::cin, age1 ); // read a full line of text into age1 string.
 
    std::cout << "Your name is " << name1 << " and your age is " << age1 << '\n'; 

    /*--------------------------------
    Mixing std::cin and std::getline()
    --------------------------------*/

    /*
    When we goint to use std::getline() after std::cin we have to use:

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')
    +#include <limits>

    after std::cin for extraneous newline character so getline() doesn't think we 
    entered an empty string.
    */

    /*------------
    String length
    ------------*/

    /*
    If we want to know how many characters are in a std::string is, 
    we can ask the std::string for its length. The syntax for doing this 
    is different than you’ve seen before, but is pretty straightforward:
    */

    std::string whatsDayIsToday { "wednesday hallo" };
    std::cout << whatsDayIsToday << " has " << whatsDayIsToday.length() << " characters\n";

    /*------------
    Quiz time
    ------------*/
    /*
    Question #1

    Write a program that asks the user to enter their full name and their age. 
    As output, tell the user how many years they’ve lived for each letter in their name 
    (for simplicity, count spaces as a letter).

    Sample output:

    Enter your full name: John Doe
    Enter your age: 46
    You've lived 5.75 years for each letter in your name.

    */
    //my answer is:
    std::cout << "Enter your name: ";
    std::string name3 {};
    std::getline( std::cin, name3 );
    
    std::cout << "Enter your age: ";
    std::string age3 {};
    std::getline( std::cin, age3 );

    double first = std::stoi(age3);

    std::cout << "You've lived " << first / name3.length() << " years for each letter in your name.\n";

    return 0;
}