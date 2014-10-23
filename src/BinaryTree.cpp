#include "BinaryTree.h"
#include <cstddef>
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
    rootNode = NULL;
}

BinaryTree::~BinaryTree()
{
    //dtor
}

void BinaryTree::ShellSortTheHeap()
{
    int middle;
    int temp;
    int i;
    int j;
    for (middle = TheHeap[0] / 2; middle > 1; middle = middle / 2)
    {
        for (i = middle; i <= TheHeap[0]; i++)
        {
            for (j = i - middle; j >= 1 && TheHeap[j]>TheHeap[j + middle]; j = j - middle)
            {
                temp = TheHeap[j];
                TheHeap[j] = TheHeap[j + middle];
                TheHeap[j + middle] = temp;
            }
        }
    }
}


void BinaryTree::BubbleSortTheHeap()
{
    bool sortedHeap = false;
    int elements = TheHeap[0];
    int j = -1;
    int temp;
    while(!sortedHeap)
    {
        sortedHeap = true;
        j++;
        for (int i = 1; i < elements - j; i++)
        {
            if (TheHeap[i] > TheHeap[i + 1])
            {
                temp = TheHeap[i];
                TheHeap[i] = TheHeap[i + 1];
                TheHeap[i + 1] = temp;
                sortedHeap = false;
            }
        }
    }

}

void BinaryTree::SelectionSortTheHeap()
{
    int minpos;
    int temp;
    int elements = TheHeap[0];
    for(int i = 1 ; i <= elements; i++)
    {
        minpos = i;
        for (int j = i + 1; j <= elements; j++)
        {
            if (TheHeap[j] < TheHeap[minpos])
            {
                minpos = j;
            }
        }
        if (minpos != 1)
        {
            temp = TheHeap[i];
            TheHeap[i] = TheHeap[minpos];
            TheHeap[minpos] = temp;
        }
    }
}

void BinaryTree::InsertionSortTheHeap()
{
    int i,j;
    for(i=2; i<=TheHeap[0]; i++)
    {
        int data=TheHeap[i];
        bool inserted=false;
        for(j=i-1; j>=1 && inserted!=true;)
        {
            if(data<TheHeap[j])
            {
                TheHeap[j+1]=TheHeap[j];
                j--;
                TheHeap[j+1]=data;
            }
            else inserted=true;
        }
    }
}

void BinaryTree::PrintHeap()
{
    if (!rootNode)
        return;
    int temp = TheHeap[0];
    for (int i = 0; i <= temp; i++)
    {
        //cout << static_cast<int>(TheHeap[i]) << " | ";
        cout << (TheHeap[i]) << " | ";
    }
}

void BinaryTree::StuffHeap(Node * inRoot)
{
    //pre order
    int temp = HeapIndex;
    TheHeap[HeapIndex] = inRoot->Data;
    cout << "\nPutting inRoot->Data = " << inRoot->Data << " in TheHeap[" << HeapIndex << "]\n";
    HeapIndex++;
    if (inRoot->Left != NULL)
    {
        StuffHeap(inRoot->Left);
    }
    if (inRoot->Right != NULL)
    {
            StuffHeap(inRoot->Right);
    }

}

void BinaryTree::GenerateHeap()
{
    if (rootNode == NULL){cout<<"Nothing To Do";return;}
    cout << "Generating Heap";
    int temp = CountNodes();
    delete TheHeap;
    TheHeap = new int [temp];
    HeapIndex = 1;
    TheHeap[0] = temp; //Store Array Size in Index 0
    StuffHeap(rootNode);
}

void BinaryTree::inorder(Node * inRoot)
{
    if (inRoot->Left != NULL)
        inorder(inRoot->Left);
    cout << inRoot->Data << " ";
    if (inRoot->Right != NULL)
        inorder(inRoot->Right);
}

void BinaryTree::postorder(Node * inRoot)
{
    if (inRoot->Left != NULL)
        inorder(inRoot->Left);
    if (inRoot->Right != NULL)
        inorder(inRoot->Right);
    cout << inRoot->Data << " ";
}

void BinaryTree::preorder(Node * inRoot)
{
    cout << inRoot->Data << " ";
    if (inRoot->Left != NULL)
        inorder(inRoot->Left);
    if (inRoot->Right != NULL)
        inorder(inRoot->Right);

}



void BinaryTree::inorder()
{
    //if tree is empty exit this method
    if (rootNode == NULL)
    {
        cout << "Empty List";
        return;
    }
    inorder(rootNode);
}

void BinaryTree::preorder()
{
    //if tree is empty exit this method
    if (rootNode == NULL)
    {
        cout << "Empty List";
        return;
    }
    preorder(rootNode);
}

void BinaryTree::postorder()
{
    //if tree is empty exit this method
    if (rootNode == NULL)
    {
        cout << "Empty List";
        return;
    }
    postorder(rootNode);
}

void BinaryTree::insert(int inData, Node *leaf){
    if (inData < leaf->Data)
    {
        if (leaf->Left!=NULL)
        {
            insert(inData, leaf->Left);
        }
        else
        {
            leaf->Left = new Node;
            leaf->Left->Data = inData;
            leaf->Left->Left = NULL;
            leaf->Left->Right = NULL;
        }
    }
    else if (inData > leaf->Data)
    {
        if (leaf->Right != NULL)
        {
            insert(inData, leaf->Right);
        }
        else
        {
            leaf->Right = new Node;
            leaf->Right->Data = inData;
            leaf->Right->Right = NULL;
            leaf->Right->Left = NULL;
        }
    }
}

int BinaryTree::CountNodes()
{
    return CountNodes(rootNode);
}

int BinaryTree::CountNodes(Node* root)
{
        if(root == NULL)
            return 0;
        else
            if(root->Left == NULL && root->Right == NULL)
                return 1;
            else
                return CountNodes(root->Left) + CountNodes(root->Right) + 1;
}

//Check if heads NULL, if it is create root, if not call recursive insert.
void BinaryTree::insert(int inData)
{
    if (rootNode != NULL)
        //We have root go ahead and insert
        insert(inData, rootNode);
    else
{
    //Create Root node.
    rootNode = new Node;
    rootNode->Data = inData;
    rootNode->Left = NULL;
    rootNode->Right = NULL;
}



}
