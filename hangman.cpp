#include <bits/stdc++.h>
#include <fstream>
using namespace std;
vector<string> WORD_LIST;
 const string FIGURE[] = {
 " ------------- \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |     |   \n"
 " |        \n"
 " |        \n"
 " |        \n"
 " |        \n"
 " ----- \n",
 " ------------- \n"
 " |     |   \n"
 " |     O   \n"
 " |        \n"
 " |        \n"
 " | \n"
 " ----- \n",
 " ------------- \n"
 " |     |  \n"
 " |     O  \n"
 " |     |  \n"
 " |     \n"
 " |     \n"
 " ----- \n",
 " ------------- \n"
 " |     | \n"
 " |     O \n"
 " |    /| \n"
 " |     \n"
 " |     \n"
 " ----- \n",
 " ------------- \n"
 " |     | \n"
 " |     O \n"
 " |    /|\\ \n"
 " |     \n"
 " |     \n"
 " ----- \n",
 " ------------- \n"
 " |     | \n"
 " |     O \n"
 " |    /|\\ \n"
 " |    / \n"
 " |     \n"
 " ----- \n",
 " ------------- \n"
 " |     | \n"
 " |     O \n"
 " |    /|\\ \n"
 " |    / \\ \n"
 " |     \n"
 " ----- \n",
};

void getword_from_file();
string chooseword();
string update(string Guessword,string secretWord,char Guess);
int game_condition(string Guessword,string secretword,int cnt);
const int MaxGuess=7;
int badGuesscount=0;
void rendergame(string Guessword,int badGuesscount);
char ReadGuess();
void renderimage(int cnt);
bool contains(string secretword,char Guess);
main()
{
    srand(time(NULL));
    getword_from_file();
    string secretword = chooseword();
    string Guessword = string(secretword.length(),'-');
    do {
        rendergame(Guessword,badGuesscount);
        char Guess = ReadGuess();
        if(contains(secretword,Guess))
        {
            Guessword = update(Guessword,secretword,Guess);
        }
        else badGuesscount++;
        renderimage(badGuesscount);
    } while(game_condition(Guessword,secretword,badGuesscount)==-1);
    if(game_condition(Guessword,secretword,badGuesscount)==1)
    {
        cout<<"Congratulation! You win!";
    }
    else cout<<"You lost. The correct word is " << secretword;
}
void getword_from_file()
{
    ifstream file("text.txt");
    if(file.is_open())
    {
        string word;
        while(file >> word)
        {
            WORD_LIST.push_back(word);
        }
        file.close();
        return ;
    }
    else {
            cout<<"Unable to openfile";
            exit(0);
    }

}
string chooseword()
{
    int sz=WORD_LIST.size();
    string word=WORD_LIST[rand()%sz];
    return word;
}
string update(string Guessword,string secretWord,char Guess)
{
    for(int i=0;i<secretWord.size();i++)
    {
        if(secretWord[i]==Guess)
        {
            Guessword[i] = Guess;
        }
    }
    return Guessword;
}
int game_condition(string Guessword,string secretword,int cnt)
{
    if(Guessword==secretword) return 1;
    if(cnt>=MaxGuess) return 0;
    return -1;
}
void rendergame(string Guessword,int badGuesscount)
{
    cout << Guessword << '\n';
    cout << "Number of your wrong guesses: " << badGuesscount << '\n';
}
char ReadGuess()
{
    cout << "Enter your guess: ";
    char your_guess;
    cin>>your_guess;
    your_guess=tolower(your_guess);
    return your_guess;
}
void renderimage(int cnt)
{
    cout<<FIGURE[cnt];
}
bool contains(string secretword,char Guess)
{
    for(int i=0;i<secretword.size();i++)
    {
        char u=secretword[i];
        if(u==Guess) return true;
    }
    return false;
}
