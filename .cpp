#include <iostream>
using namespace std;
struct student
{
    string name;
    int roll_no;
    float cgpa;

    student *next;
};
class dsa_class
{
public:
    student *head;

    int N;
    dsa_class()
    {
        head = NULL;
        N = 0;
    }
    ~dsa_class()
    {
    }
    student *input_student()
    {
        student *new_node = new student;
        cout << "Enter name :";
        cin >> new_node->name;
        cout << "Enter roll no  :";
        cin >> new_node->roll_no;
        cout << "Enter cgpa :";
        cin >> new_node->cgpa;
        return new_node;
    }
    void add_front()
    {
        student *new_node = input_student();
        
        new_node->next = head;
        head = new_node;
        N++;
        new_node = NULL;
    }
    void delete_front()
    {
        if (head != NULL)
        {
            student *temp = head;
            head = head->next;
            delete temp;
            N--;
            temp = NULL;
        }
        else
        {
            cout << "Linked list is empty :" << endl;
        }
    }
    void push()
    {
        add_front();
    }
    void pop()
    {
        delete_front();
    }
    student *top()
    {
        return head;
    }
    bool empty()
    {
        return (N == 0);
    }
    int size()
    {
        return N;
    }
    void dsiplay_student_inserted()
    {
          student *temp = head;
        
           cout << "\tName \tRoll_no\tCgpa " << endl;
           while (temp != NULL)
           {
               cout << "\t" << temp->name << "\t" << temp->roll_no << "\t" << temp->cgpa << endl;
               temp = temp->next;
            }
    }
};
int main()
{
    dsa_class obj;
    for (int i = 0; i < 3; i++)
        obj.push();
    obj.dsiplay_student_inserted();
    obj.pop();
    obj.dsiplay_student_inserted();
    obj.pop();
    obj.dsiplay_student_inserted();
}
