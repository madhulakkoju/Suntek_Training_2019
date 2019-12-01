/*
Madhu 
17241A05F3

BINARY SEARCH TREE

OPERATION                           FUNCTION
-----------------------------------------------------------------------------------------------------------
CREATE BST            || bstree* Create_BinarySearchTree()
INSERT NODE           || void insert_BinarySearchTree(bstree* b, int val)
DELETE MAX NODE       || int removeMax_bst(bstree* b)
DELETE MIN NODE       || int removeMin_bst(bstree* b)
DELETE NODE           || 
MAXIMUM               || int Max_bst(bstree* b)
MINIMUM               || int Min_bst(bstree* b)
SEARCH NODE           || void search_bstree(bstree* b, int val)
PREORDER TRAVERSAL    || void preorder_BinarySearchTree(bstree* b)
POSTORDER TRAVERSAL   || void postorder_BinarySearchTree(bstree* b)
INORDER TRAVERSAL     || void inorder_BinarySearchTree(bstree* b)
LEVEL ORDER TRAVERSAL || 

*/

// TREE NODE STRUCTURE
typedef struct treenode
{
    int val;
    struct treenode* left;
    struct treenode* right;
}treenode;

// TREE STRUCTURE -- GIVES THE ROOT OF TREE
// This is useful when multiple tree sare required in a single program.
typedef struct bstree
{
    struct treenode* root;
} bstree;

// CREATING BINARY SEARCH TREE WITH ROOT AS NULL
bstree* Create_BinarySearchTree()
{
    bstree* b= (bstree*)malloc(sizeof(bstree));
    b->root = NULL;
    return b;
}

// INORDER TRAVERSAL FOR A TREENODE* 
void inorder(treenode* x)
{
    if(x==NULL)
    return ;
    
    inorder(x->left);
    printf(" %d ",x->val);
    inorder(x->right);
    
    return ;
}

// INORDER TRAVERSAL FOR A BINARY SEARCH TREE
void inorder_BinarySearchTree(bstree* b)
{
   printf(" IN-ORDER TRAVERSAL OF BST  : ");
    inorder(b->root);
}

// PREORDER TRAVERSAL FOR A TREENODE* 
void preorder(treenode* x)
{
    if(x == NULL)
    return;
    printf(" %d ",x->val);
    preorder(x->left);
    preorder(x->right);
    return;
}

// PRE ORDER TRAVERSAL FOR A BINARY SEARCH TREE
void preorder_BinarySearchTree(bstree* b)
{
  printf(" PRE-ORDER TRAVERSAL OF BST  : ");
    preorder(b->root);
}

// POST ORDER TRAVERSAL FOR A TREENODE* 
void postorder(treenode* x)
{
  if(x==NULL)
  return;

  postorder(x->left);
  postorder(x->right);
  printf(" %d ",x->val);
  return;
}

// POST ORDER TRAVERSAL FOR A BINARY SEARCH TREE
void postorder_BinarySearchTree(bstree* b)
{
   printf(" POST-ORDER TRAVERSAL OF BST  : ");
  postorder(b->root);
}

// TO INSERT A NODE AT A SUITABLE POSITION IN BINARY SEARCH TREE
void insert_BinarySearchTree(bstree* b, int val)
{
    treenode* x= (treenode*)malloc(sizeof(treenode));
    x->val = val;
    x->left = NULL;
    x->right = NULL;
    if(b->root == NULL)
    {
        b->root = x;
            printf("%d entered\n",val);
            inorder_BinarySearchTree(b);
            printf("\n");
        return;
    }
    treenode* y = (treenode*)malloc(sizeof(treenode));
    y = b->root;
    while(1)
    {
        if(y->val >= val)
        {
          if(y->left != NULL)
            y=y->left;
          else 
          {
            y->left = x;
                printf("%d entered\n",val);
           inorder_BinarySearchTree(b);
                printf("\n");
            return;
          }
        }
        else if(y->val <= val)
        {
          if(y->right != NULL)
          y = y->right;
          else
          {
            y->right = x;
            printf("%d entered\n",val);
                inorder_BinarySearchTree(b);
                printf("\n");            
            return ;      
          }
        }
    }
    return;
}

// TO REMOVE MAXIMUM ELEMENT OF BINARY SEARCH TREEE
int removeMax_bst(bstree* b)
{
  int v;
  treenode *y = b->root;
  if(y->right == NULL)
  {
    v = y->val;
    b->root = y->left;
    

//                printf("%d del\n",y->val);
//                inorder_BinarySearchTree(b);
//                printf("\n");    
    
    return v;
  }
  while(1)
  {
    if(y->right->right != NULL)
    {
      y=y->right;
    }
    else 
    {
      v = y->right ->val;
//      printf("%d del\n",y->right->val);
      y->right = (y->right)->left;
      
//                inorder_BinarySearchTree(b);
//                printf("\n");   
    return v;
    }
  }
}

// TO REMOVE MINIMUM ELEMENT IN A BINARY SEARCH TREE
int removeMin_bst(bstree* b)
{
  int v;
  treenode *y = b->root;
  if(y->left == NULL)
  {
    b->root = y->right;
    v = y->val;
//              printf("%d del\n",y->val);
//             inorder_BinarySearchTree(b);
//                printf("\n");    
    return v;
  }
  while(1)
  {
    if(y->left->left != NULL)
    {
      y=y->left;
    }
    else 
    {
//      printf("%d del\n",y->left->val);
v = y->left->val;
      y->left = (y->left)->right;
      
//                inorder_BinarySearchTree(b);
//               printf("\n");   
return v;
    }
  }
}

// TO FIND THE MAXIMUM ELEMENT OF THE BINARY SEARCH TREE
int Max_bst(bstree* b)
{
  int v;
  treenode *y = b->root;
  if(y->right == NULL)
  {
    v = y->val;
//                printf("%d del\n",y->val);
//                inorder_BinarySearchTree(b);
//                printf("\n");     
    return v;
  }
  while(1)
  {
    if(y->right->right != NULL)
    {
      y=y->right;
    }
    else 
    {
      v = y->right ->val;
//      printf("%d del\n",y->right->val);
//                inorder_BinarySearchTree(b);
//                printf("\n");   
    return v;
    }
  }
}

// TO FIND MINIMUM ELEMENT IN THE BINARY SEARCH TREE
int Min_bst(bstree* b)
{
  int v;
  treenode *y = b->root;
  if(y->left == NULL)
  {
    
    v = y->val;
//              printf("%d del\n",y->val);
//             inorder_BinarySearchTree(b);
//                printf("\n");    
    return v;
  }
  while(1)
  {
    if(y->left->left != NULL)
    {
      y=y->left;
    }
    else 
    {
//      printf("%d del\n",y->left->val);
v = y->left->val;
//                inorder_BinarySearchTree(b);
//               printf("\n");   
return v;
    }
  }
}

// TO FIND WHETHER A REQUIRED NODE IS FOUND IN THE TREE OR NOT
void search_bstree(bstree* b, int val)
{
    treenode* y =  b->root;
    while(1)
    {
        if(y== NULL)
        {
          inorder_BinarySearchTree(b);
          printf("\n");
          printf("%d NOT found\n",val);
          return;
        }
        else if(y->val == val)
        {
          printf("%d found\n",val);
                      inorder_BinarySearchTree(b);
          printf("\n");
          return;
        }

        if(y->val > val)
        {
          y=y->left;
        }
        else if(y->val < val)
        {
          y = y->right;     
        }
    }
    return;
}
