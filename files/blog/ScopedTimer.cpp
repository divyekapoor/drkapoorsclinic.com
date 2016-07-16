#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

class ScopedTimer 
{
	private:
		LARGE_INTEGER start;
		LARGE_INTEGER end;
		LARGE_INTEGER freq;
		ostream &o;
		string s;
		
		inline void initialize() {
			QueryPerformanceFrequency(&freq);
			QueryPerformanceCounter(&start);
		}
		
	public:
		ScopedTimer() : o(cout) {
			initialize();
		}
		
		ScopedTimer(const string &st) : s(st), o(cout) {
			initialize();
		}
		
		ScopedTimer(ostream &_o) : o(_o) {
			initialize();
		}
		
		ScopedTimer(ostream &_o, const string &st) : o(_o), s(st) {
			initialize();
		}
		
		~ScopedTimer() {
			QueryPerformanceCounter(&end);
			o << "Time taken " << s << ": " 
			  << double(end.QuadPart - start.QuadPart)/freq.QuadPart << '\n';
		}
};

#if 0
int main() {
	{
		ScopedTimer s("in Sleep");
		Sleep(1000);
	}
	return 0;
}
#endif
