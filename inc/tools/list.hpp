#pragma once

template <typename elem_t>
struct Node
{
    Node* next;
    Node* prev;

    elem_t value;

    Node(elem_t init_value) : value(init_value), next(nullptr), prev(nullptr) {}
};

template <typename elem_t>
class List
{
private:

    Node<elem_t>* head_;
    Node<elem_t>* tail_;

    int size_;

public:

    List()
    {
        head_ = nullptr;
        tail_ = nullptr;
    };

    Node<elem_t>* head()
    {
        return head_;
    }

    Node<elem_t>* tail()
    {
        return tail_;
    }

    void Append(Node<elem_t>* new_node)
    {   
        ++size_;
        if (head_ == nullptr)
        {
            head_ = new_node;
            tail_ = new_node;
            
            return;
        }
        tail_->next = new_node;
        new_node->prev = tail_;

        tail_ = new_node;

    }

    void Append(elem_t elem)
    {
        Append(new Node<elem_t>(elem));
    }

    void makeHead(Node<elem_t>* node)
    {   
        if (head_ == nullptr)
        {
            head_ = node;
        }
        if (node == head_)
        {
            return;
        }
        if (node->next != nullptr)
        {
            node->next->prev = node->prev;
        }
        if (node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        node->next = head_;
        node->prev = nullptr;

        head_->prev = node;
    }


    void Delete(Node<elem_t>* node)
    {   
        --size_;
        if (node == nullptr) return;

        if (node == tail_ && node == head_)
        {
            head_ = nullptr;
            tail_ = nullptr;

            delete node;
            return;
        }
        if (node == tail_)
        {
            node->prev->next = nullptr;
            tail_ = node->prev;  
        } 
        else if (node == head_)
        {
            node->next->prev = nullptr;
            head_ = node->next;
        } 
        else
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        delete node;
    }

    int size() const
    {
        return size_;
    }

    ~List()
    {
        Node<elem_t>* deletable_node = head_;
        while (head_ != tail_)
        {
            deletable_node = head_;
            head_ = head_->next;

            delete deletable_node;
        }
        delete head_;
    }
};