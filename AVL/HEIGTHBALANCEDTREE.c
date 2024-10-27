#include <stdio.h>
#include <stdlib.h>

// Define structure for AVL tree node
struct Node {
  struct Node *lchild; // Left child pointer
  int data;            // Node's data value
  int height;          // Node's height
  struct Node *rchild; // Right child pointer
} *root = NULL;        // Initialize root as NULL

// Function to calculate the height of a node
int NodeHeight(struct Node *p) {
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height
                      : 0; // Height of left child, or 0 if absent
  hr = p && p->rchild ? p->rchild->height
                      : 0; // Height of right child, or 0 if absent

  return hl > hr ? hl + 1
                 : hr + 1; // Return the larger height + 1 for current node
}

// Function to calculate balance factor for a node
int BalanceFactor(struct Node *p) {
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height : 0; // Height of left child
  hr = p && p->rchild ? p->rchild->height : 0; // Height of right child

  return hl - hr; // Balance factor is left height - right height
}

// Left-Left (LL) Rotation to balance the tree
struct Node *LLRotation(struct Node *p) {
  struct Node *pl = p->lchild;
  struct Node *plr = pl->lchild;

  pl->rchild = p; // Rotate nodes
  p->lchild = plr;

  // Update heights of the affected nodes
  p->height = NodeHeight(p);
  pl->height = NodeHeight(pl);

  // Update root if necessary
  if (root == p)
    root = pl;

  return pl; // Return new root of the subtree
}

// Left-Right (LR) Rotation to balance the tree
struct Node *LRRotation(struct Node *p) {
  struct Node *pl = p->lchild;
  struct Node *plr = pl->rchild;

  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;

  plr->lchild = pl;
  plr->rchild = p;

  // Update heights of the affected nodes
  pl->height = NodeHeight(pl);
  p->height = NodeHeight(p);
  plr->height = NodeHeight(plr);

  // Update root if necessary
  if (root == p)
    root = plr;

  return plr; // Return new root of the subtree
}

// Right-Right (RR) Rotation to balance the tree
struct Node *RRRotation(struct Node *p) {
  struct Node *pr = p->rchild;
  struct Node *prl = pr->lchild;

  pr->lchild = p; // Rotate nodes
  p->rchild = prl;

  // Update heights of the affected nodes
  p->height = NodeHeight(p);
  pr->height = NodeHeight(pr);

  // Update root if necessary
  if (root == p)
    root = pr;

  return pr; // Return new root of the subtree
}

// Right-Left (RL) Rotation to balance the tree
struct Node *RLRotation(struct Node *p) {
  struct Node *pr = p->rchild;
  struct Node *prl = pr->lchild;

  pr->lchild = prl->rchild;
  p->rchild = prl->lchild;

  prl->lchild = p;
  prl->rchild = pr;

  // Update heights of the affected nodes
  p->height = NodeHeight(p);
  pr->height = NodeHeight(pr);
  prl->height = NodeHeight(prl);

  // Update root if necessary
  if (root == p)
    root = prl;

  return prl; // Return new root of the subtree
}

// Recursive function to insert a key in AVL Tree and balance it
struct Node *RInsert(struct Node *p, int key) {
  struct Node *t;

  // Create a new node if we have reached a null position
  if (p == NULL) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->height = 1; // New nodes are initially height 1
    t->lchild = t->rchild = NULL;
    return t; // Return the new node
  }

  // Insert in the left subtree if key is smaller than current node's data
  if (key < p->data)
    p->lchild = RInsert(p->lchild, key);
  // Insert in the right subtree if key is greater than current node's data
  else if (key > p->data)
    p->rchild = RInsert(p->rchild, key);

  // Update height of the current node
  p->height = NodeHeight(p);

  // Perform rotations if unbalanced
  if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    return LLRotation(p);
  else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    return LRRotation(p);
  else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    return RRRotation(p);
  else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    return RLRotation(p);

  return p; // Return the (potentially new) root
}

int main() {
  root = RInsert(root, 10); // Insert node with value 10
  RInsert(root, 5);         // Insert node with value 5
  RInsert(root, 2);         // Insert node with value 2

  return 0;
}
