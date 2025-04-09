#include<bits/stdc++.h>
using namespace std;
#include<conio.h>
class college{

      char name[50];  // Fixed-size character array
    char fname[50]; // Fixed-size character array
    int age;
    int rollno;


    public:
    void input(){
        cin.ignore(); // Clear input buffer
        cout << "Enter the name: ";
        cin.getline(name, 50);
        cout << "Enter the father's name: ";
        cin.getline(fname, 50);
        cout << "Enter the age: ";
        cin >> age;

        do {
            cout << "Enter the roll number (4 digits): ";
            cin >> rollno;
            if (rollno < 1000 || rollno > 9999) {
                cout << "Invalid roll number. Please enter a 4-digit roll number.\n";
            }
        } while (rollno < 1000 || rollno > 9999);

    }
    void output()

    {
        cout<<"NAME :"<<name<<endl;
        cout<<"FATHER NAME :"<<fname<<endl;
        cout<<"AGE :"<<age<<endl;
        cout<<"ROLL NO :"<<rollno<<endl;


    }
    int roll(){
        return rollno;

    }

};
void add(){
    college co;
    int r;
    cout<<"ENTER NUMBER OF RECORD ";
    cin>>r;

    ofstream obj("record.dat",ios::binary | ios::app);

    for(int i=0;i<r;i++){
         co.input();
         obj.write((char *)&co,sizeof(co));

    }
    obj.close();

}
void display(){

 college co;
    ifstream objs("record.dat", ios::binary | ios::in);
    if (!objs) {
        cout << "Error opening file for reading or no records found!" << endl;
        return;
    }

    cout << "\nDisplaying Records:\n\n";
    int recordCount = 0;  // Track the number of records
    while (objs.read((char*)&co, sizeof(co))) {
        co.output();
        cout << endl;
        recordCount++;
    }
    if (recordCount == 0) {
        cout << "No records found in the file." << endl;
    }
    objs.close();
}
void search(){
    cout<<"ENTER ROLL NO. ";
    int r;

    cin>>r;
    college co;
    ifstream objs("record.dat",ios::binary | ios::in);
     if (!objs) {
        cout << "Error opening file for reading or no records found!" << endl;
        return;
    }

    cout << "\nDisplaying Searched Records:\n\n";
    while (objs.read((char*)&co, sizeof(co))) {
        if(r==co.roll()){

            co.output();
        }
        cout << endl;
    }

}
void Delete(){
    int r;
        cout<<"ENTER ROLL NO. ";


    cin>>r;
    college co;
    ifstream objs("record.dat",ios::binary | ios::in);
     if (!objs) {
        cout << "Error opening file for reading or no records found!" << endl;
        return;
    }
    ofstream newdata("newfile.dat",ios::binary | ios::out);
    while(objs.read((char *)&co,sizeof(co))){
        if(r!=co.roll()){
            newdata.write((char *)&co,sizeof(co));

        }
    }
    objs.close();
    newdata.close();
    remove("record.dat");
    rename("newfile.dat","record.dat");

    cout<<"RECORD DELETED SUCCESSFULLY ";

}
void update()
{

     int r;
        cout<<"ENTER ROLL NO. ";


    cin>>r;
    college co;
    ifstream objs("record.dat",ios::binary | ios::in);
     if (!objs) {
        cout << "Error opening file for reading or no records found!" << endl;
        return;
    }
    ofstream newfile("newdata.dat",ios::binary );
    while(objs.read((char *)&co,sizeof(co))){
        if(r==co.roll()){
            co.input();
             cout<<"UPDATE SUCCESSFULLY "<<endl;
        }
        newfile.write((char *) &co,sizeof(co));
    }
    objs.close();
    newfile.close();
    remove("record.dat");
    rename("newdata.dat","record.dat");


}

int main(){
   int choice;
menu:  // Label for the goto statement
    cout << "\n1. Add Records\n2. Display Records\n3. Search Record\n4. Delete Record\n5. Update Record\n6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            add();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            Delete();
            break;
        case 5:
            update();
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
    getch();
    

    goto menu;



}