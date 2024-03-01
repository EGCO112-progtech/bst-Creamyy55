// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );
/*อีกวิธี
void insertNode_R(TreeNodePtr * t,int value){
  if(t==NULL){
   t=new TreeNode;
	 if(t){
		(*t)->leftPtr=NULL;
		(*t)->rightPtr=NULL;
		(*t)->data=value;
   }
  }
  else{
     if(t->data>=value) insertNode_R(&(*t)->leftPtr) //left 
        
     else insertNode_R(&(*t)->rightPtr) //right
      
   }
}*/

void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0;
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node)
   {
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root)	b->root=new_node;
		else 
      {
         while(!inserted)
         {
         if(t->data >=value)/*ค่าน้อยกว่า move/insert to the left*/ {

            if(t->leftPtr==NULL) //แทรกได้เมื่อขวาเป็นNULL
            {
               t->leftPtr=new_node;
               inserted=1;
            }
            else t=t->leftPtr;

         }
         else{ /*ค่ามากกว่า move/ insert to the right*/
         if(t->rightPtr==NULL) //แทรกได้เมื่อขวาเป็นNULL
            {
               t->rightPtr=new_node;
               inserted=1;
            }
            else t=t->rightPtr;

         }
         }//end while		
      }//end else;
  b->size++;
  }//end new_node
  
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //เรียกตัวเอง print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

   void preOrder(TreeNodePtr treePtr){
      if ( treePtr != NULL )
      {        
      printf("%3d",treePtr->data) ;  //เรียกตัวเอง print the value
      preOrder( treePtr->leftPtr ); //Recursion to the left
      preOrder( treePtr->rightPtr ); //Recursion to the right
      } // end if  
   }
   
   void postOrder(TreeNodePtr treePtr){
      if ( treePtr != NULL )
      {
      postOrder( treePtr->leftPtr ); //Recursion to the left
      postOrder( treePtr->rightPtr ); //Recursion to the right
      printf("%3d",treePtr->data) ;  //เรียกตัวเอง print the value
      } // end if 

   }
   void printTree(TreeNodePtr treePtr,int count){
   int i;
   if ( treePtr != NULL ){
      ++count; 
      printTree( treePtr->rightPtr ,count); //Recursion to the right
      for(i=0;i<count;i++) printf("   ");
      printf("%3d\n",treePtr->data) ;  //เรียกตัวเอง print the value
      printTree( treePtr->leftPtr,count ); //Recursion to the left

   }

   }