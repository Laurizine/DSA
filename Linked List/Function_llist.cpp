#include <iostream>
using namespace std;

// Định nghĩa cấu trúc một nút
struct Node {
    int data;      // Dữ liệu
    Node* next;    // Con trỏ trỏ đến nút tiếp theo

    Node(int value) {  // Hàm khởi tạo
        data = value;
        next = nullptr;
    }
};


// Hàm thêm một nút vào đầu danh sách liên kết
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value); // Tạo nút mới
    newNode->next = head;            // Con trỏ của nút mới trỏ đến nút đầu hiện tại
    head = newNode;                   // Cập nhật lại nút đầu
}

// Hàm thêm một nút vào cuối danh sách liên kết
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {  // Nếu danh sách rỗng
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {  // Duyệt đến cuối danh sách
        temp = temp->next;
    }
    temp->next = newNode;  // Gán con trỏ của nút cuối cùng đến nút mới
}

// XÓa phần tử đầu tiên 
void deleteHead(Node*& head) {
    if (head == nullptr) return; // Nếu danh sách rỗng
    Node* temp = head;
    head = head->next; // Cập nhật head
    delete temp; // Giải phóng bộ nhớ
}

//Xóa phần tử có giá trị nhất định
void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;
    if (head->data == value) {  // Nếu nút đầu chứa giá trị cần xóa
        deleteHead(head);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == nullptr) return; // Không tìm thấy giá trị
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}
   
// Duyệt danh sách liên kết
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "NULL"<< endl;
}


// Chạy
int main() {
    Node* head = nullptr; // Khởi tạo danh sách rỗng

    // Thêm phần tử
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printList(head); // Output: 1 -> 2 -> 3 -> NULL

    insertAtTail(head, 4);
    insertAtTail(head, 5);
    printList(head); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    // Xóa phần tử
    deleteHead(head);
    printList(head); // Output: 2 -> 3 -> 4 -> 5 -> NULL

    deleteNode(head, 3);
    printList(head); // Output: 2 -> 4 -> 5 -> NULL

    return 0;
}
