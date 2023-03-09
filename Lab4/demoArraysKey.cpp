/*course: CS215 - 012
 *Project: Demo how to use array to organize data items
 *Purpose:  to practice how to use array to organize data items and how to pass an array to a function
 *          (Use three arrays: smallArray, midArray and largeArray as examples, their capacities are 5, 10 and 100 respectively)
 *          1. decide the maximum value from each of two arrays: midArray and largeArray, respectively (find minimum value should be quite similar)
 *          2. define a function to insert a new data item at the tail of the array (Note that the capacity may be reached!!!)
 *             call this function to append the items from smallArray to largeArray
 *          3. define a function to remove the maximum value from an array (Note the size of the array will be changed!!!)
 *          4. use your creative ideas to do something extra
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
void insertTail(int myArray[], int newitem, int& size, int capacity);

//define a function to remove the maximum value from an array (Note the size of the array will be changed!!!)
int removeMax(int myArray[], int& size);


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
    int max = midArray[0];
    for (int i = 1; i < CAPACITY_MIDDLE; i++)
    {
        if (midArray[i] > max)
            max = midArray[i];
    }
    cout << "The maximum value of midArray is: " << max << endl;

    max = largeArray[0];
    for (int i = 1; i < size; i++)
    {
        if (largeArray[i] > max)
            max = largeArray[i];
    }
    cout << "The maximum value of largeArray is: " << max << endl;

    //2. define a function to insert a new data item at the tail of the array (Note that the capacity may be reached!!!)
    //   call this function to append all the data items from smallArray to the largeArray
    for (int i = 0; i < CAPACITY_SMALL; i++)
    {
        insertTail(largeArray, smallArray[i], size, CAPACITY_LARGE);
    }

    cout << "The large array now contains " << size << " numbers: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << largeArray[i] << endl;
    }
    cout << endl;

    //3. define a function to remove the maximum value from an array (Note the size of the array will be changed!!!)
    max = removeMax(largeArray, size);
    cout << "The maximum number in large array is: " << max << endl;
    cout << "After remove the maximum number in large array, now it contains: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << largeArray[i] << endl;
    }
    cout << endl;

    //4. Use your creative ideas to do something extra
    // Can we use the available functions to put each of two arrays: smallArray and middleArray in dscending order?
    cout << "smallArray before sorting: " << endl;
    printArray(smallArray, CAPACITY_SMALL);

    size = CAPACITY_SMALL;

    for (int i = 0; i < CAPACITY_SMALL; i++)
    {
        largeArray[i] = removeMax(smallArray, size);
    }

    for (int i = 0; i < CAPACITY_SMALL; i++)
    {
        smallArray[i] = largeArray[i];
    }

    cout << "smallArray after sorting: " << endl;
    printArray(smallArray, CAPACITY_SMALL);

    // you should be able to apply smililar sorting procedure to middleArray by yourself, have fun!

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
    for (int i = 0; i < size; i++)
        cout << myArray[i] << endl;
    cout << endl;
}

/* define a function to insert a new data item at the tail of the array
 *        (Note that the capacity may be reached!!!)
 *@parameter myArray int array: representing the array to apply insertion operation
 *@parameter newitem int: representing the new data item adding into the end of current array
 *@parameter size int: representing how many data items in myArray before and after insertion operation
 *                     it is necessary to use "calling by reference"
 *@parameter capacity int: representing the capacity of myArray, its size cannot go beyond the capacity
 *return: void function
 */
void insertTail(int myArray[], int newitem, int& size, int capacity)
{
    if (size >= capacity)
    {
        cout << "Array is full. No insertion can be made!" << endl;
        return;
    }

    myArray[size] = newitem;
    size++;
}

/* define a function to remove the maximum value from an array
 *        (Note the size of the array will be changed!!!)
 *@parameter myArray int array: representing the array to apply removing operation
 *@parameter size int: representing how many data items in myArray before and after removing operation
 *                     it is necessary to use "calling by reference"
 *return int: representing the maximum value from the array and it is the item to be removed
 */
int removeMax(int myArray[], int& size)
{
    if (size <= 0)
    {
        cout << "You cannot remove from an empty array!" << endl;
        return -1;
    }

    int max = myArray[0];
    int position = 0;
    for (int i = 1; i < size; i++)
    {
        if (myArray[i] > max)
        {
            max = myArray[i];
            position = i;
        }
    }

    for (int i = position; i < size-1; i++)
    {
        myArray[i] = myArray[i + 1];
    }
    size--;

    return max;
}
