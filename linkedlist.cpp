#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*first = NULL;

void create(int A[], int n) {
    // for last node ptr
    struct Node *last, *t;
    
    // first Node ptr
    first = new Node;
    // first.data = A[0]
    first -> data = A[0];
    // first.next = NULL
    first -> next = NULL;
    
    last = first;
    
    for (int i{1}; i<n;i++) {
        // temp Node ptr
        t = new Node;
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while ( p!= NULL) {
        cout << (p -> data) << " ";
        p = p -> next;
    }
    cout << endl;
}

void rec_display(struct Node *p) {
    if ( p!= NULL ) {
        cout << (p -> data) << " ";
        rec_display(p -> next);
    }
    cout << endl;
}

int count_nodes(struct Node *p) {
    int count{0};
    
    while ( p != NULL ) {
        count++;
        p = p -> next;
    }
    return count;
}

void sum(struct Node *p) {
    int total{0};
    
    while ( p != NULL ) {
        total += ( p -> data );
        p = p -> next;
    }
    cout << "The Linked Lists total is " << total << "." << endl;
}

void max(struct Node *p) {
    int max{0};
    max = ( p-> data );
    
    while ( p != NULL ) {
        if (max < ( p -> data) ) 
            max = ( p -> data );
        p = p -> next;
    }
    cout << "The Linked Lists max integer is " << max << "." << endl;
}

void search(struct Node *p, int value) {
    while ( p != NULL ) {
        if ( value == p -> data) {
            cout << value << " is located at address " << (p) << endl;
            return;
        }
            
        p = p -> next;
    }
    cout << value << " was not found in the linked list." << endl;
}

/*void insert(struct Node *p, int pos, int value) {
    Node *t = new Node;
    t -> data = value;
    p = first;
    
    for (int i{0}; i < pos-1; i++)
        p = p -> next;
        
    t -> next = p -> next;
    p -> next = t;
}*/


void insert(struct Node *p, int index, int val) {
    Node *t = new Node;
    
    // for non valid index
    if (index < 0 || index > count_nodes(p))
        return;
        
    t -> data = val;
    // insert as first node in linked list
    if (index == 0) {
        t -> next = first;
        first = t;
    } else {
        for (int i{0}; i < index -1; i++) 
            p = p-> next;
        t -> next = p -> next;
        p -> next = t;
    }
}

bool is_sorted(struct Node *p) {
    // lowest possible int for checking
    int x = -65536;
    
    while (p != NULL) {
        if (p -> data < x) 
            return false;
        x = p -> data;
        p = p -> next;
    }
    return true;
}

void insert_into_sorted(struct Node *p, int val) {
    
    // head node
    Node *t = new Node;
    t -> data = val;
    t -> next = NULL;
    // following tail node
    Node *q = new Node;
    
    // if the linked list is empty
    if (first == NULL)
        first = t;
     else { // check to see order in linked list
         while (p && p -> data < val) {
             q = p;
             p = p -> next;
         } // if the value is the first node in the list
         if ( p == first ) {
             t -> next = first;
             first = t;
         }
         else {
             t -> next = q -> next;
             q -> next = t;
         }
    }
}

// A return of -1 is a fail
int del(struct Node *p, int index) {
    
    // for non valid index
    if (index < 0 || index > count_nodes(p))
        return -1;
        
    // tailing pointer
    struct Node *q = NULL;
    // used for deleting a value
    int del_val = -1;
    
    // if first node
    if (index == 1) {
        q = first;
        del_val = first -> data;
        first = first -> next;
        delete q;
        return del_val;
    } else {
        for (int i{0}; i < index - 1; i++) {
            q = p;
            p = p -> next;
        }
        q -> next = p -> next;
        del_val = p -> data;
        delete p;
        return del_val;
    }
}

void remove_dupes(struct Node *p) {
    // this is the pointer that leads p
    struct Node *q = p -> next;
    
    while (q != NULL) {
        // if not a duplicate
        if (p -> data != q -> data) {
            p = q;
            q = q -> next;
        }
        // they are duplicates
        else {
            p -> next = q -> next;
            delete q;
            q = p -> next;
        }
    }
}


void reverse_linkedlist(struct Node *p) {
    // for traversing linked list
    struct Node *q = NULL;
    struct Node *r = NULL;
    // p points on first node
    while ( p != NULL ) {
        r = q;
        q = p;
        p = p -> next;
        q -> next = r;
    }
    first = q;
}

// just like function above, but done recursively
void recursive_reverse(struct Node *q, struct Node *p) {
    
    // if not null
    if (p) {
        recursive_reverse(p, p-> next);
        p -> next = q;
    } else {
        first = q;
    }
}




int main() {
    
    int A[] = { 3, 5, 7, 10, 15, -1, 7 };
    
    create(A,7);
    
    display(first);
    cout << endl;
    rec_display(first);
    cout << endl;
    cout << "There are " << count_nodes(first) << " items in the linked list." << endl;
    cout << endl;
    sum(first);
    cout << endl;
    max(first);
    search(first, -1);
    cout << endl;
    search(first, 9000);
    insert(first, 0, 555);
    cout << endl;
    display(first);
    insert(first, 8, 595);
    cout << endl;
    display(first);
    insert(first, 7, 333);
    cout << endl;
    display(first);
    cout << "There are " << count_nodes(first) << " items in the linked list." << endl;
    
        {
        if (is_sorted(first)) {
            cout << "This linked list is sorted." << endl;
        } else cout << "This linked list is not sorted." << endl;
    }
    
    int B[] = { -1, 0, 3, 4, 7, 11 };
    create(B, 6);
    display(first);
    insert_into_sorted(first, 2);
    display(first);
    insert_into_sorted(first, -3);
    display(first);
    del(first, 1);
    display(first);
    del(first, 3);
    display(first);
    
    {
        if (is_sorted(first)) {
            cout << "This linked list is sorted." << endl;
        } else cout << "This linked list is not sorted." << endl;
    }
    
    int C[] = { -69, -69, 0, 0, 420, 420, 33333, 333, 3 };
    create (C, 9);
    display(first);
    remove_dupes(first);
    display(first);
    cout << "NEWNEWNEWNEWNEWNEWNEWNEW\n\n" << endl;
    reverse_linkedlist(first);
    display(first);
    // must pass NULL to the recursive reverse
    recursive_reverse(NULL, first);
    display(first);

    
    return 0;
}