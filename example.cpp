/* these are our libraries 
- notice how camelCase is used */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// this is a shortcut
using namespace std;

/* Types */
void types() {
    /* our shortcut lets us type cout (our terminal output) 
    without 'std::' before it, and we end line using '<< endl'
    remember that if you want to compile in c++ you will run
    $g++ -std=c++11 [filename] then $./a.out */
    cout << "Hello World" << endl;

    /* Numbers */
    // const
    const double PI = 3.14;
    // var bool -usually starts with 'is'
    bool isTest = true;
    // ints (you can skip having to specify type everytime)
    int myAge = 19, time = 0755, date = 6282020;
    // float (accurate up to 6 decimal points)
    float num = 0.123456;
    // double (accurate up to 16 decimal points)
    double superDecimals = 0.1234567890123456;
    // there are more number types but these take more bites
    int largestInt = 2147483647;
    // above is the largest number able to be compiled in c++
    int overflow = 2147483648;
    cout << "LargestInt: " << largestInt << endl;
    cout << "Overflow: " << overflow << endl;
    // you can also see how large (in bites) something is with:
    long double big = 1.1237570234101342139094234;
    cout << "Big: " << sizeof(big) << endl;

    /* String Objects */
    // char 
    char myChar = 'D';
    // super char (used in c to create string objects)
    char superChar[5] = {'H', 'e', 'l', 'l', 'o'};
    // string
    string myName = " Ant";
    string dog = "-Dog";
    // opperations
    cout << "Size of str: " << myName.size() << endl;
    // returns boolean 0(False), 1(True)
    cout << "Is it empty?: " << myName.empty() << endl;
    myName.insert(0, superChar);
    myName.append(dog);
    string superStr = myName;
    cout << superStr << endl;
    // makes comparisons based on ASCII values
    cout << "Comparisons: " << endl;
    // returns 27 becuase it is lower in value
    cout << myName.compare(dog) << endl;
    // returns -27 becuase it is higher in value
    cout << dog.compare(myName) << endl;
    // returns 0 becuase it is equal
    cout << dog.compare(dog) << endl;
    // assign copies - assign([str], startingIndex, numOfChars)
    string firstName = firstName.assign(myName, 7, 3);
    cout << "Assigned Copy: " << firstName << endl;
    // erase and replace parts of a string - (startingIndex, numOfChars, [str])
    myName.erase(0, 7);
    cout << "erase " << myName << endl;
    myName.replace(3, 4, " Cat");
    cout << "replace " << myName << endl;
    // search strings - find([str], startingIndex)
    int catIndex = myName.find("Cat", 0);
    // will return value or -1 if cannot find
    cout << "Where is the Cat? " << catIndex << endl;

    /* Arrays */
    int favNums[5];
    // must include size (does not count zero)
    int badNums[2+1] = {9, 8, 4};
    // this will print out 8
    cout << "badNums[1]: " << badNums[1] << endl;
    // you can add dimentions arrays by just adding '[]'
    char chars[3][5] = {{'A', 'N', 'T'},
        {'H', 'O', 'N', 'E', 'Y'}};
    // this will print out N
    cout << "myChar: " << chars[1][2] << endl;

    /* Vectors */
    // ¡New Concept! -acts like arrays, with adjustable sizes
    vector <int> lotteryNumbersVect(10);
    // above is vector <[data-type]> [var-name](initial size)
    int lotteryNumbersArray[5] = {2, 4, 6, 8, 10};
    // now we add our array to the biggining of our vector
    lotteryNumbersVect.insert(lotteryNumbersVect.begin(),
        lotteryNumbersArray, lotteryNumbersArray + 3);
    /* vector.insert(where we would like to insert, from what
     we'd like to take from, [optional] then specifies how many
     from that list ) */
    // we can do more with this such as:
    // Inserting -from the begining of the vector to index 2
    lotteryNumbersVect.insert(lotteryNumbersVect.begin() + 2, 12);
    // appending to the end of our vector
    lotteryNumbersVect.push_back(14);
    // removing the last item of our vector
    lotteryNumbersVect.pop_back();
    // vectors have special dot functions compared to other data-types
    cout << "Vector Front: " << lotteryNumbersVect.front() << endl;
    cout << "Vector Index: " << lotteryNumbersVect.at(2) << endl;
    cout << "Vector Back: " << lotteryNumbersVect.back() << endl;
    cout << "Vector Empty: " << lotteryNumbersVect.empty() << endl;
    cout << "Vector Size: " << lotteryNumbersVect.size() << endl;
}

// // power function 
// #include <bits/stdc++.h>

/* Calculations */
void calc(){
    /* regular */
    int five = 5;
    int two = 2;
    cout << "5 = " << five << endl;
    cout << "5 + 2 = " << five + two << endl;
    cout << "5 - 2 = " << five - two << endl;
    cout << "5 * 2 = " << five * two << endl;
    cout << "5 / 2 = " << five / two << endl;
    cout << "5 % 2 = " << five % two << endl;
    cout << "5++ = " << five++ << endl;
    cout << "++5 = " << ++five << endl;
    cout << "5-- = " << five << endl;
    cout << "--5 = " << five << endl;

    /* casting */
    cout << "cast int " << (int) five / two << endl;
    cout << "cast char " << (char) five / two << endl;
    cout << "cast float " << (float) five / two << endl;

    /* comparitors */
    if (five > two || two < five){
        two = 3;
    } else if (! five && (two + five) >= five){
        five = 4;
    } else {
        cout << "if/else: " << five << endl;
    }
    
    /* switch - check for multiple options */
    int options = 2;
    switch(options) {
        case 0:
            cout << "How ";
        case 1:
            cout << "are,";
        case 2:
            cout << " you?" << endl;
            // without break it will continue searching
            break;
        // this is the defualt value if no cases are met
        default:
            cout << "Good!" << endl;
    }

    /* turner opperator */
    //variable = (condition) ? true : false;
    int question = (five > two) ? 1 : 0;
    cout << question << endl;

    /* for/while */
    for (int i = 1; i <= 10; i++) {
        cout << i;
    }
    cout << endl;
    // will give us (0-99) + 1
    int randNum = (rand() % 100) + 1;
    int attempts = 0;
    while (randNum != 100) {
        randNum = (rand() % 100) + 1;
        attempts++;
    }
    cout << "Attempts: " << attempts << endl;
    // ¡new concept! do while
    string numberGuessed;
    int intNumberGuessed = 0;
    do {
        cout << "Guess between 1-10!: ";
        /* gets user input from terminal(cin), then changes it
         into the value of our var */
        getline(cin, numberGuessed);
        // we then convert the str into an int
        intNumberGuessed = stoi(numberGuessed);
    } while(intNumberGuessed != 4);
    cout << "You Win!" << endl;
}

// initializer for our voids/functions
int main(){
    types();
    calc();
    return 0;
}