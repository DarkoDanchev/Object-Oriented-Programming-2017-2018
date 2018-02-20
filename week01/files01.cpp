#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    //std::cout,std::cin
    // //char*
    string str1 = "Semerdziev e BOG!!!";
    int a,b;
    /*ofstream write("file1.txt");
    ofstream write1;
    write1.open("file2.txt");

    write<<str1<<endl;
    write1<<str2<<endl;
    cout<<"Hello World"<<endl;*/

    /*

    while(getline(read,str1))
    {
        cout<<str1<<endl;
    }
    */
    /*string str1,str2;
    ifstream read("file1.txt");
    read>>a>>b;

    cout<<a + b<<endl;
    */

    fstream write_and_read("file1.txt", ios::in|ios::out); //ifstream(file.txt)





    //write_and_read.close();

    if(write_and_read.is_open())
    {
        write_and_read<<str1<<endl;
        write_and_read>>a>>b;

        cout<<a + b<<endl;
    }


    return 0;
}

void func1(){

}
