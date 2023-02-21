/*
 * Course: CS215-012
 * Project: Lecture Demo
 * Purpose: it demonstrates how to use vector to solve problems
 *
 * Author: Seth Hammonds
 */

#include <iostream>
#include <vector>

using namespace std;

void dothis(vector<int>& v, int item);
bool dothat(vector<int>& v, int key);

int main()
{
    vector<int> myvector;
    myvector.push_back(3);
    myvector.push_back(5);
    myvector.push_back(7);
    myvector.push_back(11);
    myvector.push_back(13);

    // display elements in the vector
    cout << "myvector contains: " << endl;
    for (int i = 0; i < myvector.size(); i++)
        cout << myvector[i] << "\t";
    cout << endl;
 
    dothis(myvector, 2);
    cout << "After calling dothis(myvector, 2)..." << endl;
    for (int i = 0; i < myvector.size(); i++)
        cout << myvector[i] << "\t";
    cout << endl;

    cout << "After calling dothat(myvector, 10)..." << endl;
    bool firstDothat = dothat(myvector, 10);
    if (!firstDothat)
        cout << "Did not take action from calling dothat!" << endl;
    else
    {
        for (int i = 0; i < myvector.size(); i++)
            cout << myvector[i] << "\t";
        cout << endl;
    }

    cout << "After calling dothat(myvector, 7)..." << endl;
    bool secondDothat = dothat(myvector, 7);
    if (!secondDothat)
        cout << "Did not take action from calling dothat!" << endl;
    else
    {
        for (int i = 0; i < myvector.size(); i++)
            cout << myvector[i] << "\t";
        cout << endl;
    }

    return 0;
}

void dothis(vector<int>& v, int item)
{
    v.push_back(0);
    for (int i = v.size() - 1; i > 0; i--)
    {
        v.at(i) = v.at(i - 1);
    }
    v.at(0) = item;
}

bool dothat(vector<int>& v, int key)
{
    if (v.size() == 0)
    {
        cout << "It is an empty vector! Cannot do it!" << endl;
        return false;
    }

    int index = 0;
    bool found = false;
    int i = 0;
    while (i < v.size() && !found)
    {
        if (key == v.at(i))
        {
            found = true;
            index = i;
        }
        i++;
    }

    if (!found)
        return false;

    for (int i = index; i < v.size() - 1; i++)
    {
        v.at(i) = v.at(i + 1);
    }
    v.pop_back();
    return true;
}