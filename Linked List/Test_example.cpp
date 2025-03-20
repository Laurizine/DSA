#include <iostream>
using namespace std;

// Cấu trúc của một nút trong danh sách liên kết
struct Node {
    string customerName;  // Tên khách hàng
    Node* next;           // Con trỏ trỏ đến khách hàng tiếp theo

    Node(string name) {  // Hàm khởi tạo
        customerName = name;
        next = nullptr;
    }
};

// Lớp Queue sử dụng danh sách liên kết đơn
class Queue {
private:
    Node* front; // Con trỏ đầu hàng đợi
    Node* rear;  // Con trỏ cuối hàng đợi

public:
    Queue() {
        front = rear = nullptr;
    }

    // Thêm khách hàng vào cuối danh sách
    void enqueue(string name) {
        Node* newNode = new Node(name);
        if (rear == nullptr) {  // Nếu danh sách rỗng
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Phục vụ khách hàng đầu tiên và xóa khỏi danh sách
    void dequeue() {
        if (front == nullptr) {  // Nếu danh sách rỗng
            cout << "Không có khách hàng nào trong danh sách chờ!\n";
            return;
        }
        Node* temp = front;
        front = front->next; // Di chuyển con trỏ front

        if (front == nullptr) // Nếu danh sách giờ rỗng, cập nhật rear
            rear = nullptr;

        cout << "Đã phục vụ khách hàng: " << temp->customerName << endl;
        delete temp;
    }

    // Hiển thị danh sách chờ
    void display() {
        if (front == nullptr) {
            cout << "Danh sách chờ trống.\n";
            return;
        }
        Node* temp = front;
        cout << "Danh sách khách hàng chờ:\n";
        while (temp != nullptr) {
            cout << "- " << temp->customerName << endl;
            temp = temp->next;
        }
    }
};


int main() {
    Queue bankQueue; // Tạo danh sách chờ

    // Thêm khách hàng vào danh sách
    bankQueue.enqueue("Nguyễn Văn A");
    bankQueue.enqueue("Trần Thị B");
    bankQueue.enqueue("Lê Văn C");

    // Hiển thị danh sách khách hàng đang chờ
    bankQueue.display();

    // Phục vụ khách hàng đầu tiên
    bankQueue.dequeue();
    
    // Hiển thị lại danh sách chờ sau khi phục vụ một khách
    bankQueue.display();

    return 0;
}
