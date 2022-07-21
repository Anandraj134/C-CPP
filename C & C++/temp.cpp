#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

string check(int);
int display1();
int search(int);

struct node
{
	node *prev;
	int data;
	int x, sum;
	string ie, nam;
	node *next;
};

struct node *start = NULL;
node *create_node()
{
	node *n = new node;
	cout << "ENTER Employee ID : " << endl;
	cin >> n->data;
	cout << "ENTER Salary: " << endl;
	cin >> n->x;
	cout << "Increment Eligibility(Y-N): " << endl;
	cin >> n->ie;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void insert_node()
{
	node *temp;
	temp = create_node();
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		node *traverse;
		traverse = start;
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next = temp;
		temp->prev = traverse;
	}
}
void display()
{
	node *traverse;
	double n, y;
	traverse = start;
	if(start == NULL)
	{
		cout << "No employee to display" << endl;
	}
	else
	{
		system("cls");

		cout << "\n---------------------ALL EMPLOYEE-------------------------" << endl;
		cout << "\n Employee ID\t"
			<< "Salary\t"
			<< "Incriment Eligibility(Y/N)\n"
			<< "Salary" << endl;
		while (traverse != NULL)
		{
			traverse->x = traverse->x + (traverse->x * 0.20);

			cout << traverse->data << "\t\t";
			cout << traverse->x << "\t\t";
			cout << traverse->ie << "\t\t";
			traverse = traverse->next;
			cout << "\n----------------------------------------------------------" << endl;
		}
	}
}

int search(int id)
{
	int count = 1;
	struct node *p = start;
	while (p != NULL)
	{
		if (p->data == id)
		{
			break;
		}
		else
		{
			count++;
			p = p->next;
		}
	}
	return count;
}
int display1()
{

	int c = 0;
	struct node *p = start;
	cout << "Existing Employee are:\n";
	cout << "Employee ID\t\tSalary\tIncriment Eligibility(Y-N)\t\n";
	while (p != NULL)
	{
		cout << p->data << "\t\t\t" << check(p->x) << "\t\t" << p->ie << "\n";
		p = p->next;
		c = c + 1;
	}
	cout << "\nEmployee : " << c << "\n\n\n";
	return c;
}

string check(int quant)
{
	int a = quant;
	stringstream ss;
	ss << a;
	string quantity = ss.str();
	if (quant <= 0)
	{
		return "Don't have EMplloyee'";
	}
	else
	{
		return quantity;
	}
}

void delete_first()
{
	node *temp;
	if (start == NULL)
	{
		cout << "Nothing to delete";
	}
	else
	{
		temp = start;
		start = start->next;
		cout << temp->data << " has been deleted" << endl;
		delete (temp);
		display();
	}
}
void search()
{

	if(start == NULL)
	{
		cout << "No Entry Found" << endl;
	}
	else
	{
		system("cls");
		display();
		double i;
		cout << "Enter Employee ID" << endl;
		cin >> i;
		int f = 0;
		struct node *p = start;
		while (p != NULL)
		{
			if (i == p->data)
			{
				f = 1;
				break;
			}
			p = p->next;
		}

		if (f == 1)
		{
			cout << "Employee is available" << endl;
		}
		else
		{
			cout << "Employee is Not available" << endl;
		}
	}
}

int main()
{

	int option;
	do
	{
		cout << "\n";
		cout << "1 ADD EMPLOYEE" << endl;
		cout << "2 SEARCH" << endl;
		cout << "3 DISPLAY" << endl;
		cout << "4 DELETE  " << endl;
		cout << "5. EXIT" << endl;

		cin >> option;
		switch (option)
		{
		case 1:
			insert_node();
			break;
		case 3:
			display();
			break;
		case 2:
			search();
			break;
		case 4:
			delete_first();
			break;
		case 5:
			return 1;
		}
	} while (option != 0);
	return 0;
}