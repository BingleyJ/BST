#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
{

public:
    BinaryTree();
    virtual ~BinaryTree();

    struct Node
    {
        int Data;
        Node* Left;
        Node* Right;
    };

    void insert(int data);
    void inorder();
    void preorder();
    void postorder();
    int CountNodes();
    void GenerateHeap();
    void StuffHeap(Node * inRoot);
    void PrintHeap();
    void InsertionSortTheHeap();
    void SelectionSortTheHeap();
    void BubbleSortTheHeap();
    void ShellSortTheHeap();
    void HeapSortTheHeap();
    void HeapSort(int* arr, int size);
    void Heapify(int* arr, int low, int high);
    void ShiftRight(int* arr, int low, int high);
    void MergeSortTheHeap();
    void Mergesort(int *a, int lo, int hi);
    void Mergearray(int *a, int lo, int mid, int hi);
    void QuickSortTheHeap();
    void BucketSortTheHeap();




private:
    void QuickSortTheHeap(int *arr, int lo, int high);
    void insert(int data, Node *leaf);
    void inorder(Node * inRoot);
    void preorder(Node * inRoot);
    void postorder(Node * inRoot);
    int CountNodes(Node * inRoot);

    Node *rootNode;
    int * TheHeap;
    int * HeapIndexPointer;
};



#endif // BINARYTREE_H
