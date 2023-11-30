#include<iostream>
#include<string>

using namespace std;

class DelimiterStack {
    private:

    struct DelimiterNode {
        char character;
        int lineNumber;
        int charCount;
        struct DelimiterNode *nextNode;
    };

        // Define stack top
    DelimiterNode *stackTop;


    public:
    //Constructor
    DelimiterStack()
    {stackTop = 0;}
    //Destructor
    ~DelimiterStack() ;
    //Stack Operations
    void push(char, int, int);
    void popDelimiter(char&, int &, int &);
    bool isEmpty();
};

//class functions definition
DelimiterStack::~DelimiterStack()
{
   DelimiterNode *delimNodePtr = 0;
   DelimiterNode *delimNextNodePtr = 0;

   delimNodePtr = stackTop;

   //if there is a node
   while(delimNodePtr != 0)
   {
       //delete it
       delimNextNodePtr = delimNodePtr;
       delete delimNodePtr;
       delimNodePtr = delimNextNodePtr;
   }
}

//to perform push operation
void DelimiterStack::push(char charact, int cNum, int lNum)
{

   DelimiterNode* tmpDelimNode = 0;
   try
   {
       tmpDelimNode = new DelimiterNode;
   }
   catch (bad_alloc)
   {
       cout << "Allocation errrorr" << endl;
       return;
   }

   tmpDelimNode->character = charact;
   tmpDelimNode->charCount = cNum;
   tmpDelimNode->lineNumber = lNum;

   //if stack is empty
   if (isEmpty())
   {
       stackTop = tmpDelimNode;
       tmpDelimNode->nextNode = 0;
   }

   //if stack is there
   else
   {
       tmpDelimNode->nextNode = stackTop;
       stackTop = tmpDelimNode;
   }

}

//function to pop from the stack
void DelimiterStack::popDelimiter(char &charact, int &cNum, int &lNum)
{
   DelimiterNode* temp = 0;

   if (isEmpty())
   {
       charact = ';';
       cNum = -1;
       lNum = -1;
   }
   else
   {
       charact = stackTop->character;
       cNum = stackTop->charCount;
       lNum = stackTop->lineNumber;
       temp = stackTop->nextNode;
       delete stackTop;
       stackTop = temp;
   }
}

//To chec kwhether the stack is empty
bool DelimiterStack::isEmpty()
{
   bool emptyStat;

   if (!stackTop)
       emptyStat = true;
   else
       emptyStat = false;
   return emptyStat;
}

//The main function
int main()
{
// variable declarations and initializations
//...
   int countLine = 0;
   DelimiterStack mydelistack;
   //declare the Push Variables
    char charPush   = '~';
    int pushCNum = -1;
    int pushLNum = -1;

   //Pop Variables declaration
   char popChar;
   int popCNum;
   int popLNum;
   bool popCheck=false;
   string currentLine = "";
   do {
       charPush = '~';
       pushCNum = -1;
       pushLNum = -1;
       countLine++;
   
       //read the line
      getline(cin, currentLine);
   // parse the input line ignore non delimiters
   for(int i=0;i<currentLine.length();i++)
   {
           // if an opening delimiter, push
          if (currentLine.at(i) == '{' || currentLine.at(i) == '[' || currentLine.at(i) == '(')
           {
               charPush = currentLine.at(i);
               pushCNum = i;
               pushLNum = countLine;
               mydelistack.push(charPush, pushCNum, pushLNum);
               //charCompare.push_back(charPush);
           }

            // if a closing delimiter, pop
           if (currentLine.at(i) == '}' || currentLine.at(i) == ']' || currentLine.at(i) == ')')
           {

               mydelistack.popDelimiter(popChar, popCNum, popLNum);

               if (popCNum!=-1)
               {
                   if (currentLine.at(i) == ']' && popChar == '[')
                   {
                       break;
                   }
                   else if (currentLine.at(i) == '}' && popChar == '{')
                   {
                       break;
                   }
                   else if (currentLine.at(i) == ')' && popChar == '(')
                   {
                       break;
                   }
                   else
                   {
                       cout << "Mismatched delimiter " << currentLine.at(i) << " found at line " << countLine<< ", char ";
                       cout<< i + 1   << popChar << " found at line " << popLNum<< ", char " << popCNum << endl;
                   }
               }
               else if (!popCheck && charPush == '~' && pushCNum == -1 && pushLNum == -1)
               {
                   cout << "Right delimiter " << currentLine.at(i) << " at line " << countLine<< ", char " << i + 1 << " has no found left delimiter.\n";
               }
           }
       }


} while (currentLine!="DONE");

   bool finalCheck = mydelistack.isEmpty();
   if(finalCheck)
   {
       cout<<"The block is delimeter matched"<<endl;
   }
   while (!finalCheck)
   {
       mydelistack.popDelimiter(popChar, popCNum, popLNum);
       cout << "Left delimiter " << popChar <<" at line "<< popLNum<< ", char " << popCNum << " has no right delimiter.\n";
       finalCheck = mydelistack.isEmpty();
   }

   //pause the console
cin.get();
return 0;
}