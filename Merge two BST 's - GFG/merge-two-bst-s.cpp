//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};
*/
#include<bits/stdc++.h> 

void insert(stack<Node*> &s, vector<int> &ans, Node* temp){
    s.pop();
    ans.push_back(temp->data);
    temp = temp->right;
    while(temp){
       s.push(temp);
       temp = temp->left;
    }
}

class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //dataues of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       
       vector<int> ans;
       stack<Node*> s1,s2;
       while(root1){
           s1.push(root1);
           root1 = root1->left;
       }
       while(root2){
           s2.push(root2);
           root2 = root2->left;
       }
       Node* temp;
       Node* temp1;
       while(!s1.empty() || !s2.empty()){
           if(s1.empty()){
               while(!s2.empty()){
                   temp = s2.top();
                   insert(s2, ans, temp);
               }
           }
           else if(s2.empty()){
               while(!s1.empty()){
                   temp = s1.top();
                   insert(s1, ans, temp);
               }
           }
           else{
               temp = s1.top();
               temp1 = s2.top();
               if(temp->data <= temp1->data){
                   insert(s1, ans, temp);
               }else{
                   insert(s2, ans, temp1);
               }
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends