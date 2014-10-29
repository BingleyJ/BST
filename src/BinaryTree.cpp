#include "BinaryTree.h"
#include <cstddef>
#include <iostream>
#include <cassert>
#include <stdlib.h>
using namespace std;

BinaryTree::BinaryTree()
{
    rootNode = NULL;
}

BinaryTree::~BinaryTree()
{
    //dtor
}

void BinaryTree::HeapSortTheHeap()

{
    if (rootNode)
    {
        cout << "Heapsort\n";
        HeapSort(TheHeap, TheHeap[0]);
    }

    else{
        cout << "Nothing to do\n" ;
        return;
    }
}

    void BinaryTree::MergeSortTheHeap()


{
    if (rootNode)
    {
        cout << "Merge Sort\n";
        Mergesort(TheHeap, 1, TheHeap[0]);
    }

    else{cout << "Nothing to do\n"; return;}
}

void BinaryTree::QuickSortTheHeap()
{
    if (rootNode)
    {
        cout << "Quicksort Sort\n";
    QuickSortTheHeap(TheHeap, 1, TheHeap[0]);
    }

    else{cout << "Nothing to do\n";return;}
}

void BinaryTree::QuickSortTheHeap(int *arr, int low, int high)
 {
  int i = low, j = high;
  int tmp;
  int pivot = arr[abs((low + high) / 2)];

  while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
        }
}
if (low < j)
    QuickSortTheHeap(arr, low, j);
if (i< high)
    QuickSortTheHeap(arr, i, high);
}

void BinaryTree::Mergesort(int *a, int lo, int hi)
{
    if(lo<hi)
    {
        int mid=((lo+hi)/2);
        Mergesort(a,lo,mid);
        Mergesort(a,mid+1,hi);
        Mergearray(a,lo,mid,hi);
    }
}

void BinaryTree::Mergearray(int *a, int lo, int mid, int hi)
{
    int i=lo;
    int j=mid+1;
    int k=0;
    int *b=new int[hi-lo+1];
    while(i<=mid && j<=hi)
    {
        if(a[i]<a[j]) //merging
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=hi)
        b[k++]=a[j++];
    for(i=hi;i>=lo;i--)
        a[i]=b[--k];
}

void BinaryTree::ShiftRight(int* arr, int low, int high) // Stole half this sp;ution from the internet
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        if (arr[swapIdx] < arr[leftChild])
        {
            swapIdx = leftChild;
        }
        if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
        {
            swapIdx = rightChild;
        }
        //Make the biggest element of root, left and right child the root
        if (swapIdx != root)
        {
            int tmp = arr[root];
            arr[root] = arr[swapIdx];
            arr[swapIdx] = tmp;
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}
void BinaryTree::Heapify(int* arr, int low, int high)
{
    int midIdx = (high - low -1)/2;
    while (midIdx >= 1)
    {
        ShiftRight(arr, midIdx, high);
        --midIdx;
    }
    return;
}


void BinaryTree::HeapSort(int* arr, int size)
{

    assert(arr);
    assert(size > 0);
    Heapify(TheHeap, 1, size);
    int high = size;
    while (high > 1)
    {
        //Swap max element with high index in the array
        int tmp = arr[high];
        arr[high] = arr[1];
        arr[1] = tmp;
        --high;
        ShiftRight(arr, 1, high);
    }
    return;
}

void BinaryTree::ShellSortTheHeap()
{
    if (!rootNode)
    {
        cout << " nothing to do\n";
        return;
    }
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
    if (!rootNode)
    {
        cout << " nothing to do\n";
        return;
    }
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
    if (!rootNode)
    {
        cout << " nothing to do\n";
        return;
    }
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
    if (!rootNode)
    {
        cout << " nothing to do\n";
        return;
    }
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
    TheHeap[*HeapIndexPointer] = inRoot->Data;
    cout << "\nPutting inRoot->Data = " << inRoot->Data << " in TheHeap[" << *HeapIndexPointer << "]\n";
    (*HeapIndexPointer)++;
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
    int HeapIndex = 1;
    HeapIndexPointer = &HeapIndex;
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
        rootNode = new Node;
        rootNode->Data = inData;
        rootNode->Left = NULL;
        rootNode->Right = NULL;
    }
}
