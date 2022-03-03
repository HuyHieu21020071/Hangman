#include <bits/stdc++.h>

using namespace std;
string WORD_LIST[] = {
 "angle", "ant", "apple", "arch", "arm", "army",
 "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
 "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
 "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
 "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
 "cow", "cup", "curtain", "cushion",
 "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
 "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
 "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
 "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
 "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
 "leaf", "leg", "library", "line", "lip", "lock",
 "map", "match", "monkey", "moon", "mouth", "muscle",
 "nail", "neck", "needle", "nerve", "net", "nose", "nut",
 "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
 "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
 "rail", "rat", "receipt", "ring", "rod", "roof", "root",
 "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
 "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
 "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
 "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
 "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
 "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
 };
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
string chooseword()
{
    int sz=200;
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
    return your_guess;
}
void renderimage(int cnt)
{
    cout<<FIGURE[cnt];
}
bool contains(string secretword,char Guess)
{
    for(char u:secretword)
    {
        if(u==Guess) return true;
    }
    return false;
}