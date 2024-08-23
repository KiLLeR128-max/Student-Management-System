#include<iostream>
#include<vector>
using namespace std;
class Student{
    private:
        int age,rollno;
        string name;
    public:
        Student(int stdRollno,int stdAge,string stdName){
            rollno=stdRollno;
            age=stdAge;
            name=stdName;
        }
        void setRollno(int stdRollno){
            rollno=stdRollno;
        }
        int getRollno(){
            return rollno;
        }
        void setAge(int stdAge){
            age=stdAge;
        }
        int getAge(){
            return age;
        }
        void setName(string stdName){
            name=stdName;
        }
        string getName(){
            return name;
        }
        void displayStudent(){
            cout<<"Roll No : "<< rollno << endl;
            cout<<"Age : "<<age<<endl;
            cout<<"Name : "<<name<<endl;
        }
};
//Create func to add a new a Student
void addNewStudent(vector<Student> &students){
    int rollno;
    int age;
    string name;

    cout<<"Enter Roll Number: ";
    cin>>rollno;
    cout<<"Enter Age: ";
    cin >>age;
    cout<<"Enter Name: ";
    cin>>name;
    //check if the student already exists
    for(int i=0;i<students.size();i++){
        if (students[i].getRollno()==rollno){
            cout<<"Student already exists with roll number "<< rollno <<endl;
            return;
        }
    }

    Student newStudent(rollno,age,name);
    students.push_back(newStudent);

    cout<< "Student Is Added Successfully..."<<endl;
    
};
// Create func for Displaying the student
void DisplayStudent(vector<Student> &students)
{
    int rollno;
    int age;
    string name;
    if (students.empty()){
        cout<<"No Student Found"<<endl;
        return;
    }
    for (int i=1;i<students.size();i++){
        students[i].displayStudent();
        cout<<endl;
    }
};
main(){
    vector<Student> students;
    students.push_back(Student(1,20,"Deb"));
    char choice;
    
    do{
        //----------------
        system("cls");
        int option;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Display all Student"<<endl;
        cout<<"3. Search a Student"<<endl;
        cout<<"4. Update a Student"<<endl;
        cout<<"5. Delete Student"<<endl;
        cout<<"6. Exit System"<<endl;
        cout<<"Enter Your option"<<endl;
        
        cin>>option;
        //----------------
        switch(option){
            case 1:
                addNewStudent(students);
                break;
            case 2:
                DisplayStudent(students);
                break;
            case 6:
                exit(1);
            default:
                cout<<"Invalid Option"<<endl;
        }
        cout<<"Do You Want To Continue -->[Yes (Y) / No (N)] ?";
        cin>>choice;
    }
    while(choice =='Y' || choice =='y' );

}