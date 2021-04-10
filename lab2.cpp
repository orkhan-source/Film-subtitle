#include <iostream>
#include <fstream>
#include <string.h>
#include <locale.h>
#include <vector>
#include <algorithm>



using namespace std;

int main() {

    string myText, myWord = "";
    vector <string> words;
    
    
    ifstream MyReadFile("WonderWoman.srt");
    

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) 
    {
       if(myText.empty() || !isalpha(myText[0]))
       {
           continue;
       }
      

       int sizestr;
       sizestr = myText.length();

       for(int i = 0; i < sizestr; i++)
       {
           
           if( myText[i] <= '.' || myText[i] == '?' || myText[i] == '/' || myText[i] == '<' || myText[i] == '>' || myText[i] == ',' )
           {
               words.push_back(myWord);
               myWord = "";
           }
           else
           {
               myWord += myText[i];
           }
           
       }
       words.push_back(myWord);
       myWord = "";       
        
    }

    vector<string> newWords = {};
    vector<string>::iterator it2;

    for(vector<string>::iterator it = words.begin(); it != words.end(); it++)
    {
        it2 = find(newWords.begin(), newWords.end(), *it);
        if(it2 != newWords.end())
        {
            continue;
        }
        else
        {
            newWords.push_back(*it);
        }
        
    }

    for(char i = 'a'; i <= 'z'; i++)
    {
        for(vector<string>::iterator it = newWords.begin(); it != newWords.end(); it++)
        {
            string a = *it;
            
            if(a[0] == i || a[0] == (i - 32))
            {
                cout << a << " ";
            }

        }
    }
       
    MyReadFile.close();
    
    return 0;
}



