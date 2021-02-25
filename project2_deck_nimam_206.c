#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char* data;
  char suit;
  struct Node *next;
};

struct Node *newList(void) // returns a head of a new empty list
{
  // create the new head pointer, and return
  struct Node* head = (struct Node*)malloc(sizeof(struct Node));
  if (head == NULL)
  {
    printf("ERROR!!!");
  }
  head->data = "-1";
  head->suit = 'n';
  head->next = 0;
  return head;
}

struct Node *insert(struct Node *prev, char *data , char suit) // inserts a new node with data field data after prev
{
  struct Node* ahead;
  struct Node* node;
  // get the node ahead from prev
  ahead = prev->next;
  // allocate and store the new node
  node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->suit = suit;
  // updated links sequence : prev -> node -> ahead
  prev->next = node;
  node->next = ahead;
}

struct Node *delete(struct Node * prev) // deletes the node after prev
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
    // print the valuen
    printf("(%s,%c) ", node->data , node->suit);
    // move to next node
    node = node->next;
  }
  printf("\n");
}

struct Node *randomShuffle(struct Node *olddeck) // returns new deck
{
  int len, i, j, k;
  struct Node* newdeck;
  struct Node* node;
  struct Node* temp;
  // get the length of our list
  len = length(olddeck);
  //Make a new linked list newdeck
  newdeck = newList();
  for (i = len - 1; i >= 0; i--)
  {
    // delete a node from the olddeck
    node = delete(olddeck);
    // generate a random number
    j = rand() % (len - i);
    // loop to that random index on olddeck
    temp = newdeck;
    for (k = 0; k < j-1; k++)
      temp = temp->next;// insert at front newdeck
    insert(temp, node->data , node->suit);
    // free the node pointer on the olddeck itself
    free(node);
  }
  // return the updated new deck
  return newdeck;
}

int main()
{
  struct Node* deck;
  struct Node* temp;
  int x , y;
  char suit;
  char* data;
  deck = newList();
  srand(7092);
  for(y = 0 ; y < 4 ; y++)
  {
    for (x = 0; x < 13; x++)
    {
      switch(x)
      {
        case 0: data = "A"; break;
        case 1: data = "1"; break;
        case 2: data = "2"; break;
        case 3: data = "3"; break;
        case 4: data = "4"; break;
        case 5: data = "5"; break;
        case 6: data = "6"; break;
        case 7: data = "7"; break;
        case 8: data = "8"; break;
        case 9: data = "9"; break;
        case 10: data = "10"; break;
        case 11: data = "J"; break;
        case 12: data = "Q"; break;
        default: data = "K"; break;
      }
      switch(y)
      {
        case 0: suit = 'C'; break;
        case 1: suit = 'D'; break;
        case 2: suit = 'H'; break;
        default: suit = 'S'; break;
      }
      temp = deck;
      while (temp->next != 0)
      temp = temp->next;
      insert(temp, data , suit);
    }
  }
  printf("Deck:\n\n");
  printList(deck);	
  deck = randomShuffle(deck);
  printf("\nShuffled Deck:\n\n");
  printList(deck);
  return 0;
}
