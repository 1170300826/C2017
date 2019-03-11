#include <iostream> 
#include <limits>
#include <string>
using namespace std;
int main()
{
	 cout << "type: \t\t" << "************size**************"<< endl;  
	 count <<"bool: \t\t" << "所占字节数："<< sizeof(bool);
	 count <<"最大值: "<< (numeric_limits<bool>::max)(); 
	 count <<"最小值："<< (numeric_limits<bool>::max)();
	 cont <<"char: \t" << "所占字节数："<< sizeof(char);
}
