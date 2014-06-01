#ifndef TVECTOR_H
#define TVECTOR_H

#include <math.h>
#include <iostream>

template <class Type>

class tVector
{
public:
    Type x;
    Type y;
    Type z;
    Type t;
public:
    tVector()
    {
        x = y = z = t = 0;
    }
    ~tVector()
    {
      std::cout << "tVector destoyed." << std::endl;
    }

    tVector(Type rx, Type ry, Type rz, Type rt)
    {
        x = rx;
        y = ry;
        z = rz;
        t = rt;
    }
    Type GetLength() const
    {
        Type Length = sqrt( x*x + y*y + z*z + t*t );
        return Length;
    }
    tVector Normilize()
    {
        Type L = this->GetLength();
        x /= L;
        y /= L;
        z /= L;
        t /= L;
        return this;
    }

    tVector operator+ (tVector & vec) const
    {
        Type sx = x + vec.x;
        Type sy = y + vec.y;
        Type sz = z + vec.z;
        Type st = t + vec.t;

        return tVector(sx, sy, sz, st);
    }
    tVector operator- (tVector & vec) const
    {
        Type sx = x - vec.x;
        Type sy = y - vec.y;
        Type sz = z - vec.z;
        Type st = t - vec.t;

        return tVector(sx, sy, sz, st);
    }
    Type operator* (tVector & vec) const
    {
        Type sx = x * vec.x;
        Type sy = y * vec.y;
        Type sz = z * vec.z;
        Type st = t * vec.t;

        return (sx + sy + sz + st);
    }

    tVector operator*= (Type & scale)
    {
        x *= scale;
        y *= scale;
        z *= scale;
        t *= scale;
        return this;
    }
    tVector operator+= (const tVector & vec)
    {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        t += vec.t;
        return this;
    }
    tVector operator-= (const tVector & vec)
    {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        t -= vec.t;
        return this;
    }
    friend std::ostream & operator<< (std::ostream & os, const tVector &vecc )
    {
        os << vecc.x << ":"<< vecc.y << ":" << vecc.z << ":"<< vecc.t << std::endl;
        return os;
    }
};



#endif // TVECTOR_H
