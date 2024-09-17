
#include <iostream>
#include<limits.h>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left , *right;
    Node() { left = right = NULL; } 
    Node(int data) { this->data = data ; left = right = NULL; } 
};
class BST {
    public:
    Node *root;
    BST() { root = NULL; }
    void insertNode(int data)
    {
        Node *newnode = new Node(data);
        
        if (root == NULL)
            root = newnode ; 
        else
        {
            Node *prev = NULL, *curr = root;
            while(curr != NULL)
            {
                prev = curr;
                if (curr->data > data)
                    curr = curr->left;
                else
                    curr = curr -> right;
            }
            if(data < prev->data)
                prev->left = newnode;
            else
                prev->right = newnode;
        }
    }
    void display(Node *root)// inorder 
    {
        if (root!= NULL)
        {
            display(root->left);
            cout<<root->data<<" ";
            display(root->right);
        }
    }
    Node* search(Node *root, int data)// inorder 
    {
        if (root!= NULL)
        {
            if (root->data == data )
                return root;
            else if (root->data > data)
                return (search(root->left, data ));
            else
                return (search(root->right, data ));
        }
        return root;
    }
    Node *successor(Node *root)
    {
        root = root->right;
        while(root->left != NULL && root!= NULL )
            root = root->left;
        return root;
    }
    Node* deleteNode(Node *root, int data)
    {
        if(root== NULL)
            return root;
        else if (root->data > data)
            root->left = deleteNode(root->left, data);
        else if (root->data < data)
            root->right = deleteNode(root->right , data);
        else{
            if(root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp; 
            }
            else if(root->left == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp; 
            }
            Node *temp = successor(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    Node * deleteTree(Node *root)
    {
        if(root != NULL)
        {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
        return root;
    }
    // int maxNode(Node * root)
    // {
    //     int val, left, right, max = INT_MIN;
    //     if(root != NULL)
    //     {
    //         val = root->data;
    //         left = maxNode(root->left);
    //         right = maxNode(root->right);
    //         if(left<right)
    //             max = right ;
    //         else
    //             max = left;
    //         if (max < val)
    //             max= val;
    //     }
    //     return max; 
    // }
    int maxNode(Node *root)
    {
        int max = INT_MIN;
        queue<Node*> q1 ;
        Node *temp;
        q1.push(root);
        while (!q1.empty())
        {
            temp = q1.front();
            if(max < temp->data)
                max = temp->data;
            if(temp->left != NULL)
                q1.push(temp->left);
            if(temp->right != NULL)
                q1.push(temp->right);
            q1.pop();
        }
        return max;
    }
    int minNode(Node * root)
    {
        int val, left, right, min = INT_MAX;
        if(root != NULL)
        {
            val = root->data;
            left = minNode(root->left);
            right = minNode(root->right);
            if(left > right)
                min  = right ;
            else
                min  = left;
            if (min  >  val)
                min = val;
        }
        return min; 
    }
    int countNodes(Node *root)
    {
        if (root == NULL)
            return 0;
        else
            return (1 + countNodes(root->left) + countNodes(root->right));
    }
    int countLeafNodes(Node *root)
    {
     
        if (root == NULL)
            return 0 ;
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
            return (0 + countLeafNodes(root->left) + countLeafNodes(root->right));
    }
    int countNonLeafNodes(Node *root)
    {
     
        if (root == NULL)
            return 0 ;
        if (root->left == NULL && root->right == NULL)
            return 0;
        else
            return (1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
    }
    // void mirrorImage(Node *root)
    // {
    //     if (root != NULL)   
    //     {
    //         mirrorImage(root->left);
    //         mirrorImage(root->right);
    //         swap(root->left, root->right);
    //     }
    // }
    void mirrorImage(Node *root)
    {
        queue<Node *> q1;
        if (root == NULL)
            return;
        else
        {
            q1.push(root);
            while(! q1.empty())
            {
                Node *temp = q1.front();
                swap(temp->left, temp->right);
                if (temp->left != NULL)
                    q1.push(temp->left);
                if(temp->right != NULL)
                    q1.push(temp->right);
                q1.pop();
            }
        }
    }
    // int height(Node *root)
    // {
    //     if(root == NULL)
    //         return 0;
    //     if(root != NULL)
    //     {
    //         int left = height(root->left);
    //         int right = height(root->right);
    //         if (left > right)
    //             return left + 1;
    //         else
    //             return right + 1 ;
    //     }
    // }
    int height(Node *root)
    {
        int count =0;
        queue<Node *> q1;
        if (root == NULL)
            return 0;
        else
        {
            q1.push(root);
            q1.push(NULL);
            while(! q1.empty())
            {
                Node *temp = q1.front();
                if (temp == NULL ){
                    count++;
                    if(q1.size() > 1)
                    q1.push(NULL);
                }
                else{
                    if (temp->left != NULL)
                        q1.push(temp->left);
                    if(temp->right != NULL)
                        q1.push(temp->right);
                }
                q1.pop();
            }
        }
        return count;
    }
    // void secondLargest(Node *root, int &smax)
    // {
    //     if(root == NULL || )
    // }
};
int main()
{
    int option , data;
    BST obj;
    while(1)
    {
        cout<<"\n1. Insert \n";
        cout<<"2. Delete \n";
        cout<<"3. Search \n";
        cout<<"4. Display \n";
        cout<<"5. Delete Tree\n";
        cout<<"6. Max data \n";
        cout<<"7. Min Data \n";
        cout<<"8. Count total Nodes \n";
        cout<<"9. Count Leaf Nodes \n";
        cout<<"10. Count non-Leaf Nodes\n";
        cout<<"11. Find Mirror Image \n";
        cout<<"12. Height \n";
        cout<<"13. Second Largest \n";
        cout<<"0. Exit \n";
        cout<<"Enter option ::  ";
        cin>>option;
        if(option == 1 )
        {
            cout<<"Enter data ";
            cin>>data;
            obj.insertNode(data);
        }
        else if(option == 2)
        {
            cout<<"Enter data :: ";
            cin>>data;
            obj.root= obj.deleteNode(obj.root , data);
        }
        else if (option == 3)
        {
            cout<<"Enter data ::  ";
            cin>>data;
            Node *temp = obj.search(obj.root , data);
            if(temp == NULL)
                cout<<"\nNot Found \n";
            else
                cout<<"\nFound \n";
        }
        else if(option  == 4)
            obj.display(obj.root);
        else if (option == 5)
            obj.root= obj.deleteTree(obj.root);
        else if (option == 6)
        {   int max = obj.maxNode(obj.root);
            cout<<"MAx = "<< max <<endl;
        }
        else if (option == 7)
        {   int min = obj.minNode(obj.root);
            cout<<"Min = "<<min<<endl;
        }
        else if (option == 8)
        {
            int count = obj.countNodes(obj.root);
            cout<<"Count = "<<count<<endl; 
        }
        else if (option == 9)
        {
            int count = obj.countLeafNodes(obj.root);
            cout<<"Count = "<<count<<endl;
        }
        else if (option==10)
        {
            int count = obj.countNonLeafNodes(obj.root);
            cout<<"Count = "<<count<<endl;
        }
        else if (option == 11)
        {
            cout<<"After Mirror :: ";
            obj.mirrorImage(obj.root);
            obj.display(obj.root);
        }
        else if (option == 12)
        {
            cout<<"\nHeight :: "<<obj.height(obj.root)<<endl;
        }
        else if (option == 13)
        {
            int smax=0 ;
            obj.secondLargest(obj.root, smax)
            cout<<"\nSecond Largest = "<<smax;
        }
        else if (option == 0)
            break;
    }
    
    
    
    return 0;
}
