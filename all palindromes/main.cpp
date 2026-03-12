
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include<cstring>
#include<strstream>
#include<algorithm>
using namespace std;
int main()
{
    fstream words("My words.txt" , ios::out |ios::in) ;
    fstream allPalindromes ("All palindromes.txt" , ios::in |ios::out) ;
    string oneWord="" ;
    string allPossible = "" ;
    vector<string> palan ;
    while(!words.eof())
    {
        words>>oneWord;
            for(int i=0 ; i<oneWord.size()  ; i++)
            {
                if(oneWord[i]==',' || oneWord[i]==' ' || oneWord[i]=='.' )
                    continue ;
                else{
                    allPossible = allPossible + oneWord[i] ;
                    palan.push_back(allPossible) ;
                    for( int j =i+1; j<oneWord.length() ; j++ )
                    {
                        if(oneWord[j]==',' || oneWord[j]==' ' || oneWord[j]=='.')
                            continue ;
                        else{
                        allPossible = allPossible + oneWord[j] ;
                        palan.push_back(allPossible) ;
                        }
                    }
                }
                allPossible = "";
            }
    }
    words.close() ;
    for(int i = 0 ; i<palan.size() ; i++)
    {
        bool found=false;
        for(int j=0;j<i;j++)
        {
            if(palan[i]==palan[j])
                found=true;
        }
        if(!found)
        {
            string reverseOfString = palan[i] ;
            reverse(reverseOfString.begin(),reverseOfString.end()) ;

            if((palan[i]==reverseOfString))
            {
                allPalindromes<<reverseOfString ;
                cout<<reverseOfString<<endl;
            }
        }
    }
    return 0;





}

