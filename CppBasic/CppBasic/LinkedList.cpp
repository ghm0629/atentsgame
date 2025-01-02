#include "stdio.h"
#include "LinkedList.h"

void LinkedList::Add(int data)
{
	// 마지막에 데이터를 추가하는 함수
	ListNode* node = new ListNode(data);

	if (head == nullptr)
	{
		head = node;	// 헤드가 비어있으면 새로 만든 노드가 새 헤드가 된다.
	}
	else
	{
		ListNode* tail = head;
		while (tail->next != nullptr)	// tail이 마지막 노드가 될 때까지 이동
		{
			tail = tail->next;
		}
		tail->next = node;				// 마지막 노드의 next로 새로 만든 노드를 지정	
	}
}

void LinkedList::Insert(int data, int position)
{
	// Data를 position번째에 추가(position이 전체길이를 벗어나면 마지막에 추가)
	ListNode* node = new ListNode(data);
	ListNode* target = head;		// position위치에 있는 노드
	ListNode* prev = nullptr;		// target 앞에 있는 노드

	if (position == 0 || head == nullptr){
		node->next = head;
		head = node;	// 리스트가 비었으면 새 노드를 헤드로 만들고 끝
		return;
	}

	// target이 적절한 위치로 갈때까지 이동시키기
	int count = 0;
	while (count < position && target != nullptr) {
		count++;
		prev = target;
		target = target->next;
}
	if (target == nullptr || target->next == nullptr) {
		Add(data); // position이 전체 길이를 벗어나면 마지막에 추가
	} else {
		node->next = target;	// 새 노드의 next를 target의 next로 설정하고
		target->next = node;		// 
	}
	//ListNode* prev = getNode(position - 1);
	//if (prev == nullptr) {
	//	Add(data); // position이 전체 길이를 벗어나면 마지막에 추가
	//} else {
	//	  newNode->next = prev->next;
	//	  prev->next = newNode;
	//}
}

void LinkedList::Remove(int data){
	// 리스트에서 data를 삭제
	if (head == nullptr) return;

	if (data == 0) {	// 첫번째 노드의 경우
		ListNode* target = head;
		head = target->next;
		delete target;
		return;
	}
	
	ListNode* prev = head;
	int index = 0;

	while (prev != nullptr && index < data - 1)		// 마지막 노드까지 반복
{
		prev = prev->next;
		index++;
}
	if (prev != nullptr && prev->next != nullptr) {  // prev가 nullptr인지 확인
		ListNode* target = prev->next;
		prev->next = prev->next->next;
		delete target;
	}
}

void LinkedList::RemoveAt(int position){
	// 리스트에서 position번째의 노드를 제거(position이 전체길이를 벗어나면 처리안함)
	if (head == nullptr) return;

	if (position == 0) {
		ListNode* target = head;
		head = head->next;
		delete target;
		return;
	}

	ListNode* tail = head;
	int count = 0;
	
	while (tail != nullptr && count < position - 1)		// target이 적절해질 때까지 진행
{
		tail = tail->next;
		count++;
	}
	if (tail != nullptr && tail->next != nullptr) {
		ListNode* target = tail->next;
		tail->next = tail->next->next;
		delete target;
	}
	//ListNode* prev = getNode(position - 1);
	//if (prev != nullptr && prev->next != nullptr) {
	//	ListNode* toDelete = prev->next;
	//	prev->next = prev->next->next;
	//	delete toDelete;
	//}
}

void LinkedList::Clear(){
	// 리스트의 모든 노드를 삭제
	while (head != nullptr)
{
		RemoveAt(0);
}
}

void LinkedList::Print(){
	// 리스트를 처음부터 끝까지 출력하는 함수
	printf("List : ");
	ListNode* node = head;
	while (node != nullptr) {
		//cout << tail->data << " -> ";
		printf("%d -> ", node->data);	// 마지막 노드까지 하나씩 찍기
		node = node->next;
	}
	printf("End\n");
}
//ListNode* LinkedList::getNode(int position) {
//	if (position < 0) return nullptr;
//
//	ListNode* current = head;
//	int index = 0;
//	while (current != nullptr && index < position) {
//		current = current->next;
//		index++;
//	}
//
//	return current;
//}