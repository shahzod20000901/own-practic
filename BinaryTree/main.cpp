#include<iostream>
using namespace std;

class Tree
{
	class Element
	{
		int Data;
		Element *pLeft, *pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) : Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class Tree;
	}*Root;
public:
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
		Element* getRoot()
		{
			return this->Root;
		}

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
				Root->pLeft = new Element(Data);
			else
				insert(Data, Root->pLeft);
		}
		else
		{
			if (Root->pRight)insert(Data, Root->pRight);
			else
				Root->pRight = new Element(Data);
		}
	}

	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}

	~Tree() 
	{
		cout << "TDestructor:\t" << this << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Tree t;
	int n;
	cout << "Введите количество лементов: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		t.insert(rand() % 100, t.getRoot());
	}
	t.print(t.getRoot());
	cout << endl;
}