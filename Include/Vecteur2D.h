#include <sstream>

template <class T>
inline const T operator - (const T & u, const T & v)
{
return u + -v;
}



class Vecteur2D
{
public:
double x,y;

inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

/**
 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
 *
 * */
inline Vecteur2D(const char *s, double d);
inline const Vecteur2D operator + (const Vecteur2D & u) const;
inline const Vecteur2D operator * (const double & a) const;
/**
 * - unaire (c'est-à- dire opposé d'un vecteur)
 * */
inline const Vecteur2D operator - () const;

/*..............
autres méthodes 
...................*/
operator std::string() const;

}; // classe Vecteur2D

inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u*a;}

 //------------ implémentation des fonctions inline ----------------------

inline  Vecteur2D::
Vecteur2D(const double & x, const double & y): x(x),y(y){}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
return Vecteur2D( x+u.x, y+u.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
return Vecteur2D( x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
return Vecteur2D(-x,-y);
}

Vecteur2D::operator std::string() const
{
std::ostringstream os;
os << "( " << x <<", " << y << ")";
return os.str();
}

std::ostream & operator << (std::ostream & os, const Vecteur2D & u)
{
os << (std::string) u;
return os;
}
