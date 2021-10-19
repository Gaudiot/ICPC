typedef long double ld;

const ld eps = 1e-9;
const ld PI = acos(-1.0L);

int cmp(ld a, ld b = 0){
    if(abs(a-b) < eps) return 0;
    return (a < b) ? -1 : +1;
}

struct PT{
    ld x, y;

    PT(ld x = 0, ld y = 0): x(x), y(y){}
    PT operator+ (const PT &p) const{ return PT(x+p.x, y+p.y); }
    PT operator- (const PT &p) const{ return PT(x-p.x, y-p.y); }
    PT operator* (ld k) const{ return PT(x*k, y*k); }
    PT operator/ (ld k) const{ return PT(x/k, y/k); }

    bool operator <(const PT &p) const {
      if(cmp(x, p.x) != 0) return x < p.x;
      return cmp(y, p.y) < 0;
    }

    bool operator== (const PT &p){ return !cmp(x, p.x) && !cmp(y, p.y);}
    bool operator!= (const PT &p){ return !(*this == p);}
};

ld dot(PT &p, PT &q) {return (p.x*q.x + p.y*q.y);}
//cross > 0, ponto a esquerda da reta
//cross < 0, ponto a direita da reta
ld cross(PT &p, PT &q) {return (p.x*q.y - q.x*p.y);}
ld angle (PT p) { return atan2(p.y, p.x); }
ld angle (PT p, PT q) { return atan2(cross(p, q), dot(p, q)); }
ld dist(PT p, PT q = {0, 0}){ return hypot(p.x-q.x, p.y-q.y);}
PT norm(PT p){ return p/dist(p);}
PT perp(PT p){return norm({p.y, -p.x});}

//degree in rad
PT rotateCCW(PT p, ld a){
    return PT(p.x*cos(a)-p.y*sin(a), p.x*sin(a)+p.y*cos(a));
}

//Check if a - b and c - d are parallel ou collinear
bool parallel(PT a, PT b, PT c, PT d){return cmp(cross(b-a, d-c)) == 0;}
bool collinear(PT a, PT b, PT c, PT d){
    return parallel(a, b, c, d) && cmp(cross(a - b, a - c)) == 0 && cmp(cross(c - d, c - a)) == 0;
}

ld computeSignedArea(const vector<PT> &p){
    ld area = 0;
    for(int i = 0 ; i < p.size() ; i++){
        int j = (i+1)%p.size();
        area += cross(p[i], p[j]);
    }
    return area/2.0;
}

ld getArea(const vector<PT> &p){
    return abs(computeSignedArea(p));
}

//projeto p na linha a-b
PT projectPointLine (PT a, PT b, PT c) {
  return a + (b-a) * dot(b-a, c-a)/dot(b-a, b-a);
}
//reflete c sobre a linha a-b
PT reflectPointLine (PT a, PT b, PT c) {
  PT p = projectPointLine(a, b, c);
  return p*2 - c;
}

//Verifica se os segmentos de reta a-b e c-d se intersectam
bool segInter (PT a, PT b, PT c, PT d) {
  if (collinear(a, b, c, d)) {
    if (cmp(dist(a, c)) == 0 || cmp(dist(a, d)) == 0 || cmp(dist(b, c)) == 0 || cmp(dist(b, d)) == 0) return true;
    if (cmp(dot(c - a, c - b)) > 0 && cmp(dot(d - a, d - b)) > 0 && cmp(dot(c - b, d - b)) > 0) return false;
    return true;
  }
  if (cmp(cross(d - a, b - a) * cross(c - a, b - a)) > 0) return false;
  if (cmp(cross(a - c, d - c) * cross(b - c, d - c)) > 0) return false;
  return true;
}

//interseccao entre a-b e c-d
PT lineInter(PT a, PT b, PT c, PT d) {
  b = b - a; d = c - d; c = c - a;
  return a + b * cross(c, d) / cross(b, d);
}

// Calcula centro do circulo dado tres pontos
PT computeCircleCenter (PT a, PT b, PT c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return lineInter(b, b + rotateCCW(a - b, 3*PI/2.0), c, c + rotateCCW(a - c, 3*PI/2.0));
}