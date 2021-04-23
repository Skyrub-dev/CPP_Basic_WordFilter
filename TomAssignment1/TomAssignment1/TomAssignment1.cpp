//Tom Kennedy C++ Assignment 1
//(40017441 / TKennedy6@uclan.ac.uk)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
//Function for finding and replacing text in the text1 file
//declared three strings for the function including 'data' - representing the file
//, 'toSearch' - representing a string to search the file and 'replaceStr' - to replace the words
void findAndReplaceAllText1(string& data, string toSearch, string replaceStr)
{
    //declared size_t (named pos) which is used for array indexing, counting and will always be positive as it can't be
    //unnasigned
    size_t pos = data.find(toSearch); //uses the '.find' function within the data string (containing the text file)
    //using the parameters of string 'toSearch'
    while (pos != string::npos) //While position is not equal to string::npos (until the end of the string)
    {
        data.replace(pos, toSearch.size(), replaceStr); //using the '.replace' function with the three arguments
        //defined above - using 'pos', the '.size' function with our toSearch string and then using replaceStr
        pos = data.find(toSearch, pos + replaceStr.size()); //using size_t pos equal the string 'data'
        //(which contains the text contents) using the .find function with three arguments we can assign
        //later on
    }
}

int main()
{
    //Initialising the banned list
    ifstream infile;
    infile.open("banned.txt");
    string banned[8]; //putting the contents of banned in an array
    cout << "Tom Kennedy C++ assignment 1" << endl;
    cout << "(40017441) TKennedy6@uclan.ac.uk" << endl;
    cout << "\n" << endl;
    
    cout << "--------------Inserting banned words into an array--------------" << endl;
    if (!infile) //if not infile output it can't be read
    {
        cout << "File could not be read! " << endl;
    }
    for (int i = 0; i < 8; ++i) //for statement to input the words into an array
    {
        infile >> banned[i];
        
        cout << banned[i] << " has been input into the array " << endl;
    }
    cout << endl;
    infile.close();
    
    cout << "\n" << endl;
    cout << "------------------------Text 1 contents-------------------" << endl;
    //initialising the text1 file
    string textcontents;
    infile.open ("text1.txt");
    getline(infile, textcontents);
    
    if (!infile)
    {
        cout << "Error" << endl;
    }

    infile >> textcontents; //reading the contents of the file and outputting it to the user
    cout << textcontents << endl << "\n\n";
    infile.close();

    cout << "\n" << endl;
    cout << "------------------------Text 2 contents-------------------" << endl;
    
    //initialising the text2.txt file

    string text2contents;
    infile.open("text2.txt");
    getline(infile, text2contents);

    if (!infile)
    {
        cout << "ERROR opening 'text2.txt'" << endl;
    }

    infile >> text2contents;
    cout << text2contents << endl << "\n\n";
    //uses a while loop, ! = not infile.eof .eof meaning end of file
    while (!infile.eof())
    {
        cout << text2contents; //outputting the contents of 'text2.txt'
        cout << endl;
        getline(infile, text2contents);
    }

    infile.close();

    cout << "\n" << endl;
    cout << "------------------------Text 3 contents-------------------" << endl;
    
    //initialising the text3.txt file

    string text3contents;
    infile.open("text3.txt");
    getline(infile, text3contents);

    if (!infile)
    {
        cout << "ERROR opening 'text3.txt'" << endl;
    }

    infile >> text3contents;
    cout << text3contents << endl << "\n\n";

    while (!infile.eof())
    {
        cout << text3contents;
        cout << endl;
        getline(infile, text3contents);
    }

    infile.close();

    cout << "\n" << endl;
    cout << "------------------------Text 4 contents-------------------" << endl;
    
    //initialising the text4.txt file
    
    string text4contents;
    infile.open("text4.txt");
    getline(infile, text4contents);

    if (!infile)
    {
        cout << "ERROR opening 'text4.txt'" << endl;
    }

    infile >> text4contents;
    cout << text4contents << endl << "\n\n";

    while (!infile.eof())
    {
        cout << text4contents;
        cout << endl;
        getline(infile, text4contents);
    }

    //Censoring the words
    cout << "\n" << endl;
    cout << "------------------------Text 1 filtered-------------------" << endl;

    string data = "this is a bit of doggoral but it will allow me to doggedly persue my aim of cataloguing the effect of applying a word filter the filter should pick out words such as cat dog and aim Who knows what other pernicious words it will endeavour to protect the innocent from there is no punctuation in order to make it easier to identify the words and i have also written it entirely in lower case you will feel like a dog if you do not manage the aim of this assignment but i expect everyone to be top cat";
    //I stored the contents of the test file in a string called 'data'
    ifstream fin("text1.txt"); //opening the textfile

    
    //I declared a load of integers for each banned word, this will be responsible for counting how many
    //times a word repeats in the text file
    int countdog = 0;
    int countcat = 0;
    int countaim = 0;
    int countear = 0;
    int countback = 0;
    int countpunk = 0;
    int countable = 0;

    //in addition to that here are some characters to represent the banned words I initialised
    char ch[800];
    char dog[] = "dog";
    char cat[] = "cat";
    char aim[] = "aim";
    char ear[] = "ear";
    char back[] = "back";
    char punk[] = "punk";
    char able[] = "able";
    //using a while loop with the argument of initialising text1 (fin being the name of the ifstream)
    //(ifstream fin text1.txt)
    while (fin)
    {
        //inserting the contents of text1 into a char called 'ch'
        fin >> ch;
        //if (strcmp being a comparison of two variables) ch, to char (dog/cat/aim/etc) is equal to 0
        //it will incrememnt one of each integer for the word (which will be used for counting how many
        //times it was used) and it will initialise the function 'findAndReplaceAllText1' using the three
        //arguments defined. The first of those being for what it's searching through, the second being
        //the word it's looking for, and third being the word it's going to replace it with
        if (strcmp(ch, dog) == 0)
        {
            countdog++;

            findAndReplaceAllText1(data, "dog", "d*g");
            //and outputting the contents
            cout << data << endl;
        }
        if (strcmp(ch, cat) == 0)
        {
            countcat++;

            findAndReplaceAllText1(data, "cat", "c*t");
        }
        if (strcmp(ch, aim) == 0)
        {
            countaim++;

            findAndReplaceAllText1(data, "aim", "a*m");
        }
        if (strcmp(ch, ear) == 0)
        {
            countear++;

            findAndReplaceAllText1(data, "ear", "e*r");
        }
        if (strcmp(ch, back) == 0)
        {
            countback;

            findAndReplaceAllText1(data, "back", "ba*k");
        }
        if (strcmp(ch, punk) == 0)
        {
            countpunk++;

            findAndReplaceAllText1(data, "punk", "pu*k");
        }
        if (strcmp(ch, able) == 0)
        {
            countable++;

            findAndReplaceAllText1(data, "able", "ab*e");
        }
        //it will then output the filtered contents of this file into a new file called 'text1Filtered.txt'
        ofstream out_file("text1Filtered.txt");
        //if the file already exists it'll just overide its contents
        out_file << data; //the output of the file is grabbing the contents from here before dumping it in
        //the file, which in this case is using the string 'data'
    }
    
    cout << "\n" << endl;
    cout << "------------------------Repeated words and words found in text 1-------------------" << endl;
    cout << "(Note: please view text1Filtered.txt for the filtered text file)" << endl;
    cout << "\n" << endl;
    //we're then using the variable added above to display how many times that specific word is mentioned
    //note, this also counts words used inside other words such as 'doggoral'
    cout << "'dog' repeated: " << countdog << " times" << endl;

    cout << "'cat' repeated: " << countcat << " times" << endl;

    cout << "'aim' repeated: " << countaim << " times" << endl;

    cout << "'ear' repeated: " << countear << " times" << endl;

    cout << "'back' repeated: " << countback << " times" << endl;

    cout << "'punk' repeated: " << countpunk << " times" << endl;

    cout << "'able' repeated: " << countable << " times\n" << endl;

    fin.close();

    while (!infile.eof())
    {
        cout << textcontents;
        cout << endl;
        getline(infile, textcontents);
    }
   
    
    //for finding each word in its specific location    
    for (int i = 0; i < 8; ++i) //using a for loop less than 8 to represent the banned list
    {
        int position = textcontents.find(banned[i]); //uses the inbuilt function called find() against the banned list

        cout << "\"" << banned[i] << "\", ";
        //if position is not equal to the end of the string
        if (position != string::npos)
        {
            //output the word found and its location using the position integer
            cout << "Found, location " << position << endl;
        }
        
        else
        {
            cout << "Not Found" << endl;
        }
        
    }
    cout << " " << endl;

    cout << "\n" << endl;
    cout << "------------------------Words found in text 2-------------------" << endl;
    //this will output where the banned words are found and their location in text 2
    //the same principles as text 1 also apply here
    for (int i = 0; i < 8; ++i)
    {
        int second = text2contents.find(banned[i]);

        cout << "\"" << banned[i] << "\", ";
        if (second != string::npos)
        {
            cout << "found in text 2, location " << second << endl;
        }

        else
        {
            cout << "Not Found" << endl;
        }
    }

    cout << "\n" << endl;
    cout << "------------------------Words found in text 3-------------------" << endl;
    //this will output where the banned words are found and their location in text 3
    //the same principles as text 1 also apply here
    for (int i = 0; i < 8; ++i)
    {
        int second = text3contents.find(banned[i]);

        cout << "\"" << banned[i] << "\", ";
        if (second != string::npos)
        {
            cout << "found in text 3, location " << second << endl;
        }

        else
        {
            cout << "Not Found" << endl;
        }
    }

    cout << "\n" << endl;
    cout << "------------------------Words found in text 4-------------------" << endl;
    //this will output where the banned words are found and their location in text 4
    //the same principles as text 1 also apply here
    for (int i = 0; i < 8; ++i)
    {
        int second = text4contents.find(banned[i]);

        cout << "\"" << banned[i] << "\", ";
        if (second != string::npos)
        {
            cout << "found in text 4, location " << second << endl;
        }

        else
        {
            cout << "Not Found" << endl;
        }
    }
    //end of system
    system("pause");
}

//REFERENCES
/*
Chougule, A. (2020). C++ size_t | Working of size_t in C++ with Code Implementation. [online] EDUCBA. Available at: https://www.educba.com/c-plus-plus-size_t/#:~:text=In%20general%2C%20size_t%20is%20the%20unsigned%20type%20which.

Cplusplus (n.d.). strcmp - C++ Reference. [online] www.cplusplus.com. Available at: https://www.cplusplus.com/reference/cstring/strcmp/ [Accessed 23 Apr. 2021].

cplusplus (n.d.). string::npos - C++ Reference. [online] www.cplusplus.com. Available at: https://www.cplusplus.com/reference/string/string/npos/ [Accessed 23 Apr. 2021].

Mishra, N. (2015). C++ Program to Count Occurrence of a Word in a Text File. [online] The Crazy Programmer. Available at: https://www.thecrazyprogrammer.com/2015/02/c-program-count-occurrence-word-text-file.html [Accessed 23 Apr. 2021].

Stack Overflow (2009). c++ - How do I Search/Find and Replace in a standard string? [online] Stack Overflow. Available at: https://stackoverflow.com/questions/1494399/how-do-i-search-find-and-replace-in-a-standard-string [Accessed 23 Apr. 2021].

Stack Overflow (2013). Search and Edit a file in C++. [online] Stack Overflow. Available at: https://stackoverflow.com/questions/18939896/search-and-edit-a-file-in-c [Accessed 23 Apr. 2021].

Varun (2016). Find and Replace all occurrences of a sub string in C++ – thispointer.com. [online] thispointer.com. Available at: https://thispointer.com/find-and-replace-all-occurrences-of-a-sub-string-in-c/ [Accessed 23 Apr. 2021].


*/