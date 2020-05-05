#include "arithmeticExpression.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

using namespace std;

arithmeticExpression::arithmeticExpression(const string &data) {
    infixExpression = data;
    root = nullptr;
}

void arithmeticExpression::buildTree() {
    cout << "**NOT IMPLEMENTED" << endl;
}

void arithmeticExpression::infix() {
    cout << "**NOT IMPLEMENTED" << endl;
}

void arithmeticExpression::prefix() {
    prefix(root);
}

void arithmeticExpression::postfix() {
    postfix(root);
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::infix(TreeNode *node) {
    cout << "**NOT IMPLEMENTED" << endl;
}

void arithmeticExpression::prefix(TreeNode *node) {
    cout << node->key;
    if (node->left != nullptr) {
        postfix(node->left);
    } 
    if (node->right != nullptr) {
        postfix(node->right);
    }
}

void arithmeticExpression::postfix(TreeNode *node) {
    if (node->left != nullptr) {
        postfix(node->left);
    } 
    if (node->right != nullptr) {
        postfix(node->right);
    } 
    cout << node->key;
}

void arithmeticExpression::visualizeTree(ofstream &outputFilename, TreeNode *node) {
    cout << "**NOT IMPLEMENTED" << endl;
}
