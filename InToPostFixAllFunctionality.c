#include <ctype.h>
#include <stdio.h>


#define MAX 100

//Define a structure for a stack node

struct Node{

    char data;
    struct  Node* next;
}*top = NULL;

 //function to create a new stack node

struct Node * createNode(char data){
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = data;
     newNode->next = NULL;
     return newNode;

 }
 //Function to check if the stack is empty

 int isEmpty(){
     return top == NULL;
 }
 //Function to push an element onto the stack

 void push(char data){
    struct Node* newNode =  createNode(data);
    newNode->next = top;
    top = newNode;
 }

//Function to pop an element from the stack
char pop(){
   if (isEmpty()){
    printf("Stack Underflow\n");
    return '\0';
   } else {
      struct Node* temp = top;
      char popped = temp->data;
      top = top->next;
      free(temp);
      return popped;
   }
}

//Function to get the top element of the stack without popping it.
char peek(){
    if(!isEmpty()){
        return top->data;
    }
    return '\0';
}

//Precedence of operators inside the stack(in-stack precedence)
int instackPrecedence(char ch){
   switch(ch){
      case '+':
      case '-':
        return 2;
      case '*':
      case '/':
        return 4;
      case '^':
        return 5;
      case '(':
        return 0;
      default:
        return -1;

   }
}

//Precedence of operators outside the stack (out-stack precedence)
int  outstackPrecedence(char ch){
   switch(ch){
      case '+':
      case '-':
        return 1;
      case '*':
      case '/':
        return 3;
      case '^':
        return 6; //Right-associative operator has higher precedence when outside
      case '(':
        return 7;
      case ')':
        return 0;
      default:
        return -1;
   }
}

int isalnum(int ch) {
    // Check if the character is a digit (0-9) or a letter (A-Z, a-z)
    if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return 1;  // True, it's alphanumeric
    }
    return 0;  // False, it's not alphanumeric
}

//Function to convert infix expression to postfix using linked list stack
void infixToPostfix(char* infix, char* postfix){
    int i, j=0;

    for(i=0; infix[i] != '\0'; i++){
            char symbol = infix[i];

    //If the symbol is an operand, add it directly to the postfix output.
    if(isalnum(symbol)){
        postfix[j++] = symbol;
    }
    //If the symbol is '(', push it to the stack
    else if(symbol == '('){
         push(symbol);
    }
    //If the symbol is ')', pop until '(' is encountered
    else if(symbol == ')'){
        while(peek() != '('){
            postfix[j++] = pop();
        }
        pop(); // Remove '(' from stack
    }
    //If the symbol is an operator
    else {
        while(!isEmpty() && instackPrecedence(peek()) >= outstackPrecedence(symbol)){
                postfix[j++] = pop();
        }
        push(symbol);
    }
}

    //Pop the remaining operators from the stack
    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression

}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;

}
