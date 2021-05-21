#include <iostream>
#include <stdlib.h>
using namespace std;

//This class is declared as a Binary Search Tree. But, in this file i will call it a Tree only.
class Tree
{
    struct node
    {
        int data;
        node* leftLink = NULL;
        node* rightLink = NULL;
    };

    public:

    node* root = (node*)malloc(sizeof(node));

    //Used to create a new node and return it's address.
    node* CreateNewNode(int data)
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode -> data = data;
        newNode -> leftLink = newNode -> rightLink = NULL;

        return newNode;
    }

    /*
        This Insert function is used to insert a new node into the tree by obtaining the root address of the tree.

        Take two arguments, the root address of the tree and the data that want to be inserted.

        Use the recursive method because this function assumes that every node can act as a root. So we can decide whether the new data will be inserted on the left or right side of the tree.
    */
    node* Insert(node* root, int data)
    {    
        if(root == NULL)
        {
            return CreateNewNode(data);

        } else if(root -> data >= data)
        {
            root -> leftLink = Insert(root -> leftLink, data);

        } else
        {
            root -> rightLink = Insert(root -> rightLink, data);
        }

        return root;
    }

    /* 
        Function to search data in a tree by getting the address of the tree and data want to be searched.

        This function take two element as the argument which is the address of the tree and the data want to be searched.
    */
    node* SearchData(node* root, int data)
    {
        while(root != NULL)
        {
            if(root -> data == data)
            {
                cout << "Data " << data << " ditemukan pada alamat " << root << "\n\n";
                return root;

            } else if(root -> data > data)
            {
                cout << "Data " << root -> data << " pergi ke kiri\n";
                root = root -> leftLink;

            } else
            {
                cout << "Data " << root -> data << " pergi ke kanan\n";
                root = root -> rightLink;
            }
        }
        
        return root;
    }
};

int main()
{
    Tree theTree;
    theTree.root = NULL;

    int dataContainer;
    int userAnswerI;
    int number[15] = {50, 25, 75, 10, 35, 60, 85, 5, 15, 30, 40, 55, 65, 80, 90};

    for(int i = 0; i < 15; i++)
    {
        theTree.root = theTree.Insert(theTree.root, number[i]);
    }
    
    do
    {
        cout << "Menu\n1. Tambah data ke tree\n2. Cari data\n3. Hapus data dari tree - deletion by Merging\n4. Hapus data dari tree - deletion by Copying\n5. Pre-order traversal\n6. Post-order traversal\n7. In-oder traversal\n8. Level-order traversal\n0. Keluar\n\nPilihan Anda : ";
        cin >> userAnswerI;
   
        if(userAnswerI == 2)
        {
            int dataContainer;

            cout << "Data yang dicari: ";
            cin >> dataContainer;

            theTree.SearchData(theTree.root, dataContainer);
        }

    } while(userAnswerI > 0 && userAnswerI <= 8);   
}