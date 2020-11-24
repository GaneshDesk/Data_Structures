//////////////////////////////////////////////////////////////////////////////////////
//
// Program which is used to demonstrate working of Binary Search Tree
//
/////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node *createbst(struct node *);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
int countnodes(struct node *);
int countleafnodes(struct node *);
int countnonleafnodes(struct node *);
void mirrorbst(struct node *);
int comparebst(struct node *,struct node *);
struct node *copybst(struct node *);
int displaylevel(struct node *,int);
int displayheightbst(struct node *,int);
void insertnode(struct node *,int);
struct node *deletenode(struct node *,int);

int main()
{
	struct node *root, *root1;
	int choice, flag, no, level;
	root = NULL;

	while (1)
	{
		printf("\nBST Creation & Traversals\n\n");
		printf("1. Create BST\n");
		printf("2. Preorder\n");
		printf("3. Inorder\n");
		printf("4. Postorder\n");
		printf("5. To Count nodes in BST\n");
		printf("6. To Count the no. of leaf nodes in BST\n");
		printf("7. To Count the no. of Non leaf nodes in BST\n");
		printf("8. To Mirror the given BST\n");
		printf("9. To Compare 2 BST's\n");
		printf("10. To Copy a BST\n");
		printf("11. To display the level of a Node in BST\n");
		printf("12. To display the height of BST\n");
		printf("13. To insert a node in BST\n");
		printf("14. To delete a node from BST\n");
		printf("15. Exit\n");

		printf("Enter your choice :- ");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
				root = createbst(root);
				break;

			case 2:
				preorder(root);
				break;

			case 3:
				inorder(root);
				break;

			case 4:
				postorder(root);
				break;

			case 5:
				printf("No. of nodes in BST are %d",countnodes(root));
				break;

			case 6:
				printf("No. of leaf nodes in BST are %d",countleafnodes(root));
				break;

			case 7:
				printf("No. of Non leaf nodes in BST are %d",countnonleafnodes(root));
				break;

			case 8:
				mirrorbst(root);
				break;

			case 9:
			       root1 = NULL;
			       root1 = createbst(root1);
			       flag = comparebst(root,root1);
			       if (flag)
						printf("2 BST's are same");
			       else
						printf("2 BST's are not same");
			       break;

			case 10:
				root1 = copybst(root);
				printf("Given bst is ");
				preorder(root);
				printf("\nCopied bst is ");
				preorder(root1);
				break;

			case 11:
				printf("Enter the node data :- ");
				scanf("%d",&no);
				level = displaylevel(root,no);
				if (level == -1)
					printf("Node with data %d not found in BST",no);
				else
					printf("Node with data %d found at level %d",no,level);
				break;

			case 12:
				if (root != NULL)
					printf("Height of BST is %d",displayheightbst(root,-1));
				else
					printf("1st create BST");
				break;

			case 13:
				printf("Enter the value of node to insert in BST :- ");
				scanf("%d",&no);
				insertnode(root,no);
				break;

			case 14:
				printf("Enter the value of node to delete from BST :- ");
				scanf("%d",&no);
				root = deletenode(root,no);
				break;

			case 15:
				return 0;;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to create BST
//
/////////////////////////////////////////////////////////////////////////////////////

struct node *createbst(struct node *root)
{
	struct node *newnode, *temp;
	char ask = 'y';

	while (ask == 'y')
	{
		newnode = (struct node *) malloc(sizeof(struct node));
	
		printf("Enter data for newnode :- ");
		scanf("%d",&newnode->data);

		newnode->left = NULL;
		newnode->right = NULL;

		if (root == NULL)
			root = newnode;
		else
		{
			temp = root;

			/* search for appropriate position for node in BST */
			while (1)
			{
				if (newnode->data < temp->data)
				{
					if (temp->left == NULL)
					{
						temp->left = newnode;
						break;
					}
					else
						temp = temp->left;
				}
				else /* newnode->data > temp->data */
				{
					if (temp->right == NULL)
					{
						temp->right = newnode;
						break;
					}
					else
						temp = temp->right;
				}
			} /* end of while (1) */
		} /* end of if (root == NULL) */
		printf("Do you want to add more nodes to BST ? ");
		scanf("%c",&ask);
	}  /* end of while (ask == 'y') */
	return root;
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to print the contents in preorder
//
/////////////////////////////////////////////////////////////////////////////////////

void preorder(struct node *temp)
{
	if (temp != NULL)
	{
		printf("%d ",temp->data);
		preorder(temp->left);   /* recursive call */
		preorder(temp->right);
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to print the contents in inorder
//
/////////////////////////////////////////////////////////////////////////////////////
void inorder(struct node *temp)
{
	if (temp != NULL)
	{
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to print the contents in postorder
//
/////////////////////////////////////////////////////////////////////////////////////

void postorder(struct node *temp)
{
	if (temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d ",temp->data);
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to count number of nodes in BST
//
/////////////////////////////////////////////////////////////////////////////////////

int countnodes(struct node *temp)
{
	static int cntr = 0;

	if (temp != NULL)
	{
		cntr++;
		countnodes(temp->left);
		countnodes(temp->right);
	}
	
	return cntr;
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to count leaf nodes
//
/////////////////////////////////////////////////////////////////////////////////////

int countleafnodes(struct node *temp)
{
	static int cntr = 0;

	if (temp != NULL)
	{
		if (
			temp->left == NULL	&& 
			temp->right == NULL
			)
		{
			cntr++;
		}
		countleafnodes(temp->left);
		countleafnodes(temp->right);
	}
	
	return cntr;
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to count non leaf nodes
//
/////////////////////////////////////////////////////////////////////////////////////

int countnonleafnodes(struct node *temp)
{
	static int cntr = 0;

	if (temp != NULL)
	{
		if (temp->left != NULL || temp->right != NULL)
			cntr++;
		countnonleafnodes(temp->left);
		countnonleafnodes(temp->right);
	}

	return cntr;
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to create mirror BST
//
/////////////////////////////////////////////////////////////////////////////////////

void mirrorbst(struct node *temp)
{
	struct node *temp1;
	if (temp != NULL)
	{
		/* swap the left & right links of this node */
		temp1 = temp->left;
		temp->left = temp->right;
		temp->right = temp1;

		/* use recursion to swap the children of a node also */
		mirrorbst(temp->left);
		mirrorbst(temp->right);
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to compaire two BST
//
/////////////////////////////////////////////////////////////////////////////////////

int comparebst(struct node *temp1,struct node *temp2)
{
	int flag;
	if (temp1 == NULL && temp2 == NULL)
	{
		return 1;
	}
	else
	{
		if (temp1->data == temp2->data)
		{
			/* compare left sub-trees */
			flag = comparebst(temp1->left,temp2->left);
			if (flag)
			{
				flag = comparebst(temp1->right,temp2->right);
				if (flag)
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to copy BST
//
/////////////////////////////////////////////////////////////////////////////////////

struct node *copybst(struct node *temp)
{
	struct node *newnode;
	if (temp != NULL)
	{
		/* create a parallel node for temp */
		newnode = (struct node *) malloc(sizeof(struct node));
		newnode->data = temp->data;
		newnode->left = copybst(temp->left);   /* imp */
		newnode->right = copybst(temp->right);
		return newnode;
	}
	else
		return NULL;
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to return the level at which data is found
//
/////////////////////////////////////////////////////////////////////////////////////

int displaylevel(struct node *temp,int no)
{
	int level = 0, flag = 0;

	/* search for node data till bottom of BST */
	while (temp != NULL)
	{
		if (no == temp->data)
		{
			flag = 1;
			break;
		}

		level++;
		if (no < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (flag)
		return level;
	else
		return -1;
}

int displayheightbst(struct node *temp,int level)
{
	static int height = -1;
	if (temp != NULL)
	{
		level++;

		if (height < level)
			height = level;

		displayheightbst(temp->left,level);
		displayheightbst(temp->right,level);
	}
	return height;
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to insert node in BST
//
/////////////////////////////////////////////////////////////////////////////////////

void insertnode(struct node *temp,int no)
{
	struct node *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode->data = no;
	newnode->left = NULL;
	newnode->right = NULL;
	while (1)
	{
		if (newnode->data == temp->data)
		{
			printf("Node with data %d exists in BST",no);
			return;
		}

		if (newnode->data < temp->data)
		{
			if (temp->left == NULL)
			{
				temp->left = newnode;
				break;
			}
			else
				temp = temp->left;
		}
		else /* newnode->data > temp->data */
		{
			if (temp->right == NULL)
			{
				temp->right = newnode;
				break;
			}
			else
				temp = temp->right;
		}
	} /* end of while (1) */
}

//////////////////////////////////////////////////////////////////////////////////////
//
// This function is used to delete node from BST
//
/////////////////////////////////////////////////////////////////////////////////////

struct node *deletenode(struct node *root,int no)
{
	struct node *temp, *parent_temp, *rn, *parent_rn, *son;
	parent_temp = NULL;

	/* search for the node to be deleted in BST */
	temp = root;
	while (temp != NULL)
	{
		if (temp->data == no)   /* node fnd, terminate the search */
			break;

		parent_temp = temp;
		if (no < temp->data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	
	if (temp == NULL)
	{
		printf("Node with data %d not found in BST",no);
		return root;
	}
	
	/* Node fnd, test the status of node */
	if (temp->left == NULL)
		rn = temp->right;
	else

	{
		if (temp->right == NULL)
			rn = temp->left;
		else /* Node to be deleted has 2 children */
		{
			/* rn will be the leftmost node of right subtree */
			parent_rn = temp;
			rn = parent_rn->right;
			son = rn->left;

			while (son != NULL)
			{
				parent_rn = rn;
				rn = son;
				son = son->left;
			}
			if (parent_rn != temp)
			{
				parent_rn->left = rn->right;
				rn->right = temp->right;
			}
			rn->left = temp->left;
		}
	}
	/* set the link of parent node of temp */
	/* case 1, root node is deleted */
	if (parent_temp == NULL)
		root = rn;
	else
	{
		/* if temp is to the left of it's parent,
		  then the left link of parent_temp is to be set to rn */
		if (parent_temp->left == temp)
			parent_temp->left = rn;
		else
			parent_temp->right = rn;
	}
	free(temp);
	printf("Node with data %d deleted successfully",no);

	return root;
}