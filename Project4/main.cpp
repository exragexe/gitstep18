#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using std::fstream;

struct FileMatch {
private:
	string firstpath;
	string secondpath;
	fstream firstfile, secondfile;
	std::ios_base::openmode open_mode;
public:
	//setters
	void setFirPath(string firstpath) { this->firstpath = firstpath; }
	void setSecPath(string secondpath) { this->secondpath = secondpath; }
	void setOpenMode(ios_base::open_mode open_mode) { this->open_mode = open_mode; }
	//geters
	ios_base::open_mode getOpenMode() { return open_mode; }
	string getFirPath(){ return firstpath; }
	string getSecPath() { return secondpath; }
	//constructors
	FileMatch()
	{
		setFirPath( "text.txt");
		setSecPath("text.txt");
		setOpenMode( ios::in);
	}
	FileMatch(string firstpath, string secondpath) :FileMatch()
	{
		setFirPath(firstpath);
		setSecPath(secondpath);
	}
	FileMatch(string firstpath, string secondpath, ios_base::open_mode open_mode) :FileMatch(firstpath, secondpath)
	{
		setOpenMode(open_mode);
	}
	//destructors
	~FileMatch() {
		firstpath.clear();
		secondpath.clear();
		open_mode=0;
		firstfile.close();
		secondfile.close();
	}
	

};

int main() {
	string firstpath = "C:\\Users\\yaros\\source\\repos\\Project4\\1.txt";
	string secondpath = "C:\\Users\\yaros\\source\\repos\\Project4\\2.txt";
	string firline, secline;
	fstream firstfile, secondfile;
	std::ios_base::openmode open_mode = ios::in;
	firstfile.open(firstpath, open_mode);
	secondfile.open(secondpath, open_mode);
	FileMatch** match = new FileMatch * [3] {
		new FileMatch(),
		new FileMatch(firstpath, secondpath),
		new FileMatch(firstpath, secondpath, open_mode),
	};
	if (firstfile.is_open() && secondfile.is_open())
	{
		cout << "The lines isn`t mutch in files:"<<endl;
		while (getline(firstfile, firline) && getline(secondfile, secline)) {
			
			if (firline != secline) {
				cout << firline<<endl;
			}
			
			if (secline != firline) {
				cout << secline << endl;
			}
			
		}
		//cout << endl;
		//cout << "The lines isn`t mutch in second file:"<<endl;
		//while (getline(secondfile, secline) && getline(firstfile, firline)) {
		//	if (secline != firline) {
		//		cout << secline << endl;
		//	}
		//}
		firstfile.close();
		secondfile.close();
		
	}
	else
	{
		cout << "File didn`t open" << endl;
	}

	return 0;					
};