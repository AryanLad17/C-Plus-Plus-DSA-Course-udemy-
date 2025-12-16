#include <iostream>
#include <algorithm> // For std::max

// Define the Node structure
struct Node {
    int data;
    Node *lchild;
    Node *rchild;
};

// Global root pointer (for simplicity, typically it's a class member)
Node *root = nullptr;

/**
 * @brief Utility function to calculate the height of a node.
 * @param p Pointer to the current node.
 * @return The height of the subtree rooted at p.
 */
int height(Node *p) {
    if (p == nullptr) {
        return 0;
    }
    int hL = height(p->lchild);
    int hR = height(p->rchild);
    return std::max(hL, hR) + 1;
}

/**
 * @brief Finds the Inorder Predecessor (largest element in the left subtree).
 * @param p Pointer to the left child of the node to be deleted.
 * @return Pointer to the Inorder Predecessor node.
 */
Node *Inperc(Node *p) {
    // Inorder Predecessor is the rightmost node in the left subtree.
    while (p && p->rchild != nullptr) {
        p = p->rchild;
    }
    return p;
}

/**
 * @brief Finds the Inorder Successor (smallest element in the right subtree).
 * @param p Pointer to the right child of the node to be deleted.
 * @return Pointer to the Inorder Successor node.
 */
Node *Insucc(Node *p) {
    // Inorder Successor is the leftmost node in the right subtree.
    while (p && p->lchild != nullptr) {
        p = p->lchild;
    }
    return p;
}

/**
 * @brief Creates a new Node.
 */
Node *createNode(int key) {
    Node *newNode = new Node;
    newNode->data = key;
    newNode->lchild = nullptr;
    newNode->rchild = nullptr;
    return newNode;
}

/**
 * @brief Inserts a node into the BST (Recursive).
 * @param p Pointer to the current node.
 * @param key The value to insert.
 * @return Pointer to the new root of the subtree.
 */
Node *Insert(Node *p, int key) {
    if (p == nullptr) {
        return createNode(key);
    }
    if (key < p->data) {
        p->lchild = Insert(p->lchild, key);
    } else if (key > p->data) {
        p->rchild = Insert(p->rchild, key);
    }
    return p;
}

/**
 * @brief Recursive function to delete a node with the given key from the BST.
 * * @param p Pointer to the current node.
 * @param key The value to delete.
 * @return Pointer to the root of the subtree after deletion.
 */
Node *Delete(Node *p, int key) {
    struct Node *t = nullptr; // t will hold the Inorder Predecessor/Successor
    
    // 1. Base Case: Key not found (reached null)
    if (p == nullptr) {
        return nullptr;
    }

    // 2. Case: Node found and is a leaf node
    if (p->lchild == nullptr && p->rchild == nullptr) {
        if (p == root) {
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    // 3. Search: Traverse the BST
    if (p->data > key) {
        p->lchild = Delete(p->lchild, key);
    } else if (p->data < key) {
        p->rchild = Delete(p->rchild, key);
    } 
    
    // 4. Case: Node to be deleted is found (p->data == key)
    else { 
        // Choose replacement based on taller subtree for potential balancing/efficiency
        if (height(p->lchild) > height(p->rchild)) {
            // Use Inorder Predecessor
            t = Inperc(p->lchild);
            p->data = t->data; // Copy replacement data to current node
            // Recursively delete the actual replacement node (which is now a duplicate)
            p->lchild = Delete(p->lchild, t->data); 
        } else {
            // Use Inorder Successor
            t = Insucc(p->rchild);
            p->data = t->data; // Copy replacement data to current node
            // Recursively delete the actual replacement node (which is now a duplicate)
            p->rchild = Delete(p->rchild, t->data);
        }
    }
    return p; // Return the updated root of the subtree
}

/**
 * @brief Public wrapper function to start the deletion process.
 */
void Delete(int key) {
    root = Delete(root, key);
}

/**
 * @brief Perform Inorder Traversal to display the BST elements (should be sorted).
 */
void Inorder(Node *p) {
    if (p) {
        Inorder(p->lchild);
        std::cout << p->data << " ";
        Inorder(p->rchild);
    }
}

// --- Main Program ---
int main() {
    // Build a BST: 50, 30, 70, 20, 40, 60, 80
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 70);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 60);
    Insert(root, 80);

    std::cout << "Original BST (Inorder Traversal): ";
    Inorder(root);
    std::cout << "\n";

    // Case 1: Delete a Leaf Node (20)
    Delete(20);
    std::cout << "After deleting 20 (Leaf): ";
    Inorder(root);
    std::cout << "\n";

    // Case 2: Delete a Node with One Child (70 is technically not one child, but let's test a middle node)
    // The current structure doesn't easily isolate a single-child case without more insertions/deletions,
    // but the two-child logic handles it implicitly if one child is NULL.

    // Case 3: Delete a Node with Two Children (50 - the root)
    Delete(50);
    std::cout << "After deleting 50 (Root/Two Children): ";
    Inorder(root);
    std::cout << "\n";

    // Delete remaining nodes
    Delete(30);
    Delete(80);
    Delete(40);
    Delete(60);

    std::cout << "After deleting all remaining nodes: ";
    Inorder(root);
    std::cout << "\n";

    return 0;
}