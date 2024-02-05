#include<iostream>
#define max 10
using namespace std;

class Stack{
private:
int stack[max],top;

public:
Stack(){
top=-1;
}

void makeEmptyStack(){
if(checkEmpty()==1){
cout<<"Stack is already empty."<<endl;
}
else{
top=-1;
cout<<"Stack's contents has been deleted."<<endl;
}
}

bool checkEmpty(){
if(top<0){
return 1;
}else{
return 0;
}
}

bool checkFull(){
if(top==max-1){
return 1;
}else{
return 0;
}
}

void push(){
if(checkFull()==1){
cout<<"CAN'T INSERT THE LIST IS ALREADY FULL"<<endl;
}else{
int pushNumber;
cout<<"Enter a number to push: "<<endl;
cin>>pushNumber;
// cout<<insertionNumber<<" was the number.";
top++;
stack[top]=pushNumber;
cout<<stack[top]<<" has been pushed."<<endl;
}
}

void deleteFromStack(){
if(checkEmpty()==1){
cout<<"CANT DELETE THE STACK IS EMPTY"<<endl;
}else{
cout<<stack[top]<<" has been popped."<<endl;
top--;
}
}

void traverse(){
if(checkEmpty()==1){
cout<<"THE STACK IS EMPTY CANNOT TRAVERSE"<<endl;
}else{
cout<<"The contents of stack are: "<<endl;
for(int i=0;i<=top;i++){
cout<<"  "<<stack[i]<<"  ";
}
cout<<endl;
}
}

void peek(){
cout<<"The element on top is: "<<stack[top]<<endl;
}

void mainProcess(){
int operationNumber=0;
do{
cout<<"Enter a number representing operations from below: "<<endl;
cout<<"1 ) Push"<<endl;
cout<<"2 ) Pop"<<endl;
cout<<"3 ) Check if stack is full"<<endl;
cout<<"4 ) Check if stack is empty"<<endl;
cout<<"5 ) Make stack empty"<<endl;
cout<<"6 ) Traverse"<<endl;
cout<<"7 ) Peek top"<<endl;
cout<<"8 ) Exit program"<<endl;
cin>>operationNumber;

switch(operationNumber){
case 1:
push();
break;
case 2:
deleteFromStack();
break;
case 3:
if(checkFull()==1){
cout<<"The stack is full."<<endl;
}else{
cout<<"The stack is not full."<<endl;
}
break;
case 4:
if(checkEmpty()==1){
cout<<"The stack is empty."<<endl;
}else{
cout<<"The stack is not empty."<<endl;
}
break;
case 5:
makeEmptyStack();
break;
case 6:
traverse();
break;
case 7:
peek();
break;
case 8:
cout<<"Program is exiting...";
break;
default:
cout<<"Invalid input, insert again!!";
}
}while(operationNumber!=8);
}
};

int main(){
Stack s1;
s1.mainProcess();
}