#include <conio.h>
#include <iostream>
#include "BinaryTree.h"

using namespace std;

void clr();
void p();

int main(){
    bool quit = false;
    int input = 'p';

    BinaryTree* tree = new BinaryTree;
    while (!quit)
    {
        clr();
        cout << "--Binary Search Tree Stuff--\n\n";
        cout<<"1 = insert int\n2 = print pre order\n3 = print post order\n4 = print in order\n5 = Generate Heap Array From BST\np = Print Heap\ni = Insertion Sort Heap\ns = Selection Sort Heap\nb = Bubble Sort Heap\nh = Shell Sort Heap\nq = quit\n";
        input = getch();
        switch (input)
        {
            case 'q' :
                quit = true;
            break;
            case '1' :
                clr();
                cout << "Enter int to add to tree:";
                //int tempChar = 'p';
                cin >> input;
                tree->insert(input);
            break;
            case '2' :
                clr();
                cout << "-- Pre Order --\n\n";
                tree->preorder();
                p();
            break;
            case '3' :
                clr();
                cout << "-- Post Order --\n\n";
                tree->postorder();
                p();
            break;
            case '4' :
                clr();
                cout << "-- In Order --\n\n";
                tree->inorder();
                p();
            break;
            case '5' :
                clr();
                tree->GenerateHeap();
                p();
            break;
            case 'p' :
                clr();
                tree->PrintHeap();
                p();
            break;
            case 'i' :
                clr();
                tree->InsertionSortTheHeap();
                p();
            break;
             case 's' :
                clr();
                tree->SelectionSortTheHeap();
                p();
            break;
            case 'b' :
                clr();
                tree->BubbleSortTheHeap();
                p();
            break;
            case 'h' :
                clr();
                tree->ShellSortTheHeap();
                p();
            break;
            default :
                clr();
                cout << "Invalid Input, Try Again";
                p();
        }

    }
    return 0;
}

void clr()
    {
    cout << string( 100, '\n' );
    }

void p()
{
    char temp = 'p';
    cout << "\nPress a key to continue .. ";
    temp = getch();
}
