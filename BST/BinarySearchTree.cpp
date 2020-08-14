#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}


struct treeNode * searchItem(struct treeNode * node, int item)
{
    if(node==0) return 0;
    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};


struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    if(node==0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return newNode;
    }

    if(node->item==item) return 0; //already an item exists, so return NULL

    if(item<node->item && node->left==0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return newNode;
    }

    if(item>node->item && node->right==0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return newNode;
    }

    if(item<node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}



int calcNodeHeight(struct treeNode * node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}


int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{


    if(node==0)return 0;

    return getSize(node->right)+getSize(node->left)+1;

}
int calcDepth(int item)//return depth of an item in the tree
{
    int c=0,flag=0;
    struct treeNode *node=root;
    while(node!=0)
    {

        if(item>node->item)
        {
            node=node->right;
        }
        else if(item<node->item)
        {
            node=node->left;
        }
        else
        {
            flag=1;
            break;
        }
        c++;
    }
    if(flag==1)return c;
    else
    {
        printf("the item not found\n");
        return 0;
    }
}

int calcNodeDepth(struct treeNode * node) //return depth of a node
{
    return calcDepth(node->item);

}




int deleteItem(struct treeNode * node, int item)
{

    if(node==0)
    {
        printf("the tree is empty");
        return 0;
    }

    else
    {
        struct treeNode *parent=0;
        struct treeNode *child=node;
        while(child!=0)
        {
            if(child->item<item)
            {
                parent=child;
                child=child->right;
            }
            else if(child->item>item)
            {
                parent=child;
                child=child->left;
            }
            else
            {
                if(parent==0) ///root node will be deleted
                {
                    if(child->left==0&&child->right==0)
                    {
                        struct treeNode *temp = 0;
                        temp=child;
                        root=0;
                        free(temp);
                        return 1;
                    }
                    else if(child->left==0)
                    {
                        struct treeNode *temp = child;
                        root=child->right;
                        free(temp);

                    }
                    else if(child->right==0)
                    {
                        struct treeNode *temp = child;
                        root=child->left;
                        free(temp);

                    }
                    else ///root has both lft and right node
                    {
                        struct treeNode *rightmin = child->right,*rightminparent=child->right;
                        while(rightmin->left!=0)
                        {
                            rightmin=rightmin->left;
                        }
                        root->item=rightmin->item;

                        if(rightmin->right==0&&child->right==rightmin)
                        {
                            child->right=0;
                            printf("the rightmin is %d\n",rightmin->item);
                            free(rightmin);

                        }
                        else if(rightmin->right==0&&(child->right)->left==rightmin)
                        {
                            (child->right)->left=0;
                            printf("the rightmin is %d\n",rightmin->item);
                            free(rightmin);

                        }
                        else
                        {
                            if(rightmin==rightminparent)
                            {

                                child->right=rightmin->right;
                                free(rightmin);
                            }
                            else
                            {
                                while(rightminparent->left!=rightmin)
                                {
                                    rightminparent=rightminparent->left;
                                }
                                rightminparent=rightmin->right;
                                free(rightmin);
                            }
                        }
                        ///not done yet
                    }
                }
                else ///not root but other node would be deleted,there is a parent of the node
                {
                    if(child->left==0&&child->right==0&&parent->left==child)
                    {
                        parent->left=0;
                        free(child);

                    }
                    else if(child->left==0&&child->right==0&&parent->right==child)
                    {
                        parent->right=0;
                        free(child);

                    }
                    else if(child->left==0&&parent->left==child)
                    {
                        parent->left=child->right;
                        free(child);
                    }
                    else if(child->left==0&&parent->right==child)
                    {
                        parent->right=child->right;
                        free(child);
                    }
                    else if(child->right==0&&parent->left==child)
                    {
                        parent->left=child->left;
                        free(child);
                    }
                    else if(child->right==0&&parent->right==child)
                    {
                        parent->right=child->left;
                        free(child);
                    }
                    else
                    {
                        struct treeNode *rightmin = child->right,*rightminparent=child->right;
                        while(rightmin->left!=0)
                        {
                            rightmin=rightmin->left;
                        }
                        child->item=rightmin->item;

                        if(rightmin->right==0&&child->right==rightmin)
                        {
                            child->right=0;
                            //printf("the rightmin is %d\n",rightmin->item);
                            free(rightmin);

                        }
                        else if(rightmin->right==0&&(child->right)->left==rightmin)
                        {
                            (child->right)->left=0;
                            //printf("the rightmin is %d\n",rightmin->item);
                            free(rightmin);

                        }
                        else
                        {
                            if(rightmin==rightminparent)
                            {

                                child->right=rightmin->right;
                                free(rightmin);
                            }
                            else
                            {

                                while(rightminparent->left!=rightmin)
                                {
                                    rightminparent=rightminparent->left;
                                }
                                rightminparent=rightmin->right;
                                free(rightmin);
                            }
                        }
                        ///not done yet
                    }

                }
                break;
            }
        }
    }
}






int getMinItem() //returns the minimum item in the tree
{
    if(root==0)
    {
        printf("the tree is empty");
        return -9999;
    }
    else
    {
        struct treeNode * node = root;
        while(node->left!=0)
        {
            node=node->left;
        }
        return node->item;
    }
}

int getMaxItem() //returns the maximum item in the tree
{
    if(root==0)
    {
        printf("the tree is empty");
        return -9999;
    }
    else
    {
        struct treeNode * node = root;
        while(node->right!=0)
        {
            node=node->right;
        }
        return node->item;
    }
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound) //returns number of items in the
{
    if(leftBound>rightBound)
    {
        printf("the input is wrong");
        return 0;
    }
    else
    {
        if(node==0)
        {
            return 0;
        }

        if(leftBound<=node->item&&rightBound>=node->item)
        {
            return rangeSearch(node->right,leftBound,rightBound)+rangeSearch(node->left,leftBound,rightBound)+1;
        }
        else return rangeSearch(node->right,leftBound,rightBound)+rangeSearch(node->left,leftBound,rightBound);

    }
}


void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0; i<height; i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}



int main(void)
{
    /*initializeTree();
    insertItem(root, 3);
    insertItem(root, 6);
    insertItem(root, 4);
    insertItem(root, 5);
    insertItem(root, -3);
    insertItem(root, 1);
    insertItem(root, -5);
    printf("\n--------------------------------\n");
    printInOrder(root, 3);
    printf("--------------------------------\n");
    printf("size is :%d\n",getSize(root));
    printf("the height is :%d\n",calcNodeHeight(root));
    printf("the depth of the node is: %d\n",calcNodeDepth(root));
    printf("the depth of the node 3 is: %d\n",calcDepth(3));
    printf("the depth of the node 1 is: %d\n",calcDepth(1));
    printf("the minimum value is %d\n",getMinItem());
    printf("the maximum value is %d\n",getMaxItem());
    printf("numbersw in range of 1 to 5 is %d\n",rangeSearch(root,1,5));
    //deleteItem(root,5);
    printf("\n--------------------------------\n");
    printInOrder(root, 3);
    printf("--------------------------------\n");*/
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. \n");
        printf("6. PrintInOrder. 7.get max 8.get min 9.getsize 10.calcdepth 11.range search 12. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(root, item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==7)
        {
            printf("the max item is %d\n",getMaxItem());
        }
        else if(ch==8)
        {
            printf("the min item is %d\n",getMinItem());
        }
        else if(ch==9)
        {
            printf("the size of the tree is %d\n",getSize(root));
        }
        else if(ch==10)
        {
            printf("enter the item u want to find depth of\n");
            int item;
            cin>>item;
            printf("the depth of the node is %d\n",calcDepth(item));
        }
        else if(ch==11)
        {
            printf("enter leftbound and right bound of the range search");
            int left,right;
            cin>>left>>right;
            printf("the number of elements present in this range is %d\n",rangeSearch(root,left,right));
        }
        else if(ch==12)
        {
            break;
        }
    }

}
