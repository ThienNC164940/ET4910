#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;



vector<std::string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

class Person
{
protected:
	string name;
	string address;
	int years;
public:
	Person() {};
	~Person() {};
	virtual void Prin() = 0;
	friend class Manager;
	
};


class Student : public Person
{
public:
	string Code_s;
	string Mom_name;
public:
	Student(){};
	~Student(){};
	void Prin(){};
	
};
class Teacher : public Person{
public:
	string Subject;
	Teacher(){};
	~Teacher(){};
	void Prin(){};

	
};
class Manager 
{
public:
	std::vector<shared_ptr<Person>> v;
	Manager(){};
	~Manager(){};
	void Add_S(){
		shared_ptr<Student> P = make_shared<Student>();
		cout<<"name : "<<endl;
		cin>>P->name;
		cout<<"address : "<<endl;
		cin>>P->address;
		cout<<"years : "<<endl;
		cin>>P->years;
		cin.clear();
		cin.ignore(1000,'\n');
		cout<<"Code : "<<endl;
		cin>>P->Code_s;
		cout<<"Mother's name : "<<endl;
		cin>>P->Mom_name;

		//shared_ptr<Person> PP = dynamic_pointer_cast<Person>(P);
		v.push_back(P);
	}
	
	void Add_T(){
		shared_ptr<Teacher> T = make_shared<Teacher>();
		cout<<"name : "<<endl;
		cin>>T->name;
		cout<<"address : "<<endl;
		cin>>T->address;
		cout<<"years : "<<endl;
		cin>>T->years;
		cin.clear();
		cin.ignore(1000,'\n');
		cout<<"Subject : "<<endl;
		cin>>T->Subject;
		//shared_ptr<Person> PP = dynamic_pointer_cast<Person>(T);
		v.push_back(T);
	}
	bool check(shared_ptr<Person> p){
		if(dynamic_pointer_cast<Teacher>(p)==NULL){
			return true;
		}
		else{
			return false;
		}
	}

	int Delet(){
		string S;
		cout<<"Nhap code : "<<endl;
		cin>>S;
		for (int i = 0; i < v.size(); ++i)
		{
			if(check(v[i])){
				shared_ptr<Student> PP = dynamic_pointer_cast<Student>(v[i]);
				for (int i = 0; i < S.size(); ++i)
				{
					if(S[i]!=PP->Code_s[i]){
						cout<<"Empty"<<endl;
						return 1;
					}

				}
				v.erase(v.begin()+i);
			}

		}
		cout<<"Success"<<endl;
		


	}
	// 
	int Print_v(){
		string S;
		cout<<"Nhap code de hien thi : "<<endl;
		cin>>S;
		for (int i = 0; i < v.size(); ++i)
		{
			if(check(v[i])){
				shared_ptr<Student> PP = dynamic_pointer_cast<Student>(v[i]);
				for (int i = 0; i < S.size(); ++i)
				{
					if(S[i]!=PP->Code_s[i]){
						cout<<"Empty"<<endl;
						return 1;
					}

				}
				cout<<"Name : "<<PP->name<<"\t|\t"<<"I'm Student \t|\t address : "<<PP->address<<"\t|\t Years : "<<PP->years<<"\t|\t Code : "<<PP->Code_s<<"\t|\t Mom's name : "<<PP->Mom_name<<endl;
				
			}

		}
	}
	void print_E(){
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i]<<endl;
		}
	}
	void Print_ALL(){
		for (int i = 0; i < v.size(); ++i)
		{
			if(check(v[i])){
				shared_ptr<Student> PP = dynamic_pointer_cast<Student>(v[i]);
				cout<<"Name : "<<PP->name<<"\t|\t"<<"address : "<<PP->address<<"\t|\t Years : "<<PP->years<<"\t|\t Code : "<<PP->Code_s<<"\t|\t Mom's name : "<<PP->Mom_name<<"\t|\tI'm Student"<<endl;
				
			}
			else{
				shared_ptr<Teacher> PP = dynamic_pointer_cast<Teacher>(v[i]);
				cout<<"Name : "<<PP->name<<"\t|\t"<<"address : "<<PP->address<<"\t|\t Years : "<<PP->years<<"\t|\t Subject : "<<PP->Subject<<"\t|\t I'm Teacher"<<endl;
			}
			//cout<<typeid(v[i]).name()<<endl;
		}
	}
	int update_Mom_name(){
		string S;
		cout<<"Nhap code de thay ten : "<<endl;
		cin>>S;
		for (int i = 0; i <v.size() ; ++i)
		{
			if(check(v[i])){
				shared_ptr<Student> PP = dynamic_pointer_cast<Student>(v[i]);
				for (int i = 0; i < S.size(); ++i)
				{
					if(S[i]!=PP->Code_s[i]){
						cout<<"Empty"<<endl;
						return 1;
					}

				}
				cout<<"Update Mom_name : "<<endl;
				cin>>PP->Mom_name;
			}
		}

	}
	void Writing(){
		ofstream file_obj;
		file_obj.open("test.txt", ios::app);
		for (int i = 0; i < v.size(); ++i)
		{
			if(check(v[i])){
				shared_ptr<Student> PP = dynamic_pointer_cast<Student>(v[i]);
				file_obj << PP->name <<"|"<<PP->address<<"|"<<PP->years<<"|"<<PP->Code_s<<"|"<<PP->Mom_name<<"|"<<"I'm Student \n";
			}
			else{
				shared_ptr<Teacher> PP = dynamic_pointer_cast<Teacher>(v[i]);
				file_obj << PP->name <<"|"<<PP->address<<"|"<<PP->years<<"|"<<PP->Subject<<"|"<<"I'm Teacher";
			}
		}
		cout<<"Success"<<endl;
	}
	void Reading(){
		ifstream file("/home/bb3/c++/day10/sharepointer/test.txt");
		
    	string line;
 		int index = 0;
    	while (getline(file, line)) {
			
			vector<string> S_line = split(line,"|");
			cout<<"SIZE : "<<S_line.size()<<endl;
			cout<<S_line[0]<<"|"<<S_line[1]<<"|"<<S_line[2]<<"|"<<S_line[3]<<"|"<<endl;

			if(S_line.size()==5){
				shared_ptr<Teacher> P = make_shared<Teacher>();
				P->name = S_line[0];
				P->address = S_line[1];
				P->years = stoi(S_line[2]);
				P->Subject = S_line[3];
				v.push_back(P);
				

			}
			if(S_line.size()==6){
				
				shared_ptr<Student> P = make_shared<Student>();
				P->name = S_line[0];
				P->address = S_line[1];
				P->years = stoi(S_line[2]);
				P->Code_s = S_line[3];
				P->Mom_name = S_line[4];
				v.push_back(P);
				

			}
			if(S_line.size()==0){
				break;
			}
			
    	}
    	
    	file.close();
    	cout<<"size = "<<v.size()<<endl;

	}
	void check_size(){
		cout<<"V = "<<v.size()<<endl;
	}
	
};




int main(int argc, char const *argv[])
{
	Manager A;
	NHAN:
	int chon;

	while(true){
		fflush(stdin);
		cout<<"Chon chuc nang"<<endl;
		cout<<"1. Them sv"<<endl;
		cout<<"2. Them gv"<<endl;
		cout<<"3. Xoa SV"<<endl;
		cout<<"4. Cap nhat ten me"<<endl;
		cout<<"5. In ten theo code "<<endl;
		cout<<"6. In ca danh sach"<<endl;
		cout<<"7. Thoat"<<endl;
		cout<<"8. Writing file (text)"<<endl;
		cout<<"9. Reading file (text)"<<endl;
		cin>>chon;
		cin.clear();
    	cin.ignore(9999,'\n');

		switch(chon){
			case 1 : A.Add_S(); continue;
			case 2 : A.Add_T(); continue;		
			case 3 : A.Delet(); continue;
			case 4 : A.update_Mom_name(); continue;
			case 5 : A.Print_v(); continue;
			case 6 : A.Print_ALL(); continue;
			case 7 : exit(0);
			case 8 : A.Writing(); continue;
			case 9 : A.Reading(); continue;
			case 10 : A.check_size(); continue;
	}		
	}


	

	return 0;
	
	
}
