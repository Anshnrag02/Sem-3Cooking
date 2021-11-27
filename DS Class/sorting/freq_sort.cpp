#include<bits/stdc++.h>
using namespace std;

string stringfrequencySort (string s)
{
    string f = "";
  vector < pair < int, char >>a;

  for (char i = (char)0; i <= 'z'; ++i)
    {
      a.push_back (
		    {
		    0, i});

    }
  for (int i = 0; s[i] != '\0'; ++i)
    {

      a[s[i]].first++;
    }
  sort (a.begin (), a.end (), greater <> ());

    for(int i = 0 ; i < (int)'z' ; i ++ ){
        for(int j = 0; j<a[i].first ; j++)
            f+=a[i].second;
    }
    return f;
}

int main(){
    string s = "Hemloboolfie";
    s=stringfrequencySort(s);
    cout<<s;
}
