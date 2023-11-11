#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

// Utility function to create new BST node
struct node *createnode(int key)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
} 

// function to do inorder traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);                  // ???????????????
        inorder(root->right);
    }
}

// function to insert new node with a key
// pnode = parent node
struct node *insert(struct node *pnode, int key)
{
    if (pnode == NULL)
    {
        return createnode(key);
    }
    if (key < pnode->key)
    {
        pnode->left = insert(pnode->left, key);          // ???????????????????????? Y asgin a value to left n sme for right
    }
    else if (key > pnode->key)
    {
        pnode->right = insert(pnode->right, key);
    }

    return pnode;
}

// Finding node with min key value in right subtree
struct node *minValueNode(struct node *pnode)
{
    struct node *current = pnode;

    while (current  != NULL)
        current = current->left;

    return current;
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->key)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->key)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        // node with 1 or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with 2 child
        // Get inorder successor (smallest in right subtree)
        struct node *temp = minValueNode(root->right);
        root->key = temp->key;

        // Delete the inorder successor
        root->right = delete (root->right, temp->key);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 70);
    insert(root, 60);
    insert(root, 40);
    insert(root, 80);
    insert(root, 30);
    insert(root, 20);

    inorder(root);

    printf("\nDelete 20\n");
    root = delete(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = delete(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    return 0;
}
