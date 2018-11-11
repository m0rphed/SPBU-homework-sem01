#ifndef SPBU_HOMEWORK_TASK_51_LINKED_LIST_H
#define SPBU_HOMEWORK_TASK_51_LINKED_LIST_H


namespace LinkedList
{
	struct Node;
	
	
	int length(Node *head);
	
	
	void shift(Node *&head, int value);


	void smartInsert(Node *&head, int data);
	
	
	void smartDelete(Node *&head, int data);
	
	
	void reverse(Node *&head);
	
	
	void printList(Node *head);
	
	
	void deleteList(Node *&head);
	
	
	void startDialogLoop(Node *&head);
}


#endif //SPBU_HOMEWORK_TASK_51_LINKED_LIST_H
