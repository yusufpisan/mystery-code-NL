#include <iostream>

using namespace std;

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void print(Node* curr) {
  while (curr != NULL) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

void insert(Node *&head, int data) {
  Node *nextNode = new Node;
  nextNode->data = data;
  nextNode->next = NULL;
  if (head == NULL) {
    head = nextNode;
  } else if (nextNode->data < head->data) {
    nextNode->next = head;
    head = nextNode;
  } else {
    Node *curr = head;
    while (curr->next != NULL && curr->next->data < nextNode->data) {
      curr = curr->next;
    }
    nextNode->next = curr->next;
    curr->next = nextNode;
  }
}

void test01() {
  Node* start = NULL;
  for (int i = 0; i < 10; ++i)
    insert(start, i);
  print(start);
  for (int i = 0; i < 10; ++i)
    insert(start, rand() % 20 - 5);
  print(start);
}

int main() {
  test01();
  cout << "Done!" << endl;
  return 0;
}