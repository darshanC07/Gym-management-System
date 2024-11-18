#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <ctime>
using namespace std;

class new_joinee
{
private:
	string name;
	int id;
	int age = 0;
	string address;
	int phone_number = 0;
	int trainer_index = 0;

public:
	friend void login(new_joinee &user, int line_index); 
	static int joinee_count;
	static int print_count();
	new_joinee()
	{
		joinee_count += 1;
		id = joinee_count;
	}
	void get()
	{
		cout << "ENTER NAME : ";
		cin >> name;
		cout << "ENTER AGE : ";
		cin >> age;
		cout << "ENTER ADDRESS : ";
		cin >> address;
		cout << "ENTER PHONE NUMBER : ";
		cin >> phone_number;
		if (trainer_index == 0)
		{
			cout << "ENTER TRAINER id : ";
			cin >> trainer_index;
		}
		ofstream file("gym_data.txt", ios::app);
		file << name << " " << age << " " << address << " " << phone_number << " " << trainer_index<<endl;
		file.close();
	}

	void put()
	{
		cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;
		cout << left << setw(15) << "NAME" << setw(15) << "AGE" << setw(15) << "ADDRESS" << setw(15) << "PHONE NUMBER" << endl;
		cout << setw(15) << name << setw(15) << age << setw(15) << address << setw(15) << phone_number << endl;
		cout << "\n----------------------------";
	}
	void viewExerciseSchedule()
	{
		cout << "\n--- Today's Exercise Schedule ---" << endl;
		cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl;
		cout << left << setw(10) << "Time" << setw(25) << "Exercise" << endl;
		cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl;
		cout << setw(10) << "6:00 AM" << setw(25) << "Cardio" << endl;
		cout << setw(10) << "7:00 AM" << setw(25) << "Yoga" << endl;
		cout << setw(10) << "8:00 AM" << setw(25) << "Strength Training" << endl;
		cout << setw(10) << "5:00 PM" << setw(25) << "Zumba" << endl;
		cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl;
	}

	void viewDietPlan()
	{
		cout << "\n--- Your Diet Plan ---" << endl;
		cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl;
		cout << left << setw(10) << "Meal" << setw(25) << "Description" << endl;
		cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl;
		cout << setw(10) << "Breakfast" << setw(25) << "Oatmeal & Fruits" << endl;
		cout << setw(10) << "Lunch" << setw(25) << "Grilled Chicken Salad" << endl;
		cout << setw(10) << "Snack" << setw(25) << "Protein Shake" << endl;
		cout << setw(10) << "Dinner" << setw(25) << "Steamed Vegetables & Fish" << endl;
		cout << setfill('-') << setw(35) << "-" << setfill(' ') << endl;
	}

	void displayPlans()
	{
		cout << left << setw(5) << "ID" << setw(20) << "Plan Name" << setw(10) << "Amount" << setw(10) << "Duration" << setw(10) << "Discount" << endl;

		cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;

		cout << setw(5) << "1" << setw(20) << "Basic" << setw(10) << "3000" << setw(10) << "1 month" << setw(10) << "5%" << endl;

		cout << setw(5) << "2" << setw(20) << "Silver" << setw(10) << "8000" << setw(10) << "3 months" << setw(10) << "10%" << endl;

		cout << setw(5) << "3" << setw(20) << "Gold" << setw(10) << "15000" << setw(10) << "6 months" << setw(10) << "15%" << endl;

		cout << setw(5) << "4" << setw(20) << "Platinum" << setw(10) << "25000" << setw(10) << "12 months" << setw(10) << "20%" << endl;
	}

	void renewPlan()
	{
		cout << "\n--- Renew Your Membership Plan ---" << endl;
		cout << "Your membership plan has been renewed successfully!" << endl;
	}

	void makePayment()
	{
		cout << "\n--- Make a Payment ---" << endl;
		time_t now = time(NULL);

		double amount;
		string plan_name;
		cout << "Enter name of your plan : ";
		cin >> plan_name;
		cout << "Enter amount to pay: ";
		cin >> amount;
		cout << "Processing........\n";
		Sleep(3000);
		cout << "Payment of " << amount << " was successful!" << endl;
		cout << "You have successfully subscribed " << plan_name << ".\nStart Date : " << ctime(&now) << endl;
	}

	void profile()
	{
		if (phone_number == 0)
		{
			cout << "You didn't setup profile. Lets do it.\n";
			get();
		}
		else
		{
			cout << "\n--- User Profile ---" << endl;
			cout << left << setw(15) << "Name:" << name << endl;
			cout << left << setw(15) << "Age:" << age << endl;
			cout << left << setw(15) << "Number:" << phone_number << endl;
			cout << left << setw(15) << "Address:" << address << endl;
			cout << left << setw(15) << "Trainer id:" << trainer_index << endl;
			cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
		}
	}

	void trainer_info()
	{
		int t_id = 101;
		// double number;
		string id, number, name, speciality, experience, time;
		fstream file;
		file.open("trainer.txt");
		cout << "\n--- Trainers List ---" << endl;
		cout << left << setw(5) << "ID"
			 << setw(20) << "Name"
			 << setw(25) << "Specialization"
			 << setw(12) << "Experience"
			 << setw(15) << "Contact"
			 << setw(20) << "Availability" << endl;

		cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;
		while (file >> id)
		{
			getline(file, id);
			getline(file, name);
			getline(file, speciality);
			getline(file, experience);
			getline(file, number);
			getline(file, time);
			cout << left << setw(5) << t_id << setw(20) << name << setw(25) << speciality << setw(12) << experience << setw(15) << number << setw(20) << time << endl;
			t_id = t_id + 1;
		}
	}

	void userDashboard()
	{
		int choice;
		cout << "\n"
			 << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
		cout << left << setw(25) << "User Dashboard" << endl;
		cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
		cout << left << setw(5) << "1." << setw(25) << "View Today's Exercise Schedule" << endl;
		cout << left << setw(5) << "2." << setw(25) << "View Diet Plan" << endl;
		cout << left << setw(5) << "3." << setw(25) << "View Membership Plan" << endl;
		cout << left << setw(5) << "4." << setw(25) << "Renew Membership Plan" << endl;
		cout << left << setw(5) << "5." << setw(25) << "Make Payment" << endl;
		cout << left << setw(5) << "6." << setw(25) << "View Profile" << endl;
		cout << left << setw(5) << "7." << setw(25) << "Choose Trainer" << endl;
		cout << left << setw(5) << "8." << setw(25) << "Exit" << endl;
		cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
		do
		{
			cout << "Choose an option: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				viewExerciseSchedule();
				break;
			case 2:
				viewDietPlan();
				break;
			case 3:
				displayPlans();
				break;
			case 4:
				renewPlan();
				break;
			case 5:
				makePayment();
				break;
			case 6:
				profile();
				break;
			case 7:
				trainer_info();
				cout << "Choose your trainer(enter id) : ";
				cin >> trainer_index;
				break;
			case 8:
				cout << "Exiting. Thank you!" << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
			}
		} while (choice != 8);
	}
};

class admin : public new_joinee
{
public:
	void get_members()
	{
		string name, age, address, number, t_id;
		fstream file;
		file.open("gym_data.txt");
		cout << "\n--- Members List ---" << endl;
		cout << left << setw(20) << "Name"
			 << setw(5) << "Age"
			 << setw(30) << "Address"
			 << setw(15) << "Number"
			 << setw(10) << "Trainer ID" << endl;

		cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
		while (file)
		{
			file >> name >> age >> address >> number >> t_id;
			cout << left << setw(20) << name
				 << setw(5) << age
				 << setw(30) << address
				 << setw(15) << number
				 << setw(10) << t_id << endl;
		}

		cout << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
	}
	void userDashboard()
	{
		int choice;
		cout << "\n"
			 << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
		cout << left << setw(25) << "ADMIN Dashboard" << endl;
		cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
		cout << left << setw(5) << "1." << setw(25) << "View/Add members" << endl;
		cout << left << setw(5) << "2." << setw(25) << "View/Add trainers" << endl;
		cout << left << setw(5) << "3." << setw(25) << "Create Notice" << endl;
		cout << left << setw(5) << "4." << setw(25) << "Exit" << endl;
		cout << setfill('-') << setw(30) << "-" << setfill(' ') << endl;
		do
		{
			cout << "Choose an option: ";
			cin >> choice;

			switch (choice)
			{
			case 1:
				get_members();
				char temp;
				cout << "Do you want to add member?(y/n) : ";
				cin >> temp;
				if (temp == 'y')
				{
					this->get();
				}
				else
				{
				}
				break;
			case 2:
				trainer_info();
				break;
			case 3:
				cout << "Today's notice : Gym will remain closed on upcoming sunday.\n";
				break;
			case 4:
				cout << "Exiting. Thank you!" << endl;
				break;
			default:
				cout << "Invalid choice. Please try again.\n"
					 << endl;
			}
		} while (choice != 4);
	}
};

int new_joinee::joinee_count = 0;
int new_joinee::print_count()
{
	cout << "\nTotal joinee : " << joinee_count;
}

void get_file_data(fstream &file, string &line)
{
	while (file)
	{
		getline(file, line);
		cout << line << endl;
	}
}

int verify(int &line_count, string in_email, string in_password)
{
	string email, password;
	int status;

	string file_n = "login_details.txt";
	fstream file;
	file.open(file_n);
	while (file >> email)
	{
		if (email == in_email)
		{
			file >> password;
			if (password == in_password)
			{
				// cout<<"correct password\n";
				status = 1;
				return 1;
			}
			else
			{
				status = 0;
			}
		}
		else
		{
			status = 0;
		}
		line_count++;
	}

	file.close();
	return status;
}

void login(new_joinee &user, int line_index)
{
	string name,address;
	int age,phone_no,t_id;
	fstream file;
	file.open("gym_data.txt");
	for (int i = 1; i <= line_index; i++)
	{
		file >> name >> age >> address >> phone_no >> t_id;
	}
	// cout << name << age << address << phone_no << t_id;
	user.name = name;
	user.age = age;
	user.address = address;
	user.phone_number = phone_no;
	user.trainer_index = t_id;
}

int main()
{
	// plans::displayPlans();
	// trainer::view_members();
	int temp;
	string email, password;
	cout << "-----| WELCOME TO SANATORIYM GYM |------\n";
	cout << "--------stay fit, stay healthy---------\n";
user:
	cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
	cout << left << setw(20) << "Create account " << setw(8) << "Press 1" << endl;
	cout << setw(20) << "Login in " << setw(8) << "Press 2" << endl;
	cout << setw(20) << "Login as Admin " << setw(8) << "Press 3" << endl;
	cout << "Your choice : ";
	cin >> temp;
	if (temp)
	{
		if (temp == 1)
		{
			ofstream c_file("login_details.txt", ios::app);
			// c_file.open("login_details",ios::app);
			new_joinee user;
			cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
			cout << setw(15) << "ENTER EMAIL : ";
			cin >> email;
			cout << setw(15) << "ENTER PASSWORD : ";
			cin >> password;
			c_file << email << " " << password<<endl;
			c_file.close();
			cout << "Account created successfully.\n";

		login_user:
			cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
			cout << "Login\n";
			cout << setw(15) << "ENTER EMAIL : ";
			cin >> email;
			cout << setw(15) << "ENTER PASSWORD : ";
			cin >> password;
			int ret, line_count = 1;
			ret = verify(line_count, email, password);
			if (ret == 1)
			{
				cout << "Login successfully.\n";
				goto new_user;
			}
			else if (ret == 0)
			{
				cout << "Invalid details.\n";
				goto login_user;
			}
		new_user:
			user.userDashboard();
		}
		else if (temp == 2)
		{
			
			cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;
			cout << "Login\n";
			login:
			cout << setw(15) << "ENTER EMAIL : ";
			cin >> email;
			cout << setw(15) << "ENTER PASSWORD : ";
			cin >> password;
			int ret, line_index = 1;
			ret = verify(line_index, email, password);
			int correct_line = line_index / 2 + 1;
			// cout<<correct_line;
			if (ret == 1)
			{
				cout << "Login successfully.\n";
				new_joinee old_user;
				login(old_user, correct_line);
				old_user.userDashboard();
			} else if(ret == 0){
				cout << "Invalid details.\n";
				goto login;
			}
		}
		else if (temp == 3)
		{
			cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

			cout << setw(20) << "ENTER ADMIN EMAIL : ";
			cin >> email;
			cout << setw(20) << "ENTER ADMIN PASSWORD : ";
			cin >> password;
			int ret;
			ret = (email == "darshan001@gmail.com" && password == "123") ? 1 : 0;
			if (ret == 1)
			{
				cout << "Login successfully.\n";
				admin self;
				self.userDashboard();
			}
			else if (ret == 0)
			{
				cout << "Invalid details.\n";
			}
		}
	}
}
