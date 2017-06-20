//
//  main.cpp
//  MidtermProject
//
//  Created by Danilo Mendes on 2/20/16.
//  dbarrosmende2015@my.fit.edu
//  Copyright © 2016 Danilo Mendes. All rights reserved.
//

/*
 Ask for the user to enter a string with the expression
 Go element by element of the string evaluating it
 if it is any of the operands (+,-,*,/)
    Get the top 2 elements of the stack, evaluate the
    operation accondingly, and push the result back to the stack.
    Always checking for division by zero, and if the stack has still available numbers.
 if the element is any other than the operands push it to the stack
 Print the result for the user
 Ask if the user wants to use the program again
 if so run the program again
 else end the program
 
 
 */

#include <iostream>
#include <string>
#include <sstream>
#include <float.h>

using namespace std;

typedef struct {
    
    double *elem;
    unsigned int top;
    unsigned int size;

}Stack;

void push(Stack *s, double value);
void pop(Stack *s);
double top(Stack *s);
void reset(Stack *s);
void initializeStack(Stack *s);
void increaseStack(Stack *s);
bool isEmpty(Stack *s);
void print(Stack *s);
int size(Stack *s);


int main(int argc, const char * argv[]) {
    
    Stack stack = *new Stack();
    unsigned short int op = 0;
    string str;
    int error = 0;
    
    do{
        
        
        
        reset(&stack);
        
        cout << "Enter the expression to be evaluated: ";
        getline(cin, str);
        
        istringstream sstr(str);
        string evl;
        
        while (sstr >> evl){
            
            if (evl == "+") {
                double x = top(&stack);
                pop(&stack);
                double y = top(&stack);
                
                if (y==-DBL_MAX) {
                    cout << "Error: Expression evaluation error. Abort." << endl;
                    error = 1;
                    break;
                }
                
                pop(&stack);
                
                push(&stack, x+y);
                
            }
            else if (evl == "-") {
                double x = top(&stack);
                pop(&stack);
                double y = top(&stack);
                
                if (y==-DBL_MAX) {
                    cout << "Error: Expression evaluation error. Abort." << endl;
                    error = 1;
                    break;
                }
                
                pop(&stack);
                
                push(&stack, y-x);
                
            }
            else if (evl == "*") {
                double x = top(&stack);
                pop(&stack);
                double y = top(&stack);
                
                if (y==-DBL_MAX) {
                    cout << "Error: Expression evaluation error. Abort." << endl;
                    error = 1;
                    break;
                }
                
                pop(&stack);
                
                push(&stack, x*y);
                
            }
            else if (evl == "/") {
                double x = top(&stack);
                pop(&stack);
                double y = top(&stack);
                
                if (y==-DBL_MAX) {
                    cout << "Error: Expression evaluation error. Abort." << endl;
                    error = 1;
                    break;
                }
                
                pop(&stack);
                
                if (x==0) {
                    cout << "Error: Division by 0. Abort." << endl;
                    error = 1;
                    break;
                }
                
                push(&stack, y/x);
                
            }
            else{
                try {
                    
                    double x = stod(evl);
                    push(&stack, x);
                    
                } catch (...) {
                    cout << "Error: Invalid character entered. Abort." << endl;
                    error=1;
                    break;
                }
                
            }
            
        }
        
        if (error==1) {
            error=0;
            continue;
        }
        
        cout << "Result: ";
        
        print(&stack);
        
        cout << endl << "Do you want to continue using the RPN? ";
        
        do{
            cout << "(1 YES / 0 NO): ";
            cin >> op;
            
            //http://stackoverflow.com/questions/10553597/cin-and-getline-skipping-input
            cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            
        }while(op!=0 && op!=1);
    
    }while(op==1);
    
    return 0;
}

void push(Stack *s, double value){

    if (s->top == s->size) {
        increaseStack(s);
    }
    
    s->elem[size(s)] = value;
    s->top++;
    
}

void pop(Stack *s){
    
    if (isEmpty(s)) {
        cout << "Error: Could not pop, stack is empty." << endl;
        return;
    }
    
    s->elem[s->top - 1] = DBL_MAX;
    s->top--;
    
}

double top(Stack *s){
    
    if (isEmpty(s)) {
        cout << "Error: Could not top, stack is empty." << endl;
        return -DBL_MAX;
    }
    
    return s->elem[s->top-1];
    
}

void reset(Stack *s){
    
    if(s->elem != NULL){
        delete [] s->elem;
    }
    
    s->size = 10;
    s->elem = new double[s->size];
    s->top = 0;

    initializeStack(s);
    
}

void initializeStack(Stack *s){
    
    for (int i=0; i < s->size; i++) {
        s->elem[i] = DBL_MAX;
    }
    
}

void increaseStack(Stack *s){
    
    Stack aux = *new Stack();
    
    aux.elem = new double[s->top];
    aux.size = s->top;
    aux.top = 0;
    
    for (int i=0; i<s->top; i++) {
        
        push(&aux, s->elem[i]);
        
    }
    
    delete [] s->elem;
    s->top = 0;
    s->size *= 2;
    s->elem = new double [s->size];
    initializeStack(s);
    
    for (int i=0; i < aux.top; i++) {
        push(s, aux.elem[i]);
    }
    
}

bool isEmpty(Stack *s){
    
    return !s->top;
}

void print(Stack *s){
    
    for (int i=0; i < size(s); i++) {
        
        if (s->elem[i] == DBL_MAX || isEmpty(s)) {
            return;
        }
        
        cout << s->elem[i] << "\t";
    }
    
    cout << endl;
    
}

int size(Stack *s){
    return s->top;
}
