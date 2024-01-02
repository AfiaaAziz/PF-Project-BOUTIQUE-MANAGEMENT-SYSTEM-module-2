#include <iostream> // header file for input output stream
#include <fstream> // header file for file streams
#include <iomanip> // header file for setw.

using namespace std;

const int max_customers = 100;//(rows) 
const int attributes = 4;//(columns)


// Function declarations
void mainMenu(); // function for main menu
void DressesMenu(); // function for dresses menu
void addDress();   // Function to add a dress
void viewDress();   // Function to view all dresses
void searchDress();   // Function to search for a dress by dress code
void updateDress();   // Function to update dress information
void deleteDress();   // Function to delete a dress


void CustomerMenu(); //function for customer menu
void addCustomer(int customers[][attributes], int& numCustomers);// function to add customer details.
void viewCustomers(const int customers[][attributes], int numCustomers); // function to view customer details.
void deleteCustomer(int customers[][attributes], int& numCustomers);// function to delete customer details.
void updateCustomer(int customers[][attributes], int numCustomers);// function to update customer details.
void searchCustomer(const int customers[][attributes], int numCustomers);// function for search customer details.
void addToFile(const int customers[][attributes], int numCustomers);// function to add customer details to files.
void loadFromFile(int customers[][attributes], int& numCustomers);// function to load customer details from files.

int main() //main function 
{
    while (true) //loops through the block of code as long as the condition is true
    {
        mainMenu();//calling main menu function

    }
    return 0;
}

void mainMenu() //function to dispaly the main menu .
{
    int choice;// variable of int datatype to store the choice of user
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "************************************************************ BOUTIQUE MANAGEMENT SYSTEM ************************************************************" << endl;
   cout <<  "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
   //menu displayed for the user either he works on entity 1 or 2 
    cout << "1. DRESSES " << endl;
    cout << "2. CUSTOMER " << endl;
    cout << "3. Exit " << endl;
    //choice is taken from the user
    cout << "Enter your choice: ";
    cin >> choice;//user enter choice

    switch (choice) //switch statements is used to handle the user choice
    {
    case 1:
        while (true)//loop through the dresses menu as long as the condition is true
        {
            DressesMenu();// If user chooses Dresses, go to DressesMenu function
        }
        break;
    case 2:
        while (true) //loop through the dresses menu as long as the condition is true
        {
            CustomerMenu(); // If user chooses Customer, go to CustomerMenu function
        }
            break;
  
    case 3:
        exit(0);// If user chooses Exit, exit the program
    default:
        cout << "Invalid choice!\n Enter a valid choice" << endl;// Displaying an error message for invalid choices
        break;
    }
}
void DressesMenu() // Function to display the Dresses menu
{
    int choice;// Variable to store the user's choice
    
    cout << "******* DRESSES *******" << endl;
   
    // Displaying Dresses menu options
    cout << "1. Add dress " << endl;
    cout << "2. View dress " << endl;
    cout << "3. Search dress " << endl;
    cout << "4. Update dress " << endl;
    cout << "5. Delete dress " << endl;
    cout << "6. Back to Main Menu " << endl;
    
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Enter your choice: ";    // Prompting user for input

    cin >> choice;//user enter the choice from the above choices.

    
   //switch statements is used to handle the user choice
    
    switch (choice) 
    {
    case 1: 
        addDress();// If user chooses Add dress, go to addDress function
        break;
    case 2:
        viewDress();// If user chooses View dress, go to viewDress function
        break;
    case 3:
        searchDress();// If user chooses Search dress, go to searchDress function
        break;
    case 4:
        updateDress();// If user chooses Update dress, go to updateDress function
       
        break;
    case 5:
        deleteDress();// If user chooses Delete dress, go to deleteDress function
        break;
   
    case 6:
        mainMenu();// If user chooses Back to Main Menu, go back to mainMenu function
        break;
    default:
        cout << "Invalid choice!\n Enter a valid choice" << endl;// Displaying an error message for invalid choices
        break;
    }
}


//function to add dress
void addDress()
{
    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price

    ofstream outputfile; // Output stream to create and write to the file
    outputfile.open("dresses.txt", ios::app); // Open the file in append mode to add dress information
   
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << " Enter Dresses details: " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

 
    cout << " Enter code of dress: "; // Prompt user for dress code
    cin >> dress_code; // Get user input for dress code
    cout << " Enter Name of dress: "; // Prompt user for dress name
    cin >> dress_Name; // Get user input for dress name
    cout << " Enter the material/type of dress: "; // Prompt user for dress type
    cin >> dress_type; // Get user input for dress type
    cout << " Enter the price of dress: "; // Prompt user for dress price
    cin >> dress_Price; // Get user input for dress price

    // Write dress information to the file
    outputfile << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t\t" << dress_Price << endl;

    cout << "Dress added successfully.\n"; // Display success message
    outputfile.close(); // Close the file
}



// Function to view all dresses
void viewDress()
{
    ifstream fin; // Input stream to read from the file
    fin.open("dresses.txt"); // Open the file for reading
    //using exception handling.
    try
    {
        if (fin.fail())// Check if reading from the file fails
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e)// Catch and handle runtime error if file operation fails
    {
        cout << "Error" << e.what() << endl; //  display the error
    }

    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price

    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    // Display header for dress information
    cout << "Dress Code\tDress Name\t\tDress Type\t\tDress Price " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;


    // Loop through the file's rows and display dress information
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        cout << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t" << dress_Price << endl;
    }
    fin.close(); // Close the file
}
// Function to search for a dress by dress code
void searchDress()
{
    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price

    ifstream fin; // Input stream to read from the file
    fin.open("dresses.txt"); // Open the file for reading
    //using exception handling.
    try
    {
        if (fin.fail()) // check if reading from the file files.
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e) // catch and handle runtime error if file operation fails.
    {
        cout << "Error" << e.what() << endl; // display the error
    }

    string search_code; // Variable to store the dress code to be searched

    cout << " Enter the Code of dress you want to search: "; // Prompt user for the dress code to search
    cin >> search_code; // Get user input for the dress code
    bool found = false; // Variable to track whether the dress is found or not

    // Loop through the file's rows and search for the dress with the specified dress code
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        if (dress_code == search_code)// Check if the dress code matches the search code
        {
            found = true; // Set found to true if the dress is found
            cout << " Dress Found:  Code: " << dress_code << endl; // display dress code.
            cout << " Name: " << dress_Name << endl; // dispaly dress name.
            cout << " Type: " << dress_type << endl; // dispaly dress type.
            cout << " Price: " << dress_Price << endl; // display dress price.
        }
    }

    // Display message if the dress is not found
    if (!found)
    {
        cout << " Dress with this " << search_code << " does not found " << endl;
    }

    fin.close(); // Close the file
}

// Function to update the dress information
void updateDress()
{
    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price

    string update_code; // Variable to store the dress code to be updated

    cout << " Enter the dress Code you want to update: "; // Prompt user for the dress code to update
    cin >> update_code; // Get user input for the dress code to update

    ifstream fin; // Input stream to read from the file
    fin.open("dresses.txt"); // Open the file for reading
    //using exception handling.
    try
    {
        if (fin.fail())// check if reading from the file files.
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e)// catch and handle runtime error if file operation fails.
    {
        cout << "Error" << e.what() << endl; // display the error.
    }

    ofstream fout; // Output stream to create and write to a temporary file
    fout.open("temp.txt"); // Open the temporary file

    // Loop through the file's rows and update the dress information
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        if (dress_code == update_code)// Check if the dress code matches the update code
        {
            cout << " Enter the new price : "; // Prompt user for the new dress price
            cin >> dress_Price; // Get user input for the new dress price
        }
        fout << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t\t" << dress_Price << endl;
    }

    cout << " Price updated successfully "; // Display success message
    fout.close(); // Close the temporary file
    fin.close(); // Close the original file

    fin.open("temp.txt"); // Open the temporary file for reading
    //using exception handling.

    try
    {
        if (fin.fail())// check if reading from the file files.
        {
            throw runtime_error("File not found."); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e) // catch and handle runtime error if file operation fails.
    {
        cout << "Error" << e.what() << endl; // Catch and display the error
    }

    fout.open("dresses.txt"); // Open the original file for writing

    // Loop through the temporary file's rows and write to the original file
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        fout << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t\t" << dress_Price << endl;
    }

    fout.close(); // Close the original file
    fin.close(); // Close the temporary file
}

// Function to delete a dress
void deleteDress()
{
    string dress_code, dress_Name, dress_type; // Variables to store dress information
    double dress_Price; // Variable to store dress price

    ifstream fin; // Input stream to read from the file
    ofstream fout; // Output stream to create and write to a temporary file


    fout.open("temp.txt"); // Open the temporary file for writing
    fin.open("dresses.txt"); // Open the original file for reading

    //using exception handling.

    try
    {
        if (fin.fail())// check if reading from the file files.
        {
            throw runtime_error("File Not Found"); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e) // catch and handle runtime error if file operation fails.
    {
        cout << "Error! " << e.what() << endl; //  display the error
    }

    string delete_code; // Variable to store the dress code to be deleted

    cout << " Enter the dress code you want to delete: "; // Prompt user for the dress code to delete
    cin >> delete_code; // Get user input for the dress code to delete

    // Loop through the file's rows and delete the specified dress
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        if (dress_code == delete_code)// Check if the dress code matches the delete code
        {
            cout << " Dress with code " << delete_code << "  is deleted successfully.\n"; // Display success message
            continue; // Skip writing the deleted dress to the temporary file
        }
        fout << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t\t" << dress_Price << endl;//
    }

    fin.close(); // Close the original file
    fout.close(); // Close the temporary file

    fin.open("temp.txt"); // Open the temporary file for reading
    //using exception handling.

    try
    {
        if (fin.fail()) // check if reading from the file files.
        {
            throw runtime_error("File Not Found"); // Throw an error if file opening fails
        }
    }
    catch (runtime_error& e)// catch and handle runtime error if file operation fails.
    {
        cout << "Error! " << e.what() << endl; //  display the error
    }

    fout.open("dresses.txt"); // Open the original file for writing

    // Loop through the temporary file's rows and write to the original file
    while (fin >> dress_code >> dress_Name >> dress_type >> dress_Price)
    {
        fout << dress_code << "\t\t" << dress_Name << "\t\t\t" << dress_type << "\t\t\t\t" << dress_Price << endl;
    }

    fout.close(); // Close the original file.
    fin.close(); // Close the temporary file.
}
// function to display customer menu
void CustomerMenu() 
{
    int customers[max_customers][attributes];//2D array of name customers to store customer data
    int numCustomers = 0;//variable to keep track of the number of customers 
    loadFromFile(customers, numCustomers);//function to load customers data from file is  called.


    int choice;//variable is declared to handle the user's choices
    //displaying the customer menu options
    
    cout << "*******CUSTOMER*******" << endl;
    
    cout << "1. Add customer " << endl;
    cout << "2. View customers " << endl;
    cout << "3. Search customer " << endl;
    cout << "4. Update customer " << endl;
    cout << "5. Delete customer " << endl;
    cout << "6. Back to Main Menu " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << "Enter your choice: ";//prompts the user to enter choice 

    cin >> choice;//the user enter the choice from the above menu

    //switch statements is used to handle the user choice
    switch (choice) 
    {//start of switch brackets
    case 1://case 1 where add customer function is called
        addCustomer(customers, numCustomers);
        break;
    case 2://case 2 where view customer function is called
        viewCustomers(customers, numCustomers);
        break;
    case 3://case 3 where  search customer function is called
        searchCustomer(customers, numCustomers);
        break;
    case 4://case 4 where update customer function is called
        updateCustomer(customers, numCustomers);
        break;
    case 5://case 5 where delete customer function is called
        deleteCustomer(customers, numCustomers);
        break;
    case 6://case 6 if the user enter 6 it return to the main menu
        mainMenu();
        break;
    default://default case invalid choice.
        cout << "Invalid choice!\n Enter a valid choice" << endl;
        break;
    }
}
//function to add a new customer.
void addCustomer(int customers[][attributes], int& numCustomers)//function definition to add a new customer
{//checking if there is space for a new customer as num customer keep the track of number of customers
    if (numCustomers < max_customers)
    {
        cout << "---------------------------" << endl;
        cout << " Enter customer details: " << endl;
        cout << "---------------------------" << endl;

        cout << " Enter Customer's ID: ";
        cin >> customers[numCustomers][0];// reading and storing customer id in 2d array 
        cout << " Enter Receipt No.: ";
        cin >> customers[numCustomers][1];// reading and storing customer receipt number in 2d array 
        cout << " Enter Customer's age: ";
        cin >> customers[numCustomers][2];// reading and storing customer's age in 2d array 
        cout << " Enter Total Purchases: ";
        cin >> customers[numCustomers][3];// reading and storing customer's total purchases in 2d array 

        numCustomers++;//incrementing the number of customers

        addToFile(customers, numCustomers);//adding all the customer information to a file 

        cout << "Customer added successfully.\n";
    }
    else// this statement executes if the maximum number of customers is reached
    {
        cout << "Maximum number of customers reached." << endl;
    }
}
//function to view the customer details
void viewCustomers(const int customers[][attributes], int numCustomers) 
{
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout << " ID\tReceipt No.\tAge\tTotal Purchases " << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    //loop iterates through each customer printing id,receipt number,age and total purchases.
    for (int i = 0; i < numCustomers; i++) 
    {//starting of for loop brackets.
        //printing each attribute of the customer.
        cout << customers[i][0] << setw(10)<< customers[i][1] << setw(12) << customers[i][2] << setw(15) << customers[i][3] << endl;
    }//ending of for loop brackets
}


// Function to search for a customer by ID in a 2D array 'customers'
void searchCustomer(const int customers[][attributes], int numCustomers) 
{
    int search_id;// Variable to store the customer ID to be searched

    cout << "---------------------------------------------" << endl;
    // Prompt the user to enter the ID of the customer to be searched

    cout << "Enter the ID of customer you want to search: ";
    cin >> search_id;

    bool found = false;// Boolean flag to indicate whether the customer is found or not


    for (int i = 0; i < numCustomers; i++)     // Loop through each customer in the array

    {
        if (customers[i][0] == search_id)   // Check if the current customer's ID matches the search ID

        {
            found = true;  // Set the 'found' flag to true

            cout << "---------------" << endl;
            // Display customer information including id receipt number age and total purchaces

            cout << "Customer Found:" << endl;
            cout << "---------------" << endl;

            cout << "ID: " << customers[i][0] << endl;
            cout << "Receipt No.: " << customers[i][1] << endl;
            cout << " Age " << customers[i][2] << endl;
            cout << " Total Purchases " << customers[i][3] << endl;
        }
    }
    // Check if the customer was not found and display a message.

    if (!found) {
        cout << "Customer with ID " << search_id << " not found." << endl;
    }
}
// Function to update customer details by searching with their ID

void updateCustomer(int customers[][attributes], int numCustomers) {
    int update_id;    // Variable to store the customer ID to be updated

    cout << "---------------------------------------------" << endl;
    // Prompt the user to enter the ID of the customer to be updated

    cout << "Enter the ID of customer you want to update: ";

    cin >> update_id;
    // Boolean flag to indicate whether the customer is found or not

    bool found = false;

    for (int i = 0; i < numCustomers; i++)     // Loop through each customer in the array
    {
        if (customers[i][0] == update_id)         // Check if the current customer's ID matches the update ID

        {
            found = true;
            cout << "-----------------------------------" << endl;

            cout << "Enter new details for the customer:" << endl;
            cout << "-----------------------------------" << endl;

            cout << " Enter Customer's ID: "; // Display a message prompting the user to enter new id

            cin >> customers[i][0];
            cout << " Enter Receipt No.: "; // Display a message prompting the user to enter new receipt number

            cin >> customers[i][1];
            cout << " Enter Customer's Age ";  // Display a message prompting the user to enter new age

            cin >> customers[i][2];
            cout << " Enter Total Purchases ";  // Display a message prompting the user to enter new total purchases.

            cin >> customers[i][3];

            addToFile(customers, numCustomers);// Call a function to add the updated customer details to a file


            cout << "Customer updated successfully.\n"; // Display a message that customer (with all his details ) updated successfully

        }
    }

    if (!found) {
        cout << "Customer with ID " << update_id << " not found." << endl;
    }
}

// Function to delete a customer  by searching with their ID

void deleteCustomer(int customers[][attributes], int& numCustomers) {
    int delete_id;    // Variable to store the customer ID to be deleted

    cout << "----------------------------------------------" << endl;
    // Prompt the user to enter the ID of the customer to be deleted

    cout << "Enter the ID of customer you want to delete: ";
    cin >> delete_id;

    bool found = false;    // Boolean flag to indicate whether the customer is found or not


    for (int i = 0; i < numCustomers; i++)   // Loop through each customer in the array
    {
        if (customers[i][0] == delete_id)
        {
            found = true; // Set the 'found' flag to true

            cout << "-----------------" << endl;
            // Display a message indicating the deleted customer's details

            cout << "Customer Deleted:" << endl;
            cout << " ID " << customers[i][0] << endl;
            cout << " Receipt No. " << customers[i][1] << endl;
            cout << " Age " << customers[i][2] << endl;
            cout << " Total Purchases " << customers[i][3] << endl;

            for (int j = i; j < numCustomers-1 ; j++) // Initialize the loop variable j to the index of the deleted customer i 
            {
                for (int k = 0; k < attributes; k++) //loop through each attribute (column) of the customer.
                {
                    customers[j][k] = customers[j + 1][k];// Copy the value of each attribute from the next customer to the current customer
                   

                }

            }

            numCustomers--; // Decrease the total number of customers

            addToFile(customers, numCustomers); // Call a function to add the updated customer details to a file


            cout << "Customer deleted successfully.\n";//message displayed that the customer deleted successfully

        }

    }

    if (!found) //if the customer not found then this statement executes that customer with ID (this) not found
    {
        cout << "Customer with ID " << delete_id << " not found." << endl;
    }
}
// Function to add customer details to a file

void addToFile(const int customers[][attributes], int numCustomers) 
{
    ofstream fout("customers.txt");// Open a file named "customers.txt" for writing


    for (int i = 0; i < numCustomers; i++)    // Loop through each customer(row)
    {
        for (int j = 0; j < attributes; j++) // Loop through each attribute of the customer and write to the file, separated by tabs(columns)
        {
            fout<< customers[i][j] << "\t\t";
        }
        fout << endl;// Move to the next line in the file for the next customer

    }

    fout.close();// Close the file

}
// Function to load customer details from a file

void loadFromFile(int customers[][attributes], int& numCustomers) {
    ifstream fin("customers.txt");    // Open a file named "customers.txt" for reading


    if (!fin)     // Check if the file exists

    {
        cout << "Error: File not found." << endl;  // Display an error message if the file is not found

        return;
    }

    numCustomers = 0;    // Initialize the total number of customers to 0

    // Read customer details from the file until the end of the file is reached

    while (fin >> customers[numCustomers][0] >> customers[numCustomers][1] >> customers[numCustomers][2] >> customers[numCustomers][3])
    {
        numCustomers++;  // Increment the total number of customers

    }

    fin.close();    // Close the file that is opened

}



