#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>

using namespace std;

class bookshop{

    private:
      struct Node{
         int book_no,copies;
         string name, author, publisher;
         Node *next;
      };

    public:
         Node *head = NULL;
         void menu();
         void Add_book();
         void Search();
         void Update();
         void Delete();
         void Sort();
         void Show();

};
void bookshop::menu(){

    p:
    int choice;
    system("cls");
    cout<<"\n\n\n\n\t\t\tControl Panel"<<endl;
    cout<<"\n\n\t1.Add New Book"<<endl;
    cout<<"\n\n\t2.Check Spacific Book"<<endl;
    cout<<"\n\n\t3.Update Book"<<endl;

    cout<<"\n\n\t4.Delete Book"<<endl;
    cout<<"\n\n\t5.Show All Book"<<endl;
    cout<<"\n\n\t6.Exit"<<endl;
    cout<<"\n\n\t\tEnter Your Choice  : ";
    cin>>choice;
    switch(choice){
        case 1:
            Add_book();
        break;

        case 2:
            Search();
        break;

        case 3:
            Update();
        break;

        case 4:
            Delete();
        break;

        case 5:
            Sort();
            Show();
        break;

        case 6:
          exit(0);

        default:
        cout<<"\n\tInvlute Value....Please Try Again";
    }
    getch();
        goto p;
}

void bookshop::Add_book()
{
    system("cls");
    cout<<"\t\t\tDATA\n";
    Node *new_node = new Node;
    cout<<"\tBook No         : ";
    cin>> new_node -> book_no;
    cout<<"\tBook Name       : ";
    cin>> new_node -> name;
    cout<<"\tAuthor Name     : ";
    cin>> new_node -> author;
    cout<<"\tPublisher name  : ";
    cin>> new_node -> publisher;
    cout<<"\tNo. Of Copies   : ";
    cin>>new_node -> copies;
    new_node -> next = NULL;           //  Laster node ta null ke point korbr

    if(head == NULL){
        head = new_node;
    }
    else{
        Node *prev_node = head;
        while(prev_node -> next != NULL){
            prev_node = prev_node -> next;
        }
        prev_node -> next = new_node;
    }
    cout<<"\t\t\tNew Book Add Successfully.";
}

void bookshop::Search()
{
    system("cls");
    int Book_no, found = 0;
    cout<<"\t\t\tDATA\n";
    if(head == NULL){
        cout<<"List is Empty.";
    }
    else{
        cout<<"Find Book No : ";
        cin>>Book_no;
        Node *ptr = head;
        while(ptr != NULL){
            if(ptr -> book_no == Book_no){
                system("cls");
                cout<<"\t\tDATA\n";
                cout<<"\nBook No        : "<<ptr -> book_no;
                cout<<"\nBook Name      : "<<ptr -> name;
                cout<<"\nAuthor Name    : "<<ptr -> author;
                cout<<"\nPublisher Name : "<<ptr -> publisher;
                cout<<"\nNo. Of Copies  : "<<ptr -> copies;
                found ++;
            }
            ptr = ptr -> next;
        }
        if(found == 0){
            cout<<"\n\n\t\tBook is not found.";
        }
    }

}

void bookshop :: Update()
{
    system("cls");
    int Book_no, found = 0;
    cout<<"\t\t\tDATA\n";
    if(head == NULL){
        cout<<"List is Empty.";
    }
    else{
        cout<<"Find Book No : ";
        cin>>Book_no;
        Node *ptr = head;
        while(ptr != NULL){
            if(ptr -> book_no == Book_no){
                system("cls");
                cout<<"\t\tDATA\n";
                cout<<"\nBook No        : ";
                cin >> ptr -> book_no;
                cout<<"\nBook Name      : ";
                cin >> ptr -> name;
                cout<<"\nAuthor Name    : ";
                cin >> ptr -> author;
                cout<<"\nPublisher Name : ";
                cin >> ptr -> publisher;
                cout<<"\nNo. Of Copies  : ";
                cin >> ptr -> copies;
                found ++;
                cout << "Book Update Succesfully.";
            }
            ptr = ptr -> next;
        }
        if(found == 0){
            cout<<"\n\n\t\tBook is not found.";
        }
    }
}

void bookshop :: Delete()
{
    system("cls");
    int Book_no, found = 0;
    cout<< "\t\tDATA\n";
    if(head == NULL){
        cout << "List is Empty.";
    }
    else{
        cout << "\nDelete The No of Book : ";
        cin >> Book_no;
        if(Book_no == head -> book_no){
            Node *ptr = head;
            head = head -> next;
            delete ptr;
            cout << "Delete Book Successfully.";
            found++;
        }
        else{
            Node *prev = head;
            Node *ptr = head;
            while(ptr != NULL){
                if(Book_no == ptr -> book_no){
                    prev -> next = ptr -> next;
                    delete ptr;
                    cout << "Delete Book Succeccfully."<<endl;
                    found++;
                    break;
                }
                prev = ptr;
                ptr = ptr -> next;
            }
        }
        if(found == 0){
            cout << "Book No. is invalid."<<endl;
        }
    }
}

void bookshop :: Sort()
{
     system("cls");
     if(head == NULL){
        cout << "List is empty."<<endl;
        getch();
        menu();
     }
     int test_b_no,test_copies;
     string test_name, test_author, test_publisher;
     Node *ptr = head,*cpt;

     while(ptr -> next != NULL){
        cpt = ptr -> next;
        while(cpt != NULL){
            if(ptr -> book_no > cpt -> book_no){

               test_b_no = ptr -> book_no;
               test_name = ptr -> name;
               test_author = ptr -> author;
               test_publisher = ptr -> publisher;
               test_copies = ptr -> copies;

               ptr -> book_no = cpt -> book_no;
               ptr -> name = cpt -> name;
               ptr -> author = cpt -> author;
               ptr -> publisher = cpt -> publisher;
               ptr -> copies = cpt -> copies;

               cpt -> book_no = test_b_no;
               cpt -> name = test_name;
               cpt -> author = test_author;
               cpt -> publisher = test_publisher;
               cpt -> copies = test_copies;
            }
            cpt = cpt -> next;
        }
        ptr = ptr -> next;
     }
}


void bookshop :: Show()
{
    system("cls");
    cout<<"\t\t\tDATA\n";
        Node *ptr = head;
        while(ptr != NULL){
                cout<<"\nBook No        : "<<ptr -> book_no;
                cout<<"\nBook Name      : "<<ptr -> name;
                cout<<"\nAuthor Name    : "<<ptr -> author;
                cout<<"\nPublisher Name : "<<ptr -> publisher;
                cout<<"\nNo. Of Copies  : "<<ptr -> copies<<endl;
                cout << "############################"<<endl;
                ptr = ptr -> next;
            }


}

int main()
{
    bookshop obj;
    obj.menu();
}
