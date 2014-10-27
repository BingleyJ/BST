/*
 John Bingley BST Implementation with sorts

 I'll be honest I needed help from
 google for a lot of this. I have a better
 understanding of how recursion is just a
 copy of the method pushed on the stack.

 Still some bug in the stuffheap method. Sometimes the last member of the array is memory junk.
 The sorts may be a bit buggy still. I tried to work out the sort on wiki
 then refer to google for help fixing it.
*/
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
        cout<<"1 = insert int to the BST\n2 = print pre order\n3 = print post order\n4 = print in order\n";
        cout <<"5 = Generate Heap Array From BST\np = Print Heap\ni = Insertion Sort Heap\ns = Selection";
        cout<<" Sort Heap\nb = Bubble Sort Heap\nh = Shell Sort Heap\ne = Heap Sort the Heap\nm =";
        cout<<" Merge Sort the Heap\nu = QuickSort the Heap\nq = quit\n";
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
            case 'e' :
                clr();
                tree->HeapSortTheHeap();
                p();
            break;
            case 'm' :
                clr();
                tree->MergeSortTheHeap();
                p();
            break;
             case 'u' :
                clr();
                tree->QuickSortTheHeap();
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
