#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}
void print_occurrences(const vector<ull>& output) {
    for (int i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    
}


ull PolyHash(const string& S,const ull& p,const ull& x) {
    ull hash = 0;
    for (int i = S.length()-1; i >= 0; i--)
    {
        hash = ( hash * x + S[i] ) % p;
    }
    return hash;
}
vector <ull>PrecomputeHashes(const string& T, const ull& PatternLength,const ull& p,const ull& x,const string&Sub) {
    vector<ull>H(T.length() - PatternLength + 1);
    H[T.length() - PatternLength] = PolyHash(Sub, p, x);
    ull y = 1;
    for (int i = 1; i <= PatternLength; i++)
    {
        y = (y * x) % p;
    }
    for (int i = T.length()-PatternLength-1; i >= 0; i--)
    {
        H[i] = (ull)(x * H[i + 1] + T[i] - y * T[i + PatternLength]) % p;
    }
    return H;
}
bool AreEqual(const string& S1, const string& S2) {
    if (S1.length()!=S2.length())
    {
        return false;
    }
    for (int i = 0; i < S1.length()-1 ; i++)
    {
        if (S1[i]!=S2[i])
        {
            return false;
        }
    }
    return true;
}
vector<ull> RabinKarp(const Data& data ) {
   const string& T = data.text;
   const string& P = data.pattern;
   vector<ull>result;
   ull p = 100000007;
   ull x = 1;

   ull pHash = PolyHash( P, p, x);
   string Substring = T.substr((T.length() - P.length()), P.length());
   vector<ull> H = PrecomputeHashes(T, P.length(), p, x, Substring);

   for (int i = 0; i <= (T.length() - P.length()) ; i++)
   {
       const string &sub = T.substr(i,P.length());//from the current index and till we move number of indices equal to pattern length
       if (pHash!=H[i])
       {
           continue;
       }
       if (AreEqual(sub,P))
       {
           result.push_back(i);
       }
   }
   return result;


}

int main() {
    print_occurrences(RabinKarp(read_input()));
    return 0;
}
