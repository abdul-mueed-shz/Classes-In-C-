#include <iostream>
using namespace std;

class olist
{
private:
	int size;
	int data;
	int *arra;
	int currentindex = 0;

public:
	olist()//default constructor
	{
		size = 10;
		arra = new int[size];

		for (int i = 0; i < size; i++)
		{
			arra[i] = NULL;
		}

	}
	olist(int s)//parametric constructor
	{
		size = s;
		arra = new int[size];

		for (int i = 0; i < size; i++)
		{
			arra[i] = NULL;
		}

	}
	olist(const olist &carra)//copy constructor
	{
		size = carra.size;
		currentindex = carra.currentindex;
		arra = new int[size];

		for (int start = 0; start < size; start++)
		{
			arra[start] = carra.arra[start];
		}

	}

	void increasesize()//this function increases size by using pointers
	{
		int *arraincrease = new int[size * 2];

		for (int i = 0; i < size; i++)
		{
			arraincrease[i] = arra[i];
		}
		delete[]arra;

		size = size * 2;
		arra = new int[size];
		for (int i = 0; i<size; i++)
		{
			arra[i] = arraincrease[i];
		}
		delete arraincrease;
	}

	void sort(int* arr, int size)//function for sorting array
	{
		int temporary = 0;

		for (int a = 1; a < size; a++)
		{
			for (int b = 0; b < size - 1; b++)
			{
				if (arr[a]<arr[b])
				{
					temporary = arr[a];

					arr[a] = arr[b];

					arr[b] = temporary;
				}

			}
		}
	}

	void insert(int d)//function for inserting elements
	{
		if (currentindex < size)
		{
			arra[currentindex] = d;
			currentindex++;
			sort(arra, currentindex);

		}
		else if (currentindex >= size)
		{
			increasesize();
			arra[currentindex] = d;
			currentindex++;
			sort(arra, currentindex);

		}
	}

	void Delete(int i)//function for deleting elements
	{
		if (i>currentindex || i<0)
		{
			cout << "invalid index,can't delete" << endl;
		}
		else
		{
			for (int x = i; x<currentindex; x++)
			{
				arra[x] = arra[x + 1];
			}
			currentindex--;
		}

	}
	int retrieve(int i)//function for retrieving an element at a certain index
	{
		if (i >= currentindex || i<0)
		{
			cout << "invalid index,Enter again" << endl;
		}
		else
		{
			return arra[i];
		}
	}
	friend ostream &operator<<(ostream &out, olist &outarray)//for printing
	{
		cout << "ALL ENTERED ELEMENTS IN THE LIST ARE" << endl;
		int limit = outarray.currentindex;

		for (int print = 0; print <limit; print++)
		{
			out << outarray.arra[print] << endl;
		}

		return out;
	}
	
	void operator=(olist &carra)//for assigning
	{
		size = carra.size;
		currentindex = carra.currentindex;
		arra = new int[size];

		for (int start = 0; start < size; start++)
		{
			arra[start] = carra.arra[start];
		}

	}

	int length()//gives current length of the array
	{
		return currentindex;
	}

};


int main()//driver main for testing of functions
{
	olist a(3);
	int ele;
	cout << "How many elemets do you want to add in the array,right now:"; cin >> ele;
	system("cls");

	cout << "Enter elements:"<<endl;
	for (int i = 0; i < ele; i++)
	{
		int inp;
		cin >> inp;
		a.insert(inp);
	}
	cout << a << endl;
	cout << "And the length of the ordered list is: " << a.length() << endl;

	cout << "Now if you want to delete element, press 1 and if you don't want to then press 0:"; int choice; cin >> choice; int temp=0;
	if (choice == 0)
	{
		temp++;
	}
	else if (choice == 1)
	{
		cout << "How many elements do you want to delete:"; int delamount; cin >> delamount;
		system("cls");
		cout << a << endl;
		cout << "Enter the element you want to remove" << endl;
		for (int x = 0; x < delamount; x++)
		{
			int inp;
			cin >> inp;
			a.Delete(inp-1);
			cout << "List after deletion:" << endl;
			cout << a;

		}
		system("cls");
		cout << "List after deletion of all elements:" << endl;
		cout << a;
		cout << "And the length of the list is" << endl;
		cout<<"Length:"<<a.length() << endl;
	}

	a.insert(58);
	a.insert(58);

	system("cls");
	cout << "Copying 1st list into the second:" << endl;
	cout << endl;
	cout << "1st list:" << endl;
	cout << a << endl;
	cout << "And its length is:" << a.length() << endl;
	olist b = a;
	cout << "Second list is:"<<endl;
	b.insert(58);
	cout << b << endl;
	cout << "And its length is:" << b.length() << endl;
	
	cout << "Retrieving element 2 of array b:" << endl;
	int r = b.retrieve(2);
	cout << r << endl;

	system("pause");
}
