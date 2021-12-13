//
// Created by Shayo on 6/5/2019.
//

#ifndef DYNAMICARRAY_LINKEDLIST_H
#define DYNAMICARRAY_LINKEDLIST_H

#include <stdio.h>

template<class T>
class ListNode{
    ListNode<T>* next;
    T data;
};

template<class T>
class LinkedList {
private:
    ListNode<T> *hd;
    ListNode<T> *tl;
    int size;
public:
    /*
     * Constructor without parameters
     */
    LinkedList<T>() : hd(NULL), tl(NULL), size(0) {};
    void insert(T new_){
        size++;
        if(!hd){
            hd = new ListNode<T>;
            hd->data = new_;
            hd->next = NULL;
            tl = hd;
        }else{
            if(hd == tl){
                tl = new ListNode<T>;
                tl->data=new_;
                tl->next=NULL;
                hd->next=tl;
            }else{
                ListNode<T> *node= new ListNode<T>;
                node->data = new_;
                node->next = NULL;
                tl->next=node;
                node->next=NULL;
            }
        }
    }

    bool exist(T want){
        if(!hd){
            return false;
        }
        ListNode<T> *node = hd;
        while(node!=tl){
            if(node->data==want)
                return true;
            node = node->next;
        }
        return false;

    }

    ListNode<T> *get(T want){
        if(!hd)
            return NULL;
        ListNode<T> *node = hd;
        while(node!=tl){
            if(node->data==want)
                return node;
            node = node->next;
        }
        return NULL;
    }

    ~LinkedList(){
        while(hd!=tl){
            ListNode<T> *tmp = hd;
            hd = hd->next;
            delete tmp;
        }
        delete tl;
    }

};


#endif //DYNAMICARRAY_LINKEDLIST_H
