//Finals_Submission_for_Data_Structures

/*Antonio Casakit
09001852900
BSIT-2nd Year
AMACC - Las Pinas
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class Stack
{
private:
	int top;
	int arr[5];

public:
	Stack()
	{
		top = -1;
		for (int i = 0; i < 5; i++)
		{
			arr[i] = 0;
		}
	}

	bool isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if (top == 4)
			return true;
		else
			return false;
	}

	void push(int val)
	{
		if (isFull())
		{
			cout << "Stack overflow" << endl;
		}
		else
		{
			top++; // 1
			arr[top] = val;
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else
		{
			int popValue = arr[top];
			arr[top] = 0;
			top--;
			return popValue;
		}
	}
	int count()
	{
		return(top + 1);
	}
	int peek(int pos)
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else
		{
			return arr[pos];
		}
	}
	void change(int pos, int val)
	{
		cout << "Value changed at location" << pos << endl;
	}
	void display()
	{
		cout << "All values in the stack are " << endl;
		for (int i = 4; i >= 0; i--)
		{
			cout << arr[i] << endl;
		}
	}
};

int main()
{
	int moption;
	do
	{
		cout << "What operation do you want to perform?" << endl;
		cout << "1. Stack" << endl;
		cout << "2. Queue" << endl;
		cout << "3. Heap Maps" << endl;
		cout << "4. List" << endl;
		cout << "9. Clear Screen" << endl;
		cout << "0. Exit Program" << endl << endl;
		cin >> moption;
		switch (moption)
		{
		case 0:
			break;
		case 1:
		{Stack s1;
		int option, position, value;
		do
		{
			cout << "What operation do you want to perform?" << endl;
			cout << "1. Push" << endl;
			cout << "2. Pop" << endl;
			cout << "3. isEmpty()" << endl;
			cout << "4. isFull()" << endl;
			cout << "5. peek()" << endl;
			cout << "6. count()" << endl;
			cout << "7. change()" << endl;
			cout << "8. display()" << endl;
			cout << "9. Clear Screen" << endl << endl;
			cout << "0. Previous Screen" << endl << endl;

			cin >> option;
			switch (option)
			{
			case 0:
				break;
			case 1:
				cout << "Enter an item to push into the stack" << endl << endl;
				cin >> value;
				s1.push(value);
				break;
			case 2:
				cout << "Pop Function Called - Popped Value: " << s1.pop() << endl << endl;
				break;
			case 3:
				if (s1.isEmpty())
					cout << "Stack is empty" << endl << endl;
				else
					cout << "Stack is not empty" << endl << endl;
				break;
			case 4:
				if (s1.isFull())
					cout << "Stack is full" << endl << endl;
				else
					cout << "Stack is not full" << endl << endl;
				break;
			case 5:
				cout << "Enter the position of the item that you want to peek" << endl << endl;
				cin >> position;
				cout << "Peek function called - Value at position " << position << " is " << s1.peek(position) << endl << endl;
				break;
			case 6:
				cout << "Count function called - The number of items in the Stack are " << s1.count() << endl << endl;
				break;
			case 7:
				cout << "Change function called - " << endl << endl;
				cout << "Enter the position of the item that you want to change: ";
				cin >> position;
				cout << endl;
				cout << "Enter the value of the item you want to change: ";
				cin >> value;
				s1.change(position, value);
				break;
			case 8:
				cout << "Display Function Called - " << endl << endl;
				s1.display();
				break;
			case 9:
				system("cls");
				break;
			default:
				cout << "Enter a valid option number" << endl << endl;
			}
		} while (option != 0); }
		break;
		case 2:
		{queue <int> q, q1;
		q.push(1);
		q.push(5);
		q.push(3);
		q.push(6);
		q.push(2);
		q.push(0);
		q.push(-1);
		q.push(4);
		q1 = q;
		cout << "Queue elements are ";
		while (!q1.empty())
		{
			cout << q1.front() << " ";
			q1.pop();
		}
		cout << endl << "Average of all elements of the said queue is ";
		int sum = 0;
		int count = 0;
		while (!q.empty())
		{
			sum += q.front();
			count++;
			q.pop();
		}
		double avg = (double)sum / count;
		cout << avg << endl << endl;
		break;
		}
		case 3:
		{unordered_map<int, int>myTable;
		int elem, key;
		int searchKey;
		int option;
		do
		{
			cout << "What operation do you want to perform?" << endl;
			cout << "1. Insert an element into the table" << endl;
			cout << "2. Search for an element from the key" << endl;
			cout << "3. Delete an element using a key" << endl;
			cout << "4. Exit" << endl;
			cout << "0. Previous Screen" << endl << endl;

			cin >> option;
			switch (option)
			{
			case 0:
				break;
			case 1:
				cout << "Enter element to be inserted: " << endl;
				cin >> elem;
				cout << "Enter key at which element to be inserted: " << endl;
				cin >> key;
				myTable.insert(pair<int, int>(elem, key));
				for (auto pair : myTable)
					cout << endl << pair.first << " - " << pair.second << endl;
				break;
			case 2:
				cout << "Enter the key: " << endl;
				cin >> searchKey;
				cout << "Found it in " << myTable[searchKey] << endl;
				break;
			case 3:
				cout << "Enter the key: " << endl;
				cin >> searchKey;
				myTable.erase(searchKey);
				break;
			case 4:
				return 0;
			default:
				cout << "Enter a valid option" << endl << endl;
			}
		} while (option != 0); }
		case 9:
			system("cls");
			break;
		}
	} while (moption != 0);
	return 0;
}