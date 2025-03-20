#include <iostream>
using namespace std;

// Lớp Node đại diện cho một phần tử trong danh sách liên kết
class Node {
public:
    int data;   // Dữ liệu của nút
    Node* next; // Con trỏ trỏ đến nút tiếp theo

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Lớp LinkedList chứa các phương thức thao tác với danh sách liên kết
class LinkedList {
private:
    Node* head; // Con trỏ đầu danh sách

public:
    // Constructor - Khởi tạo danh sách rỗng
    LinkedList() {
        head = nullptr;
    }

    // Thêm phần tử vào đầu danh sách
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Thêm phần tử vào cuối danh sách
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) { // Nếu danh sách rỗng
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) { // Duyệt đến cuối danh sách
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Xóa phần tử đầu tiên
    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Xóa phần tử theo giá trị
    void deleteNode(int value) {
        if (head == nullptr) return;

        if (head->data == value) { // Nếu giá trị cần xóa nằm ở đầu danh sách
            deleteHead();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return; // Không tìm thấy giá trị cần xóa

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Hiển thị danh sách
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor - Giải phóng bộ nhớ khi chương trình kết thúc
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(1);
    list.insertAtHead(2);
    list.insertAtHead(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    list.printList(); // 3 -> 2 -> 1 -> 4 -> 5 -> NULL

    list.deleteHead();
    list.deleteNode(4);

    list.printList(); // 2 -> 1 -> 5 -> NULL

    return 0;
}