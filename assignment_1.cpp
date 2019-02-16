/********************************************************************************************
    Blessing Alagba
    v223e376
    Description: This program takes in the 100 digits and adds them line by line to get the final answer
*/

#include<iostream>
#include <fstream>

using namespace std;

//contains the carry value
int carry = 0;
//add function to add all the numbers together
//there is an empty array called total and an array called current_number that holds the current number in the list
//this function adds all the elements in the two arrays and moves on to the next step
//after adding two numbers and it finds out that the sum is greater than 10, it carries the other digit to the other row of numbers to be added
void add( int total[],int current_number []){
    for(int i = 0; i < 55; i++){
       total[i] +=  current_number[i] + carry;

            if( total[i] >= 10)
            {
                carry = 1;
                total[i] -= 10;
            }
            else
            {
                carry = 0;
            }

    }
}
int main(){
    string num;
    //reads from the nums.txt file
    ifstream line("nums.txt");

    int arr[55] = {0};
    int total[55] = {0};

    //checks to see if the stream actually exists
    if (line.is_open())
    {
            //reads the string or an input stream
            while(getline(line, num))
            {
                //puts the numbers in the array and reverses it.
                //the loop goes to the first number in the array of the nums.txt list, it takes the number and flips it with the
                //last number in the line.
                for(int i = 0; i < 50; i++)
                {
                    arr[i] = num[ 49 - i ] -'0';
                }
                //calls the add function
                add(total, arr);

            }

           //shows the total for all the digits
           for(int i = 0; i < 55; i++)
           {
                cout << total[i];
           }
           cout << endl;

           //reverses the answer
           for(int i = 0; i < 55; i++)
            {
                arr[i] = total[54-i];
            }

            //removes the zero at the beginning of the answer
            int n = 0;
            while (arr[n] == 0)
            {
                n++;
            }

            //prints out the result after removing the zeros at the beginning of the answer
            for(int i = n; i < 55; i++)
            {
                cout << arr[i];
            }

            cout << endl;

            //makes sure that 10 digits of the answer are printed out once the zeros have been removed
            //because before the zeros were removed, the zeros were included in the 10 digits that were showing
            //once the zeros are removed there are now 7 digits and we have to print 10, so this section makes sure 10 digits are printed
            for (int i = n; i < (10+n); i++)
            {
                cout << arr[i];
            }
            cout << endl;
    }
    return 0;

}
