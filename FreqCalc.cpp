//Author : Maruf Tonmoy
//Date:15 May 2023(updated)
//use of C++ standard template library(STL)

#include<iostream>
#include<algorithm>
#include<iomanip>
#include<map>
#include<utility>
#include<vector>

using namespace std;


typedef map<string,int> mapTypeString;
typedef map<char,int> mapTypeChar;
typedef vector<pair<int,string>> vecStr;
typedef vector<pair<int,char>> vecChar;

void readInput(mapTypeString& m,mapTypeChar& n,vecStr& v,vecChar& c);
char myTolower(char c);
void printWords(mapTypeString& m,mapTypeChar& n,vecStr& v,vecChar& c);
bool myCompare1(const pair<int,string>& x, const pair<int,string>& y);
bool myCompare2(const pair<int,char>& x, const pair<int,char>& y);

int main()
{

   mapTypeString mp;
   mapTypeChar np;
   vector<pair<int,string>> vstr;

   vector<pair<int,char>> cstr;

   readInput(mp,np,vstr,cstr);
   printWords(mp,np,vstr,cstr);

   return 0;
}
void printWords(mapTypeString& m,mapTypeChar& n,vecStr& v,vecChar& c)
{

   cout<<endl;
   cout<<setw(20)<<left<<"Words"<<right<<"frequencies"<<endl;
   cout<<"------------------------------"<<endl;
   for(map<string,int>::iterator it=m.begin();it != m.end();++it)
      cout<<setw(20)<<left<<it->first<<right<<it->second<<endl;



   cout<<endl;
   cout<<setw(20)<<left<<"Frequencies"<<right<<"words"<<endl;
   cout<<"------------------------------"<<endl;
   for(vector< pair<int,string> >::iterator it = v.begin(); it != v.end(); ++it)
   {
      cout<<setw(20)<<left<<it->first<<right<<it->second<<endl;
   }


   cout<<endl;
 cout<<setw(20)<<left<<"letters"<<right<<"frequencies"<<endl;
   cout<<"------------------------------"<<endl;
   for(map<char,int>::iterator it=n.begin();it != n.end();++it)
      cout<<setw(20)<<left<<it->first<<right<<it->second<<endl;


   cout<<endl;
   cout<<setw(20)<<left<<"frequencies"<<right<<"letters"<<endl;
   cout<<"------------------------------"<<endl;
   for(vector< pair<int,char> >::iterator it = c.begin(); it != c.end(); ++it)
   {
      cout<<setw(20)<<left<<it->first<<right<<it->second<<endl;
   }

}
char myTolower(char c)
{
   return (tolower(c));
}

/********************************************************************
*function to read input from user teminal
*
*Input:
*output:
*********************************************************************/
void readInput(mapTypeString& m,mapTypeChar& n,vecStr& v,vecChar& c)
{
   string str;
   cout<<"The input list of words is(enter ctrl Z in windows or ctrl D in unix to end input):"; //Ctrl + z in windows, ctrl + d in unix to send eof when done user input
   while(cin>>str)
   {
      transform(str.begin(),str.end(),str.begin(),myTolower);
      m[str]++;

   }


   for(map<string,int>::iterator it=m.begin();it != m.end();++it)
      v.push_back(make_pair(it->second,it->first));

  sort(v.begin(), v.end(), myCompare1);




    for(map<string,int>::iterator it=m.begin();it != m.end();++it)
   {
      string temp=it->first;
      for(string::iterator iT=temp.begin();iT != temp.end();++iT)
	 n[*iT]=(n[*iT]++)+ it->second;
   }

 for(map<char,int>::iterator it=n.begin();it != n.end();++it)
      c.push_back(make_pair(it->second,it->first));

 sort(c.begin(), c.end(), myCompare2);





}




bool myCompare1(const pair<int,string>& x, const pair<int,string>& y)
{

   if(x.first == y.first)
      return x.second < y.second;
   return x.first > y.first;
}


bool myCompare2(const pair<int,char>& x, const pair<int,char>& y)
{

   if(x.first == y.first)
      return x.second < y.second;
   return x.first > y.first;
}
