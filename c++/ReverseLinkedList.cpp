#include<iostream>

using namespace std;

typedef struct SingleLinkNode{
	int val;
	SingleLinkNode* next;
	SingleLinkNode(int a):val(a),next(NULL){};
}SingleLinkNode;

SingleLinkNode* reverseLinkedList(SingleLinkNode* head){
	if(head == NULL)
		return NULL;
	
	SingleLinkNode* pre=NULL,cur=head,next=head->next;
	
	while(next != NULL){
		cur->next = pre;
		pre = cur;
		cur = next;
		next = next->next;
	}
	
	cur->next = pre;
	
	return cur;
}

int main(){
	SingleLinkNode* n1 = new SingleLinkNode(3);
	SingleLinkNode* n2 = new SingleLinkNode(2);
	SingleLinkNode* n3 = new SingleLinkNode(1);

	n1->next = n2;
	n2->next = n3;

	SingleLinkNode* head = reverseLinkedList(n1);
	SingleLinkNode* next;

	while(head != NULL){
		next = head->next;
		cout<<head->val<<endl;
		head = next;
	}

	return 0;
}