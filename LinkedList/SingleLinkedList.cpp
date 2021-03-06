//Single Linked List

#include <iostream>
#include <cstdlib>

using namespace std;

class StringNode{
private:
    string elem;
    StringNode* next;
    
    friend class StringLinkedList;
};

class StringLinkedList{
private:
    StringNode* head;
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const string& front() const;
    void addFront(const string& e);
    void removeFront();
};

// 생성자 : head노드를 NULL로 초기화시켜줌
StringLinkedList::StringLinkedList() : head(NULL) {}

// 소멸자 : 전부다 없어질때까지 front의 노드 날려버림 (결국 tail까지 다 날리는격!)
StringLinkedList::~StringLinkedList() {
    while (!empty())
        removeFront();
}

// head가 빈다 == 리스트가 빈다 == 1반환
// head에 뭔가 있다 == 리스트에 뭐가 차있네 == 0반환
bool StringLinkedList::empty() const{
    return head == NULL;
}

/* 이전 원소를 얻는다???? */
const string& StringLinkedList::front() const{
    return head->elem;
}

// list의 앞에 node를 추가하는함수
void StringLinkedList::addFront(const std::string &e){
    StringNode* v = new StringNode; // 새로운 노드 생성
    v->elem = e;                    // 데이터 저장
    v->next = head;                 // 지금 head는 v의 뒤에 있다
    head = v;                       // v가 이제 head가 된다
}

// list의 앞의 node를 제거하는함수
void StringLinkedList::removeFront(){
    StringNode* old = head; // 현재 head를 old에 저장
    head = old->next;       // head를 old노드 다음의 노드로 설정
    delete old;             // 이전의 old노드 날려버리기
}
