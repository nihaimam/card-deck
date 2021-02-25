#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

//prototypes
struct Node *newList(void);
struct Node *insertNode(struct Node *prev, int data);
struct Node *removeNode(struct Node * prev);
int length(struct Node *head);
void printList(struct Node *head);

struct Node *newList(void) // returns a head of a new empty list
{
  // create the new head pointer, and return 
  struct Node* head = (struct Node*)malloc(sizeof(struct Node));
  head->data = -1;
  head->next = 0;
  return head;
}

struct Node *insertNode(struct Node *prev, int data) // inserts a new node with data field data after prev
{
  // create and allocate memory
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  if (node == NULL)
  {
    printf("ERROR!!!");
  }
  // store data in node
  node->data = data;
  // create a temp node
  struct Node* temp;
  // if prev is 0 or the data value is greater than the node data value
  if(prev == 0 || prev->data >= node->data)
  {
    // node next is prev
    node->next = prev;
    // prev node is node
    prev = node;
  }
  else
  {
    temp = prev;
    // until temp next is not 0 and node next data is less than node data
    while(temp->next != 0 && temp->next->data < node->data)
    {
      temp = temp->next;
    }
    // node next is temp next and temp next is node
    node->next = temp->next;
    temp->next = node;
  }
  return temp;
}

struct Node *removeNode(struct Node * prev) // deletes the node after prev 
{
  struct Node* ahead;
  struct Node* node;
  // the node to delete
  node = prev->next;
  // the node ahead
  ahead = node->next;
  // update links
  prev->next = ahead;
  // return the removed node
  return node;
}

int length(struct Node *head) // number of elements in the list
{
  struct Node* node;
  int len;
  // start with the length 0, and first node
  len = 0;
  node = head->next;
  // repeat till traverse is complete
  while (node != 0)
  {
  // length increment whenever we have a new node
    len++;
    // move to next node
    node = node->next;
  }
  // return the computed length
  return len;
}

void printList(struct Node *head) // print the data fields for the entire list
{
  struct Node* node;
  // start with the first node
  node = head->next;
  // repeat till traverse is complete
  while (node != 0)
  {
    // print the value
    printf("%d ", node->data);
    // move to next node
    node = node->next;
  }
  printf("\n\n");
}

int main()
{
  struct Node* deck;
  int val, x;
  deck = newList();
  srand(7092);	
  for (x = 0; x < 10; x++)
  {
    val = rand() % 1001;
    printf("Random Value: %d\n", val);
    insertNode(deck, val);		
    printf("List Length : %d\n", length(deck));
    printList(deck);
  }
  printf("\nFinal List Length : %d\n", length(deck));
  printList(deck);
  removeNode(deck);
  return 0;
}
