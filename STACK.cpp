#include <iostream>
using namespace std;


class stack
{
private:
	int *arr;
	int size;
	int currentindex;


public:
	stack()
	{
		size = 10;
		arr = new int[size];
		currentindex = 0;

		for (int x = 0; x < size; x++)
		{
			arr[x] = NULL;
		}

	}
	stack(int size)
	{
		this->size = size;
		arr = new int[size];
		currentindex = 0;


		for (int x = 0; x < size; x++)
		{
			arr[x] = NULL;
		}
	}
	stack(const stack &copy)
	{
		size = copy.size;
		arr = new int[size];
		currentindex = copy.currentindex;
		for (int i = 0; i < size; i++)
		{
			arr[i] = copy.arr[i];
		}

	}
	void push(int data)
	{
		arr[currentindex] = data;
		currentindex++;
	}
	void pop()
	{
		if (currentindex == 0)
		{
			cout << "Stack is empty" << endl;
		}
		else if (currentindex > 0)
		{
			arr[currentindex - 1] = NULL;
			currentindex--;
		}
	}

	void Delete(int i)
	{
		if (i>currentindex || i<0)
		{
			cout << "Stack doesnt have such element." << endl;
		}
		else
		{
			for (int x = i; x<currentindex; x++)
			{
				arr[x] = arr[x + 1];
			}
			currentindex--;
		}

		
	}
	void showstack()
	{
		for (int x = 0; x < currentindex; x++)
		{
			
				cout << "_______" << endl;
				cout << arr[x] << endl;
		
		}
	}
};


int main()
{
	stack c;

	c.pop();
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		c.push(i+1);
	}

	c.showstack();
	cout << endl;



	cout << "Stack after popping last two elements" << endl;
	for (int x = 0; x < 2; x++)
	{
		c.pop();
	}
	c.showstack();
	cout << endl;
	c.Delete(7);
	cout << endl;

	cout << "Stack after deleting 3rd element:" << endl;
	c.Delete(2);

	c.showstack();


	system("pause");
}