#include <iostream>
#include <array>
#include <vector>
using namespace std;

template<typename T>void vector_properties(const std::vector<T>& vec);

//#define ARRAY
#define VECTOR

void main()
{
	setlocale(LC_ALL, "russian");
#ifdef ARRAY
	const int n = 5;
	std::array<int, n>arr = { 1,2,3,4,5 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
#endif // DEBUG

#ifdef VECTOR
	/*std::vector<char> vec = { 3,4,5,6,67,7 };
	vec.push_back(111111);
	vec.shrink_to_fit();
	vector_properties(vec);

	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << "\t";
			cout << vec.at(i) << "\t";
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cout << endl;
		std::cerr << "Error: " << e.what() << endl;
	}*/


	std::vector<std::string> s_vec = { "Хорошо ","Живет ","На ","Свете ","Винни ", "Пух" };
	for (std::vector<std::string>::iterator it = s_vec.begin(); it != s_vec.end(); it++)
	{
		cout << *it;
	}
	cout << endl;

	for (std::vector<std::string>::reverse_iterator rit = s_vec.rbegin(); rit != s_vec.rend(); rit++)
	{
		cout << *rit;
	}
	cout << endl;
#endif // VECTOR


}
template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size: " << vec.size() << endl;
	cout << "MaxSize: " << vec.max_size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
}