#include <iostream>                           // The #include tells the compiler that it needs to include access to a library, in this
                                              // case the iostream library which deals with input and output.         

using namespace std;                          // using namespace tells the compiler to apply the specified library prefixes to function calls
                                              // in this case it's specifying the std "standard" which prefixes std:: to calls like cout or cin.
                                              // This is great for smaller programs but in larger projects it's better to use 
                                              // namespaces with smaller scope than std  

 

bool searchList(const long [], int, long);    // This is a function prototype, this notifies the compiler that this function exists before it is called
                                              // within the program. Otherwise all functions would have to be written at the top of a program

 

const int SIZE = 10;                          // This is declaring a global constant integer variable called SIZE and initializing it with the value 10.
                                              // It is global meaning it's scope is the entire program and constant meaing it can't be changed once created.

 

int main()                                    // This is the main function call for this program. This is where an operating system looks to enter
                                              // a C++ program.

{

      long ticket[SIZE] = { 13579,  26791,       // This is an array declaration, the array is called "ticket" and has the type long. The size of the
                                                 // array is using the global const var SIZE which is 10. The array is initialized with the values
                                                 // inside the brackets.

                                      26792,  33445, 

                                      55555,  62483, 

                                      77777,  79422, 

                                      85647,  93121 };

                         

     

      long winningNum;                           // This is declaring a variable of type long called winningNum without initializing it with a value. A long 
                                                 // is short for long int, this is used when a regular int may not be large enough for the data

 

      cout << "\nPlease enter this week's 5-digit "   // This calls cout first cout, this is part of the iostream library (the namespace prefixes std:: to this)
                                                      // which is used to print to console. The << is an insertion operator which moves the (in this case) text
                                                      // on the right into the stream although not garanteed to be printed yet. The string data also has a '\n' 
                                                      // which is a new line char, which simply moves down a line first.

             << "winning lottery number: ";              // This is continuing the stream of data into the output buffer. After this line it is still not
                                                         // garanteed to output as no flush() or endl was called.

 

      cin  >> winningNum;                             // cin is cout's opposite, cin takes in characters from different types of input (in this case keyboard)
                                                      // and then uses >> which is an extraction operator which will take the input and extract it to the
                                                      // variable winningNum.

 

     

      if (searchList(ticket, SIZE, winningNum))       // This is an if statement. Inside it's condition is a function call to "searchList" which takes 
                                                      // three arguments (const long [], int, long) and returns a boolean. This was the function protoyped
                                                      // at the top of the program. When the function returns true the program will proceed into the if statement
                                                      // otherwise will pass over it.

      {

           

            cout << "You have a winning ticket.\n";      // This is the output to console that will happen when the if statement is true, in this case if
                                                         // a winning number is found

      }

      else                                            // the else statement is an optional statement to follow an if statement, the code inside it is 
                                                      // executed only when the proceeding if statement is false

      {

            cout << "You did not win this week." << endl;    // This is the output of the else statement which is a cout with text explaing that
                                                             // the ticket passed to seachList was not a winning ticket.

      }

 

      return 0;                             // the return 0; in main() tells the OS that the program successfully finished and exits. It can return
                                            // different values to give a different exit condition (eg: return 1; means an error occurred)

}

 

// ********************************************************

//                                                        *

//                                                        *

//                                                        * COMMENTS: can use /*   */ to comment out large sections

//                                                        * I'm not sure if I'm missing what this comment box is meant for?

//                                                        *

//                                                        *

// ********************************************************

 

 

 

 // I added this comment inncase the above  comment box was meant to comment on the function definition
 // The function definiton needs to match the prototype at the top of the file. This is where the functionality of said function is written.
 // This function definition is saying it will return a boolean type, the functions name, and finally lists the parameters that
 // are needed to be passed to the function to work.

bool searchList(const long list[], int numElems, long value)

{

      bool found = false;                            // Declares boolean variable found and initializes it to false

 

 

 // This is a for loop, for loops are used to iterate over instructions a set amount of times (for the most part). This for loop uses 
 // int count (initialized to 0), then says to check if count is less than numElems (function parameter) AND (&& and operator) bool found is not true.
 // When the condition is true count is then incremented by one using a post-incrememnt operator "count++" and the loop will iterate again, otherwise end.

      for (int count = 0; count < numElems && !found; count++)

      {

            if (list[count] == value)      // If statement with a condition that checks if the passed array "list" at index "count" is equal to 
                                           // the passed function parameter "value"

                  found = true;               // When the if statements condition is met the boolean "found" is set to true, this will also end the for loop
                                              // before the next iteration as the for loops condition is no longer true

      }

 

      return found;                     // The function needs to return a boolean value and does so with "found" which will return true 
                                        // if the array has a matching element to "value", otherwise false

}