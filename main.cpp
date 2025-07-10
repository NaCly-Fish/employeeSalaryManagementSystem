#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class Staff {
	protected:
		string number;
		string name;
		string sex;
		string address;
		int salary;
		static int sum_salary; //总工资
		static int sum_member; //总员工人数
	public:
		Staff();
		Staff(string number,string name,string sex,string address,int salary);

		void print() {};
		void setnumber(string num) {
			number=num;
		}
		void setname(string na) {
			name=na;
		}
		void setsex(string se) {
			sex=se;
		}
		void setaddress(string add) {
			address=add;
		}
		void setsalary(int sa) {
			salary=sa;
		}

		int getsalary();
		string getname() {
			return name;
		}
		string getnumber() {
			return number;
		}
		string getsex() {
			return sex;
		}
		string getaddress() {
			return address;
		}
};

Staff::Staff() {
	number="";
	name="";
	sex="";
	address="";
	salary=0;
}


Staff::Staff(string number,string name,string sex,string address,int salary) {
	this->number = number;
	this->name = name;
	this->sex = sex;
	this->address = address;
	this->salary = salary;
}
int Staff::getsalary() {
	return salary;
}




class Regular_staff:public Staff {
	protected:
		int allowance; //岗位津贴
		int old_age_pension; //养老金
		int Housing_Fund; //住房公积金
		int medical_insurance; //医疗保险
		int tax;
		int r_salary; //实际工资
	public:
		Regular_staff();
		Regular_staff(string num,string na,string sex,string add,int salary,int all ,int oap, int Hou, int med);
		void getr_salary();										//计算实发工资
		void gettax();
		int getreal() {
			return r_salary;
		}
		void setallowance(int all) {
			allowance=all;
		}
		void setold_age_pension(int oap) {
			old_age_pension=oap;
		}
		void setHousing_Fund(int Hou) {
			Housing_Fund=Hou;
		}
		void setmedical_insurance(int med) {
			medical_insurance=med;
		}
		void display() {
			cout<<"员工编号："<<number<<"\t"<<"姓名："<<name<<"\t"<<"性别："<<sex<<endl;
			cout<<"地址："<<address<<endl;
			cout<<"岗位津贴："<<allowance<<"\t"<<"养老金："<<old_age_pension<<endl;
			cout<<"住房公积金："<<Housing_Fund<<"\t"<<"医疗保险："<<medical_insurance<<endl;
			cout<<"本月税后实际工资："<<r_salary<<endl;
		}

		int getallowance() {
			return allowance;
		}
		int getold_age_pension() {
			return old_age_pension;
		}
		int getHousing_Fund() {
			return Housing_Fund;
		}
		int getmedical_insurance() {
			return medical_insurance;
		}


} rs[10000];


Regular_staff::Regular_staff() {
	number="";
	name="";
	sex="";
	address="";
	salary=0;
	allowance=0;
	old_age_pension=0;
	Housing_Fund=0;
	medical_insurance=0;
}

void Regular_staff::gettax() {

	this->salary = getsalary();
	if (salary<5000) {
		tax=0;
	}
	if (salary>5000&&r_salary<41000) {
		tax=(salary-5000)*0.03;
	}
	if (salary>41000&&r_salary<149000) {
		tax=(salary-41000)*0.1+2520;
	}
	if (salary>149000&&r_salary<305000) {
		tax=(salary-149000)*0.2+16920;
	}
	if (salary>305000&&r_salary<425000) {
		tax=(salary-305000)*0.25+31920;
	}
	if (salary>425000&&r_salary<665000) {
		tax=(salary-425000)*0.3+52920;
	}
	if (salary>665000&&r_salary<965000) {
		tax=(salary-665000)*0.35+85920;
	}
	if (salary>965000) {
		tax=(salary-965000)*0.45+181920;
	}
}

Regular_staff::Regular_staff(string num,string na,string sex,string add,int salary,int all ,int oap, int Hou, int med) : Staff(num,na ,sex, add ,salary) {
	this->allowance = all;
	this->old_age_pension = oap;
	this->Housing_Fund = Hou;
	this->medical_insurance = med;
	gettax();
	r_salary = getsalary()+allowance-old_age_pension-Housing_Fund-medical_insurance-tax;

}
void Regular_staff::getr_salary() {
	r_salary = getsalary()+allowance-old_age_pension-Housing_Fund-medical_insurance-tax;
}





class Temporary_staff:public Staff {
	protected:
		int bonus; //奖金
		int tax;
		int r_salary; //实际工资
	public:
		Temporary_staff();
		Temporary_staff(string num,string na,string sex,string add,int salary,int bo );
		void gettax();
		int getr_salary();
		int getreal() {
			return r_salary;
		}
		void setbonus(int bo) {
			bonus=bo;
		}
		void display() {
			cout<<"员工编号："<<number<<"\t"<<"姓名："<<name<<"\t"<<"性别："<<sex<<endl;
			cout<<"地址："<<address<<endl;
			cout<<"奖金："<<bonus<<endl;
			cout<<"本月税后实际工资："<<r_salary<<endl;
		}

		int getbonus() {
			return bonus;
		}


} ts[10000];

Temporary_staff::Temporary_staff() {
	number="";
	name="";
	sex="";
	address="";
	salary=0;
	bonus=0;
}

void Temporary_staff::gettax() {

	if (salary<5000) {
		tax=0;
	}
	if (salary>5000&&salary<41000) {
		tax=(salary-5000)*0.03;
	}
	if (salary>41000&&salary<149000) {
		tax=(salary-41000)*0.1+2520;
	}
	if (salary>149000&&salary<305000) {
		tax=(salary-149000)*0.2+16920;
	}
	if (salary>305000&&salary<425000) {
		tax=(salary-305000)*0.25+31920;
	}
	if (salary>425000&&salary<665000) {
		tax=(salary-425000)*0.3+52920;
	}
	if (salary>665000&&salary<965000) {
		tax=(salary-665000)*0.35+85920;
	}
	if (salary>965000) {
		tax=(salary-965000)*0.45+181920;
	}
}
Temporary_staff::Temporary_staff(string num,string na,string sex,string add,int salary,int bo ) : Staff(num ,na ,sex, add ,salary) {
	this->bonus = bo;
	gettax();
	r_salary =salary + bonus - tax;				//计算最终工资

}




void print_Begin() {
	printf("\n\t\t 职工工资管理系统\n\n");
	printf("**************************************************\n\n");
	printf("1 查找员工信息\n\n2 更新员工数据\n\n3 输出员工信息\n\n4 关闭程序\n\n");
	printf("**************************************************\n\n");
	printf("请选择：");
}

void loading() {
	printf("\n\n\t\tLoading......\n\n\n");
	printf(" ");
	for (int i = 1; i <= 40; ++i) {
		printf(".");
		Sleep(50); //延迟输出
	}
	printf(" ");
}

void cls() { //清屏加修改颜色
	system("cls");
	system("color 0B");
}

void refresh() {
	cls();
	print_Begin();
}

int x=0;


void get_rstxt() {										//读取正式员工的数据
	fstream f;
	f.open("Regular_staff.txt",ios::in);
	string num;
	string na;
	string sex;
	string add;
	int salary;
	int all ;
	int oap;
	int Hou;
	int med;
	int i;
	for(i=0; !f.eof(); i++) {
		f>>num>>na>>sex>>add>>salary>>all>>oap>>Hou>>med;
		rs[i].setnumber(num);
		rs[i].setname(na);
		rs[i].setsex(sex);
		rs[i].setaddress(add);
		rs[i].setsalary(salary);
		rs[i].setallowance(all);
		rs[i].setold_age_pension(oap);
		rs[i].setHousing_Fund(Hou);
		rs[i].setmedical_insurance(med);
		rs[i].gettax();
		rs[i].getr_salary();
	}
	x=i-1;
	f.close();
}
void get_tstxt() {										//读取临时员工的数据
	fstream f;
	f.open("Temporary_staff.txt",ios::in);
	string num;
	string na;
	string sex;
	string add;
	int salary;
	int bo;
	int i;
	for(i=0; f.eof(); i++) {
		f>>num>>na>>sex>>add>>salary>>bo;
		ts[i].setnumber(num);
		ts[i].setname(na);
		ts[i].setsex(sex);
		ts[i].setaddress(add);
		ts[i].setsalary(salary);
		ts[i].setbonus(bo);
	}
	x=i-1;
	f.close();
}

void find_name_r(string n) {							//通过员工姓名，查询正式员工的数据
	get_rstxt();
	for(int i=0; i<=x; i++) {
		if(rs[i].getname()==n) {
			rs[i].display();
			cout<<endl;
			break;
		}
		if(i==x) {
			cout<<"抱歉，未查询到该员工，请核实员工信息！"<<endl;
			break;
		}
	}

}

void find_name_t(string n) {							//通过员工姓名，查询临时员工的数据
	get_tstxt();
	for(int i=0; i<x; i++) {
		if(ts[i].getname()==n) {
			ts[i].display();
			cout<<endl;
			break;
		}
		if(i==x-1) {
			cout<<"抱歉，未查询到该员工，请核实员工信息！"<<endl;
			break;
		}
	}
}

void find_number_r(string m) {							//通过编号查找 正式 员工
	get_rstxt();
	for(int i=0; i<x; i++) {
		if(rs[i].getnumber()==m) {
			rs[i].display();
			cout<<endl;
			break;
		}
		if(i==x-1) {
			cout<<"抱歉，未查询到该员工，请核实员工信息！"<<endl;
			break;
		}
	}
}

void find_number_t(string m) {							//通过编号查找 临时 员工
	get_tstxt();
	for(int i=0; i<x; i++) {
		if(ts[i].getnumber()==m) {
			ts[i].display();
			cout<<endl;
			break;
		}
		if(i==x-1) {
			cout<<"抱歉，未查询到该员工，请核实员工信息！"<<endl;
			break;
		}
	}
}

void find_salary_r(double a,double b) {					//工资范围 ，控制 a <= b  正式员工
	int num=0;
	get_rstxt();
	for(int i=0; i<x; i++) {
		if(rs[i].getreal()>=a&&rs[i].getreal()<=b) {
			rs[i].display();
			cout<<endl;
			num++;
		}
		if(i==x-1&&num==0) {
			cout<<"抱歉，未查询到相应员工，请核实员工信息！"<<endl;
			break;
		}
	}
}

void find_salary_t(double a,double b) {					//工资范围 ， 同上
	int num=0;
	get_tstxt();
	for(int i=0; i<x; i++) {
		if(ts[i].getreal()>=a&&ts[i].getreal()<=b) {
			ts[i].display();
			cout<<endl;
			num++;
		}
		if(i==x-1&&num==0) {
			cout<<"抱歉，未查询到相应员工，请核实员工信息！"<<endl;
			break;
		}
	}
}

void modify_new_r() { 									//新增员工信息
	string num;
	string na;
	string sex;
	string add;
	int salary;
	int all ;
	int oap;
	int Hou;
	int med;
	cout<<"\n\n请输入新正式员工的编号、姓名、性别、家庭地址、基础工资、岗位津贴、养老金、住房公积金、医疗保险\n\n";
	cin>>num>>na>>sex>>add>>salary>>all>>oap>>Hou>>med;
	get_rstxt();
	for(int i=0; i<x; i++) {
		if(rs[i].getnumber()==num) {
			cout<<"\n编号重复！请核实员工信息！";
			break;
		}
		if(i==x-1) {
			fstream f;
			f.open("Regular_staff.txt",ios::out|ios::app);
			f<<num<<" "<<na<<" "<<sex<<" "<<add<<" "<<salary<<" "<<all<<" "<<oap<<" "<<Hou<<" "<<med<<" ";
			f.close();
			cout<<"已将"<<na<<"加入系统名单！";
		}
	}

}

void modify_new_t() {
	string num;
	string na;
	string sex;
	string add;
	int salary;
	int bo;
	cout<<"请输入新临时员工的编号、姓名、性别、家庭地址、基础工资、奖金";
	cin>>num>>na>>sex>>add>>salary>>bo;
	get_tstxt();
	for(int i=0; i<x; i++) {
		if(ts[i].getnumber()==num) {
			cout<<"\n编号重复！请核实员工信息！";
			break;
		}
		if(i==x-1) {
			fstream f;
			f.open("Temporary_staff.txt",ios::out|ios::app) ;
			f<<num<<" "<<na<<" "<<sex<<" "<<add<<" "<<salary<<" "<<bo<<" ";
			f.close();
			cout<<"已将"<<na<<"加入系统名单！";
		}
	}

}

void modify_address_r(string num) { 					//正式 地址
	get_rstxt();
	for(int i=0; i<x; i++) {
		if(rs[i].getnumber()==num) {
			cout<<"已找到该员工，请输入该员工新的家庭住址；"<<endl;
			string new_address;
			cin>>new_address;
			rs[i].setaddress(new_address);
			cout<<"修改成功！！"<<endl;
			break;
		}
		if(i==x-1) {
			cout<<"抱歉，未查询到该员工，请核对员工信息！"<<endl;
			break;
		}
	}
	fstream  fc("Regular_staff.txt",ios::trunc);
	fc.close();
	fstream f;
	f.open("Regular_staff.txt",ios::out);
	for(int i=0; i<x; i++) {
		f<<rs[i].getnumber()<<" "<<rs[i].getname()<<" "<<rs[i].getsex()<<" "<<rs[i].getaddress()<<" "<<rs[i].getsalary()<<" "<<rs[i].getallowance()<<" "<<rs[i].getold_age_pension()<<" "<<rs[i].getHousing_Fund()<<" "<<rs[i].getmedical_insurance()<<" ";
	}
	f.close();
}


void modify_address_t(string num) {
	get_tstxt();
	for(int i=0; i<x; i++) {
		if(ts[i].getnumber()==num) {
			cout<<"已找到该员工，请输入该员工新的家庭住址；"<<endl;
			string new_address;
			cin>>new_address;
			ts[i].setaddress(new_address);
			cout<<"修改成功！！"<<endl;
			break;
		}
		if(i==x-1) {
			cout<<"抱歉，未查询到该员工，请核对员工信息！"<<endl;
			break;
		}
	}
	fstream  fc("Temporary_staff.txt",ios::trunc);
	fc.close();
	fstream f;
	f.open("Temporary_staff.txt",ios::out);
	for(int i=0; i<x; i++) {
		f<<ts[i].getnumber()<<" "<<ts[i].getname()<<" "<<ts[i].getsex()<<" "<<ts[i].getaddress()<<" "<<ts[i].getsalary()<<" "<<ts[i].getbonus()<<" ";
	}
	f.close();
}

void modify_salary_r(string num) { 						//修改工资  清屏 重新输入  正式
	get_rstxt();
	for(int i=0; i<x; i++) {
		if(rs[i].getnumber()==num) {
			cout<<"已找到该员工，请输入该员工新的基础工资；"<<endl;
			int new_salary;
			cin>>new_salary;
			rs[i].setsalary(new_salary);
			cout<<"修改成功！！"<<endl;
			break;
		}
		if(i==x-1) {
			cout<<"抱歉，未查询到该员工，请核对员工信息！"<<endl;
			break;
		}
	}
	fstream  fc("Regular_staff.txt",ios::trunc);
	fc.close();
	fstream f;
	f.open("Regular_staff.txt",ios::out);
	for(int i=0; i<x; i++) {
		f<<rs[i].getnumber()<<" "<<rs[i].getname()<<" "<<rs[i].getsex()<<" "<<rs[i].getaddress()<<" "<<rs[i].getsalary()<<" "<<rs[i].getallowance()<<" "<<rs[i].getold_age_pension()<<" "<<rs[i].getHousing_Fund()<<" "<<rs[i].getmedical_insurance()<<" ";
	}
	f.close();
}

void modify_salary_t(string num) {
	get_tstxt();
	for(int i=0; i<x; i++) {
		if(ts[i].getnumber()==num) {
			cout<<"已找到该员工，请输入该员工新的基础工资；"<<endl;
			int new_salary;
			cin>>new_salary;
			ts[i].setsalary(new_salary);
			cout<<"修改成功！！"<<endl;
			break;
		}
		if(i==x-1) {
			cout<<"抱歉，未查询到该员工，请核对员工信息！"<<endl;
			break;
		}
	}
	fstream  fc("Temporary_staff.txt",ios::trunc);
	fc.close();
	fstream f;
	f.open("Temporary_staff.txt",ios::out);
	for(int i=0; i<x; i++) {
		f<<ts[i].getnumber()<<" "<<ts[i].getname()<<" "<<ts[i].getsex()<<" "<<ts[i].getaddress()<<" "<<ts[i].getsalary()<<" "<<ts[i].getbonus()<<" ";
	}
	f.close();
}

void print_num_r() {					//打印员工信息 正式
	get_rstxt();
	for(int i=0; i<x; i++) {
		cout<<endl<<"员工编号:"<<rs[i].getnumber()<<"  员工姓名:"<<rs[i].getname()<<endl<<endl;
		cout<<"员工地址:"<<rs[i].getaddress()<<endl<<endl;
		cout<<"员工性别:"<<rs[i].getsex()<<"  员工税后实际工资:"<<rs[i].getreal()<<endl<<endl;
		cout<<"--------------------------------------------------------------------"<<endl;
	}
}

void print_num_t() {
	get_tstxt();
	for(int i=0; i<x; i++) {
		cout<<endl<<"员工编号:"<<ts[i].getnumber()<<"  员工姓名:"<<ts[i].getname()<<endl<<endl;
		cout<<"员工地址:"<<ts[i].getaddress()<<endl<<endl;
		cout<<"员工性别:"<<ts[i].getsex()<<"  员工税后实际工资:"<<ts[i].getreal()<<endl<<endl;
		cout<<"--------------------------------------------------------------------"<<endl;
	}
}

void print_num(int type) {
	int i,j,o = type;
	get_rstxt();
	get_tstxt();
	Regular_staff temp_r;
	Temporary_staff temp_t;
	cout<<"按编号由低到高输出:"<<endl<<"--------------------------------------------------------------------"<<endl;
// 	cout<<"按编号顺序输出：1.正式员工 2.临时员工"<<endl<<"请输入："<<endl;
// 	cin>>o;
	switch(o) {
		case 1:

			for (j=0; j<x; j++) {
				for (i=0; i<x-j; i++) {
					if (rs[i].getnumber()>rs[i+1].getnumber()) {
						temp_r=rs[i];
						rs[i]=rs[i+1];
						rs[i+1]=temp_r;
					}
				}
			}
			print_num_r();
			break;
		case 2:

			for (j=0; j<x; j++) {
				for (i=0; i<x-j; i++) {
					if (ts[i].getnumber()>ts[i+1].getnumber()) {
						temp_t=ts[i];
						ts[i]=ts[i+1];
						ts[i+1]=temp_t;
					}
				}
			}
			print_num_t();
			break;
	}
}
void print_sequence(int type) {
	int i,j,o = type;
	get_rstxt();
	get_tstxt();
	Regular_staff temp_r;
	Temporary_staff temp_t;
	cout<<"按工资由低到高输出:"<<endl<<"--------------------------------------------------------------------"<<endl;
//	cout<<"按工资由高到低输出：1.固定员工 2.临时员工"<<endl<<"请输入："<<endl;
//	cin>>o;
	switch(o) {
		case 1:

			for (j=0; j<x; j++) {
				for (i=0; i<x-j; i++) {
					if (rs[i].getreal()<rs[i+1].getreal()) {
						temp_r=rs[i];
						rs[i]=rs[i+1];
						rs[i+1]=temp_r;
					}
				}
			}
			print_num_r();
			break;
		case 2:

			for (j=0; j<x; j++) {
				for (i=0; i<x-j; i++) {
					if (ts[i].getreal()<ts[i+1].getreal()) {
						temp_t=ts[i];
						ts[i]=ts[i+1];
						ts[i+1]=temp_t;
					}
				}
			}
			print_num_t();
			break;
	}
}

void print_flashback(int type) {
	int i,j,o = type;
	get_rstxt();
	get_tstxt();
	Regular_staff temp_r;
	Temporary_staff temp_t;
	cout<<"按工资由低到高输出:"<<endl<<"--------------------------------------------------------------------"<<endl;
//	cout<<"按工资由低到高输出：1.固定员工 2.临时员工"<<endl<<"请输入："<<endl;
//	cin>>o;
	switch(o) {
		case 1:

			for (j=0; j<x; j++) {
				for (i=0; i<x-j; i++) {
					if (rs[i].getreal()>rs[i+1].getreal()) {
						temp_r=rs[i];
						rs[i]=rs[i+1];
						rs[i+1]=temp_r;
					}
				}
			}
			print_num_r();
			break;
		case 2:

			for (j=0; j<x; j++) {
				for (i=0; i<x-j; i++) {
					if (ts[i].getreal()>ts[i+1].getreal()) {
						temp_t=ts[i];
						ts[i]=ts[i+1];
						ts[i+1]=temp_t;
					}
				}
			}
			print_num_t();
			break;
	}
}



int type;

void charge_type() {
	while(1) {
		cls();
		printf("请选择职工类型\n\n1 正式职工\n\n2 临时职工\n\n");		//输入职工类型
		cin >>type;
		if(type != 1 && type !=2) {				//判断类型是否输入合法
			cls();
			printf("\n职工类型输入错误！x_x\n请重试！");
			Sleep(1500);
			continue;
		} else break;
	}
}


void print_opt1() {
	printf("\n\t\t 1 查找员工信息\n\n");
	printf("**************************************************\n\n");
	printf("1 职工姓名\n\n2 职工编号\n\n3 工资介于a到b的职工\n\n");
	printf("**************************************************\n\n");
	printf("请选择：");
}

void opt1() {

	string num1;
	while(1) {
		cls();
		print_opt1();
		cin>>num1;
		if(num1 == "1") {
			charge_type();
			cls();
			cout <<"请输入员工姓名："<<endl;
			string n;
			cin >> n;
			cout<<endl;
			if(type == 1) {
				find_name_r(n);
			} else if(type == 2) {
				find_name_t(n);
			}
			break;
		}
		if (num1 == "2") {
			charge_type();
			cls();
			cout <<"请输入员工编号："<<endl;
			string n;
			cin >> n;
			cout<<endl;
			if(type == 1) {
				find_number_r(n);
			} else if(type == 2) {
				find_number_t(n);
			}
			break;
		}
		if (num1 == "3") {
			charge_type();
			cls();
			cout <<"请输入工资范围（最小值和最大值）："<<endl;
			double a,b;
			cin >> a >> b;
			cout<<endl;
			if(a>b) {
				double temp;
				temp = a;
				a = b;
				b = temp;
			}
			if(type == 1) {
				find_salary_r(a,b);
			} else if(type == 2) {
				find_salary_t(a,b);
			}
			break;
		} else {
			printf("\n员工信息输入错误！x_x\n请重试！");
			Sleep(1500);
			continue;
		}
	}

}


void print_opt2() {
	printf("\n\t\t 2 更新员工数据\n\n");
	printf("**************************************************\n\n");
	printf("1 新增员工数据\n\n2 修改员工数据\n\n3 返回主界面\n\n");
	printf("**************************************************\n\n");
	printf("请选择：");
}

void opt2() {

	string num2;
	while(1) {
		cls();
		print_opt2();
		cin >> num2;

		if(num2=="1") {
			cls();
			charge_type();
			cls();
			if(type == 1) {
				modify_new_r();
			}
			if(type == 2) {
				modify_new_t();
			}
			break;
		}

		if (num2 == "2") {
			cls();
			charge_type();
			cls();
			printf("\n\n1 修改员工地址\n\n2 修改员工工资\n\n请选择：");
			int n;
			cin >> n;
			cls();
			string m;
			printf("\n\n请输入员工编号：");
			cin>>m;
			if(type ==1) {
				cls();
				if(n ==1) modify_address_r(m);
				if(n ==2) modify_salary_r(m);
			}
			if(type ==2) {
				cls();
				if(n ==1) modify_address_t(m);
				if(n ==2) modify_salary_t(m);
			}
			break;
		}
		if(num2=="3") {
			cls();
			break;
		} else {
			cls();
			printf("\n输入错误！x_x\n\n请重试\n\n");
			Sleep(1500);
			continue;
		}

	}

}



void print_opt3() {
	printf("\n\t\t 3 输出员工信息\n\n");
	printf("**************************************************\n\n");
	printf("1 按工资由高到低输出 \n\n2 按工资由低到高输出\n\n3 按编号输出（低到高）\n\n4 返回主界面\n\n");
	printf("**************************************************\n\n");
	printf("请选择：");
}

void opt3() {
	string num3;
	while(1) {
		cls();
		print_opt3();
		cin >> num3;
		if(num3 == "1") {
			cls();
			charge_type();
			cls();
			print_sequence(type);
			break;
		}
		if(num3 == "2") {
			cls();
			charge_type();
			cls();
			print_flashback(type);
			break;
		}
		if(num3 == "3") {
			cls();
			charge_type();
			cls();
			print_num(type);
			break;
		}
		if(num3 == "4") {
			cls();
			break;
		} else {
			cls();
			cout<<"请输入正确的选项！"<<endl;
			Sleep(1500);
			continue;
		}
	}

}


void opt4() {
	cls();
	printf("\n欢迎下次使用！再见^_^\n\n");
}

void opt_error() {
	printf("\n\n输入错误！x_x\n\n请输入正确选项！\n\n");
}

int main() {
	system("color 0B");
	loading();
	cls();
	print_Begin();
	string opt;
	int o;

	while(1) {
		cin >> opt;
		o=atoi(opt.c_str());
		switch(o) {
			case 1:
				opt1();
				system("pause");
				refresh();
				break;

			case 2:
				opt2();
				system("pause");
				refresh();
				break;

			case 3:
				opt3();
				system("pause");
				refresh();
				break;

			case 4:
				opt4();
				Sleep(500) ;
				return 0;

			default:
				cls();
				opt_error();
				system("pause");
				refresh();
				break;

		}
	}
}
