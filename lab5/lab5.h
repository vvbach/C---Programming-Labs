#pragma once

#include <iostream>
#include "Exception.h"

template<class T>
T findMin(T a, T b){
    return ((a < b) ? a : b);
}

template<int N, class T>
class Queue{
    struct Node
    {
        T data;
        Node* next;
        Node(T d)
        {
            data = d;
            next = nullptr;
        }
    };
private:
    Node* head, *tail;
    int size;
public:
    Queue(){
        head = tail = nullptr;
        size = 0;
    }
    ~Queue(){
        Node* toDelete = head;
        while(toDelete != NULL) {
            Node* next = toDelete->next;
            delete toDelete;
            toDelete = next;
        }
    }
    void Enqueue(T data){
        try{
            if (size == N){
                throw Exception("Queue is full !");
            }
            Node* p = new Node(data);
            if (tail == nullptr){
                head = tail = p;
                size++;
                return;
            }
            tail->next = p;
            tail = p;
            size++;
        }
        catch (Exception &e){
            cout << e.getMessage() << endl;
        }
    }
    void Dequeue(T &data){
        try{
            if (size == 0){
                throw Exception("Queue is empty !");
            }
            Node* q = head;
            data = head->data;
            head = head->next;
            size--;
            if (head == nullptr) tail = nullptr;
            delete q;
        } catch (Exception &e){
            cout << e.getMessage() << endl;
        }
    }
};
