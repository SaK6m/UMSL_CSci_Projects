#include <iostream>
#include <string>

using namespace std;

//structure members I did this outside the class body
struct Node {
    char delimiterCharacter;
    int lineNumber;
    int charPos;
    Node *prev = NULL;
};

class Stack {
    private:
        Node* topOfStack = NULL; //node pointing to the top of the stack
    
    public:
        Stack();
        ~Stack();
        int pop(char&, int&, int&);
        void push(char, int, int);
        bool isEmpty();
};

Stack::Stack(){}
Stack::~Stack(){}

void Stack::push(char delimiterCharacter, int lineNumber, int charPos) {
    // Node* temp = (Node*)malloc(sizeof(Node));
    Node* temp = new Node;

    temp->delimiterCharacter = delimiterCharacter;
    temp->lineNumber = lineNumber;
    temp->charPos = charPos;

    //checking and filing
    if (!isEmpty()) {
        temp->prev = topOfStack;
    }

    topOfStack = temp; //adding on top of the stack
    temp = NULL;
}

int Stack::pop(char& delimiterCharacter, int& lineCount, int& charPos){

    //checking if there was items in the stack
    if (isEmpty()) {

        //for missing left delimiter
        cout << "Right delimiter " << delimiterCharacter << " had no left delimiter found at line "
            << lineCount << ", char " << charPos <<endl;
        return -1; // means stack is empty.
    }

    //copying the value from the stack to the referenced variable
    delimiterCharacter = topOfStack->delimiterCharacter;
    lineCount = topOfStack->lineNumber;
    charPos = topOfStack->charPos;

    Node *temp;
    temp = topOfStack;
    delete topOfStack;

    if (temp->prev == NULL) {
        topOfStack = NULL;
    } else {
        topOfStack = temp->prev;
    }

    return 1; // means node is popped
}

bool Stack::isEmpty(){
    return (topOfStack == NULL) ? true : false; // (condition) ? val if true : val if false; // ternary operator
}

int main() 
{   
    string input;
    int lineCount = 0;

    char popped_char;
    int popped_lineCount, popped_charPos;

    Stack* block = new Stack; //dynamically allocating 

    do { 
        fflush(stdin);
        getline(cin,input);
        lineCount++;
        
        for (int i = 0; i < input.length(); i++) {
            //checking for any left delimiters
            if (input[i] == '{' || input[i] == '(' || input[i] == '[') {
                block->push(input[i], lineCount, (i + 1));
            } else if (input[i] == '}' || input[i] == ')' || input[i] == ']') {
                popped_char = input[i];
                popped_lineCount = lineCount;
                popped_charPos = (i + 1);

                if (block->pop(popped_char, popped_lineCount, popped_charPos) == -1)
                    continue;
                //checking if the delimiters are matched
                if ((popped_char == '{' && input[i] == '}') || 
                    (popped_char == '(' && input[i] == ')') ||
                    (popped_char == '[' && input[i] == ']')) {
                    continue; // if matched nothing more to be done
                } else {
                    cout << "Mismatched delimiter " << input[i] << " found at line " << lineCount
                    << ", char " << (i + 1) << " does not match " << popped_char 
                    << " found at line " << popped_lineCount
                    << ", char " << popped_charPos  << endl;
                }
            }
        }
    } while (input != "DONE" && input != "done");
     
    //checking if we missed the right delimiter after finishing the program

    while (!block->isEmpty())
    {
        block->pop(popped_char, popped_lineCount, popped_charPos);
        cout << "Left delimiter " << popped_char << " at line " << popped_lineCount
            << ", char " << popped_charPos << " had no right delimiter." << endl;
    }
  
    //deleting the block
    delete block;
    return 0;
}
