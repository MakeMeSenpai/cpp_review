// these are our libraries - notice how camelCase is use
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    myName.erase(0, 6);
    cout << "erase " << myName << endl;
    myName.replace(2, 4, " Cat");
    cout << "replace " << myName << endl;
    // search strings - find([str], startingIndex)
    int catIndex = myName.find("Cat", 0);
    // will return value or -1 if cannot find (does not count 0)
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
    
    /* switch - checks for multiple options */
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

    /* Exception Handling */
    // used to catch potential errors (like dividing by zero)
    int denominator = 0;
    // Tries potentailly damaging pieces of code inside a try block
    try {
        // if this code fails then it will not run
        if (denominator != 0) {
            cout << 2/denominator << endl;
        // sense the value is zero we will throw our value
        } else throw (denominator);
    // every throw needs a catcher, in which will run successful code
    } catch (int denominator) {
        // error codes are also typically placed here. warning users of dangerous actions
        cout << "Error, line 167: Numerator cannot be divided by a denominator of  "
         << denominator << endl;
    }

    /* for/while */
    for (int i = 1; i <= 10; i++) {
        cout << i << ", ";
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

/* Read/Write Files (File.IO) */
int readWrite(){
    /* note that anything outside of asci value is too big for
    defualt chars.. sorry not sorry umlauts - does take away 
    from the example a little bit tho. */
    string deutschland = "aae, ooo, uuu, szts";
    // creates our file (with var name writer)
    ofstream writer("almenia.txt");
    // checks if file was written
    if (! writer) {
        cout << "Error, line 200." << endl;
        return 0;
    } else {
        // writes into our file
        writer << "Hardest Letters to pronounce" << endl;
        writer << deutschland << endl;
        writer.close();
    }
    // ofstream: output file stream
    // appends our file
    ofstream appender("almenia.txt", ios::app);
    if (! writer) {
        cout << "Error, line 212." << endl;
        return 0;
    } else {
        // appends our file
        appender << "\n Almenia is Deutschland in spanish btw." << endl;
        appender.close();
    }
    /* other ofstream readers */
    // // reads your file as if it was binary
    // ofstream oneZero("almenia.txt", ios::binary);
    // // Opens file to read input
    // ofstream appender("almenia.txt", ios::in);
    // // uses default reader
    // ofstream appender("almenia.txt", ios::trunc);
    // // Opens file to write output
    // ofstream appender("almenia.txt", ios::out);
    char letter;
    // reads our file, if: input file stream
    ifstream reader("almenia.txt");
    if (! reader) {
        cout << "Error, Falty Write." << endl;
        return 0;
    } else {
        // for each char, if it's no the end of file
        for (int i = 0; ! reader.eof(); i++) {
            // collect each character
            reader.get(letter);
            // print it out
            cout << letter;
        }
        // then close file
        reader.close();
        cout << endl;
    }
}

/* Object Oriented Programming */
/* Functions */
// this is a function in c++, and must contain data-type
int math(int a, int b = 0) { // b is an optional param
    int c = a + b;
    return c;
}
// they can share a name, but must have different params
int math(int a, int b, int c) {
    // our return statement can calculate
    return a + b + c;
}
/* functions must also contain a data-type specifying what is
 expected to return. This is a recursion function
 and is usually named with get[Name] */
int getZed(int z = 0) {
    char germanAlpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
     'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
     'U', 'V', 'W', 'X', 'Y', 'Z'}; // 'Ä', 'Ö', 'Ü', 'ß'};
    if (germanAlpha[z] == 'Z') {
        return 1;
    } else if (26 == z) {
        return 0;
    } else {
        cout << "searching..." << germanAlpha[z] << endl;
        return getZed(z+1);
    }
}
/* Pointers */
//const char* to return str (act like a tupel).
const char* str() {
    // above you can see that * are used for pointers 
    if (getZed() == 1) {
        return "Found Me!";
    } else {
        return "Not Found";
    }
}

string bDay(int guess) {
    int birth= 73101;
    // & are used to find allocated data points
    int* where = &birth;
    // we used string stream to combin our variable with our str
    ostringstream day;
    day << "My birthday can be located at " << where;
    // we then redefine the object as a string to our str var date
    string date = day.str();
    // and if the user doesn't enter 10, returns it.
    if (guess != 10) {
        return date;
    }
    // by placing * before the var, we can get it's real value
    string there = to_string(*where);
    /* note that we must redefine the int into a string in order to 
    correspond with functions datatype */
    return there;
}

// prints out our values
int print() {
    // cout << << << endl;
    cout << "First math: " << math(1) << endl;
    cout << "Second math: " << math(3, 5, 7) << endl;
    cout << "getZed: \n" << str() << endl;
    cout << "pick another number 1-10: "; 
    string guessed;
    getline(cin, guessed);
    int guess = stoi(guessed);
    cout << "what is your birthday? " << bDay(guess) << endl;
}

// Runs our program!
int main(){
    types();
    calc();
    readWrite();
    print();
    return 0;
}