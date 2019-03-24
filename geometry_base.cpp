/* 
    credits to github.com/loppa for a part of the algorithms
*/
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define MAX 
const double EPS = 1e-9; // se o erro for menor que 10 ^(-9) então não tem erro
const double PI = acos(-1.0);

template<class T> // T vai ser do tipo que for passado no parâmetro   
class Point{ 
public:
    T x,y;
    Point(){}; // Construtor vazio

    Point(long double x,long double y){
        this->x = x;
        this->y = y;
    }
    Point operator + (const Point &b)const{ // sobrecarga de operador + agora é + de ponto
        return Point(x+b.x,y+b.y);
    }
    Point operator - (const Point &b) const{
        return Point(x - b.x, y - b.y);
    }

    Point operator += (const Point &b){
        this->x += b.x;
        this->y += b.y;
        return Point(this->x,this->y);
    }

    Point operator -= (const Point &b){
        this->x -= b.x;
        this->y -= b.y;

        return Point(this->x,this->y);
    }

    bool operator == (const Point &b) const{
        return (abs(x - b.x)<EPS and abs(y - b.y) < EPS); // se a subtraçao de ambos for menor que erro é igual
    }
    // baseado no eixo X
    bool operator < (const Point &b) const{
        return (x < b.x or (x==b.x and y<b.y));
    }
    /*
    Produto escalar
    p*q = |p|*|q|*cos(ang)   ang: inner ang (0 <= ang < PI)
    p*q = 0 => ang = 90 / p*q > 0 => ang < 90 / p*q < 0 => ang > 90
    p*p = |p|^2  => |p| = sqrt(p*p)
    */
    T operator * (const Point &b) const {
        return (this->x * b.x) + (this->y * b.y);
    }

    /*
    Produto vetorial
    p^q = |p|*|q|*sin(ang)   ang: directed ang from p to q(-PI < ang <= PI)
    p^q = 0 => ang = 0 or PI, p and q are colinear
    p^q > 0 => 0 < ang < PI / p^q < 0 => -PI < ang < 0
    p^q = directed area of paralelogram formed by vectors p and q
    dist point p to line ab = ||ab^p|| / ||ab||
    */
    T operator ^ (const Point &b) const { 
        return (this->x * b.y) - (this->y * b.x); 
    }

    Point operator / (T k) const { // divisão de um ponto por escalar
        if (k == 0) 
            cout << "Dividisão por 0" << endl;
        return Point (x/k, y/k);
    }
    Point operator * (T k) const { // multiplicação de um escalar pelo ponto
        return Point (x*k, y*k);
    }
    /*
        Tamanho = sqrt((x1-x2)^2  + (y1-y2)^2);
        caso já passe o ponto como a subtração dos dois
        x3 = x1-x2;
        y3 = y1-y2;
        Tamanho = sqrt(x3*x3 + y3*y3);
    */
    T tamanho() const{
        return sqrt(x*x + y*y);
    }
    // tamanho elevado ao quadrado
    T tamanho2(){
        return x*x + y*y; 
    }

    // distancia de ponto a ponto elevado ao quadrado
    T dpp2 (const Point &b) const {
        return ((*this)-b).tamanho2();
    }

    /*Distancia ponto a ponto*/
    T dpp (const Point &b) const {
        return ((*this)-b).tamanho();
    }

    /*
    área de um poligono concavo ou convexo
    dado vetor de vertices ordenados clockwise ou
    counter clockwise
    */
    static T area (vector <Point> v) {
        T area = 0.0;
        for (int i = 0; i < (int)v.size(); i++) 
            area += v[i] ^ v[(i+1)%v.size()];
        return abs(area/2.0);
    }
};

int main()
{   
    fastcin;
    
    return 0;
}