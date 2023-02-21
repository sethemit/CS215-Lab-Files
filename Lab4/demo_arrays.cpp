/*course: CS215 - 012
 *Project: Demo how to use array to organize data items
 *Purpose: to practice how to use array to organize data items and how to pass an array to a function
 *         (Use three arrays: smallArray, midArray and largeArray as examples, their capacities are 5, 10 and 100 respectively)
 *          1. decide the maximum value from each of two arrays: midArray and largeArray, respectively (find minimum value should be quite similar)
 *          2. define a function to insert a new data item at the tail of the array (Note that the capacity may be reached!!!)
 *            call this function to append the items from smallArray to largeArray
 *          3. define a function to remove the maximum value from an array (Note the size of the array will be changed!!!)
 *          4. Use your creative ideas to do something extra
 *
 *Author: Seth Hammonds
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Collect a valid integer from the user
int validIntInput();

//print each item in an array
void printArray(int myArray[], int size);


//define a function to insert a new data item at the tail of the array (Note that the capacity may be reached!!!)

//define a function to remove the maximum value from an array (Note the size of the array will be changed!!!)


int main()
{
    // define a few constants
    const int CAPACITY_SMALL = 5;
    const int CAPACITY_MIDDLE = 10;
    const int CAPACITY_LARGE = 100;
    const int MIN = 1;
    const int MAX = 99;     // define a range of [MIN, MAX]

    // declare a few arrays to organize data items;
    int smallArray[CAPACITY_SMALL] = {32, 7, 19, 16, 2};
    int midArray[CAPACITY_MIDDLE];
    int largeArray[CAPACITY_LARGE];

    // generate a sequence of random numbers in the range of [MIN, MAX]
    // and store them into the array
    int seed = static_cast<int>(time(0));
    srand(seed);

    cout << "The small-size array contains: " << endl;
    printArray(smallArray, CAPACITY_SMALL);


    for (int i = 0; i < CAPACITY_MIDDLE; i++)
    {
        midArray[i] = rand() % (MAX - MIN + 1) + MIN;
    }
    cout << "The middle-size array contains: " << endl;
    printArray(midArray, CAPACITY_MIDDLE);

    // repeatedly collect user input of valid integers 
    // and store them into the array
    // how many numbers are in the array? It is decided by size
    int size = 7;
    for (int i = 0; i < size; i++)
    {
        largeArray[i] = validIntInput();
    }

    //1. decide the maximum value from each of two arrays: midArray and largeArray, respectively





    //2. define a function to insert a new data item at the tail of the array (Note that the capacity may be reached!!!)
    //   call this function to append all the data items from smallArray to the largeArray




    //3. define a function to remove the maximum value from an array (Note the size of the array will be changed!!!)





    //4. Use your creative ideas to do something extra





    return 0;
}


/* Collect an integer from the user as the valid input
 * @parameter list: empty
 * @return int: it returns the valid integer collected from the user input
 */
int validIntInput()
{
    bool validInput = false;
    int input;

    do
    {
        cout << "Please enter an integer: ";
        cin >> input;

        if (cin.fail())     //verify if cin fails
        {
            cout << "That is not even a number!" << endl;
            // Clear the failing state.
            cin.clear();
        }
        else   // verify input is an integer 
        {
            // valid input has been collected
            validInput = true;
        }
        cin.ignore(256, '\n');  //extract and ingore anything left (bad input) in the input stream
    } while (!validInput);
    return input;
}



/* Print each item in an array, one at each row
 *@parameter myArray int array:
 *@parameter size int: 
 *return: void function
 */
void printArray(int myArray[], int size)
{

}
