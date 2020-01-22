///**Bismillahir Rahmanir Rahim.**
#include <bits/stdc++.h>
#define int                   long long int
#define clr(a, v)             memset(a,v,sizeof a)
#define all(v)                v.begin(),v.end()
#define ast(v)                sort(all(v))
#define sfs(s)                scanf("%s", s)
#define sf(n)                 scanf("%lld", &n)
#define sff(n, m)             scanf("%lld %lld",&n,&m)
#define dst(v)                sort(all(v),greater<int>())
#define sfff(n, m, o)         scanf("%lld %lld %lld",&n,&m,&o)
#define PP(n, m)              cout << n << " " << m << "\n"
#define PPP(a, b, c)          cout<<a<<" "<<b<<" "<<c<<"\n"
#define MX(a)                 *max_element(all(a))
#define MI(a)                 *min_element(all(a))
#define SUM(a)                accumulate(all(a),0)
#define I(n)                  cin >> n
#define II(n, m)              cin >> n >> m
#define III(a, b, c)          cin >> a >> b >> c
#define MIN(a, b, c)          min(a, min(b, c))
#define MAX(a, b, c)          max(a, max(b, c))
#define MID(b, e)             (b+(e-b)/2)
#define CAS(a)                cout << "Case " << a << ":"
#define pf(n)                 printf("%lld", n)
#define pff(n,m)              printf("%lld %lld\n",n,m)
#define prln(n)               cout<<n<<"\n"
#define P(n)                  cout << n
#define debug                 cout << " debug\n"
#define yes                   cout << "yes\n"
#define no                    cout << "no\n"
#define minus1                cout << "-1\n"
#define zero                  cout << "0\n"
#define sp                    cout << " "
#define nl                    cout << "\n"
#define pii                   pair<int,int>
#define mp                    make_pair
#define pb                    push_back
#define S                     second
#define F                     first

using namespace std;
const int N = 2e5+50;
const int mod = 1e9+7;
bool is_prime[N+50];
//cout<<fixed<<showpoint;
//cout<<setprecision(12)<<res<<"\n";
vector<int>prime,primeFactor;
int digit(int n){return log10(n)+1;}
int bit_on(int n,int pos){return n=n|(1<<pos);}
int bit_off(int n,int pos){return n=n&~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
string toString(int n){stringstream ss;ss<<n;string s;ss>>s;return s;}
int toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
bool isVowel(char ch){ ch=tolower(ch); if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
double dis(double x, double y, double x2, double y2){double res = sqrt(pow(x-x2,2) + pow(y-y2,2));return res;}
void sieve(){prime.push_back(2);for(int i=4;i<=N;i+=2)is_prime[i]=1;for(int i=3; i<N; i+=2){if(is_prime[i] == 0)
{prime.push_back(i);for(int j = i*i; j<N; j += (i*2))is_prime[j]=1;}}}
bool isPrime(int n){if(n == 1) return false;if(n == 2) return true;if(n%2 == 0) return false;
for(int i = 3; i * i <= n; i += 2 )if(n%i == 0) return false;return true;}
void primeFac(int n){int tmp = sqrt(n);for(int i = 0; prime[i] <= tmp; i++){if(n%prime[i] == 0)
{while(n%prime[i] == 0){n /= prime[i];primeFactor.pb(prime[i]);}}}if(n > 1)primeFactor.pb(n);}
int SOD(int n){int sum = 1;for(int i = 0; prime[i] <= n; i++){if(n%prime[i] == 0){int cnt = 1;
while(n%prime[i] == 0){n /= prime[i];cnt++;}sum *= (pow(prime[i], cnt) - 1)/ (prime[i] - 1);}}return sum;}
int NOD(int n){int till=sqrt(n+1);int p,divisor=1;for(int i=0;prime[i]<=till;i++){if(n%prime[i]==0){p=1;
while(n%prime[i]==0){n/=prime[i];p++;}till=sqrt(n);divisor*=p;}}if(n>1)divisor*=2;return divisor;}
bool isDigit(char ch){if(ch >= 48 && ch <= 57) return true; else return false;}
string Upper(string s){transform(all(s),s.begin(),::toupper);return s;}
string Lower(string s){transform(all(s),s.begin(),::tolower);return s;}
int fx[]={0,0,1,-1};    //grid visit
int fy[]={1,-1,0,0};
//Template end
//-------------------******Alhamdulillah******--------------------//

double area(int x1,int y1, int x2, int y2, int x3, int y3){
    return abs(((x1*y2+x2*y3+x3*y1)-(x2*y1+x3*y2+x1*y3))/2.0);
}

int isInside(int x1,int y1, int x2, int y2, int x3, int y3, int x, int y){
    double A = area(x1,y1,x2,y2,x3,y3);
    double A1 = area(x,y,x2,y2,x3,y3);
    double A2 = area(x1,y1,x,y,x3,y3);
    double A3 = area(x1,y1,x2,y2,x,y);
    if(A==(A1+A2+A3)) return 1;
    else return 0;
}

int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast();
    int tc=1;
    for(int T=1; T<=tc; T++){
        int a1,b1,a2,b2,a3,b3;
        cin>>a1>>b1>>a2>>b2>>a3>>b3;
        int x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        if(isInside(a1,b1,a2,b2,a3,b3,x1,y1) || isInside(a1,b1,a2,b2,a3,b3,x2,y2) ||
           isInside(a1,b1,a2,b2,a3,b3,x3,y3) || isInside(x1,y1,x2,y2,x3,y3,a1,b1) ||
           isInside(x1,y1,x2,y2,x3,y3,a2,b2) || isInside(x1,y1,x2,y2,x3,y3,a3,b3))
            yes;
        else no;
    }
    return 0;

}

//--------------------******Alhamdulillah******-------------------//

