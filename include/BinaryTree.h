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
    void MergeSortTheHeap();
    void QuickSortTheHeap();
    void BucketSortTheHeap();




private:
    void insert(int data, Node *leaf);
    void inorder(Node * inRoot);
    void preorder(Node * inRoot);
    void postorder(Node * inRoot);
    int CountNodes(Node * inRoot);

    Node *rootNode;
    int * TheHeap;
    int HeapIndex;
};



#endif // BINARYTREE_H
